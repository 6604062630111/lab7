#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int random100to200();

int main() {
    int M, N, i, j, k;
    int rnum, numok;
    int array[20][20];

    printf("array sizes:");
    scanf("%d %d", &M, &N);

    if (M < 3) M = 3;
    if (N > 19) N = 19;

    srand(time(NULL));

    // กำหนดค่าเริ่มต้นให้ array
    for (j = 0; j < 20; j++) {
        for (k = 0; k < 20; k++) {
            array[j][k] = -1;
        }
    }

    for (i = 0; i < M * N; i++) {

        do {
            rnum = random100to200();
            numok = 1;

            for (j = 0; j < M; j++) {
                for (k = 0; k < N; k++) {
                    if (array[j][k] == rnum) {
                        numok = 0;
                    }
                }
            }

        } while (numok == 0);

        array[i / N][i % N] = rnum;
    }

    for (j = 0; j < M; j++) {
        for (k = 0; k < N; k++) {
            printf("%d ", array[j][k]);
        }
        printf("\n");
    }

    return 0;
}

int random100to200() {
    return (rand() % 101) + 100;
}


