#include <stdio.h>
#include <string.h>

int main()
{
  char str[] = "Ceci est bien une phrase de test avec des mots difféents";
//  int len = strlen(str);
  char d[] = "romain";

  char *p = strtok(str, d);

  while(p != NULL)
  {
    printf("'%s'\n", p);
    p = strtok(NULL, d);
  }
  printf("\n");
  return 0;
}
