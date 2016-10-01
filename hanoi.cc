#include<iostream>
using namespace std;

int pole[3][100] {};

void setup(int n) {
	for(int i=n; i>0; i--) pole[0][n-i] = i;
}

void show() {
	for(int i=0; i<3; i++) {
		for(int j=0; pole[i][j] != 0; j++) cout << pole[i][j] << ' ';
		cout << endl;
	}
	cout << "------------------" << endl;
}

int move(int a, int b) {//move one piece from a to b
	int i;
	for(i=0; pole[a][i] != 0; i++);
	int k = pole[a][i-1];
	pole[a][i-1] = 0;
	for(i=0; pole[b][i] != 0; i++);
	pole[b][i] = k;
	show();
}

int move(int n, int a, int b) {//move n pieces
	int c;
	if(a + b == 1 ) c = 2;
	else if(a + b == 2) c = 1;
	else c = 0;

	if(n == 1) move(a, b);
	else {
		move(n-1, a, c);
		move(a, b);
		move(n-1, c, b);
	}
}

int main(int c, char** v)
{
	if(c < 2) return 0;
	int a = atoi(v[1]);
	setup(a);
	move(a, 0, 2);
}
