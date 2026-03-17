//palindrome_1.c
/* Write a function that receive in input a string
 * and returns `True` if the string is palindrome, `False` otherwise.
 */

#include <stdio.h>
#include <string.h>
#define N_WORDS 15
#define MAXSTRING 100

typedef int Bool;

Bool palindrome (char *s, int n){
  int i,j;
  for (i=0; i<n/2; i++) {
      j = n - i - 1;
      if (s[i] != s[j]) return 0;
  }

  return 1;
}

int main(void){

  Bool answer;
  char source[MAXSTRING];
  int i;
  char *words[N_WORDS] = {"A",
                          "AA", "AX",
                          "ABA", "AAX", "AXY",
                          "ABBA", "ABAX", "AAXY", "AXYW",
                          "ABCBA", "ABBAX", "ABAXY", "AAXYW", "AXYWZ"  };

  printf("\n\n");

  for(i=0; i<N_WORDS; i++){
    strcpy(source, words[i]);
    answer= palindrome(source,strlen(source));
    printf("%s PALINDROME: %s\n",source, answer ? "YES":"NO");
  }

  getchar();

}
