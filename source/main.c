#include <var.h> // where to find variables and constants
#include <stdio.h>

int main(int argc, char * argv[]){

  if(argc == 1){
    printf("arguments missing!\ninput: deduply --help for more information\n"); // to write deduply --help
    return 0;
  }

  int i;
  char dir_path[MAX_PATH_LENGTH] = argv[argc - 1];
  char *files[MAX_FILES];

  for(i = 0; (i+1) < (argc-2); i++){
    files[i] = argv[i+1];
  }
}
