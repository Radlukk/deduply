#include "var.h"

int check_dir(char *dir_path){
 
  struct dirent *de;
  DIR *dir;

  if((dir = opendir(dir_path)) == NULL){
    printf("Could not open %s", dir_path);
    return -1;
  }

  // checking if the path lead to a dir
  if((de = readdir(dir) != NULL) && de->d_type == DT_DIR){
    return 1;
  }

  return 0;
}
