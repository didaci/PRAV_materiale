
#include <printf.h>

void printArray(int* v, int n){
    printf("[");
    for (int i=0; i<n; i++){
        printf("%d ",v[i]);
    }
    printf("]\n");
}

void  insertionSort(int* v, int n) {
    int el, j;
    for (int i = 1; i < n; i++) {
        el = v[i];
        j = i - 1;
        while ( j >= 0 && v[j] > el) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = el;
    }
}




int main() {

    int vett[]={9,8,7,6,5,4,3,2,1,0};
    int nEl=sizeof (vett)/sizeof(vett[0]);
    printArray(vett, nEl);
    insertionSort(vett, nEl);
    printArray(vett, nEl);

    return 0;
}