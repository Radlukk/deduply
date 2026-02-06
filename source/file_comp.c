#include <var.h>
#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>
// src = file to compare
// base = file the src copares to
void file_comp(char *src, char *base, unsigned char *hash_base){

  size_t i;
  unsigned char buff[BUF_SIZE];
  unsigned long szsrc, szbase;
  FILE *fb;

  if(!strcmp(src, base)){
    return NULL;
  }

  if(!(fb = fopen(base, "r"))){
    printf("Could not open %s", base);
    return NULL;
  }

  fseek(fb, 0L, SEEK_END);
  szbase = ftell(fb);
  fclose(fb);

  if(!(fb = fopen(src, "r"))){
    printf("Could not open %s", src);
    return NULL;
  }

  fseek(fb, 0L, SEEK_END);
  szsrc = ftell(fb);
  fclose(fb);

  if(szbase != szsrc){
    return NULL;
  }

  if(!(fb = fopen(base, "rb"))){
    // something ERROR
    return NULL;
  }

  SHA256_CTX sha256;
  SHA256_Init(&sha256);
  i = 0;
  while((i = fread(buff, 1, sizeof(buff), fb)) > 0){
    //digesting the hash step by step
    SHA256_Update(&sha256, buff, i);
  }
  SHA256_Final(hash_base, &sha256);
}
