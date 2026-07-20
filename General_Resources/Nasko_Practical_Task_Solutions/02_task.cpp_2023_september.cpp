#include <iostream>
#include <vector>
#include <sstream>

struct SearchResult {
    std::string fileName;
    unsigned line_number;
    std::string line;
};

class File {
public:
    virtual std::vector<SearchResult> search(const std::string&) const = 0;

    virtual ~File() { }
};

class Document : public File {
    std::string name;
    std::string contents;

public:
    Document(const std::string& _name, const std::string& _contents)
        : name(_name), contents(_contents) { }

    std::vector<SearchResult> search(const std::string& str) const {
        std::istringstream doc(contents);
        std::string line;
        unsigned lineCount = 0;
        std::vector<SearchResult> result;
        while(std::getline(doc, line)) {
            ++lineCount;
            if (line.find(str) != std::string::npos) {
                result.push_back({ name, lineCount, line });
            }
        }

        return  result;
    }
};

class Folder: public File {
    std::vector<File*> files;
    std::string name;
public:
    Folder(const std::string& _name): name(_name) { }

    void addFile(File* file) {
        files.push_back(file);
    }

    std::vector<SearchResult> search(const std::string& str) const {
        std::vector<SearchResult> result;
        for(const File* f : files) {
            std::vector<SearchResult> found = f ->search(str);
            result.insert(result.end(), found.begin(), found.end());
//            for(const SearchResult& line: found) {
//                result.push_back(line);
//            }
        }


        return result;
    }
};

int main() {
    Document d1("employees.txt", "John Smith\nMaryia Ivanova\n"),
        d2("inventory.txt","Computers: 3\nPrinters: 1"),
        d3("employees.txt","Ivan Petrov\nJane Smith"),
        d4("inventory.txt","Computers: 5, 3D Printers: 1");

    Folder root("root"),
        acme("ACME Soft, Inc."),
        best("Best Soft, OOD");

    acme.addFile(&d1);
    acme.addFile(&d2);
    best.addFile(&d3);
    best.addFile(&d4);

    root.addFile(&acme);
    root.addFile(&best);

    std::vector<SearchResult> results = root.search("Smith");
    for(unsigned i = 0; i < results.size(); ++i) {
        std::cout << results[i].fileName
                  << ", line " << results[i].line_number << ": "
                  << results[i].line << std::endl;
    }
}