// fizzbuzz_4.c

// Anticipation of change



#include <stdio.h>
typedef int Bool;
// don't repeat yourself!
Bool isMultiple(int n, int d){
  return  n%d==0;
}
Bool isGreaterThan(int n, int d){
  return  n>d;
}

void fizzBuzz(int i, int div1, int div2, int sw_f){// fizzbuzz function
  Bool fizz, buzz;
  switch (sw_f){
    case 1:
      fizz= isMultiple(i, div1);
      buzz= isMultiple(i, div2);
      break;
    case 2:
      fizz= isGreaterThan(i, div1);
      buzz= isGreaterThan(i, div2);
      break;
  }

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
  int sw_f; //switch function: 1 or 2
  int div1, div2;

  // -----------------------
  div1=3;
  div2=5;
  sw_f=1;

  printf("\n\n--------------\n\n");

  for (i=1; i<=N; i++){
    fizzBuzz( i,  div1,  div2, sw_f);
  }
}
