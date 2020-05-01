#include <stdio.h> 		 
#include <string.h>		 
#include <stdlib.h>

#include "functions.h"


void clearBuffer(){
    char c; 
    while ( (c = getchar()) != '\n' && c != EOF ) { }

}

int main(int argc, char *argv[])
{
    char action;

	char key[5];
    char vect[5];
    char text[100];

    char keyCopy[5];
    char vectCopy[5];

    printf("Insert action: ");
    scanf("%c", &action);
    clearBuffer();

    printf("Insert key: ");
    fgets(key, 5, stdin);
    clearBuffer();


    printf("Insert vector: ");
    fgets(vect, 5, stdin);
    clearBuffer();

    printf("Insert text: ");
    fgets(text, 100, stdin);
    
    if(action == 'e'){
        printf("encryption:\n");
         strcpy(keyCopy, key);
        strcpy(vectCopy, vect);

        encrypt(key, vect, text);
    

        printf("text:%s\n",text );
        

        
    }else if(action == 'd'){
        printf("decryption:\n");
        
        decrypt(key, vect, text);

        printf("text:%s\n",text );
    }
    /*
    strcpy(keyCopy, key);
    strcpy(vectCopy, vect);

    encrypt(key, vect, text);
    

    printf("ext:%s\n",text );

    decrypt(keyCopy, vectCopy, text);

    printf("text:%s\n",text );
    */
	
	return 0;
}
