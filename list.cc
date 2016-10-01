#include<iostream>
#include<random>
using namespace std;

struct List {
	int data;
	List* p = nullptr;
};

uniform_int_distribution<> di(1,5);
random_device rd;

List* setup(int n) {
	if(n == 0) return nullptr;
	List* p = new List;
	p->data = di(rd);
	p->p = setup(n-1);
	return p;
}

void show(List* p) {
	if(p == nullptr) return;
	cout << p->data << ' ';
	show(p->p);
}

void free_mem(List* p) {
	if(p == nullptr) return;
	free_mem(p->p);
	free(p);
}

int count(List* p, int n) {
	return p == nullptr ? 0 : (p->data == n) + count(p->p, n);
}

void del(List* p, int n) {
	List* tmp;
	if(p->p == nullptr) return;
	del(p->p, n);//이 줄을 밑으로 내리면 연이어질 때 안 지워진다.
	if(p->p->data == n) {
		tmp = p->p->p;
		free(p->p);
		p->p = tmp;
	}
}

List* del2(List* p, int n) {
	if(p == nullptr) return nullptr;
	if(p->data == n) {
		List* tmp = p->p;
		free(p);
		return del2(tmp, n);
	} else {
		p->p = del2(p->p, n);
		return p;
	}
}
int del_2(int n) {
	return n == 2;
}

int del_everyother(int n) {
	static int k = 0;
	return k++ % 2 == 0;
}
List* del_if(List* p, int(*pf)(int)) {
	if(p == nullptr) return nullptr;
	if((*pf)(p->data)) {
		List* tmp = p->p;
		free(p);
		return del_if(tmp, pf);
	} else {
		p->p = del_if(p->p, pf);
		return p;
	}
}

void del_if2(List* p, int(*pf)(int)) {
	if(p != nullptr) { 
		if((*pf)(p->data)) {
			p->data = p->p->data;
			List* tmp = p->p->p;
			free(p->p);
			p->p = tmp;
		}
		del_if(p->p, pf);
	}
}

List* del_everyother(List* p, int n) {
	if(p == nullptr) return nullptr;
	List* tmp;
	if(n%2 == 0) {
		tmp = p->p;
		free(p);
		return del_everyother(tmp, n+1);
	} else {
		p->p = del_everyother(p->p, n+1);
		return p;
	}
}

struct SparseMatrix {//첫번째 노드에서는 행렬의 너비 높이 0이 아닌 값의 갯수이고, 
	int x, y, v;//두번째 노드부터는 x,y좌표와 그 값이다.
	SparseMatrix* node;
};

List* alternate(List* p1, List* p2, int n) {
	if(p1 == nullptr && p2 == nullptr) return nullptr;
	List *p;
	if(n%2 == 0) {
		if(p1 != nullptr) {
			p = new List;
			p->data = p1->data;
			p->p = alternate(p1->p, p2, n+1);
		} else p = alternate(p1, p2, n+1);
	} else {
		if(p2 != nullptr) {
			p = new List;
			p->data = p2->data;
			p->p = alternate(p1, p2->p, n+1);
		} else p = alternate(p1, p2, n+1);
	}
	return p;
}

List* altern(List* p1, List* p2) {
	List *p, *head;
	p = head = new List;
	while(p1 != NULL || p2 != NULL) {
		if(p1 != NULL) {
			p->p = new List;
			p = p->p;
			p->data = p1->data;
			p1 = p1->p;
		}
		if(p2 != NULL) {
			p->p = new List;
			p = p->p;
			p->data = p2->data;
			p2 = p2->p;
		}
	}
	List* tmp = head->p;
	delete head;
	return tmp;
}

List* split(List *from, List *&to1, List *&to2, int n) {
	if(from == nullptr) return nullptr;
	List *p = new List;
	if(n%2 == 0) {
		to1 = p;
		to1->data = from->data;
		to2 = split(from->p, to1->p, to2, n+1);
	} else {
		to2 = p;
		to2->data = from->data;
		to1 = split(from->p, to1, to2->p, n+1);
	}
	return p;
}

List* split(List* from) {
	if(from == nullptr) return nullptr;
	List* p = new List;
	p->data = from->data;
	p->p = from->p == nullptr ? nullptr : split(from->p->p);
	return p;
}


class Alt 
{
public:
	Alt(int a, int b) {
		l1 = setup(a);
		cout << endl << "l1 is : "; show(l1);
		l2 = setup(b);
		cout << endl << "l2 is : "; show(l2);
		alt = get_l1();
		cout << endl << "alt is :"; show(alt);
		cout << endl;
	}
	virtual ~Alt() {
		free_mem(l1);
		free_mem(l2);
		free_mem(alt);
	}

protected:
	List *l1, *l2, *alt;

private:
	List* get_l1() {
		static List* l = l1;
		if(l == nullptr) {
			end1 = true;
			if(end2) return nullptr;
			else return get_l2();
		} else {
			List* p = new List;
			p->data = l->data;
			l = l->p;
			p->p = get_l2();
		}
	}

	List* get_l2() {
		static List* l = l2;
		if(l == nullptr) {
			end2 = true;
			if(end1) return nullptr;
			else return get_l1();
		} else {
			List* p = new List;
			p->data = l->data;
			l = l->p;
			p->p = get_l1();
		}
	}

	bool end1 = false, end2 = false;
};


int main()
{
	{
		List* p = setup(20);
		show(p);
		cout << endl << "3값은 " << count(p, 3) << endl;
		p = del2(p, 3);
		show(p);
		cout << endl << "3값은 " << count(p, 3) << endl;
		p = del_everyother(p, 0);
		cout << "둘 중 하나 지움." << endl;
		show(p);
		free_mem(p);
	}
	cout << endl;
	List *p = setup(10);
	cout << "p : "; show(p); cout << endl;
	List *q = setup(15);
	cout << "q : "; show(q); cout << endl;
	auto r = altern(p, q);
	cout << "p,q alternate : "; show(r); cout << endl;
	free_mem(p);
	free_mem(q);
	p = split(r);
	q = split(r->p);
	cout << "p : "; show(p); cout << endl;
	cout << "q : "; show(q); cout << endl;
	del_if2(q, del_2);
	cout << "q : "; show(q); cout << endl;
	q = del_if(q, del_everyother);
	cout << "q : "; show(q); cout << endl;
	free_mem(p);
	free_mem(q);
	free_mem(r);

	Alt a{7, 5};
}
