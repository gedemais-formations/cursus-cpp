#include <stdio.h>
#include <string.h>

//Function declaration
char addition(char str[], int pos);
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

	int res;
	int size = sizeof(concat);
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
				break;
			case '*':
				break;
			case '/':
				break;
		}

		i++;
	}
	return 0;
}

char addition (char str[], int pos){
	char num1[30];

	previous_word(num1, str, pos);

	printf("%s\n", num1);
	return 0;
}

void previous_word(char *word, char str[], int pos){
	int i,j;

	j=0;
	i=pos - 1;
	
	while(i >= 0){
		if(str[i] <= '9' || str[i] >= '0' || str[i] == '.'){
			word[j] = str[i];
			j++;
			i--;
		}else {
			word[j] = '\0';			
			break;
		}	
	}
	
	revstr(word);
}

void next_word(char *word, char str[], int pos){
	int i,j;

	j=0;
	i=pos + 1;

	while(i <= strlen(word)-1){
		if(str[i] <= '9' || str[i] >= '0' || str[i] == '.'){
			word[j] = str[i];
			j++;
			i++;
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
