#include"list.h"

List* add(List* L, element n) {
	if(L == NULL || L->data > n) {
		List* new = (List*)malloc(sizeof(List));
		new->data = n;
		new->p = L;
		return new;
	} else {
		L->p = add(L->p, n);
		return L;
	}
}

List* merge(List* p1, List* p2) {
	List *p, *head;
	p = head = (List*)malloc(sizeof(List));
	while(p1 != NULL || p2 != NULL) {
		p->p = (List*)malloc(sizeof(List));
		p = p->p;
		if(p2 == NULL) {
			p->data = p1->data;
			p1 = p1->p;
		} else if(p1 == NULL) {
			p->data = p2->data;
			p2 = p2->p;
		} else {
			if(p1->data > p2->data) {
				p->data = p2->data;
				p2 = p2->p;
			} else {
				p->data = p1->data;
				p1 = p1->p;
			}
		}
		p->p = NULL;
	}
	List* tmp = head->p;
	free(head);
	return tmp;
}

int main() {
	List *p = NULL;
	p = add(p, 1);
	p = add(p, 2);
	p = add(p, 5);
	p = add(p, 6);
	p = add(p, 8);
	List* q = NULL;
	q = add(q, 3);
	q = add(q, 4);
	q = add(q, 7);
	q = add(q, 9);
	q = add(q, 11);
	printf("\np : "); show(p);
	printf("\nq : "); show(q);
	List* r = merge(p, q);
	printf("\np,q 번갈아서 합침. : "); show(r); 
	printf("\n");
	free_mem(p);
	free_mem(q);
	free_mem(r);
}
