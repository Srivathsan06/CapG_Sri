#include<stdio.h>

int main()

{

	int Practice_array[150];
	int i;
	int j=0;

	for(i=25;i<=125;i++)
	{
		if(i%2==0)
		{
			Practice_array[j]=i;
			j++;
		}
	}

	for(i=25;i<=125;i++)
	{
		if(i%2!=0)
		{
			Practice_array[j]=i;
			j++;
		}
	}

	printf("\n");

	for(i=0;i<j;i++)
	{
		printf("\t %d",Practice_array[i]);

		if(i%10==0)
		{
			printf("\n\n");
		}
	}

	return 0;

}

	
