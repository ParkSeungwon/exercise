#include"list.h"

void remove_node2(List* x) {
	x->data = x->p->data;
	x->p = x->p->p;
	free(x->p);
}

int main() {
	List* p = setup(5);
	printf("p :"); show(p);
	remove_node2(p->p);
	printf("\np :"); show(p);
}
