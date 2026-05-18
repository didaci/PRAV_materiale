#include <stdio.h>


void merge(int* v, int p, int q, int r){
    int i;
    int i_left, i_right;
    int len_left=q-p+1;
    int len_right=r-q;
    int v_left[len_left];
    int v_right[len_right];

    for (i=0;i<len_left;i++ ){
        v_left[i]=v[p+i ];
    }
    for (i=0;i<len_right;i++ ){
        v_right[i]=v[q+i+1 ];
    }

    i_left=0;
    i_right=0;
    i=p;

    do {
        if (v_left[i_left]<=v_right[i_right]){
            v[i]=v_left[i_left];
            i++; i_left++;
        }
        else{
            v[i]=v_right[i_right];
            i++; i_right++;
        }
    }
    while (i_left<len_left && i_right<len_right);

    while(i_left<len_left){
        v[i]=v_left[i_left];
        i++; i_left++;
    }
    while(i_right<len_right){
        v[i]=v_right[i_right];
        i++; i_right++;
    }
}

void merge_sort(int* v, int p, int r) {
    int q;

    if (p<r) {

        q = (p + r) / 2; // DIVISIONE FRA INTERI
        merge_sort(v, p, q);
        merge_sort(v, q + 1, r);
        merge(v, p, q, r);
    }
}



void printArray(int* v, int n){
    printf("[");
    for (int i=0; i<n; i++){
        printf("%d ",v[i]);
    }
    printf("]\n");
}



int main() {

    int vett[]={38, 27, 43, 3, 9, 82, 10};
    int nEl= sizeof (vett)/ sizeof(vett[0]);
    printArray(vett, nEl);
    merge_sort(vett, 0, nEl-1);
    printArray(vett, nEl);



    return 0;
}
