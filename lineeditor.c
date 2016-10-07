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
	char c, d; 
	int line;
	char buffer[MAX];
	printf("Delete[line], View[line], Insert[line] Save Quit\n");
	printf("입력할 명령은?>>");
	scanf("%c%d", &c, &line); 
	scanf("%c", &d);//for trailing new line of scanf bug
	switch(c) {
		case 'd': return delete_line(l, line-1);
		case 'v': display(l, line); return l;
		case 'i': printf("입력할 문자열은? ");
				  fgets(buffer, MAX, stdin);
				  return insert_line(l, line-1, buffer);
		case 's': save(l); return l;
		case 'q': return NULL;
		default : return l;
	}
}

int main(int c, char** v) {
	if(c < 2) v[1] = "sav.txt";
	FILE* f = fopen(v[1], "r");
	char buffer[MAX];
	Line* l = NULL;
	while(fgets(buffer, MAX, f)) l = insert_line(l, 1000, buffer);
	display(l, 10000);
	fclose(f);
	while(l=command(l));
}

