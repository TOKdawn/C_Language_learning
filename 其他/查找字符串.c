#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define EXIT_SUCCESS 0
int getCout(char *str, char *substr, int *count) {
  int rv = 0;
  char *p = str;
  int ncout = 0;
  if (str == NULL || substr == NULL || count == NULL) {
    rv = -1;
    printf("func getCout()check err:%d \n", rv);
    return rv;
  }
  do {
    p = strstr(p, substr);
    if (p == NULL) {
      break;
    } else {
      ncout++;
      p = p + strlen(substr);
    }
  } while (*p != '\0');
  *count = ncout;
  printf("ncout:%d\n", ncout);
  return rv;
}
int main(int argc, char const *argv[]) {
  int ret = 0;
  char *p = "abcddwq2edabcdsadabcd";
  // char *p = NULL;
  int ncont = 0;
  char *subp = "abcd";
  ret = getCout(p, subp, &ncont);
  if (ret != 0) {
    printf("func GetCout()err:%d\n", ret);
    return EXIT_SUCCESS;
  }
  return 0;
}
