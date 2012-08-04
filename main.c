#include "stdio.h"
#include "stdlib.h"

int removeSpaceChars (char * pSentence, int len, int first, int last) {
  int i = last + 1;
  int start = first;
  while (i < len) {
    pSentence[start] = pSentence[i];

    ++start;
    ++i;
  }
  while (start < len) {
    pSentence[start] = '\0';
    ++start;
  }

  return 0;
}

int removeSpace (char * pSentence, int len) {
  int i = -1;
  int first = 0;
  int last = 0;
  int j = -1;
  int count = 0;
  int tag = 0;

  if (pSentence == 0) return 0;
  while (++i < len) {
    if (pSentence[i] != ' ') {
      first = i;
      break;
    }
  }

  i = len;
  while (--i > -1) {
    if (pSentence[i] != ' ') {
      last = i;
      break;
    }
  }

  i = first;
  j = 0;
  while (i < last + 1) {
    pSentence[j] = pSentence[i];
    ++j;
    ++i;
  }
  count = j - 1;

  while (j < len) {
    pSentence[j] = '\0';
    ++j;
  }

  printf ("%s\n\r", pSentence);

  i = 0;
  while (i < count) {
    if (pSentence[i] == ' ') {
      if (tag ==0) {
        tag = 1;
        first = i + 1;
      }
    } else {
      if (tag == 1) {
        last = i - 1;

        removeSpaceChars (pSentence, len, first, last);
        
        tag = 0;
        count = count - (last - first + 1);
        i = first - 1;

        first = 0;
        last = 0;
      }
    }

    ++i;
  }

  return 0;
}

int main (int argc, char * argv[]) {
  char * pSentence = "      this is  the    sentence      of     test        ";
  printf ("%s\n\r", pSentence);
  removeSpace (pSentence, 55);
  printf ("%s\n\r", pSentence);
  return 0;
}
