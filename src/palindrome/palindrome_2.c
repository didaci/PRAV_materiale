//palindrome_2.c
#include <stdio.h>
#include <string.h>

#define MAXSTRING 100
#define N_WORDS 15

void join_string(char *destination, const char* source_1, int n1,const char* source_2, int n2 ){
  int i;
  for (i=0; i<n1; i++){
    destination[i]=source_1[i];
  }
  for (i=0; i<n2; i++){
    destination[n1+ i]=source_2[i];
  }
  destination[n1+n2]='\0';
};



void invert_string(const char *source, int n, char *dest){

    int i,j;
    for (i=0; i<n; i++) {
        j = n - i - 1;
        dest[i] = source[j];
    }
    dest[i]='\0';
}


void create_palindrome(const char *source, int n, char *s_palindrome){
    char s_inv[MAXSTRING];
    invert_string(source, n, s_inv);
    join_string(s_palindrome, s_inv, n ,source, n );
}

int main(void){

  char source[MAXSTRING];
  char source2[MAXSTRING];
  char dest[MAXSTRING];

  char *words[N_WORDS] = {"A",
                          "AA", "AX",
                          "ABA", "AAX", "AXY",
                          "ABBA", "ABAX", "AAXY", "AXYW",
                          "ABCBA", "ABBAX", "ABAXY", "AAXYW", "AXYWZ"  };

  int i;


  // test invert_string(const char *source, int n, char *dest)
  printf("\n\ntest invert_string\n");

  for(i=0; i<N_WORDS; i++){
    strcpy(source, words[i]);
    invert_string(source,strlen(source), dest);
    printf("%s->%s\n", source, dest);
  }


  // test  join_string
  printf("\n\ntest join_string\n");
  for(i=0; i<N_WORDS-1; i++){
    strcpy(source, words[i]);
    strcpy(source2, words[i+1]);
    join_string(dest, source,strlen(source),source2,strlen(source2));
    printf("%s + %s -> %s\n", source, source2, dest);
  }


  // test create_palindrome
  printf("\n\n test create_palindrome\n\n");


  for(i=0; i<N_WORDS; i++){
    strcpy(source, words[i]);
    create_palindrome(source, strlen(source), dest);
    printf("%s->%s\n", source, dest);
  }


  getchar();

}
