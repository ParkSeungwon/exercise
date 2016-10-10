#include <stdio.h>
#include <stdlib.h>
typedef int element;
typedef struct Matrix {
	int x, y;
	element v;
	struct Matrix* node;
} Matrix;

Matrix* create(int row, int column) {
	Matrix* r = (Matrix*)malloc(sizeof(Matrix));
	r->x = row;
	r->y = column;
	r->node = NULL;
	return r;
}

Matrix* insert(Matrix* p, int row, int column, element value) {
	if (!p) {
		p = (Matrix*)malloc(sizeof(Matrix));
		p->x = row;
		p->y = column;
		p->v = value;
		p->node = NULL;
	} else p->node = insert(p->node, row, column, value);
	return p;
}

element get_value(Matrix* p, int x, int y) {
	for (p = p->node; p; p = p->node) if (p->x == x && p->y == y) return p->v;
	return 0;
}

void print(Matrix* p) {
	int width = p->x;
	int height = p->y;

	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) printf("%d ", get_value(p, x, y));
		printf("\n");
	}
}
void read(Matrix* p) {
	int x, y, v;
	printf("x, ,y, v ");
	scanf("%d%d%d", &x, &y, &v);
	insert(p, x, y, v);
}

int main()
{
	Matrix *m = create(12, 15);
	read(m);
	insert(m, 4, 7, 3);
	insert(m, 4, 8, 9);
	print(m);
	return 0;
}

