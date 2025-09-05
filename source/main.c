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
  if(argc-2 > 10){
    printf("too many arguments: max 10 files can be input\n");
    return 0;
  }

  int i, fnum;
  char dir_path[MAX_PATH_LENGTH+1] = argv[argc - 1]; // I coud add the option to look in the current working dir if nothing given
  file_list *fls = NULL;
  unsigned char *hashs[32]; // the program can take max 10 files to compare
  FILE *fs;

  fnum = argc - 2;
  get_src_files(argv, hashs, fnum);
  scan_dir(dir_path, fls);
 
}
