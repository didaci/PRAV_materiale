// fizzbuzz_2.c

//  DRY

#include <stdio.h>
int main(){
  int N=30;
  typedef int Bool;
  Bool fizz, buzz;
  int div1, div2;
  int i;
  // -------------------
  div1=3;
  div2=5;
  printf("--------------\n");
  for ( i=1; i<=N; i++){
    fizz=i%div1==0;
    buzz=i%div2==0;


    if (fizz && buzz )
      printf("fizzbuzz\n");
    else if (fizz)
      printf("fizz\n");
    else if (buzz)
      printf("buzz\n");
    else
      printf("%d\n",i);
  }
getchar();
}
