#include"list.h"
//연결 리스트 헤더
typedef struct ListHeader {
	int length;
	List* head;
	List* tail;
} ListHeader;

//헤더노드를 이용한 삽입함수
void insert_node(ListHeader *header, List *new_node)
{
	List *p, *prev;
	for(p = header->head; p != new_node; p = p->p) prev = p;
	prev->p = (List*)malloc(sizeof(List));
	prev->p->p = new_node;
}

//헤더 노드를 이용한 삭제함수
void remove_node(ListHeader *header, List *removed)
{
	List *p, *prev;
	for(p = header->head; p != removed; p = p->p) prev = p;
	prev->p = p->p;
	free(p);
}

//헤더노드를 이용한 공백 검사 함수
int is_empty(ListHeader *header)
{
	return header->length == 0;
}

//헤더노드를 이용한 검색 함수
List* search(ListHeader *header, element data)
{
	for(List* p = header->head; p != header->tail; p = p->p) 
		if(p->data == element) return p;
	return NULL;
}
