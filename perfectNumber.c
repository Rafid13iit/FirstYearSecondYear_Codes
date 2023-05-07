#include <stdio.h>

int main() {
    int start, end, i, j, sum;

    scanf("%d%d", &start, &end);

    printf("Perfect numbers in the range %d to %d are:\n", start, end);

    for (i = start; i <= end; i++) {
        sum = 0;

        for (j = 1; j < i; j++) {
            if (i % j == 0) {
                sum += j;
            }
        }

        if (sum == i) {
            printf("%d\n", i);
        }
    }

    return 0;
}
