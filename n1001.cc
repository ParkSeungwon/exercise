#include<iostream>
using namespace std;

int curious(int n)
{
	int r = 0;
	while(n >0) {
		if((n%2) != 0) r++;
		n /= 2;
	}
	return r;
}

int main()
{
	for(int i=1000; i>0; i--) cout << i << " : " << curious(i) << endl;
}	
