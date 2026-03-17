// palindrome_3.c
#include <stdio.h>
#include <string.h>

#define MAXSTRING 100
#define N_WORDS 15



typedef int Bool;

Bool palindrome (char *s, int n){
    for (int i = 0; i<n/2; i++){
    if (s[i] != s[n-i-1]){
      return 0;
    }
  }
  return 1;
}



void copy_n_characters(char *destination, const char* source, int n){
  int i;
  for (i=0; i<n; i++){
    destination[i]=source[i];
  }
  destination[i]='\0';
};

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



void split_palindrome_otherstring(const char *source, int n, char *s_palindrome, char *s_nonpalindrome){
/*  find the biggest palindrome substring [ON THE LEFT]
 * and split the string
 *  i.e. 'ABCBAXY'->  ('ABCBA' , 'XY')
 *       'ABCDE'->   ('A' , 'BCDE')
 *       'ABCBA'->  ('ABCBA' , '')
 */
    int n1;
    for(n1=n; n1>0; n1--){
      Bool is_palindrome;
      is_palindrome = palindrome(source, n1); // check if the substring [0, i-1] is palindrome
      if (is_palindrome){
        // n1 is the lengh of the palindrome substring
        // source+n1 is the address of the first character of the non palindrome substring
        break;
      }
    }
    copy_n_characters(s_palindrome, source, n1);
    copy_n_characters(s_nonpalindrome, source+n1, n-n1); // from i to the end of the string

}


void invert_string(const char *source, int n, char *dest){
  int i;
  for (i=0; i<n; i++){
    dest[i]=source[n-i-1];
  }
  dest[i]='\0';

}

void create_palindrome(const char *source, int n, char *s_palindrome){
  /*
    #1. split into palindrome, other_string
    #   i.e. 'ABCBAXY'-> 'ABCBA' , 'XY'
    #2. add the (inverted) otherstring part of the string to the original string
    #   i.e. 'YX' + 'ABCBAXY'

    # PROS: easy to understand - modularity
    # CONS: slow. it is possible to optimize the function.
    */

    int n_np;
    char s_part_palindrome[MAXSTRING];
    char s_part_otherstring[MAXSTRING];
    char s_inv_otherstring[MAXSTRING];

    split_palindrome_otherstring(source, n, s_part_palindrome, s_part_otherstring);

    n_np = strlen(s_part_otherstring);
    invert_string(s_part_otherstring, n_np, s_inv_otherstring);
    join_string(s_palindrome, s_inv_otherstring, n_np ,source, n );

}

int main(void){

  Bool is_palindrome;
  char dest_1[MAXSTRING];
  char dest_2[MAXSTRING];

  char *words[N_WORDS] = {"A",
                          "AA", "AX",
                          "ABA", "AAX", "AXY",
                          "ABBA", "ABAX", "AAXY", "AXYW",
                          "ABCBA", "ABBAX", "ABAXY", "AAXYW", "AXYWZ"  };

  char source[]="It matters not how strait the gate, I am the captain of my soul.";
  int i, n;
  n= strlen(source);


  // test copy_n_characters - copy 10 characters
  printf("\n\ntest copy 10 characters\n");
  printf("Source: %s\n\n",source);

  for (i=0; i<n/2; i++){
    copy_n_characters(dest_1, &source[i],10) ;
    printf("from index %d->%s\n", i , dest_1);

  }


  // test split_palindrome_otherstring
  printf("\n\ntest split_palindrome_otherstring\n");
  for(i=0; i<N_WORDS; i++){
    split_palindrome_otherstring(words[i], strlen(words[i]), dest_1, dest_2);
    printf("%s->%s, %s\n", words[i], dest_1, dest_2);
}


  // test create_palindrome
  printf("\n\n test create_palindrome\n");

  for(i=0; i<N_WORDS; i++){
    create_palindrome(words[i], strlen(words[i]), dest_1);
    printf("%s->%s\n", words[i], dest_1);
  }


  getchar();

}
