#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Find the location of the first occurrence of pattern in text
// or say that it does not occur if that is the case.
// If you find the pattern in the text, output the index of the
// first letter in text where the pattern first occurs.

// You must also print the total number of character compairsons that
// the program made.

// If the number of unchecked characters in the text is ever less than
// the length of the pattern the algorithm must stop.

// NOTE:  All test texts and patterns should not contain any white space
//        (e.g. blank space character, newline, tab, etc.) as scanf
//        will stop on such an input character.

int main()
{
  char text[10000] ;
  char pattern[200] ;
  int m,n ;

  int comparisons = 0;

  printf("enter text : ") ;
  scanf("%s", text) ;
  printf("enter pattern you are searching for : ") ;
  scanf("%s", pattern) ;

  m = strlen(pattern) ;
  n = strlen(text) ;
  printf("The pattern has %d characters and the text has %d characters.\n", m,n) ;

  int text_table[128];
  for(int i = 0; i < 128; ++i) {
      text_table[i] = m;
  }

  for(int i = 0; i < m-1; ++i){
      text_table[(int) pattern[i]] = m - i - 1;
  }

    printf("\n");
    for(int i = 97; i < 123; ++i) {
        printf("%c", (char) i);
    }
    printf("\n");
  for(int i = 97; i < 123; ++i){
      printf("%d", text_table[i]);

  }
  printf("\n");

  int start_index = 0;
  int found = 0;
  for(int i = m-1; i < 128; ++i) {
      for(int k = (m-1) + start_index; k >= start_index; --k) {
          ++comparisons;
          if(pattern[k-start_index] != text[k]) {
              break;
          }
          if(k == start_index) {
              found = 1;
          }
      }
      if(found == 1) {
          break;
      }
      else {
          start_index += text_table[(int) text[m-1 + start_index]];
          if(start_index > n)
              break;
      }
  }
  if(found == 1) {
      printf("\nThe pattern was found starting at index %d", start_index);
  }
  else {
      printf("\nthe pattern was not found");
  }
  printf("\nthere were %d comparisons\n", comparisons);

}

  


