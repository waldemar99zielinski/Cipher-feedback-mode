#include <stdio.h> 		 
#include <string.h>		 
#include <stdlib.h>

#include "functions.h"


void clearBuffer(){
    char c; 
    while ( (c = getchar()) != '\n' && c != EOF ) { }

}
int incorectInput(char* key){
    if(strlen(key)==4 ) return 0;
    return 1;
}

int main(int argc, char *argv[])
{
    FILE *file;
    char action;

	char key[5];
    char vect[5];
    char text[100] = "";

    char keyCopy[5];
    char vectCopy[5];
    char textCopy[101];

    printf("Insert action: ");
    scanf("%c", &action);
    clearBuffer();

    printf("Insert key: ");
    fgets(key, 5, stdin);
    clearBuffer();
    
    if(incorectInput(key)){
            printf("Incorrect input\n");
            return 1;
        }

    printf("Insert vector: ");
    fgets(vect, 5, stdin);
    clearBuffer();

    if(incorectInput(vect)){
            printf("Incorrect input\n");
            return 1;
        }

    printf("Insert text: ");
    fgets(text, 101, stdin);
    
    if(action == 'e'){
        
        strcpy(keyCopy, key);
        strcpy(vectCopy, vect);
        strcpy(textCopy, text);
        //printf("encrypted: %d\n",strlen());
        int lenght = strlen(text);
        
        
        encryptv2(key, vect, text, lenght);
        

        printf("encryptedv2: %s, %lu, %lu\n",text , strlen(text), strlen(textCopy));

        lenght = strlen(text);
        
        decryptv2(keyCopy, vectCopy, text, lenght);
        //decrypt(keyCopy, vectCopy, text);
        printf("decrypted: %s\n",text );
        
    }else if(action == 'd'){
        
        int lenght = strlen(text);

        decryptv2(key, vect, text, lenght);

        printf("text:%s, %d\n",text, lenght );
    }
    
	
	return 0;
}
