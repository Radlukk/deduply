#include <var.h>
#include <chack_dirpath.h>

void get_src_files(char *argv[], unsigned char *hashs[], int fnum){

  int i, j;
  char *files[MAX_FILES];
  unsigned char buff[BUF_SIZE];
  FILE *fs;

  for(i = 0; i < fnum; i++){
    files[i] = argv[i+1];
  }

  // save all the hashs of the files to deduplicate

  j = 0;
  for(i = 0; i < fnum; i++){
    int byte;
    byte = 0;
    if(check_dirpath(files[i])){
      printf("%s is a directory not a file\n", files[i]);
    }
    else{
      if((fs = fopen(src, "rb"))){
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        while((byte = fread(buff, 1, sizeof(buff), fs)) > 0){
          //digesting the hash step by step
          SHA256_Update(&sha256, buff, byte);
        }
        SHA256_Final(hashs[j++], &sha256);
      }
      else{
        printf("Could not open the file %s\n", files[i]);
      }
    }
  }
}
