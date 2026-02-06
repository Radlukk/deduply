#include <var.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include <append_file.h>

void unmake_path(char *);
void make_path(char *, char *);

int scan_dir(char *path_to_scan, file_list * h){

  struct dirent *de;
  DIR *dir;

  if((dir = opendir(path_to_scan)) == NULL){
    // printf("Could not open %s", path_to_scan);
    perror("Error");
    exit(EXIT_FAILURE);
  }

  while((de = readdir(dir)) != NULL){
     // if *de point to a regular file
    if(de->d_type == DT_REG){
      // update data structure
      make_path(path_to_scan, de->d_name);
      h = append_file(h, path_to_scan);
      unmake_path(path_to_scan);
    }
    // if *de point to another directory
    else if(de->d_type == DT_DIR){
      make_path(path_to_scan, de->d_name);
      scan_dir(path_to_scan, h);
      unmake_path(path_to_scan);
    }
  }

  return 0;
}

void make_path(char *dir, char *sub_dir){

  unsigned short i, j, dim1, dim2;

  dim1 = strlen(dir);
  dim2 = strlen(sub_dir);

  // if there is enought space
  if((MAX_PATH_LENGTH-dim1) > (dim2+1)){
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

#include "append_file.c"
