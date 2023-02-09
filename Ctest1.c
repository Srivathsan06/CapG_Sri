#include<stdio.h>


int main() 
{
	int i,j,k,l;
	i=10,j=11,k=12,l=0;
	l=(i>j)?((i>k)?i:k):((j>k)?j:k);
	printf("%d",l);
	return 0;
}
