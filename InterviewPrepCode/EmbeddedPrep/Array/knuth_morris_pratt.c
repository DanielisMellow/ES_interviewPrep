#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void compute_lps_array(char *pat, int pattern_len, int *lps) {
  int prefix_len = 0;
  lps[0] = 0; // longest prefix suffix
  int i = 1;

  while (i < pattern_len) {
    if (pat[i] == pat[prefix_len]) {
      prefix_len++;
      lps[i] = prefix_len;
      i++;
    } else if (prefix_len != 0) {
      prefix_len = lps[prefix_len - 1];
    } else {
      // 'prefix_len' reached 0 so save that into lps[] move forward
      lps[i] = 0;
      i++;
    }
  }
}

void kmp_search(char *pat, char *txt) {
  int pattern_len = strlen(pat);
  int text_len = strlen(txt);

  int *lps = (int *)malloc(sizeof(int) * pattern_len);
  compute_lps_array(pat, pattern_len, lps);

  for (int i = 0; i < pattern_len; i++) {
    printf("%d", lps[i]);
  }
  printf("\n");

  int i = 0; // the position of the current character in the text
  int j = 0; // the postionn of the current character in the pattern
  while (i < text_len) {
    if (pat[j] == txt[i]) {
      j++;
      i++;
    }
    if (j == pattern_len) {
      printf("Found pattern at index %d \n", i - j);
      j = lps[j - 1]; // reset
    }
    // mismatch after j matches
    else if (i < text_len && pat[j] != txt[i]) {
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

  char *txt = "----ABCXXXABAB-----ABCXXXABCB";
  char *pat = "ABCXXXABCB";
  kmp_search(pat, txt);
  return 0;
  return EXIT_SUCCESS;
}
