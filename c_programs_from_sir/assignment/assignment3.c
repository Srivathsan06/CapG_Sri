#include <stdio.h>

int main()
{

	int number=0;
	int reversenum=0, q=0, r=0;

	printf("\nEnter the number: ");
	scanf("%d",&number);
	
	q=number;

	while(q!=0)
	{
		r = q%10;
		reversenum = (reversenum * 10)+r;
		q=q/10;
	}

	printf("\n\nRev No: %d\n",reversenum);


	return 0;
}