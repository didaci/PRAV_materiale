// FIZZBUZZ_5

/*
*
* È un’implementazione accettabile dell’idea alla base dello Strategy Pattern, 
* perché usa un puntatore a funzione per rendere sostituibile una parte del 
* comportamento a runtime. 
* Tuttavia, come esempio di Strategy Pattern è piuttosto minimale 
* e ricorda più una callback o un predicato parametrico che una strategia completa.
*
*/

#include <stdio.h>
typedef int Bool;

void fizzBuzz(int i, int div1, int div2, 
          Bool (*p_cond)(int a, int b)){
  Bool fizz, buzz;
  fizz= p_cond(i, div1);
  buzz= p_cond(i, div2);

  if (fizz && buzz )
    printf("fizzbuzz\n");
  else if (fizz)
    printf("fizz\n");
  else if (buzz)
    printf("buzz\n");
  else
    printf("%d\n",i);
}

//----

Bool isMultiple(int n, int d){
    return  n%d==0;
}
Bool isGreaterThan(int n, int d){
    return  n>d;
}


int main(){
  int N=20, i, div1, div2;

  /* pointer to a function
   * it can point to isMultiple(), 
   * to isGreaterThan(),
   * or to any function that accepts two integers 
   * and returns an integer (Bool)
   */
  
  Bool (*p_condition)(int a, int b);
  p_condition= isMultiple; // oppure isGreaterThan


  // -----------------------
  div1=3;
  div2=5;
  printf("\n\n--------------\n\n");

  for (i=1; i<=N; i++){
    fizzBuzz( i,  div1,  div2, p_condition);
  }
}
