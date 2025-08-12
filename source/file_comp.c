#include "var.h"

#define BUF_SIZE (64 * 1024) // 64KB

// src = file to compare
// base = file the src copares to
int file_comp(char *src, char *base){

  sixe_t i;
  unsigned char buff[BUF_SIZE], hash_base[32];
  unsigned long szsrc, szbase;
  FILE fb;
  // need more variables

  if(!(fb = fopen(base, "r"))){
    printf("Could not open %s", base);
    return -1;
  }

  fseek(fb, 0L, SEEK_END);
  szbase = ftell(fb);
  // fclose(fb);

  if(szbase != szscr){
    return 0; // the two file have different sizes
  }

  if(!(fb = fopen(base, "rb"))){ 
    // something ERROR
    return 0;
  }

  SHA256_CTX sha256;
  i = 0;
  while((i = fread(buff, 1, sizeof(buff), fb)) > 0){
    //digesting the hash step by step
    SHA256_Update(&sha256, buff, i);
  }
  SHA256_Final(hash_base, &sha256);
}
