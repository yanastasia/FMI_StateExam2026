#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class Rational {
private:
    int numerator, denominator;

public:
    Rational() {
        numerator = 0;
        denominator = 1;
        cout << "default constructor" << endl;
    }

    Rational(int n) : numerator(n), denominator(1) {
        cout << "constructor with one argument" << endl;
    }

    Rational(int n, int d) : numerator(n), denominator(d) {
    }

    Rational(Rational const &copy) : denominator(copy.denominator), numerator(copy.numerator) {
        cout << "copy constructor called" << endl;
    }

    ~Rational() {
        cout << "desctructor" << endl;
    }

//    Rational operator*(Rational const &rational) const {
//        Rational result = Rational(this->numerator * rational.numerator, this->denominator * rational.numerator);
//        return result;
//    }

    void print() const {
        cout << this->numerator << "/" << this->denominator << endl;
    }

    bool operator==(Rational const &r1) const {
        return r1.numerator == this->numerator && r1.denominator == this->denominator;
    }

    Rational operator+(int a) const {
        return Rational(this->numerator + a, this->denominator + a);
    }

    friend void friendFunction(Rational const &r) {
        cout << r.numerator << " " << r.denominator;
    }

    void test(Rational const &r) {
        cout << r.numerator << " " << r.denominator;
    }

    friend class RationalVector;

    Rational &operator*=(Rational const &r) {
        this->numerator *= r.numerator;
        this->denominator *= r.denominator;
        return *this;
    }

    Rational operator*(Rational const &r) const {
        Rational test = *this;
        return test *= r;
    }

    int &operator[](int index) {
        if (index == 0) {
            return this->numerator;
        } else if (index == 1) {
            return this->denominator;
        }

        cerr << "Error";
        return numerator;
    }

    friend istream &operator>>(istream &stream, Rational &r) {
        stream >> r.numerator >> r.denominator;
        return stream;
    }

    friend ostream &operator<<(ostream &stream, Rational const &r) {
        stream << r.numerator << " / " << r.denominator << endl;
        return stream;
    }

    Rational &operator=(Rational const &r) {
        cout << "operator= called" << endl;

        if (this != &r) {
            this->numerator = r.numerator;
            this->denominator = r.denominator;
        }

        return *this;
    }

    // ++r
    Rational &operator++() {
        this->numerator += denominator;
        return *this;
    }

    Rational operator++(int) {
        Rational old = *this;
        this->numerator += denominator;
        return old;
    }

    double operator()() const {
        return this->numerator / (double) this->denominator;
    }

    Rational operator()(int x, int y) const {
        return Rational(this->numerator + x, this->denominator + y);
    }

    operator double() const {
        return (double) this->numerator / this->denominator;
    }

    operator int() const {
        return this->numerator;
    }
};

class RationalVector {
private:
    Rational a, b;

public:
    void flip() {
        a.numerator = -a.numerator;
        b.numerator = -b.numerator;
    }
};

Rational add(Rational a, Rational b) {
    return Rational(2);
}

void test(Rational rational) {

}

class Player {
private:
    char *name;
    int score;

public:
    Player() {
        this->name = nullptr;
    }

    Player(const char *init_name, int score = 0) : score(score) {
        this->name = new char[strlen(init_name) + 1];
        strcpy(this->name, init_name);
    }

    Player(Player const &p) {
        this->name = new char[strlen(p.name) + 1];
        strcpy(this->name, p.name);
        this->score = p.score;
    }

    char *getName() const {
        return this->name;
    }

    void setName(const char *new_name) {
        delete[] this->name;
        this->name = new char[strlen(new_name) + 1];
        strcpy(this->name, new_name);
    }

    int getScore() const {
        return this->score;
    }

    void setScore(int new_score) {
        this->score = new_score;
    }

    Player &operator=(Player const &p) {
        if (this != &p) {
            if (this->name != nullptr) {
                delete[] this->name;
            }

            this->name = new char[strlen(p.name) + 1];
            strcpy(this->name, p.name);
        }

        return *this;
    }

