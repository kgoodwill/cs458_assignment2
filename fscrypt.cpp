/*
* Implementation of the Electronic Codebook Mode (ECB)
*/

#include "fscrypt.h"
//BLOCKSIZE = 8
void *fs_encrypt(void *plaintext, int bufsize, char *keystr, int *resultlen){
	//void BF_set_key(BF_KEY *key, int len, const unsigned char* data);
	//Generate the input key
	//Break up the input into blocks
	const char* ptext = (const char *)plaintext;
	string text = (string) ptext;
	cout << "converted to string: " << text << endl;
	int numBytes = sizeof(char) * text.size();
	cout << "Number of bytes: " << numBytes << endl;
	int padding = numBytes % 8;
	vector<char *> blocks = new vector<char *>();
	for(int i = 0; i < numBytes; i++){
		for(int j = 0; j < 8; j++){
			if(ptext[i] == NULL){
				//Do padding stuff
			}
		}
		//Substring the first 8 chars
		//Add to the vector
		char *tmp;
	}
}

void *fs_decrypt(void *ciphertext, int bufsize, char *keystr, int *resultlen){

}

char *substring(char *string, int position, int length) {
   char *pointer;
   int c;
 
   pointer = malloc(length+1);
 
   if (pointer == NULL)
   {
      printf("Unable to allocate memory.\n");
      exit(1);
   }
 
   for (c = 0 ; c < length ; c++)
   {
      *(pointer+c) = *(string+position-1);      
      string++;   
   }
 
   *(pointer+c) = '\0';
 
   return pointer;
}
