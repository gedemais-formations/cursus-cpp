#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool ft_strchr(char c, char *charset) {
  if (charset == NULL) return (false);
  for (int i = 0; charset[i] != '\0'; i++) {
    if (c == charset[i]) return true;
  }
  return false;
}

char *ft_strdup(char *s, char *charset) {
  int len, i;
  char *dup_s;
  if (s == NULL) return (NULL);
  if (charset == NULL) return (NULL);

  len = 0;
  while (s[len] != '\0' && !ft_strchr(s[len], charset)) len++;

  if (len == 0) return (NULL);

  dup_s = (char *)calloc(len + 1, sizeof(char));
  if (dup_s == NULL) return (NULL);
  i = 0;
  while (i != len) {
    dup_s[i] = s[i];
    i++;
  }

  dup_s[i] = '\0';

  return (dup_s);
}

char **ft_split(char *s, char *charset) {
  char **res;
  int row, i;
  if (s == NULL) return (NULL);
  if (charset == NULL) return (NULL);

  //  Get number of row
  row = 0;
  for (i = 0; s[i] != '\0'; i++) {
    if (ft_strchr(s[i], charset)) row++;
  }

  res = malloc(sizeof(char *) * (row + 2));
  if (res == NULL) return (NULL);

  res[row + 1] = NULL;

  for (i = 0; i != row + 1; i++) {
    res[i] = ft_strdup(s, charset);
    //  Move the PTR
    while (*s != '\0' && !ft_strchr(*s, charset)) {
      s++;
    }
    if (*s != '\0') s++;
  }

  return (res);
}