    ~Player() {
        if (this->name != nullptr) {
            delete[] this->name;
        }
    }

    operator const char *() const {
        return this->name;
    }

    void print() const {
        cout << this->name << " -> " << this->score;
    }
};

void classes_constructors_destructors_operators() {
    //    Rational a;
//    Rational b;
//    add(a, b);
//    Rational res = add(1, Rational());
//    cout << "before main start" << endl;

//    Rational r2(2, 3);
//    Rational r3(2, 3);
//    Rational result = r2 * r3;
//
//    result.print();
//    test(result);
//
//    bool isEqual = r2 == r3;
//    Rational resultPlus3 = r2 + 3;
//    resultPlus3.print();
//    cout << isEqual << endl;

//    Rational operandA(2 ,3);
//    Rational operandB(3, 5);
//    operandA *= operandB;
//    operandA.print();

//    Rational indexer(2, 3);
//    cout << indexer[0] << " " << indexer[1] << endl;
//    indexer[0] = 5;
//    indexer[1] = 7;
//    indexer.print();

//    Rational r;
//    cin >> r;
//    cout << r;

//     Player player;
//     char name[] = "Atanas Vasilev";
//     cout << strlen(name);
//     Player player1(name);
//     player = player1;
//     Player player2 = player1;
//
//     cout << player.getName() << player1.getName() << player2.getName() << endl;


//    Rational t(2, 3);
//    Rational p(3, 4);
//    Rational result = t * p;
//    t.print();
//    p.print();
//    result.print();

//    Rational rational(2, 3);
//    Rational prefix = ++rational;
//    prefix.print();
//    rational.print();
//    Rational postfix = rational++;
//    postfix.print();
//    rational.print();

//    Rational rational(3, 5);
//    cout << rational() << endl;
//    cout << rational(1, 5);

//    Rational rational(3 ,5);
//    double result = rational;
//    cout << result << endl;
//    int numerator = rational;
//    cout << numerator << endl;

//    char name[] = "Nasko";
//    Player player(name);
//    char const* result = name;
//    cout << result;
//    cout << strlen(result) << endl;
}

template<typename T>
class Point {
    T x, y;

public:
    void translate(T a) {
        x += a;
        y += a;
    }
};

template<typename TKey, typename TValue>
class KeyValuePar {
    TKey key;
    TValue value;

public:
    KeyValuePar() {}

    KeyValuePar(TKey init_key, TValue init_value) : key(init_key), value(init_value) {}

    TKey getKey() const {
        return this->key;
    }

    TValue getValue() const {
        return this->value;
    }
};

template<typename T>
void template_swap(T &a, T &b) {
    T tmp = a;
    a = b;
    b = tmp;

    cout << "template swap" << endl;
}

void template_swap(int &a, int &b) {
    a += b;
    b = a - b;
    a = a - b;
    cout << "customized swap" << endl;
}

template<typename T>
void reverseArray(T *arr, int n) {
    for (int i = 0; i < n / 2; ++i) {
        template_swap(arr[i], arr[n - i - 1]);
    }
}

void templates() {
//    int a = 2, b = 3;
//    template_swap<int>(a, b);
//    template_swap(a, b);

//    int a[3] = { 1, 2, 3 };
//    reverseArray(a, 3);
}

class Hero : public Player {
private:
    int level;

public:
    Hero(const char *init_name, int init_score, int init_level) : Player(init_name, init_score), level(init_level) {
    }

//    Hero(Hero const & hero) : Player(hero) {
//        this->level = hero.level;
//    }

    int getLevel() const {
        return this->level;
    }

    void setLevel(int new_level) {
        this->level = new_level;
    }

    void print() const {
        Player::print();
        cout << " at level: " << this->level;
    }
};

class Base {
private:
    int a;

public:
    Base(int init_a = 0) : a(init_a) {

    }

    Base &operator=(const Base &base) {
        cout << "base operator=" << endl;
        if (this != &base) {
            this->a = base.a;
        }

        return *this;
    }

