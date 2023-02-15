#include<stdio.h>

int main()
{
	int n,i,j,k;
	int count1=1;
	int count2=1;
	int count3=0;

	printf("\n\n Enter the number: ");
	scanf("%d",&n);

	for(i=2;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			if(i+j==n)
			{
				if(i==0 || i==1)
				{
					count1=0;
				}
				else
				{
					for(k=2;k<=i/2;++k)
					{	
						if(i % k == 0)
						{
							count1=0;
							break;
						}
					}
				}
				if(j==0 || j==1)
				{
					count2=0;
				}
				else
				{
					for(k=2;k<=j/2;++k)
					{
						if(j % k ==0)
						{
							count2=0;
							break;
						}
					}
				}
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


	if(count3!=0)
	{
		printf("\n\n Ways : %d \n\n",count3);
	}
	else
	{
		printf("\n\n No ways available!! \n\n");
	}

	return 0;

}

