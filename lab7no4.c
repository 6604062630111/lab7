#include <stdio.h>

void printHead(int w);
void printBody(int w, int h);

int main() {
    int width, height;
    scanf("%d %d", &width, &height);

    printHead(width);
    printBody(width, height);
    printHead(width);

    return 0;
}

void printHead(int w) {
    int i = 0;
    while (i < w) {
        printf("*");
        i++;
    }
    printf("\n");
}

void printBody(int w, int h) {
    int i = 0;

    while (i < h - 2) {
        int j = 0;
        while (j < w) {
            if (j == 0 || j == w - 1)
                printf("*");
            else
                printf(" ");
            j++;
        }
        printf("\n");
        i++;
    }
}
