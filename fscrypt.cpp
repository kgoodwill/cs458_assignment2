/*
* Implementation of the Electronic Codebook Mode (ECB)
*/

#include "fscrypt.h"

int getNumBlocks(int bytes);
int getPadding(int bytes);
//BLOCKSIZE = 8
void *fs_encrypt(void *plaintext, int bufsize, char *keystr, int *resultlen){
	//void BF_set_key(BF_KEY *key, int len, const unsigned char* data);
	//Generate the input key
	//Break up the input into blocks
	char* ptext = (char *)plaintext;

	//string text = (string) (const)ptext;
	//cout << "converted to string: " << text << endl;
	
 	int numBytes = (sizeof(char) * strlen(ptext)) + 1;
	cout << "Number of bytes: " << numBytes << endl;
	
 	int padding = getPadding(numBytes);
 	cout << "Padding: " << padding << endl;
  
 	int numBlocks = getNumBlocks(numBytes);
	cout << "numBlocks: " << numBlocks << endl;
	
  	vector<unsigned char *> *blocks = new vector<unsigned char *>();
	for(int i = 0; i < numBlocks; i++){
		//Substring the first 8 chars
		//Add to the vector
		int startValue = i * sizeof(char) * BLOCKSIZE;
		for(int j = 0; j < BLOCKSIZE; j++){
			printf("%c\n", ptext[startValue + j]);
			if(ptext[startValue + j] == '\0'){
				//cout << "Found It" << endl;
				//Do the padding stuff
				for(int k = 0; k <= padding; k++){
					ptext[startValue + j + k] = (char)(((int)'0') + padding);
					//printf("%c\n", ptext[startValue + j + k]);
				}
			}
		}
		
		//cout << startValue << endl;
    	unsigned char* tmp = (unsigned char*)malloc(BLOCKSIZE);
    	strncpy((char*)tmp, ptext + startValue, BLOCKSIZE);
    	cout << tmp << endl;
    	blocks->push_back(tmp);
	}
	printf("%s %s\n", blocks->at(0), blocks->at(1));
}

void *fs_decrypt(void *ciphertext, int bufsize, char *keystr, int *resultlen){

}

int getNumBlocks(int bytes){
  	int blocks = bytes / BLOCKSIZE;
  	if(bytes % BLOCKSIZE != 0){
    	blocks++;
  	}
  	return blocks;
}

int getPadding(int bytes){
  	int padding = 0;
  	if(bytes % BLOCKSIZE != 0){
    	padding = bytes % BLOCKSIZE;
  	}
  	return padding;
}
