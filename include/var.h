#ifndef VAR_H
#define VAR_H

#define BUF_SIZE (64 * 1024) // 64KB
#define MAX_PATH_LENGTH 1024 // 1024 = 1 kiB
#define MAX_FILES 10

typedef struct file_list_t{

    char file_name[MAX_PATH_LENGTH]; // non va bene devo usare solo un puntatore e trovare una funzione per aquisire la stringa
    struct file_list_t *next;

}file_list;

#endif // var.h
