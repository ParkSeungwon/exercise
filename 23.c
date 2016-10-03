#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct List {
	int exp, coef;
	struct List* node;
} List;

List* add(List* l, int coef, int exp) {
	if(l == NULL || exp > l->exp) {
		List* new = (List*)malloc(sizeof(List));
		new->coef = coef;
		new->exp = exp;
		new->node = l;
		return new;
	} else if(exp == l->exp) l->coef += coef;
	else l->node = add(l->node, coef, exp);
	return l;
}

void display(List* l) {
	while(l != NULL) {
		if(l->coef) printf("%c%dx^%d", l->coef<0 ? ' ' : '+', l->coef, l->exp);
		l = l->node;
	}
}
	
List* poly_add(List* A, List* B) {
	List* C = NULL;
	while(A != NULL) {
		C = add(C, A->coef, A->exp);
		A = A->node;
	}
	while(B != NULL) {
		C = add(C, B->coef, B->exp);
		B = B->node;
	}
	return C;
}

List* poly_sub(List* A, List* B) {
	List* C = NULL;
	while(A != NULL) {
		C = add(C, A->coef, A->exp);
		A = A->node;
	}
	while(B != NULL) {
		C = add(C, -B->coef, B->exp);
		B = B->node;
	}
	return C;
}

float poly_eval(List* A, float n) {
	if(A == NULL) return 0;
	return pow(n, A->exp) * A->coef + poly_eval(A->node, n);
}

int main() {
	List* A = NULL;
	A = add(A, 2, 6);
	A = add(A, 7, 3);
	A = add(A, -2, 2);
	A = add(A, -9, 0);
	printf("\nA : ");
	display(A);

	printf("\nB : ");
	List* B = NULL;
	B = add(B, -2, 6);
	B = add(B, -4, 4);
	B = add(B, 6, 2);
	B = add(B, 6, 1);
	B = add(B, 1, 0);
	display(B);

	printf("\nA+B : ");
	List* C = poly_add(A, B);
	display(C);

	printf("\n3을 대입한 값은 %f", poly_eval(C, 3));
	List* D = poly_sub(A, B);
	printf("\nA-B : ");
	display(D);
}


