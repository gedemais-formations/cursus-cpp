#include "main.h"
/*
 * @param c characters to check
 * @param *charset String of all characters to check
 */
bool ft_strchr(char c, char *charset) {
  if (charset == NULL) return (false);
  for (int i = 0; charset[i] != '\0'; i++) {
    if (c == charset[i]) return true;
  }
  return false;
}