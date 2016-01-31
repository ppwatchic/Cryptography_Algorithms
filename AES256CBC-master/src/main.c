#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//#include <windows.h>
//#include <stdbool.h>

#include "Base64.h"
#include "AES256CBC.h"

//To compile the following code you have to link OpenSSL libeay32.lib with your project.

int main(void){
	const unsigned char *password = "TESTING_PASS_TESTING_PASS_TESTING_PASS_TESTING_PASS\0";
	unsigned char aesSalt[PKCS5_SALT_LEN + 1] = { 0 };
	unsigned char aesKey[AES_KEY_LEN + 1] = { 0 };
	unsigned char aesIV[EVP_MAX_IV_LENGTH + 1] = { 0 };

	const char plain[] = "PLAIN_TEXT_PLAIN_TEXT_PLAIN_TEXT\0";
	int cipherTextLength = 0;
	char *ciphertext = { 0 };
	char *decryptedtext = { 0 };

	if (GenerateKeys(password, strlen(password) + 1, aesSalt, aesKey, aesIV)){
		cipherTextLength = Encrypt(&ciphertext, plain, strlen(plain) + 1, aesKey, aesIV);
		if (cipherTextLength > 0){
			printf("Encrypted text: %s\n\n", ciphertext);

			if (Decrypt(&decryptedtext, ciphertext, cipherTextLength, aesKey, aesIV) > 0){
				printf("Decrypted text: %s\n\n", decryptedtext);

				if (decryptedtext){
					// HeapFree(GetProcessHeap(), 0, decryptedtext);
					free(decryptedtext);
					decryptedtext = NULL;
				}
			}

			if (ciphertext){
				//HeapFree(GetProcessHeap(), 0, ciphertext);
				free(decryptedtext);
				ciphertext = NULL;
			}
		}
	}

	return EXIT_SUCCESS;
}
