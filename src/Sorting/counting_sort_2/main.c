// Sorting/counting_sort_2

#include <stdio.h>
#include <stdlib.h>

// DUPLICATES
void printArray(int *v, int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("]\n");
}

void counting_sort(int *vett, int nEl) {
    int i, j, idx, value;
    int min = vett[0], max = vett[0];
    for (i = 1; i < nEl; i++) {
        if (vett[i] < min) min = vett[i];
        if (vett[i] > max) max = vett[i];
    }

    int range = max - min + 1;
    int *count = malloc(range * sizeof(*count));
    for ( i = 0; i < range; i++) count[i] = 0;

    // start snippet count
    // Count the occurrences of each element
    for (i = 0; i < nEl; i++) {
        value = vett[i];
        idx = value - min; // remap
        count[idx]++;
    }
    // end snippet count

    // start snippet build_array
    // Build the sorted array
    i = 0;
    for (idx = 0; idx < range; idx++) {
        while (count[idx] > 0) {
            vett[i] = idx + min;
            i++;
            count[idx]--;
        }
    }
    // end snippet build_array

    // Free the allocated memory
    free(count);
}

int main() {
    int vett[] = {3, 7, 1, 8, 2, 7, 3, 8};
    int nEl = sizeof(vett) / sizeof(vett[0]);
    printArray(vett, nEl);
    counting_sort(vett, nEl);
    printArray(vett, nEl);
    return 0;
}
