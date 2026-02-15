#include <stdio.h>

long convert(int h, int m, int s);

int main() {
    int h, m, s;
    scanf("%d %d %d", &h, &m, &s);

    long result = convert(h, m, s);
    printf("%ld", result);

    return 0;
}

long convert(int h, int m, int s) {
    long total = 0;
    total = (long)h * 3600 + (long)m * 60 + s;
    return total;
}

