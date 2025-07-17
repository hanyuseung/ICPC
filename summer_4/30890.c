#include <stdio.h>

int main(void) {
    int X, Y;
    scanf("%d %d", &X, &Y);

    int i = 1, j = 1;

    while (i <= X && j <= Y) {
        if ((long long)i * Y < (long long)j * X) {
            printf("1");
            i++;
        }
        else if ((long long)i * Y > (long long)j * X) {
            printf("2");
            j++;
        }
        else {
            printf("3");
            i++;
            j++;
        }
    }
    while (i <= X) {
        printf("1");
        i++;
    }
    while (j <= Y) {
        printf("2");
        j++;
    }

    printf("\n");
    return 0;
}
