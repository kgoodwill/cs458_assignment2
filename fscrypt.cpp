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
	const char* ptext = (const char *)plaintext;

	string text = (string) ptext;
	cout << "converted to string: " << text << endl;
	
  int numBytes = sizeof(char) * text.size();
	cout << "Number of bytes: " << numBytes << endl;
	
  int padding = getPadding(numBytes);
  cout << "Padding: " << padding << endl;
  
  int numBlocks = getNumBlocks(numBytes);
  cout << "numBlocks: " << numBlocks << endl;
	
  vector<char *> *blocks = new vector<char *>();
	for(int i = 0; i < numBlocks; i++){
		//Substring the first 8 chars
		//Add to the vector
    unsigned char* tmp = (unsigned char*)malloc(BLOCKSIZE);
    strncpy((char*)tmp, ptext, BLOCKSIZE);
    cout << tmp << endl;
	}
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
