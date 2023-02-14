#include<stdio.h>

int main()
{
	int n,i,j,k,l;
	int count=0;

	printf("\n\n Enter the number: ");
	scanf("%d",&n);

	for(i=1;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			for(k=j;k<n;k++)
			{
				for(l=k;l<n;l++)
				{
					if(i+j+k+l==n)
					{
						count++;
						printf("\n %d + %d + %d + %d \n",i,j,k,l);
					}
				}
			}
		}
	}

	printf("\n\n Ways : %d \n\n",count);

	return 0;

}
