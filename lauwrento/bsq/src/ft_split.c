#include "main.h"

/*
 * @param *s Source string
 * @param *charset Delimiter string (Each caractère will be a delimiter)
 * @return Array of char pointer
 */
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