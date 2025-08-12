#ifndef VAR_H
#define VAR_H

#define MAX_PATH_LENGTH 1024 // 1024 = 1 kiB
#define MAX_FILES 5

typedef struct file_list_t{

    char file_name[MAX_PATH_LENGTH];
    struct file_list_t *next;

}file_list;

#endif // var.h
