#include<stdio.h>
#include<string.h>
int main()
{
	char a[1024];
	char b[1024];
	char c[1024];

	printf("\n\nEnter name 1:");
	scanf("%s",a);

	printf("\n\nEnter name 2:");
	scanf("%s",b);

	int i=0,j=0;

	for(i=0;i<strlen(a)||i<strlen(b);i++)
	{
		if(i<strlen(a))
		{
			c[j]=a[i];
			j++;
		}
		if(i<strlen(b))
		{
			c[j]=b[i];
			j++;
		}
	}

	printf("\n\n%s\n\n",c);

	return 0;
}
