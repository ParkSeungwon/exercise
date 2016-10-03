#include<stdio.h>
#include<time.h>
#include"list.h"

List* search(List* head, element data)
{
	List *current = head->p;
	head->data = data;
	for(; current->data != data; current = current->p);
	return current == head ? NULL : current;
}

List* search2(List* l, element data) {
	for(; l; l = l->p) if(l->data == data) return l;
	return NULL;
}

int main() {
	for(int k=100; k!=1000000; k *=10) {
		double sum1=0, sum2=0;
		double max1=0, max2=0;
		for(int i=0; i<100; i++) {
			List* p = setup(k);
			List* head = (List*)malloc(sizeof(List));
			head->p = p;
			head->data = 6;

			clock_t start, end;
			start = clock();
			List* r = search2(p, 6);
			end = clock();
			double t = (double)(end - start);
			sum1 += t;
			max1 = max1 < t ? t : max1;
			if(r) printf("%d", r->data);
			List* tmp;
			for(; p; p = p->p) tmp = p;
			tmp->p = head;

			start = clock();
			r = search(head, 6);
			end = clock();
			t = (double)(end - start);
			sum2 += t;
			max2 = max2 < t ? t : max2;

			if(r) printf("%d", r->data);
			tmp->p = NULL;
			free(head);
		}
		printf("%d개의 요소에서 헤드없는 탐색의 수행시간은 %lf\n", k, sum1/100);
		printf("%d개의 요소에서 헤드없는 탐색의 최악 수행시간은 %lf\n", k, max1);

		printf("%d개의 요소에서 헤드를 이용한 탐색의 수행시간은 %lf\n", k, sum2/100);
		printf("%d개의 요소에서 헤드를 이용한 탐색의 최악수행시간은 %lf\n", k, max2);
	}
}
