#include <iostream>
#include <stdexcept>
#include <algorithm>

using namespace std;

void print_backwards(const char *begin, const char *end) {
    if (begin == end) {
        return;
    }

    print_backwards(begin + 1, end);

    if (*begin <= 32) {
        const char *temp = begin + 1;
        while (*temp > 32) {
            cout << *temp;
            temp++;
        }

        cout << " ";
    }
}

void print_backwards(const char *string) {
    const char *temp = string;
    while (*temp) {
        temp++;
    }

    print_backwards(string, temp);

    const char* begin = string;
    while(*begin > 32) {
        cout << *begin++;
    }
}

class Interval {
protected:
    int start;
    int duration;
    int current;

public:
    Interval() {
        this->start = 0;
        this->duration = 1;
        this->current = 0;
    }

    Interval(int _start, int _duration) : start(_start), duration(_duration) {
        this->current = start;
    }

    int operator*() const {
        return current;
    }

    Interval& operator++() {
        if (this->last()) {
            throw out_of_range("The last element of the interval is reached");
        }

        this->current++;
        return *this;
    }

    Interval operator++(int) {
        if (this->last()) {
            throw out_of_range("The last element of the interval is reached");
        }

        Interval temp = *this;
        this->current++;
        return temp;
    }

    bool last() {
        return this->current == this->start + duration;
    }

    void reset() {
        this->current = this->start;
    }
};

class SquaredInterval : public Interval {
public:
    SquaredInterval() {
    }

    SquaredInterval(int start, int duration) : Interval(start, duration) {
    }

    int operator*() const {
        return Interval::operator*() * Interval::operator*();
    }

    bool operator>(const SquaredInterval& other) const {
        return this->getMaxValue() > other.getMaxValue();
    }

    int getMaxValue() const {
        return max(
                this->start * this->start,
                (this->start + this->duration) * (this->start + this->duration));
    }

    void print() const {
        cout << "start: " << this->start << " " << "duration: " << this->duration << endl;
    }
};

void sortIntervals(SquaredInterval* arr, int size) {
    sort(arr, arr + size, [](const SquaredInterval& a, SquaredInterval& b) {
        return a > b;
    });
}

int main() {
    SquaredInterval i(0,10);
    std::cout << *i << std::endl;
    do {
        ++i;
        std::cout << *i << std::endl;
    } while (!i.last());

    SquaredInterval intervals[3] = {
            SquaredInterval(1, 5),
            SquaredInterval(-2, 4),
            SquaredInterval(-9, 10)
    };

    sortIntervals(intervals, 3);

    for (int j = 0; j < 3; ++j) {
        intervals[j].print();
    }
}


