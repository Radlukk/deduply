#include "var.h"

// src = file to compare
// base = file the src copares to
int file_comp(char *src, char *base){

  unsigned long szsrc, szbase;
  FILE *fp;

  if(!(fp = fopen(src, "r"))){
    printf("Could not open %s", src);
  }

  fseek(fp, 0L, SEEK_END);
  szsrc = ftell(fp);


  if(!(fp = fopen(base, "r"))){
    printf("Could not open %s", base);
  }

  fseek(fp, 0L, SEEK_END);
  szbase = ftell(fp);

  if(szbase != szscr){
    return 0;
  }
}
