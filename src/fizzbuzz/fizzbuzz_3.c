// fizzbuzz_3.c

// Modularize the problem
// Single responsability principle:
//  a function is responsible for one and only one thing.



#include <stdio.h>
typedef int Bool;
// don't repeat yourself


Bool isMultiple(int n, int d){
  return  n%d==0;
}


void fizzBuzz(int i, int div1, int div2){// fizzbuzz function
  Bool fizz, buzz;
  fizz= isMultiple(i, div1);
  buzz= isMultiple(i, div2);


  if (fizz && buzz )
    printf("fizzbuzz\n");
  else if (fizz)
    printf("fizz\n");
  else if (buzz)
    printf("buzz\n");
  else
    printf("%d\n",i);
}

int main(){
  int N=30;
  int i;
  int div1, div2;

  // -----------------------
  div1=3;
  div2=5;
  printf("\n\n--------------\n\n");

  for (i=1; i<=N; i++){
    fizzBuzz( i,  div1,  div2);
  }
  getchar();
}
