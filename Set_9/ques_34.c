#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x, y;
} Point;

Point p[100], pivot;

/* Cross product */
int cross(Point a, Point b, Point c)
{
    return (b.x - a.x) * (c.y - a.y)
         - (b.y - a.y) * (c.x - a.x);
}

/* Sort points by polar angle */
int compare(const void *a, const void *b)
{
    Point p1 = *(Point *)a;
    Point p2 = *(Point *)b;

    return cross(pivot, p1, p2);
}

int main()
{
    int n, i, j, top = 0;

    printf("Enter number of points: ");
    scanf("%d", &n);

    printf("Enter points (x y):\n");
    for (i = 0; i < n; i++)
        scanf("%d %d", &p[i].x, &p[i].y);

    /* Find lowest point */
    int pos = 0;
    for (i = 1; i < n; i++)
        if (p[i].y < p[pos].y ||
           (p[i].y == p[pos].y && p[i].x < p[pos].x))
            pos = i;

    /* Put pivot at p[0] */
    Point temp = p[0];
    p[0] = p[pos];
    p[pos] = temp;

    pivot = p[0];

    /* Sort remaining points */
    qsort(p + 1, n - 1, sizeof(Point), compare);

    /* Graham Scan */
    Point stack[100];
    stack[top++] = p[0];
    stack[top++] = p[1];

    for (i = 2; i < n; i++) {
        while (top >= 2 &&
               cross(stack[top - 2], stack[top - 1], p[i]) <= 0)
            top--;

        stack[top++] = p[i];
    }

    printf("\nConvex Hull:\n");
    for (i = 0; i < top; i++)
        printf("(%d, %d)\n", stack[i].x, stack[i].y);

    return 0;
}

// Input:

// Enter number of points: 6
// Enter points (x y):
// 0 0
// 2 0
// 4 2
// 3 4
// 1 3
// 2 2


// Output:

// Convex Hull:
// (0, 0)
// (2, 0)
// (4, 2)
// (3, 4)
// (1, 3)

