#include"list.h"

List* alternate(List* p1, List* p2) {
	List *p, *head;
	p = head = (List*)malloc(sizeof(List));
	while(p1 != NULL || p2 != NULL) {
		if(p1 != NULL) {
			p->p = (List*)malloc(sizeof(List));
			p = p->p;
			p->data = p1->data;
			p1 = p1->p;
		}
		if(p2 != NULL) {
			p->p = (List*)malloc(sizeof(List));
			p = p->p;
			p->data = p2->data;
			p2 = p2->p;
		}
	}
	List* tmp = head->p;
	free(head);
	return tmp;
}

int main() {
	List *p = setup(10);
	printf("\np : "); show(p);
	List *q = setup(15);
	printf("\nq : "); show(q);
	List* r = alternate(p, q);
	printf("\np,q 번갈아서 합침. : "); show(r); 
	printf("\n");
	free_mem(p);
	free_mem(q);
	free_mem(r);
}
