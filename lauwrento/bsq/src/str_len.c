#include <main.h>

size_t str_len(const char* s) {
  unsigned int count = 0;
  if (!s)
    return 0;
  while (*s != '\0') {
    count++;
    s++;
  }
  return count;
}