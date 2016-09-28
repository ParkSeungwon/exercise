#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	for(int n=0; ; n++) {
		if(1000*n*n+1000 < pow(2, n)) {
			cout << n; break;
		}
	}
}
