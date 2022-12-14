
#include<stdio.h>



int main(int argc, char **argv )

{
   
//Decalring variable
char operator;

int number1,number2;
float result;

//Enter  the operator and read variables
printf("Chose one of the operator: +, -, *, / :");
scanf("%c", &operator);
printf("Enter the first number:");
scanf("%d",&number1);
printf("Enter the second number:");
scanf("%d",&number2);

	
if (operator=='/') {

	if (number2 == 0) {
	printf("Division cannot be zero.Please enter another value");
	scanf("%d",&number2);	
}
	result = number1 / number2;
        printf("You selected deivision of %d and %d is:%f", number1,number2,result);
}
else if(operator =='*') {

        result = number1 * number2;
        printf("You selected multiplication of %d and %d is:%f",number1,number2,result);
}
else if (operator =='+') 
{       
        result = number1 + number2;
        printf("You selected Addition of %d and %d is:%f",number1,number2,result);
}
else if(operator =='-')
{       
        result = number1 -number2;
        printf("You selected Substraction of %d and %d is:%f",number1,number2,result);
}

else {

        printf("Youd did enter wrong input data");
}



}
