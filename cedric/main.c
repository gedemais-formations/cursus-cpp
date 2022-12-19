#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int calculate(int value1, int value2, char op){
  int result;
  switch (op) {
    case '+':
      result = value1 + value2;
      break;

    case '-':
      result = value1 - value2;
      break;

    case 'x':
      result = value1 * value2;
      break;

    case '/':
      result = value1 / value2;
      break;
  }
  return result;
}

int main(int argc, char *argv[]) {
  double val1, val2, res;
  char *ptr;
  int arg = argc/2;
  char op[arg];
  double val[arg];
  //Check args
  /*for (int i=1; i< argc; i++) {
    printf("arg%d=%s\n", i, argv[i]);
  }*/

  //Check number of args
  if(argc%2==1){
    printf("error : invalid number of arguments\n");
    return(0);
  }

  //Check args
  for(int i=1;i<argc;i++){
	  //Check if even, it's a number, else it's an operator
	  if(i%2==1){
		val[(i-1)/2] = strtod(argv[i], NULL);

	  } else{ //Operator
		//Check if the string has only one char
		if(strlen(argv[i]) == 1){
			//Check if operator is in calculator
			ptr = strchr("+-x/",argv[i][0]); 
			if(ptr == NULL){
				printf("error : invald operator (%s)", argv[i]);
			return 0;
			} else {
				op[i/2] = argv[i][0];
			}
		} else { //Ope with multiple char
			printf("error : invald operator (%s)", argv[i]);
			return 0;
		}
    }
  }
  res = val[0];

	//Check number of arg
	//printf("Argc %d\n", arg);

  //Calculate
  for(int i=1;i<arg;i++){
    res = calculate(res, val[i], op[i]);
  }
  printf("%lf\n", res);

  /* Prediction for bonus 2: transform val and op into a single list, go through
  the list, until you find x or /, do a calculate on the operator and its
  neighbours, and remove the operator and its right neighbour and replace the
  its neighbours, and remove the operator and its right-hand neighbour and
  replace the neighbour by its left neighbour.*/
  return 0;
}
