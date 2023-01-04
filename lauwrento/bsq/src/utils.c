#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * @param c characters to check
 * @param *charset String of all characters to check
 */
bool ft_strchr(char c, char *charset) {
  for (int i = 0; charset[i] != '\0'; i++) {
    if (c == charset[i]) return true;
  }
  return false;
}

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

/*
 * @param *s Source string
 * @param *charset Delimiter string (Each caractère will be a delimiter)
 * @return Array of char pointer
 */
char **ft_split(char *s, char *charset) {
  char **res;
  int row, i;
  if (s == NULL) return (NULL);

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
