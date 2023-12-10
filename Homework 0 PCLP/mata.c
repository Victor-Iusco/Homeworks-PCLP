#include <stdio.h>

typedef struct {
    int x;
    int y;
    int z;
} Vector;

int main() {
    Vector v;
    v.x = 1;
    v.y = 2;
    v.z = 3;

    printf("Vector: (%d, %d, %d)\n", v.x, v.y, v.z);

