#include <iostream>
#include<vector>
#include <cstring>
#include <cmath>

using namespace std;

int calc(int a[5]) {
    int sum = 8;
    for (int i = 0; a[i]; ++i)
        sum += i;

    return sum;
}

void task_1_1() {
    // after second index will be initialized with 0
    int a[7] = {1, 2, 3};
    std::cout << calc(a); // 11
}

void task_1_2() {
    char text[] = "hello", *p = text;
    while (*p) cout << ++*p++;
    // while (*p) cout << ++(*(p++));
    // ifmnp
}

void task_1_3() {
    int *pt;
    int a[3] = {4, 19, 13};
    pt = &a[1];
    pt += 1;
    std::cout << *pt << std::endl; // 13
}

void f(int *arr1, const int *arr2) {
    int *p1 = arr1;
    const int *p2 = arr2;
    while (*p2 >= 0) {
        *p1++ = *p2++;
    }
}

void printArr(const int *arr, int length) {
    for (int i = 0; i < length; ++i) {
        cout << arr[i] << ", ";
    }

    cout << endl;
}

void task_1_4() {
    int A[4] = {-1, -2, -3, -4};
    int B[4] = {10, 20, 30, -1};
    f(A, B);

    // A: 10, 20, 30, -4
    // B: 10, 20, 30, -1
    printArr(A, 4);
    printArr(B, 4);
}

struct Point {
    float x;
    float y;

    float getDistance(Point b) {
        return sqrt(pow(b.x - this->x, 2) + pow(b.y - this->y, 2));
    }
};

struct Circle {
    Point center;
    float radius;
};

enum RelativePosition {
    NO_COMMON_POINTS,
    TOUCHING,
    INTERSECTING,
    SAME
};

// the precision is not problem for float type but just in case we can use this technique
bool areEqual(float a, float b) {
    float epsilon = 1e-6f;
    return std::abs(a - b) < epsilon;
}

RelativePosition findRelativePosition(Circle a, Circle b) {
    double epsilon = 1e-9;

    float distance = sqrt(pow(a.center.x - b.center.x, 2) + pow(a.center.y - b.center.y, 2));
    // float pointDistance = a.center.getDistance(b.center);

    if (distance > a.radius + b.radius) {
        return RelativePosition::NO_COMMON_POINTS;
    } else if (b.radius + a.radius == distance) {
        return RelativePosition::TOUCHING;
    } else if (b.radius + a.radius > distance && distance > abs(b.radius - a.radius)) {
        return RelativePosition::INTERSECTING;
    } else if (distance == abs(a.radius - b.radius)) {
        return RelativePosition::TOUCHING;
    } else if (distance == 0 && a.radius == b.radius) {
        return RelativePosition::SAME;
    }
    return RelativePosition::NO_COMMON_POINTS;
}

int main() {
    Circle circle = {center: Point{3, 4}, 4};
    Circle second = {Point{3, 4}, 5};
    cout << findRelativePosition(circle, second);

    double x = 0.1 + 0.2; // 0.1f + 0.2f should be 0.3f, but due to floating-point precision, it might not be exact
    double y = 0.3;
}