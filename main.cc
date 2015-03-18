//CBC Mode
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "fscrypt.h"

int main()
{
  char s[] = "hello world";
  char *outbuf, *recvbuf;
  char pass[] = "top secret";
  int len = 0;
  int recvlen = 0;

  outbuf = (char *) fs_encrypt((void *) s, strlen(s)+1, pass, &len);
  printf("%s %d\n", "length after encryption = ", len);

  int i = 0;
  printf("ciphertext = ");
  for (i = 0; i < len; i++)
      printf("%02x", outbuf[i]);
  printf("\n");

  recvbuf  = (char *) fs_decrypt((void *) outbuf, len, pass, &recvlen);
  assert(memcmp(s, recvbuf, recvlen) == 0);
  assert(recvlen == (strlen(s) + 1));
  printf("plaintext = %s\n", recvbuf);
}

void *fs_encrypt(void *plaintext, int bufsize, char *keystr, int *resultlen){
  //Ci+1 = E(Ci ^ Pi+1, K)
  //Break the plaintext into blocks of size BLOCKSIZE
  char[] text = new [bufsize]; //Holds the plaintext
  char *ptext = (char *)plaintext;
  int numBlocks = (bufsize / BLOCKSIZE) % 8;
  for(int i = 0; i < numBlocks; i++){
    //Iterate through text and break into blocks to use in some other 2d array
  }
  //Set up the key, don't know length
  //void BF_cbc_encrypt(const unsigned char *in, unsigned char *out, long length, BF_KEY *schedule, unsigned char *ivec, int enc);
}

void *fs_decrypt(void *plaintext, int bufsize, char *keystr, int *resultlen){
  //Opposite of Encryption
  //Break the ciphertext into blocks of size BLOCKSIZE
  //Set up the key
}