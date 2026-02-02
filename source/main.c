#include <var.h> // where to find variables and constants
#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>
#include <stdlib.h>

#include "append_file.h"
#include "check_dirpath.h"
#include "file_comp.h"
#include "get_src_files.h"
#include "scan_dir.h"

int main(int argc, char * argv[]){

  if(argc < 3){
    printf("arguments missing!\ninput: deduply --help for more information\n"); // to write deduply --help
    return 0;
  }

  // to be modified when I add more options
  if(argc-2 > MAX_FILES){
    printf("too many arguments: max 10 files can be input\n");
    return 0;
  }

  int i, fnum;
  char *dir_path;
  char *new_dir_path;
  size_t size = MAX_PATH_LENGTH;
 
  do{
    new_dir_path = realloc(dir_path, size);
    if(new_dir_path == NULL){
      perror("Problem with 'char *dir_path'");
      return 0;
    }
    dir_path = new_dir_path;
    size += MAX_PATH_LENGTH;
  }
  while(strcpy(dir_path, argv[argc-1]));

  file_list *fls = NULL;
  unsigned char *hashs[MAX_FILES], tmp_hash[32]; // the program can take max 10 files to compare

  // given for granted that the only arguments are the files and the dir
  fnum = argc - 2;
  get_src_files(argv, hashs, fnum);

  if(check_dir(dir_path) || scan_dir(dir_path, fls)){
    perror("Error with the given path");
    return 0;
  }

  for(i = 0; i < fnum; i++){
    file_comp(argv[i+1], fls->file_name, tmp_hash);
    if(!(strcmp(tmp_hash, hashs[i]))){
      if(remove(fls->file_name)){
        fprintf(stderr, "ERROR: %s can not be removed\n", fls->file_name);
      }
    }
  } 
  return 0;
}
