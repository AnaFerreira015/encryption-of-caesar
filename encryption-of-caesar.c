#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 256

char *encryption(char *msg, int key) {
	int size = strlen(msg), i;
	for (i = 0; i < size; i++) {
		msg[i] += key;
	}
	return msg;
}

char *decryption(char *msg, int key) {
	int size = strlen(msg), i;
	for (i = 0; i < size; i++) {
		msg[i] -= key;
	}
	return msg;
}

int main () {
	int key, size, i;
	char msg[MAX_SIZE], *msg_cript, *msg_decript;
	
	printf("Enter the key: \n");
	scanf("%d", &key);
	
	printf("Enter the message: \n");
	scanf("%[A-Z a-z,.]", msg);
	
	msg_cript = encryption(msg, key);
	
	printf("\nCRYPTOGRAPHY MESSAGE: %s\n", msg_cript);
	
	msg_decript = decryption(msg_cript, key);
	
	printf("\nMESSAGE DESCRIPTIONGRAPH: %s\n", msg_decript);
	
	return 0;
}