    void print() const {
        cout << a;
    }
};

class Derived : public Base {
private:
    int b;
public:
    Derived(int init_a = 0, int init_b = 0) : Base(init_a), b(init_b) {
    }

    Derived(const Derived &copy) : Base(copy) {
    }

    Derived &operator=(const Derived &copy) {
        cout << "derived operator=" << endl;
        if (this != &copy) {
            Base::operator=(copy);
            this->b = copy.b;
        }

        return *this;
    }

    void print() const {
        Base::print();
        cout << " " << b << endl;
    }
};

void inheritance() {
    Derived derived(1, 2);
    Derived copy(3, 4);
    copy = derived;
    copy.print();

    char name[] = "Nasko";
    Hero hero(name, 12, 10);
    hero.print();
    cout << endl;

    Hero *heroPointer = &hero;
    Player p = hero;
    p.print();
    cout << endl;

    Player *playerPointer = heroPointer;
    playerPointer->print();
    cout << endl;

    char new_name[] = "NaskoIT";
    p.setName(new_name);

    p.print();
    cout << endl;

    hero.print();
    cout << endl;

    char new_hero_name[] = "Hero";
    heroPointer->setName(new_hero_name);
    hero.print();
    cout << endl;
    playerPointer->print();
    cout << endl;
    p.print();
    cout << endl;

//    Player new_player(name, 10);
//    Hero h = (Hero const&)p;
//    h.setLevel(14);
//    cout << h.getLevel();
//    Player* new_player_pointer = &new_player;
//    Hero* hp = (Hero*)new_player_pointer;
//    hp->setLevel(14);
//    cout << hp->getLevel();
//    cout << hp->getName();


}

template<typename T>
double distance(Point<T> point1, Point<T> point2) {
    return 0;
}

class ClassA {
private:
    int a;

public:
    ClassA(int init_a = 0) : a(init_a) {}

    virtual void print() const {
        cout << a;
    }

    virtual ~ClassA() {
    }
};

class ClassB : public ClassA {
private:
    int b;

public:
    ClassB(int init_a = 0, int init_b = 0) : ClassA(init_a), b(init_b) {}

    void print() const {
        ClassA::print();
        cout << " " << b;
    }
};

class ClassC : public ClassB {
public:
    ClassC(int init_a = 0, int init_b = 1) : ClassB(init_a, init_b) {}
};

void virtual_functions() {
    char name[] = "NaskoIT";
    Player *pp = new Hero(name, 10, 15);
    pp->print();
    cout << endl;
    ((Hero *) pp)->print();
    cout << endl;

    ClassB classB(1, 2);
    ClassA *p = &classB;
    p->print();
    cout << endl;

    ClassA &by_ref = classB;
    by_ref.print();
    cout << endl;

    ClassC classC(4, 5);
    ClassA *pointer = &classC;
    pointer->print();
    cout << endl;
}

class BaseDiamond {
private:
    string name;

public:
    BaseDiamond() : name("") {
        cout << "BaseDiamond default ctor" << endl;
    }

    BaseDiamond(const string &init_name) : name(init_name) {
        cout << "BaseDiamond params ctor" << endl;
    }

    string getName() const {
        return this->name;
    }

    void print() const {
        cout << this->name;
    }
};

class MultiBaseA : virtual public BaseDiamond {
private:
    int level;

public:
    MultiBaseA() : level(0) {
        cout << "MultiBaseA default ctor" << endl;
    }

    MultiBaseA(const string &name, int level) : BaseDiamond(name), level(level) {
        cout << "MultiBaseA params ctor" << endl;
    }

    bool operator>(const MultiBaseA &a) const {
        return true;
    }

    void print() const {
        BaseDiamond::print();
        cout << " " << this->level;
    }
};

class Other {
};

class MultiBaseB : virtual public BaseDiamond, public Other {
private:
    int score;
public:
    MultiBaseB() : score(0) {
        cout << "MultiBaseB default ctor" << endl;
    }

