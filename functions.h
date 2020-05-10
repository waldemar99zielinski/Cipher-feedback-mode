#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void encrypt(char* key, char* vector, char* plainText);
void encryptv2(char* key, char* vector, char* plainText,  int  lenght);
void decrypt(char* key, char* vector, char* cipherText);
void decryptv2(char* key, char* vector, char* plainText,  int  lenght);

#endif 