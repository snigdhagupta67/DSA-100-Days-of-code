#include <stdio.h>

int main() {
    int n, i, j;
    int isIdentity = 1;

    scanf("%d", &n);

    int a[n][n];

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);

            if (i == j && a[i][j] != 1) {
                isIdentity = 0;
            }
            else if (i != j && a[i][j] != 0) {
                isIdentity = 0;
            }
        }
    }

    if (isIdentity)
        printf("Identity Matrix");
    else
        printf("Not an Identity Matrix");

    return 0;
}