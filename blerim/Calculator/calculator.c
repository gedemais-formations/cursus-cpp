//Version1
/*#include<stdio.h>



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
*/

//Using command switch 

#include <stdio.h>  
#include <math.h>  
#include <stdlib.h>  
      
// function declarations   
int addition();  
int subtraction();  
int multiplication();  
int division();  
int sq();  
int squareroot();
int module();  
void exit();  
  
int main(int argc, char **argv)  
{  
    int opt;  
    do  
    {  
        printf (" Select operation by selecting number: ");  
        printf (" \n 1 Addition  \t \t 2 Subtraction \n 3 Multiplication \t 4 Division \n 5 Square \t \t  6 Square Root \t \t\n 7 Module \t \t 8 Exit \n");      
          
        scanf ("%d", &opt);

    // use switch to choose 
    switch (opt)  
    {  
        case 1:  
            addition(); //addition function  
            break;  
              
        case 2:  
            subtraction(); //subtraction  
            break;  
              
        case 3:  
            multiplication(); //multiplication  
            break; 
              
        case 4:  
            division(); // diviion
            break;  
              
        case 5:  
            sq(); // square 
            break; 
              
        case 6:  
            squareroot(); // square root  
            break;
	case 7:
	    module(); //module
	    break;  
              
        case 8:  
            exit(0); // exit program 
            break; 
              
        default:  
            printf(" Please try again!! ");  
            break;                        
    }  
    printf (" \n \n --------------------- \n ");  
    } while (opt != 8);  
      
    return 0;        
}  
  
// addition 
int addition()  
{  
    int num1, num2, result;  
    printf (" The first number is: ");  
    scanf ("  %d", &num1);  
    printf (" The second number is: ");  
    scanf ("  %d", &num2);  
    result = num1 + num2;    
    printf (" The addition of %d + %d is: %d", num1, num2, result);  
}  
  
// subtraction()
int subtraction()  
{  
    int num1, num2, result;  
    printf (" The first number is: ");  
    scanf ("  %d", &num1);  
    printf (" The second number is: ");  
    scanf ("  %d", &num2);  
    result = num1 - num2;    
    printf (" The subtraction of %d - %d is: %d", num1, num2, result);  
}  
  
// multiplication() 
int multiplication()  
{  
    
    int num1, num2, result;  
    printf (" The first number is: ");  
    scanf ("  %d", &num1);  
    printf (" The second number is: ");  
    scanf ("  %d", &num2);  
    result = num1 * num2;    
    printf (" The multiply of %d * %d is: %d", num1, num2, result);  
}  
  
// division()  
int division()  
{  
    int num1, num2, result;  
    printf (" The first number is: ");  
    scanf ("  %d", &num1);  
    printf (" The second number is: ");  
    scanf ("  %d", &num2);  
      
    if (num2 == 0)  
    {  
        printf (" \n You cannot divide by zero. Please enter another value ");  
        scanf ("%d", &num2);        
    }  
    result = num1 / num2;    
    printf (" \n The division of %d / %d is: %d", num1, num2, result);  
}  
  
// sq()   
int sq()  
{  
    int num1, result;  
    printf (" Enter a number to get the Square: ");  
    scanf ("  %d", &num1);  
      
    result = num1 * num1;    
    printf (" \n The Square of %d is: %d", num1, result);  
}  
  
 //squareroot
int squareroot()  
{  
    float result;  
    int num1;  
    printf (" Enter a number to get the Square Root: ");  
    scanf ("  %d", &num1);  
  
    result = sqrt(num1);   
    printf (" \n The Square Root of %d is: %f", num1, result);  
} 

//Module.

int module()
{
long long num1,num2, result;
printf("Enter number1:");
scanf("%lld", &num1);
printf("Enter number2:");
scanf("%lld", &num2);

result =num1 % num2;
printf("Module of %d and %d:",num1,num2,result);

}
