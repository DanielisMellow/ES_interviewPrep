#include <stdio.h>
#include <stdlib.h>

const char *my_strstr(const char *haystack, const char *needle) {

  int i = 0, j = 0, match_idx = 0;

  if (needle[j] == '\0') {

    return haystack;
  }
  while (haystack[i] != '\0' && needle[j] != '\0') {
    if (haystack[i] != needle[j]) {
      i++;
    } else {
      match_idx = i;
      while (haystack[i] == needle[j] && haystack[i] != '\0') {
        i++;
        j++;
      }
      if (needle[j] == '\0') {
        return &haystack[match_idx];
      }
      i = match_idx + 1;
      j = 0;
    }
  }

  return NULL;
}

int main(int argc, char *argv[]) {

  const char hey[] = "ABABDABACDABABCABAB";
  const char ndle[] = "ABABCABAB";

  printf("%s", my_strstr(hey, ndle));

  return EXIT_SUCCESS;
}
