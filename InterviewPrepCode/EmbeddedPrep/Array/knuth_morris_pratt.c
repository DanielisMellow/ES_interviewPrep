#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void compute_lps_array(char *pat, int M, int *lps) {
  int len = 0;
  lps[0] = 0;
  int i = 1;

  while (i < M) {
    if (pat[i] == pat[len]) {
      len++;
      lps[i] = len;
      i++;
    } else { // pat[i] != pat[len]
      if (len != 0) {
        len = lps[len - 1];
      } else {
        lps[i] = 0;
        i++;
      }
    }
  }
}

void kmp_search(char *pat, char *txt) {
  int M = strlen(pat);
  int N = strlen(txt);

  int *lps = (int *)malloc(sizeof(int) * M);

  int j = 0;

  compute_lps_array(pat, M, lps);

  for (int i = 0; i < M; i++) {
    printf("%d", lps[i]);
  }
  printf("\n");
  int i = 0;
  while (i < N) {
    if (pat[j] == txt[i]) {
      j++;
      i++;
    }
    if (j == M) {
      printf("Found pattern at index %d \n", i - j);
      j = lps[j - 1];
    }
    // mismatch after j matches
    else if (i < N && pat[j] != txt[i]) {
      // Do not match lps[0..lps[j-1]] characters,
      // they will match anyway
      if (j != 0)
        j = lps[j - 1];
      else
        i = i + 1;
    }
  }

  free(lps);
}

int main(int argc, char *argv[]) {

  char *txt = "ABABDABACDABABCABAB";
  char *pat = "ABABCABAB";
  kmp_search(pat, txt);
  return 0;
  return EXIT_SUCCESS;
}
