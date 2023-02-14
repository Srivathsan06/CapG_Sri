#include<stdio.h>

int main()
{
	int number=0, i=0,j=0;

	printf("\n\n Enter the number you want to check : ");
	scanf("%d",&number);

	for(i=2;i<number;i++)
	{
		if(number%i==0)
		{
			j++;
			break;
		}
	}

	if(j==0)
	{
		printf("\n\n %d is a prime number \n\n",number);
	}
	else
	{
		printf("\n\n %d is not a prime number \n\n",number);
	}

	return 0;
}

