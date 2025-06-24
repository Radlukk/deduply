/* #include <stdlib.h>
 * #include <list.h>
 * #include <stdio.h> */

lista_t * append(lista_t *head, int n){

	lista_t *elem, *ptr;
	elem = (lista_t *)malloc(sizeof(lista_t));
	if (elem){
    elem->next = NULL;
	  elem->num = n;
  }
  else{
    printf("errore di allocazione\n");
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
