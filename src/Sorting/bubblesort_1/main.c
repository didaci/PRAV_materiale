#include <stdio.h>
void bubbleSort(int* v, int n){
	int tmp;
	for (int j=0; j<n-1; j++){
		printf("iter: %d \n",j);
		for (int i=0; i<n-1; i++){
			if (v[i]>v[i+1]){
				// SWAP
				tmp=v[i]; v[i]=v[i+1]; v[i+1]=tmp;
			}
		}
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
	int vett[6]={9,18,7,15,21,11};
	int nEl=6;
	printArray(vett, nEl);
	bubbleSort(vett, nEl);
	printArray(vett, nEl);
	return 0;
}
