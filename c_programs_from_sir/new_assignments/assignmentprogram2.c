#include<stdio.h>

int main()
{

	int number=0;
	int sum=0, prod=1, q=0, r=0;

	printf("\nEnter the number: ");
	scanf("%d",&number);
	
	q=number;

	while(q!=0)
	{
		r = q%10;
		sum=sum+r;
		prod=prod*r;
		q=q/10;
	}

	printf("\n\nSum: %d\n\n Prod: %d\n\n",sum,prod);


	return 0;
}
