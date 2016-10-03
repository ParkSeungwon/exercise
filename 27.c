#include <stdio.h>
#define MAX 100
typedef int element;

typedef struct SortedList {
	element data[MAX];
	int length;
} SortedList;

void add(SortedList* L, element n) {
	if(L->length == 0) {
		L->length = 1;
		L->data[0] = n;
	} else {
		int i;
		for(i=0; i<L->length; i++) if(L->data[i] > n) break;
		for(int j=L->length; j>i; j--) L->data[j] = L->data[j-1];
		L->data[i] = n;
		L->length++;
	}
}

void display(SortedList* L) {
	for(int i=0; i<L->length; i++) printf("%d ", L->data[i]);
}

int is_in(SortedList* L, element n) {
	for(int i=0; i<L->length; i++) {
		if(n == L->data[i]) return 1;
		else if(n < L->data[i]) return 0;
	}
	return 0;
}

void clear(SortedList* L) {
	L->length = 0;
}

int get_length(SortedList* L) {
	return L->length;
}

int is_empty(SortedList* L) {
	return L->length == 0;
}

int is_full(SortedList* L) {
	return L->length == MAX;
}

int main()
{
	SortedList list;
	list.length = 0;
	if(is_empty(&list)) printf("리스트는 비어있습니다.\n");
	add(&list, 8);
	add(&list, 3);
	add(&list, 1);
	add(&list, 5);
	add(&list, 6);
	display(&list);
	if(is_in(&list, 3)) printf("\n3은 리스트에 있습니다.\n");
	printf("리스트의 사이즈는 %d\n", get_length(&list));
	clear(&list);
	printf("지운 후 리스트의 데이터 : ");
	display(&list);

}
