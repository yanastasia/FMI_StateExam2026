#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isEqual(const char *a, const char *b) {
    int i = 0;
    while (a[i] && b[i]) {
        if (a[i] != b[i]) {
            return false;
        }

        i++;
    }

    if (a[i] || b[i]) {
        return false;
    }

    return true;
}

bool is_subordinate(const char *employee, const char *manager, const char *leaders[][2], size_t n) {
    for (int i = 0; i < n; ++i) {
        if (isEqual(leaders[i][0], employee)) {
            if (isEqual(leaders[i][1], manager)) {
                return true;
            }
            else {
                return is_subordinate(leaders[i][1], manager, leaders, n);
            }
        }
    }

    return false;
}

bool exists(const char* element, const char* collection[][2], size_t n) {
    for (int i = 0; i < n; ++i) {
        if (isEqual(collection[i][1], element)) {
            return true;
        }
    }

    return false;
}

const char* the_big_boss(const char* leaders[][2], size_t n) {
    for (int i = 0; i < n; ++i) {
        const char* employee = leaders[i][0];
        for (int j = 0; j < n; ++j) {
            if (!exists(employee, leaders, n)) {
                return  employee;
            }
        }
    }

    return nullptr;
}

int main() {
    const char* leaders[3][2] = {
            { "Ivan Ivanov", "maria" },
            { "maria", "Ivan Draganov" },
            { "Ivan Draganov", "Stoyan Petrov" }
    };

    const char* employee = "Иван Иванов";
    const char* manager = "Стоян Петров";
    cout << is_subordinate(employee, manager, leaders, 3) << endl;
    cout << the_big_boss(leaders, 3);
}