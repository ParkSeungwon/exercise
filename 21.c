#include<stdio.h>
#include<stdlib.h>
typedef int element;
typedef struct {
	element *stack;
	int top;
	int max_top; //현재 배열의 크기
} RStackType;

void change_stack_size(RStackType* st, int sz) {
	element* rs = (element*)calloc(sz, sizeof(element));
	for(int i=0; i<st->top; i++) rs[i] = st->stack[i];
	if(st->stack) free(st->stack);
	st->stack = rs;
}

void push(RStackType* st, element n) {
	if(st->top == st->max_top) {
		st->max_top = 2 * st->max_top + 1;
		change_stack_size(st, st->max_top);
	} 
	st->stack[st->top++] = n;
}

void pop(RStackType* st) {
	if(st->top < st->max_top / 4) {
		st->max_top = st->max_top / 2;
		change_stack_size(st, st->max_top);
	}
	st->top--;
}

void show(RStackType* st) {
	for(int i=0; i<st->top; i++) printf("%d ", st->stack[i]);
	printf("\n");
}

int main() {
	RStackType rs = {NULL, 0,0};
	for(int i=0; i<100; i++) push(&rs, i);
	show(&rs);
	for(int i=0; i<90; i++) pop(&rs);
	show(&rs);
}
