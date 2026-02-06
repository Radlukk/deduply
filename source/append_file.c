#include <stdio.h>
#include <string.h>
#include <var.h>
#include <stdlib.h>

file_list * append_file(file_list *head, char *file){

	file_list *elem, *ptr;
	elem = (file_list *)malloc(sizeof(file_list));
	if(elem){
    elem->next = NULL;
	  strcpy(elem->file_name, file);
  }
  else{
    perror("Allocation Error");
    return head;
  }
	if(head){
		ptr = head;
		while(ptr->next){
			ptr = ptr->next;
		}
		ptr->next = elem;
	}
	else {
		head = elem;
	}
	return head;
}
