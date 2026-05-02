/*
Problem: Given a target distance and cars' positions and speeds, compute the number of car fleets reaching the destination.
Sort cars by position in descending order and calculate time to reach target.

Assumed Input Format
First line: target
Second line: n
Third line: n space-separated positions
Fourth line: n space-separated speeds
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pos;
    int speed;
} Car;

static int compareCars(const void *a, const void *b)
{
    const Car *x = (const Car *)a;
    const Car *y = (const Car *)b;
    return y->pos - x->pos;
}

int main(void)
{
    int target, n;
    printf("Enter target distance: ");
    if (scanf("%d", &target) != 1) return 0;
    printf("Enter number of cars: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    Car *cars = (Car *)malloc((size_t)n * sizeof(Car));
    if (cars == NULL) return 1;

    printf("Enter %d positions: ", n);
    for (int i = 0; i < n; i++) scanf("%d", &cars[i].pos);
    printf("Enter %d speeds: ", n);
    for (int i = 0; i < n; i++) scanf("%d", &cars[i].speed);

    qsort(cars, (size_t)n, sizeof(Car), compareCars);

    int fleets = 0;
    double lastTime = -1.0;
    for (int i = 0; i < n; i++)
    {
        double time = (double)(target - cars[i].pos) / cars[i].speed;
        if (time > lastTime)
        {
            fleets++;
            lastTime = time;
        }
    }

    printf("Number of car fleets: %d\n", fleets);
    free(cars);
    return 0;
}
