#include <stdio.h>
#include <stdbool.h>

/*
 * Se il ciclo interno effettua l'ultimo spostamento fra gli indici i e i+1, 
 * non è più necessario controllare gli elementi da i in poi.
*/

void bubbleSort_4(int* v, int n){
	int tmp,j=0, p=n;
	bool continua;
	do {
		continua=false;
		for (int i=0; i<n-1; i++){
			if (v[i]>v[i+1]){ // SWAP
				continua=true;
				p=i+1;
				tmp=v[i]; v[i]=v[i+1]; v[i+1]=tmp;
			} // end IF
		} // end FOR
	n=p;
	}
	while (continua && n>1); // con n==2 -> i==0;  non è necessario arrivare a n==1
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
	bubbleSort_4(vett, nEl);
	printArray(vett, nEl);
	return 0;
}
