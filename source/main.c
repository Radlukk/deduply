#include <var.h> // where to find variables and constants
#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

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
  char dir_path[MAX_PATH_LENGTH] = argv[argc - 1]; // I coud add the option to look in the current working dir if nothing given
  file_list *fls = NULL;
  unsigned char *hashs[MAX_FILES], tmp_hash[32]; // the program can take max 10 files to compare
  FILE *fs;

  fnum = argc - 2;
  get_src_files(argv, hashs, fnum);

  if(check_dir(dir_path) || scan_dir(dir_path, fls)){
    perror("Error with the given path")
    return 0;
  }

  while(fls){
    for(i = 0; i < fnum; i++){
      tmp_hash = file_comp(argv[i+1], fls->file_name);
      if(!(strcmp(tmp_hash, hashs[i]))){
        if(remove(fls->file_name)){
          fprintf(stderr, "ERROR: %s can not be removed\n", fls->file_name)
        }
      }
    }
  }
  return 0;
}