    MultiBaseB(const string &name, int score) : BaseDiamond(name), score(score) {
        cout << "MultiBaseB params ctor" << endl;
    }

    void print() const {
        BaseDiamond::print();
        cout << " " << this->score;
    }

    bool operator>(const MultiBaseB &a) const {
        return false;
    }
};

class MultiDerived : public MultiBaseB, public MultiBaseA {
private:
    int difficulty;

public:
    MultiDerived() : difficulty(0) {
        cout << "MultiDerived default ctor" << endl;
    }

    MultiDerived(const string &name, int score, int level, int difficulty)
            : BaseDiamond(name), MultiBaseB("", score), MultiBaseA("", level), difficulty(difficulty) {
        cout << "MultiDerived params ctor" << endl;
    }

    bool operator>(const MultiDerived &a) {
        return MultiBaseB::operator>(a);
    }

    void print() const {
        cout << "override print" << endl;
    }
};

void multiple_inheritance() {
//    MultiDerived multiDerived;
//    MultiDerived second;
//    cout << (multiDerived > second);

    // MultiDerived default_test;
    MultiDerived params_test("Nasko IT", 1, 2, 3);
    // cout << params_test.getName() << endl;
    params_test.print();
    BaseDiamond *pp = &params_test;
    pp->print();
}

class AbstractClass {
private:
    int number;

public:
    AbstractClass() : number(0) {
        cout << "abstract class default constructor" << endl;
    }

    AbstractClass(int init_number) : number(init_number) {
        cout << "abstract class params constructor" << endl;
    }

    int getNumber() const {
        return number;
    }

    virtual void process() const = 0;
};

class Implementation : public AbstractClass {
public:
    Implementation() {
        cout << "Implementation default constructor called" << endl;
    }

    Implementation(int number) : AbstractClass(number) {
        cout << "Implementation params ctor called" << endl;
    }

    void process() const {
        cout << "Process: " << this->getNumber() << endl;
    }
};

void polymorphism() {
    Implementation task;
    task.process();

    Implementation anImplementation(1);
    anImplementation.process();
}

class StaticClass {
private:
    int score;
    static int instances;

public:
    static int test;

    StaticClass(int init_score = 0) : score(init_score) {
        instances++;
    }

    static int getInstances() {
        return instances;
    }
};

int StaticClass::instances = 0;
int StaticClass::test = 10;

void static_in_classes() {
    cout << StaticClass::getInstances() << endl;
    StaticClass staticClass;
    cout << staticClass.getInstances() << endl;
    cout << StaticClass::getInstances() << endl;
    cout << staticClass.test << endl;
}

void files() {
//    ifstream my_file("text.txt", std::ios::in);
//    ifstream image("image.jpg", ios::in | ios::binary);
//
//    ofstream html("page.html", ios::out);
//    ofstream logs("application.logs", ios::out | ios::app);
//    ofstream fo("file.data", ios::out | ios::binary);

    const string path = "C:\\Users\\Atanas.Vasilev\\Downloads\\New folder\\easy.txt";
    ifstream file(path);
    if (!file) {
        cout << "file cannot be opened" << endl;
    }

    char line[100];
    while (file.getline(line, 100)) {
        cout << line;
    }

    file.close();

    ofstream appendFileStream(path, ios::app);
    if (!appendFileStream) {
        cout << "Cannot open file: " << path << endl;
    }

    char data[] = "\nWritten by: Nasko IT";
    appendFileStream << data << endl;
}

void streams() {
    char nums[] = "1 2 3";
    istringstream stream(nums);
    int a, b, c;
    stream >> a >> b >> c;
    cout << a << b << c << endl;

    ostringstream output;
    output << 1.2 << " " << 3.5;
    string result = output.str();
    cout << result << endl;
}

int main() {
    cout << "start main" << endl;

    // classes_constructors_destructors_operators();
    // templates();
    // inheritance();
    // virtual_functions();
    // multiple_inheritance();
    // polymorphism();
    //static_in_classes();
    // files();
    streams();
    cout << "before main end" << endl;
}