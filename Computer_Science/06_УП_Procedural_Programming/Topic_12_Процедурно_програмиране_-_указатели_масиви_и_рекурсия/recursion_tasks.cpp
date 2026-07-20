bool binarySearch(const char *arr, size_t size, int target) {
    if (size == 0) {
        return false;
    }

    size_t mid = size / 2;
    if (arr[mid] == target) {
        return true;
    } else if (arr[mid] > target) {
        return binarySearch(arr, mid, target);
    }

    return binarySearch(arr + mid + 1, size - mid - 1, target);
}

unsigned fact(unsigned n) {
    if (n == 0 || n == 1) {
        return 1;
    }

    return n * fact(n - 1);
}

int fastPower(int n, int k) {
    if (k == 0) {
        return 1;
    }

    if (k % 2 == 1) {
        return n * fastPower(n, k - 1);
    }

    return fastPower(n * n, k / 2);
}

int fibb(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    return fibb(n - 1) + fibb(n - 2);
}

bool isPalinromeRec(const char *str, size_t len) {
    if (len <= 1) {
        return true;
    }

    return str[0] == str[len - 1] && isPalinromeRec(str + 1, len - 2);
}

bool isPalinrome(const char *str) {
    return isPalinromeRec(str, strlen(str));
}

bool linearSearch(const int *arr, size_t size, int searched) {
    if (size == 0) {
        return false;
    }

    return arr[0] == searched || linearSearch(arr + 1, size - 1, searched);
}

bool isCapital(char ch) {
    return ch >= 'A' && ch <= 'Z';
}

bool isLower(char ch) {
    return ch >= 'a' && ch <= 'z';
}

void getLowerAndUpperCount(const char *str, int &lowerCount, int &capitalCount) {
    if (!*str) {
        return;
    }

    if (isLower(*str)) {
        lowerCount++;
    } else if (isCapital(*str)) {
        capitalCount++;
    }

    getLowerAndUpperCount(str + 1, lowerCount, capitalCount);
}

int myMax(int a, int b) {
    return a > b ? a : b;
}

int getMaxInArr(const int *arr, size_t size) {
    if (size == 0) {
        return INT_MIN;
    }

    return myMax(arr[0], getMaxInArr(arr + 1, size - 1));
}

int getMaxInArr2(const int *arr, size_t size) {
    if (size == 0)
        return INT_MIN;
    if (size == 1)
        return arr[0];

    size_t mid = size / 2;
    return myMax(getMaxInArr2(arr, mid), getMaxInArr(arr + mid, size - mid));
}

int power(int n, int k) {
    if (k == 0) {
        return 1;
    }

    return n * power(n, k - 1);
}

bool isPrefixRec(const char *text, const char *pattern) {
    if (!*pattern) {
        return true;
    }
    if (!*text) {
        return false;
    }

    return *text == *pattern && isPrefixRec(text + 1, pattern + 1);
}

bool findInTextRec(const char *text, size_t textLen, const char *pattern, size_t patternLen) {
    if (textLen < patternLen) {
        return false;
    }

    return isPrefixRec(text, pattern) || findInTextRec(text + 1, textLen - 1, pattern, patternLen);
}

bool findInText(const char *text, const char *pattern) {
    return findInTextRec(text, strlen(text), pattern, strlen(pattern));
}

int sumArr(const int *arr, size_t size) {
    if (size == 0) {
        return 0;
    }

    return arr[0] + sumArr(arr + 1, size - 1);
}

int sumArrTail(const int* arr, size_t size, int res = 0) {
    if (size == 0) {
        return res;
    }

    return sumArrTail(arr + 1, size - 1, res + arr[0]);
}