#include <stdio.h>

typedef struct {
    int x;
    int y;
} Point;

void move(Point *current, Point target) {
    // Move horizontally
    while (current->x != target.x) {
        if (current->x < target.x) {
            current->x++;
        } else {
            current->x--;
        }
        printf("Moved to (%d, %d)\n", current->x, current->y);
    }

    // Move vertically
    while (current->y != target.y) {
        if (current->y < target.y) {
            current->y++;
        } else {
            current->y--;
        }
        printf("Moved to (%d, %d)\n", current->x, current->y);
    }
}

int main() {
    Point start = {0, 0}; // Starting point
    Point end = {5, 7};   // Target point

    printf("Starting at (%d, %d)\n", start.x, start.y);
    move(&start, end);
    printf("Reached target at (%d, %d)\n", start.x, start.y);

    return 0;
}