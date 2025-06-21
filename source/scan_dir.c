
int scan_dir(char *path_to_scan, /*data structure*/ ){

  struct dirent *de;
  DIR *dir;

  if((dir = opendir(path_to_scan)) == NULL){
    printf("Could not open %s", path_to_scan);
    return 0;
  }

  while((de = readdir(dir)) != NULL){
     // if *de point to a regular file
    if(de->d_type == DT_REG){
      // update data structure
    }
    // if *de point to another directory
    else if(de->d_type == DT_DIR){
      // make a function that merge the name of the new dir whit the old one
      scan_dir(//...);
    }
  }
}
