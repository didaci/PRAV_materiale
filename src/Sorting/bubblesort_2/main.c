#include <stdio.h>
#include <stdbool.h>

/*
* quando non avvengono più swap per un intero ciclo esterno, 
* l'array è ordinato. 
* Posso interrompere la procedura di ordinamento.
*/
void bubbleSort_2a(int* v, int n){
	int tmp;
	bool continua;
	for (int j=0; j<n-1; j++){
		printf("iter: %d \n",j);
		continua=false;
		for (int i=0; i<n-1; i++){
			if (v[i]>v[i+1]){ // SWAP
				continua=true;
				tmp=v[i]; v[i]=v[i+1]; v[i+1]=tmp;
			}
		}
	 if (continua==false) break;
	}
}
void bubbleSort_2b(int* v, int n){
	int tmp,j=0;
	bool continua;
	do {
		printf("iter: %d \n",j++);
		continua=false;
		for (int i=0; i<n-1; i++){
			if (v[i]>v[i+1]){ // SWAP
				continua=true;
				tmp=v[i]; v[i]=v[i+1]; v[i+1]=tmp;
			}
		}
	}
	while (continua);
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
	bubbleSort_2a(vett, nEl);
	printArray(vett, nEl);
	return 0;
}
