#include <stdio.h>
#include <stdlib.h>

#define MAX_LIST_SIZE 100

typedef int element;
typedef struct {
	element list[MAX_LIST_SIZE];
	int length;
} ArrayListType;

void clear(ArrayListType* l) {
	l->length = 0;
}

void replace(ArrayListType* l, int pos, element item) {
	l->list[pos] = item;
}
	
element get_entry(ArrayListType* l, int pos) {
	return l->list[pos];
}

int get_length(ArrayListType* l) {
	return l->length;
}
