#include <stdio.h>

int main() {
    int n = 4; // n为图案的行数
    int i, j;

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= 2 * n - 1; j++) {
            if (j <= n - i || j >= n + i) {
                printf(" ");
            } else {
                printf("*");
            }
        }
        printf("\n");
    }

    return 0;
}