#include <stdio.h>
typedef int element;

typedef struct SortedList {
	element data;
	struct SortedList *head, *tail;
} SortedList;

SortedList* add(SortedList* L, element n) {
	if(L == NULL || L->data > n) {
		SortedList* new = (SortedList*)malloc(sizeof(SortedList));
		new->data = n;
		new->head = L == NULL ? NULL : L->head;
		new->tail = L;
		return new;
	} else {
		L->tail = add(L->tail, n);
		return L;
	}
}

void display(SortedList* L) {
	if(L == NULL) return;
	printf("%d ", L->data);
	display(L->tail);
}

int is_in(SortedList* L, element n) {
	if(L == NULL) return 0;
	if(L->data == n) return 1;
	else return is_in(L->tail, n);
}

SortedList* clear(SortedList* L) {
	if(L != NULL) {
		clear(L->tail);
		free(L);
	}
	return NULL;
}

int get_length(SortedList* L) {
	if(L == NULL) return 0;
	return get_length(L->tail) + 1;
}

int main()
{
	SortedList* list = NULL;
	list = add(list, 3);
	list = add(list, 1);
	list = add(list, 7);
	list = add(list, 2);
	display(list);
	if(is_in(list, 7)) printf("\n7은 리스트에 있습니다.\n");
	printf("길이는 %d\n", get_length(list));
	list = clear(list);
	display(list);
}
