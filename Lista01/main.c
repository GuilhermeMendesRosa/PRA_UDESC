#include <stdio.h>

void main() {

    int k = 9;
    int size = 4;
    int array[] = {1, 2, 4, 5};

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (i == j) {
                continue;
            }

            if (array[i] + array[j] != k) {
                continue;
            }

            printf("True");

            return;
        }
    }

    printf("False");

}