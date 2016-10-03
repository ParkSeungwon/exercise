#include<stdio.h>
#include<fstream>
#include<string.h>
#include<stdlib.h>
#include<iostream>
#define MAX 200
using namespace std;

typedef struct Line {
	char line[MAX];
	struct Line* node;
} Line;

Line* insert_line(Line* l, int pos, char* contents) {//pos == 0 -> to end
	if(l == NULL) {
		Line* lnew = (Line*)malloc(sizeof(Line));
		strcpy(lnew->line, contents);
		lnew->node = NULL;
		return lnew;
	} else if(pos == 0) {
		Line* lnew = (Line*)malloc(sizeof(Line));
		strcpy(lnew->line, contents);
		lnew->node = l;
		return lnew;
	} else {
		l->node = insert_line(l->node, pos-1, contents);
		return l;
	}
}

Line* delete_line(Line* l, int pos) {
	if(l == NULL) return NULL;
	else if(pos == 0) {
		Line* tmp = l->node;
		free(l);
		return tmp;
	} else {
		l->node = delete_line(l->node, pos - 1);
		return l;
	}
}

Line* display(Line* l, int pos) {
	for(int i=0; i<pos; l = l->node);
	for(int i=pos; l && i<pos+20; l=l->node) {
		for(int j=0; j<MAX; j++) {
			if(l->line[j] == '\n') {
				l->line[j] = '\0';
				break;
			}
		}
		printf("%d : %s\n", i++, l->line);
	}
	return l;
}

Line* save(Line* l) {
	ofstream f("sav.txt");
	for(; l; l = l->node) f << l->line;
}

Line* command(Line* l) {
	char c; int line;
	char buffer[MAX];
	printf("Edit d[line], View v[line], Save s, Insert i[line]\n");
	printf("입력할 명령은?>>");
	cin >> c; cin >> line;
	switch(c) {
		case 'd': return delete_line(l, line);
		case 'v': return display(l, line);
		case 'i': scanf("%s", buffer);
				  return insert_line(l, line, buffer);
		case 's': return save(l);
	}
}

int main(int c, char** v) {
	if(c < 2) return 0;
	FILE* f = fopen(v[1], "r");
	char buffer[MAX];
	Line* l = NULL;
	l = insert_line(l, 0, "thi si it");
	l = insert_line(l, 0, "tjkfhali si it");
	int i = 0;
	while(fgets(buffer, MAX, f)) l = insert_line(l, 1000, buffer);
	display(l, 3);
	scanf("%s", buffer);
	l = insert_line(l, 4, buffer);
	display(l, 12);
}

