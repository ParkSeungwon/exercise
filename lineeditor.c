#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 200

typedef struct Line {
	char line[MAX];
	struct Line* node;
} Line;

Line* insert_line(Line* l, int pos, char* contents) {
	if(l == NULL) {
		Line* new = (Line*)malloc(sizeof(Line));
		strcpy(new->line, contents);
		new->node = NULL;
		return new;
	} else if(pos == 0) {
		Line* new = (Line*)malloc(sizeof(Line));
		strcpy(new->line, contents);
		new->node = l;
		return new;
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

void display(Line* l, int pos) {
	for(int i=1; l && i<=pos; l=l->node) printf("%d : %s", i++, l->line);
}

void save(Line* l) {
	FILE* f=fopen("sav.txt", "w");
	for(; l; l=l->node) fputs(l->line, f);
	fclose(f);
}

Line* command(Line* l) {
	int c, line;
	char buffer[MAX];
	printf("1.Delete[line], 2.View[line], 3.Insert[line] 4.Save 5.Quit\n");
	printf("입력할 명령은?>>");
	fflush(stdin);
	scanf("%d", &c); scanf("%d", &line);fflush(stdin);
	switch(c) {
		case 1: return delete_line(l, line-1);
		case 2: display(l, line); return l;
		case 3: fgets(buffer, MAX, stdin);
				return insert_line(l, line-1, buffer);
		case 4: save(l); return l;
		case 5: return NULL;
	}
}

int main(int c, char** v) {
	if(c < 2) return 0;
	FILE* f = fopen(v[1], "r");
	char buffer[MAX];
	Line* l = NULL;
	while(fgets(buffer, MAX, f)) l = insert_line(l, 1000, buffer);
	display(l, 100);
	fclose(f);
	while(l=command(l));
}

