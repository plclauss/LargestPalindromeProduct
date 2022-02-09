#include <iostream>

void isPalindrome (int* arr, int arrSize) {
    for (int i = 0; i < (arrSize/2); i++) {
        for (int j = (arrSize - 1); j > (arrSize/2); j--) {
            if (*(arr + i) != *(arr + j)) {
                *(arr + 0) = 0;
                return;
            }
        }
    }
    *(arr + 0) = 1;
}

int createList(int prod) {
    int temp = prod;
    int count = 0;
    while (prod != 0) {
        prod /= 10;
        count++;
    }
    if ((count % 2) == 0)
        return 0;

    int* convert = (int*)malloc(sizeof(int) * count);
    count = 0;
    prod = temp;

    while (prod != 0) {
        *(convert + count) = prod % 10;
        count++;
        prod /= 10;
    }

    isPalindrome(convert, count);
    if (*(convert + 0) == 1)
        return 1;
    free(convert);
    return 0;
}

int product() {
    for (int i = 999; i >= 100; i--) {
        for (int j = i - 1; j >= 100; j--) {
            int res = createList(i * j);
            if (res == 1) {
                return (i * j);
            }
        }
    }
    return 0;
}
int main() {
    std::cout << product() << std::endl;
    return 0;
}
