#include "list.h"
//13.
void remove_node(List *head, List *to_delete) {
	head->p = to_delete->p;
	free(to_delete);
}

//14.
int add(List* p)
{
	return p != NULL ? p->data + add(p->p) : 0;
}

//15.
int count(List* p, int n) {
	return p == NULL ? 0 : (p->data == n) + count(p->p, n);
}

//16~17.
List* del_if(List* p, int(*condition)(int)) {
	if(p != NULL) { 
		if((*condition)(p->data)) {
			List* tmp = p->p;
			free(p);
			return del_if(tmp, condition);
		} else {
			p->p = del_if(p->p, condition);
			return p;
		}
	}
}

//16.
int del_2(int n) {
	return n == 2;
}

//17.
int del_everyother(int n) {
	static int k = 0;
	return k++ % 2 == 0;
}


int main()
{
	srand(time(NULL));
	List* p = setup(20);
	show(p);
	printf("\n2값은 %d개\n", count(p, 2));
	printf("합은 %d\n", add(p));
	p = del_if(p, del_2);
	show(p);
	printf("\n지운 후 2값은 %d개\n", count(p, 2));
	p = del_if(p, del_everyother);
	printf("\n둘 중 하나 지움. : "); show(p);
	remove_node(p, p->p);
	printf("\n2번째 지운 후 :"); show(p);
	free_mem(p);
	
}
