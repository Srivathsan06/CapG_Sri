#include<stdio.h>

int main()
{
	char name[25];
	int d;
	int i=0;
	printf("Enter name!\n\n");
	printf("Press enter key to complete input!!\n\n");
	for(i=0;d!=10;i++)
	{
		scanf("%c",&name[i]);
		d=name[i];
		
	}
	printf("\n\n");
	printf("%s",name);
	printf("\n\n");
	return 0;
}
