#include <var.h> // where to find variables and constants
#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

int main(int argc, char * argv[]){

  if(argc == 1){
    printf("arguments missing!\ninput: deduply --help for more information\n"); // to write deduply --help
    return 0;
  }

  int i;
  char dir_path[MAX_PATH_LENGTH] = argv[argc - 1];
  char *files[MAX_FILES];
  file_list *fls = NULL;
  FILE *fs;

  for(i = 0; (i+1) < (argc-2); i++){
    files[i] = argv[i+1];
  }

  if(!(fs = fopen(src, "r"))){
    printf("Could not open %s", src);
    return -1;
  }

  scan_dir(dir_path, fls);

  // save all the hashs of the file to deduplicate
  for(i = argc; i > 1; i--){
    SHA256_CTX sha256;
    int byte = 0;
    while((byte = fread(buff, 1, sizeof(buff), fb)) > 0){
      //digesting the hash step by step
      SHA256_Update(&sha256, buff, byte);
    }
    // ho bisogno di una struttura dati per salvare gli hash
    SHA256_Final(hash_base, &sha256);
    }
}
