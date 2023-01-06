#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

char *decoupe_phrase(int i,int j, char *phrase)
{
	char *phrase_decoupee = NULL;
	if(j<i)
	{
		return "Impossible";
	}
	else
	{
		phrase_decoupee=malloc(sizeof(char)*(j-i-1));
		if(phrase_decoupee == NULL)
		{
			return NULL;
		}
		for (int k = i; k<=j; k++)
		{
			phrase_decoupee[i]=phrase[i];
		}
	}
	return phrase_decoupee;
}

int main ()
{
	int  depart = 3;
	int arrivee = 5;
	char *phrase = "Bonjour à tous !";
	char *phrase_decoupee = decoupe_phrase(depart,arrivee, phrase);
	printf("%s \n", phrase_decoupee);
	free(phrase_decoupee);
	return 0;
}

