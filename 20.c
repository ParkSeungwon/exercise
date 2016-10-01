#include"list.h"

List* split(List* from) {
	if(from == NULL) return NULL;
	List* p = (List*)malloc(sizeof(List));
	p->data = from->data;
	p->p = from->p == NULL ? NULL : split(from->p->p);
	return p;
}

int main() {
	List* p = setup(11);
	List* q = split(p);
	List* r = split(p->p);
	printf("p : "); show(p);
	printf("\nq : "); show(q);
	printf("\nr : "); show(r);
}
