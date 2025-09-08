#include <var.h>
#include <string.h>

// src = file to compare
// base = file the src copares to
unsigned char *file_comp(char *src, char *base){

  size_t i;
  unsigned char buff[BUF_SIZE], hash_base[32];
  unsigned long szsrc, szbase;
  FILE fb;

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
  szbase = ftell(fb);
  fclose(fb);

  if(szbase != szscr){
    return NULL;
  }

  if(!(fb = fopen(base, "rb"))){
    // something ERROR
    return NULL;
  }

  SHA256_CTX sha256;
  SHA256_Init(&sha256);
  i = 0;
  hash_base = NULL;
  while((i = fread(buff, 1, sizeof(buff), fb)) > 0){
    //digesting the hash step by step
    SHA256_Update(&sha256, buff, i);
  }
  SHA256_Final(hash_base, &sha256);

  return hash_base;
}
