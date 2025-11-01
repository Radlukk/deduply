#include <var.h>
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

int check_dir(char *dir_path){
 
  struct dirent *de;
  DIR *dir;

  if((dir = opendir(dir_path)) == NULL){
    // printf("Could not open %s", dir_path);
    perror("Error in dir evaluation");
    exit(-1);
  }

  // checking if the path lead to a dir
  if((de = readdir(dir) != NULL) && de->d_type == DT_DIR){
    exit(EXIT_SUCCESS);
  }

  return 1;
}
