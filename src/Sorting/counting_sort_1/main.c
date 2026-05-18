#include <stdio.h>
#include <stdlib.h>


void printArray(int *v, int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("]\n");
}

void counting_sort(int *vett, int nEl) {
    int i, j, idx;
    int min = vett[0], max = vett[0];
    for (i = 1; i < nEl; i++) {
        // determino il range
        min = (vett[i] < min) ? vett[i] : min;
        max = (vett[i] > max) ? vett[i] : max;
    };

    int range = max - min + 1;
    int presence[range];
    //int *presence = malloc(range * sizeof(*presence ));
    for (i = 0; i < range; i++) presence[i] = 0;

    // Mark the presence of each element

    for (i = 0; i < nEl; i++) {
        j = vett[i] - min;
        presence[j] = 1;
    }


    // Build the sorted array
    idx = 0;
    for (i = 0; i < range; i++) {
        if (presence[i] == 1) {
            vett[idx] = i + min;
            idx++;

        }
    }

    // Free the allocated memory
    // free(presence);


}

int main() {


    int vett[] = {3, 7, 1, 8, 2};
    int nEl = sizeof(vett) / sizeof(vett[0]);
    printArray(vett, nEl);
    counting_sort(vett, nEl);

    printArray(vett, nEl);


    return 0;
}
