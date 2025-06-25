#include "var.h"
#include <string.h>

int scan_dir(char *path_to_scan, file_list * h){

  struct dirent *de;
  DIR *dir;

  if((dir = opendir(path_to_scan)) == NULL){
    printf("Could not open %s", path_to_scan);
    return -1;
  }

  while((de = readdir(dir)) != NULL){
     // if *de point to a regular file
    if(de->d_type == DT_REG){
      // update data structure
      // more condition to value
      h = append_file(h, de->d_name);
    }
    // if *de point to another directory
    else if(de->d_type == DT_DIR){
      make_path(path_to_scan, de->d_name);
      scan_dir(path_to_scan, h);
      unmake_path(path_to_scan);
    }
  }
}

void make_path(char *dir, char *sub_dir){

  unsigned short i, j, dim1, dim2;

  dim1 = strlen(dir);
  dim1 = strlen(dir);

  // if there is enought space
  if((MAX_PATH_LENGTH-dim1i) > (dim2+1)){
    i = 0;
    j = 0;
    while(*(dir+i) != '\0'){
      i++;
    }
    *(dir+i) = '/';
    i++;
    // copy in the subdirectory
    while(*(sub_dir+j) != '\0'){
      *(dir+i) = *(sub_dir+j);
      i++;
      j++;
    }
    *(dir+i) = '\0';
  }
  else
    printf("buffer finished!\n");
}

// go back to the previous dir
void unmake_path(char *dir){

  int i;
  i = 0;

  while(*(dir+i) != '\0')
    i++;

  while(*(dir+i) != '/'){
    *(dir+i) = '0';
    i--;
  }
  *(dir+i) = '\0';
}
