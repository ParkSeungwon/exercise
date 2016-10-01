#include<stdio.h>
#include<time.h>
#include<stdlib.h>
typedef int element;
typedef struct List {
	element data;
	struct List* p;
} List;


List* setup(int n) {
	if(n == 0) return NULL;
	List* p = (List*)malloc(sizeof(List));
	p->data = rand() % 5;
	p->p = setup(n-1);
	return p;
}

void show(List* p) {
	if(p != NULL) {
		printf("%d ", p->data);
		show(p->p);
	}
}

void free_mem(List* p) {
	if(p == NULL) return;
	free_mem(p->p);
	free(p);
}
