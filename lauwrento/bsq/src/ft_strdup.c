#include "main.h"

/*
 * @param *s source string
 * @param *charset delimiter
 * @return String
 */
char *ft_strdup(char *s, char *charset) {
  int len, i;
  char *dup_s;
  if (s == NULL) return (NULL);

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
