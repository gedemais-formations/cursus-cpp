#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

//Function declaration
void addition(char str[], int pos);
void substraction(char str[], int pos);
void multiplication(char str[], int pos);
void division(char str[], int pos);
void previous_word(char *s, char str[], int pos);
void next_word(char *s, char str[], int pos);
void revstr(char *str1);

int main(int argc, char **argv)
{
	int i = 1;
	char *concat;

	while(i < argc){
		strcat(concat, argv[i]);
		i++;
	}
	
	int size = strlen(concat);
	i = 0;
	while(i < size - 1){
		if(concat[i] == '\0'){
			break;
		}
		switch(concat[i]){
			case '+':
				addition(concat, i);
				break;
			case '-':
				substraction(concat, i);
				break;
			case '*':
				multiplication(concat, i);
				break;
			case '/':
				division(concat, i);
				break;
		}

		size = strlen(concat);
		i++;
	}
	printf("%s\n", concat);
	return 0;
}

void addition (char str[], int pos){
	char num1[30]={}, num2[30]={};

	previous_word(num1, str, pos);
	pos = pos - strlen(num1);
	next_word(num2, str, pos);
	memmove(str, str+1, strlen(str));
	
	float num_p = atof(num1);
	float num_n = atof(num2);

	float res_f = num_p + num_n;
	char str_res[30];
	sprintf(str_res, "%f", res_f);

	strcpy(str, strcat(str_res, str));	
}

void substraction(char str[], int pos){
	char num1[30]={}, num2[30]={};

	previous_word(num1, str, pos);
	pos = pos - strlen(num1);
	next_word(num2, str, pos);
	memmove(str, str+1, strlen(str));
	
	float num_p = atof(num1);
	float num_n = atof(num2);

	float res_f = num_p - num_n;
	char str_res[30];
	sprintf(str_res, "%f", res_f);

	strcpy(str, strcat(str_res, str));		
}

void multiplication(char str[], int pos){
	char num1[30]={}, num2[30]={};

	previous_word(num1, str, pos);
	pos = pos - strlen(num1);
	next_word(num2, str, pos);
	memmove(str, str+1, strlen(str));
	
	float num_p = atof(num1);
	float num_n = atof(num2);

	float res_f = num_p * num_n;
	char str_res[30];
	sprintf(str_res, "%f", res_f);

	strcpy(str, strcat(str_res, str));	
}

void division(char str[], int pos){
	char num1[30]={}, num2[30]={};

	previous_word(num1, str, pos);
	pos = pos - strlen(num1);
	next_word(num2, str, pos);
	memmove(str, str+1, strlen(str));
	
	float num_p = atof(num1);
	float num_n = atof(num2);

	float res_f = num_p / num_n;
	char str_res[30];
	sprintf(str_res, "%f", res_f);

	strcpy(str, strcat(str_res, str));	
}

void previous_word(char *word, char str[], int pos){
	int i,j;

	j=0;
	i=pos - 1;
	
	while(i >= 0){
		if((str[i] <= '9' && str[i] >= '0') || str[i] == '.'){
			word[j] = str[i];
			memmove(&str[i], &str[i+1], strlen(str) - i);
			j++;
			i--;
		}else {
			word[j] = '\0';			
			break;
		}	
	}
	if(strlen(word) > 2){
		revstr(word);
	}
}

void next_word(char *word, char str[], int pos){
	int i,j;

	j=0;
	i=pos + 1;

	while(i <= strlen(str) - 1){
		if((str[i] <= '9' && str[i] >= '0') || str[i] == '.'){
			word[j] = str[i];
			memmove(&str[i], &str[i+1], strlen(str) - i);
			j++;			
		}else {
			word[j] = '\0';	
			break;
		}	
	}
}

// function definition of the revstr()  
void revstr(char *str1)  
{  
    int i, len, temp;  
    len = strlen(str1); 
      
   
    for (i = 0; i < len/2; i++)  
    {  
        temp = str1[i];  
        str1[i] = str1[len - i - 1];  
        str1[len - i - 1] = temp;  
    }  
}  
