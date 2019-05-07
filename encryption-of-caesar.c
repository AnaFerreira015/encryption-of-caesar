#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 256

#define ANSI_COLOR_RESET "\033[0;0m"
#define ANSI_COLOR_LIGHT_MAGENTA "\033[1;95m"
#define ANSI_COLOR_GREEN "\033[1;32m"
typedef unsigned char UCHAR;

UCHAR *encryption(UCHAR *msg, int key)
{
	int size = strlen(msg);
	int i = 0, cont = 0;
	char letter;

	for (letter = 'a'; letter <= 'z'; letter++)
	{
		while (i <= size)
		{
			if (msg[i] == letter)
			{
				msg[i] = letter + key;
				i++;
				cont++;
				letter = 'a';
			}
			else if (msg[i] == ' ')
			{
				i++;
				cont++;
				letter = 'a';
			}
			else if (msg[i] == toupper(letter))
			{
				msg[i] = toupper(letter + key);
				i++;
				cont++;
				letter = 'a';
			}
			else
			{
				letter++;
			}
			if (cont == size)
				break;
		}
	}
	return msg;
}

UCHAR *decryption(UCHAR *msg_cript, int key)
{
	int size = strlen(msg_cript);
	int i = 0, cont = 0;
	char letter;

	for (letter = 'a'; letter <= 'z'; letter++)
	{
		while (i <= size)
		{
			if (msg_cript[i] == letter)
			{
				msg_cript[i] = letter - key;
				i++;
				cont++;
				letter = 'a';
			}
			else if (msg_cript[i] == ' ')
			{
				i++;
				cont++;
				letter = 'a';
			}
			else if (msg_cript[i] == toupper(letter))
			{
				msg_cript[i] = toupper(letter - key);
				i++;
				cont++;
				letter = 'a';
			}
			else
			{
				letter++;
			}
			if (cont == size)
				break;
		}
	}
	return msg_cript;
}

int main()
{
	int key, size, i;
	UCHAR msg[MAX_SIZE], aux[MAX_SIZE], *msg_cript, *msg_decript;

	printf("Enter the message: \n");
	gets(msg);

	printf("\nEnter the key: \n");
	scanf("%d", &key);

	msg_cript = encryption(msg, key);

	printf(ANSI_COLOR_GREEN "\n===========================================");
	printf(ANSI_COLOR_RESET);

	printf(ANSI_COLOR_LIGHT_MAGENTA "\nCRYPTOGRAPHY MESSAGE: %s\n", msg_cript);

	msg_decript = decryption(msg_cript, key);

	printf(ANSI_COLOR_LIGHT_MAGENTA "\nMESSAGE DESCRIPTIONGRAPH: %s\n", msg_decript);
	printf(ANSI_COLOR_RESET);

	printf(ANSI_COLOR_GREEN "===========================================\n");
	printf(ANSI_COLOR_RESET);

	return 0;
}
