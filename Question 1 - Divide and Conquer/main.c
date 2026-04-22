#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int x; // x -> coordinate 
    int h;// h-> height at that point 
} Point;

Point* merge(Point* left, int n1, Point* right, int n2, int* size) {
    int i = 0, j = 0, k = 0;
    int h1 = 0, h2 = 0;

    Point* result = (Point*)malloc((n1 + n2) * sizeof(Point));

    while (i < n1 && j < n2) {
        int x;

        if (left[i].x < right[j].x) {
            x = left[i].x;
            h1 = left[i].h;
            i++;
        } else {
            x = right[j].x;
            h2 = right[j].h;
            j++;
        }

        int maxH = (h1 > h2) ? h1 : h2;

        if (k == 0 || result[k - 1].h != maxH) {
            result[k].x = x;
            result[k].h = maxH;
            k++;
        }
    }

    while (i < n1) {
        result[k++] = left[i++];
    }

    while (j < n2) {
        result[k++] = right[j++];
    }

    *size = k;
    return result;
}

Point* skyline(int buildings[][3], int low, int high, int* size) {
    if (low == high) { // best case scenario 
        Point* res = (Point*)malloc(2 * sizeof(Point));

        res[0].x = buildings[low][0];
        res[0].h = buildings[low][1];

        res[1].x = buildings[low][2];
        res[1].h = 0;

        *size = 2;
        return res;
    }

    int mid = (low + high) / 2;

    int size1, size2;

    Point* leftSky = skyline(buildings, low, mid, &size1);
    Point* rightSky = skyline(buildings, mid + 1, high, &size2);

    return merge(leftSky, size1, rightSky, size2, size);
}

int main() {
    int buildings[][3] = {
        {1, 11, 5},
        {2, 6, 7},
        {3, 13, 9},
        {12, 7, 16}
    };

    int n = sizeof(buildings) / sizeof(buildings[0]);
    int size;

    Point* result = skyline(buildings, 0, n - 1, &size);

    printf("Skyline:\n");
    for (int i = 0; i < size; i++) {
        printf("(%d, %d)\n", result[i].x, result[i].h);
    }

    return 0;
}
