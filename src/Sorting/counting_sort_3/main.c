#include <stdio.h>
#include <stdlib.h>

// Sort Structures

typedef struct {
    int index;  // The integer field used for sorting
    int v1;
    float v2;
    // other fields
} Element;


void printArray(Element *v, int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("(%d %d %0.2f )", v[i].index, v[i].v1,v[i].v2 );
    }
    printf("]\n");
}

void counting_sort(Element *vett, int nEl) {
    int i, j,k, value, idx;
    int min = vett[0].index, max = vett[0].index;
    for (i = 1; i < nEl; i++) {
        if (vett[i].index < min) min = vett[i].index;
        if (vett[i].index > max) max = vett[i].index;
    }

    int range = max - min + 1;
    int *count = malloc(range * sizeof(*count));
    for (int i = 0; i < range; i++) count[i] = 0;

    // Count the occurrences of each element
    for (i = 0; i < nEl; i++) {
        value = vett[i].index;
        idx = value - min;// remap
        count[idx]++;
    }


    // Cumulative occurrences 
    for (idx = 1; idx < range; idx++) {
        count[idx] += count[idx - 1];
    }

    // Build the sorted array
    Element *output = malloc(nEl * sizeof(*output));
    for (i = nEl - 1; i >= 0; i--) {
        
        idx = vett[i].index - min;
        k = count[idx] - 1;
        output[k] = vett[i];
        count[idx]--;
    }

    // Copy the sorted elements back to the original array - NEW
    for (i = 0; i < nEl; i++) {
        vett[i] = output[i];
    }


    // Free the allocated memory
    free(count);
    free(output);
}


int main() {
    Element vett[] = {
            {3, 100, 1.1},
            {7, 200, 2.2},
            {1, 300, 3.3},
            {8, 400, 4.4},
            {2, 500, 5.5},
            {7, 600, 6.6},
            {3, 700, 7.7},
            {8, 800, 8.8}
    };
    int nEl = sizeof(vett) / sizeof(vett[0]);

    printf("Original array:\n");
    printArray(vett, nEl);

    counting_sort(vett, nEl);

    printf("\nSorted array:\n");
    printArray(vett, nEl);

    return 0;
}