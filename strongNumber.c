#include <stdio.h>

int main() {
    int start, end, i, j, sum, fact, rem;

    scanf("%d%d", &start, &end);

    printf("Strong numbers in the range %d to %d are:\n", start, end);

    for (i = start; i <= end; i++) {
        sum = 0;
        j = i;

        while (j > 0) {
            fact = 1;
            rem = j % 10;

            for (int k = 1; k <= rem; k++) {
                fact *= k;
            }

            sum += fact;
            j /= 10;
        }

        if (sum == i) {
            printf("%d\n", i);
        }
    }

    return 0;
}
