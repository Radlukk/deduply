#include <var.h>
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

int check_dir(char *dir_path){

  struct stat st;
  int res;
  res = -1;

  printf("checking %s\n", dir_path);

  if(stat(dir_path, &st) == -1){
    perror("stat\n");
    return res;
  }

  // checking if the path lead to a dir
  if(S_ISDIR(st.st_mode)){
    res = 0;
    return res;
  }

  if(S_ISREG(st.st_mode)){
    res = 1;
    return res;
  }

  return res;
}
