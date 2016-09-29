#include<stdio.h>
int nCr(int n, int r)
{
	if(r==0 || r==n) return 1;
	return nCr(n-1, r-1) + nCr(n-1,r);
}

int main()
{
	return nCr(6, 4);
}
