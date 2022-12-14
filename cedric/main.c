#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  double val1, val2, res;
  char op;
  //Check args
  for (int i=1; i< argc; i++) {
    printf("arg%d=%s\n", i, argv[i]);
  }

  //Transform args in double
  sscanf(argv[1], "%lf", &val1);
  op = argv[2][0];
  sscanf(argv[3], "%lf", &val2);
  printf("Valeur 1 : %lf\nValeur 2 : %lf\n", val1, val2);
  switch (op) {
    case '+':
      res = val1 + val2;
      break;

    case '-':
      res = val1 - val2;
      break;

    case '*':
      res = val1 * val2;
      break;

    case '/':
      res = val1 / val2;
      break;
  }

  printf("%lf\n", res);
  return 0;
}
