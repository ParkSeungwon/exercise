#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct Tree {
	element data;
	struct Tree *left, *right;
} Tree;

void show(Tree* node) {
	if(!node) return;
	show(node->left);
	printf("%d ", node->data);
	show(node->right);
}

void free_mem(Tree* node) {
	if(!node) return;
	free_mem(node->left);
	free_mem(node->right);
	free(node);
}

Tree* insert(Tree* node, element n) {
	if(!node) {
		node = (Tree*)malloc(sizeof(Tree));
		node->data = n;
		node->left = NULL;
		node->right = NULL;
	} else if(node->data > n) node->left = insert(node->left, n);
	else node->right = insert(node->right, n);
}

Tree* delete(Tree* node) {
	if(node->left && node->right) {
		Tree* prev = p;
		for(Tree* p = node->right; p; p = p->left) prev = p;
		node->data = prev->data;
		pprev->left = prev->right;
		free(prev);
	}
}
				}
int main() {
	Tree* root = insert(root, 8);
	insert(root, 5);
	insert(root, 7);
	insert(root, 4);
	insert(root, 12);
	insert(root, 1);
	insert(root, 9);
	show(root);
	free(root);
}
