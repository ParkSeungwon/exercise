//in C language
#include<stdio.h>
#define MAX 100
typedef int element;
typedef int boolean;
typedef struct Set_Struct {
	element array[MAX];
	boolean valid[MAX];
} Set;

void init(Set* A) 
{
	for(int i=0; i<MAX; i++) A->valid[i] = 0;
}

int is_in(Set* A, element n)
{
	for(int i=0; i<MAX; i++) if(n == A->array[i] && A->valid[i]) return 1;
	return 0;
}

void remov(Set* A, element n)
{
	if(is_in(A, n)) 
		for(int i=0; i<MAX; i++) if(n == A->array[i] && A->valid[i]) A->valid[i] = 0;
}

void insert(Set* A, element n)
{
	if(!is_in(A, n)) {
		for(int i=0; i<MAX; i++) {
			if(!A->valid[i]) {
				A->array[i] = n;
				A->valid[i] = 1;
				break;
			}
		}
	}
}

Set union_sets(Set A, Set B)
{
	Set C;
	init(&C);
	for(int i=0; i<MAX; i++) if(A.valid[i]) insert(&C, A.array[i]);
	for(int i=0; i<MAX; i++) if(B.valid[i]) insert(&C, B.array[i]);
	return C;
}

Set inter_sets(Set A, Set B)
{
	Set C;
	init(&C);
	for(int i=0; i<MAX; i++) 
		if(A.valid[i] && is_in(&B, A.array[i])) insert(&C, A.array[i]);
	return C;
}

Set minus_sets(Set A, Set B)
{
	Set C;
	init(&C);
	for(int i=0; i<MAX; i++) if(A.valid[i]) insert(&C, A.array[i]);
	for(int i=0; i<MAX; i++) if(B.valid[i]) remov(&C, B.array[i]);
	return C;
}

void show(Set* A)
{
	printf("{ ");
	for(int i=0; i<MAX; i++) if(A->valid[i]) printf("%d,", A->array[i]);
	printf("\b}");
}

Set and(Set A, Set B)
{
	Set C;
	for(int i=0; i<MAX; i++) C.valid[i] = A.valid[i] && B.valid[i];
	return C;
}

Set or(Set A, Set B)
{
	Set C;
	for(int i=0; i<MAX; i++) C.valid[i] = A.valid[i] || B.valid[i];
	return C;
}

Set not(Set A)
{
	Set C;
	for(int i=0; i<MAX; i++) C.array[i] = A.array[i];
	for(int i=0; i<MAX; i++) C.valid[i] = !A.valid[i];
	return C;
}

Set xor(Set A, Set B)
{
	Set C;
	for(int i=0; i<MAX; i++) C.valid[i] = !(A.valid[i] == B.valid[i]);
	return C;
}

int main()
{
	Set A,B,C;
	init(&A); init(&B); init(&C);
	for(int i=0; i<5; i++) insert(&A, i);
	for(int i=0; i<5; i++) insert(&B, i+2);
	show(&A);
	show(&B);
	C = union_sets(A, B);
	show(&C);
	C = inter_sets(A, B);
	show(&C);
}

	





