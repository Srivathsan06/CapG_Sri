#include<stdio.h>

int isPrime(int);
int noOfWays(int);
int main()
{
	int n;
	int count=0;

	printf("\n\n Enter the number: ");
	scanf("%d",&n);

	count=noOfWays(n);

	if(count==0)
	{
		printf("\n\n No ways!\n\n");
	}
	else
	{
		printf("\n\n %d ways!!\n\n",count);
	}

	return 0;
}


int noOfWays(int n)
{
	int i,j;
	int count1=1,count2=1,count3=0;

	for(i=2;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			if(i+j==n)
			{
				count1=isPrime(i);
				count2=isPrime(j);
				if(count1==1 && count2==1)
				{
					printf("\n\n %d + %d = %d",i,j,n);
					count3++;
				}
			}
			count1=1;
			count2=1;
		}
	}

	return count3;
}

int isPrime(int l)
{
	int k, m=l, count3=1;
	for(k=2;k<m;k++)
	{
		if(m%k==0)
		{
			count3=0;
			break;
		}
	}
	return count3;
}
