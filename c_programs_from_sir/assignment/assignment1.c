#include<stdio.h>

int main()
{
	int i;

	printf("\n Shawarma Menu\n");
	printf("1. Classic chicken Shawarma roll\n");
	printf("2. Crispy chicken Shawarma roll\n");
	printf("3. Moroccan chicken Shawarma roll\n");
	printf("4. Mexican chicken Shawarma roll\n");
	printf("5. Arabian chicken Shawarma roll\n");
	printf("\n Enter the item number you want to order : ");

	scanf("%d",&i);

	if(i==1)
	{
		printf("\n You have ordered Classic chicken Shawarma roll!");
		printf("\n Price: 100 Rs");
		printf("\n Thank you visit again >3\n\n");
	}
	else if(i==2)
	{
		printf("\n You have ordered Crispy chicken Shawarma roll!");
		printf("\n Price: 120 Rs");
		printf("\n Thank you visit again >3\n\n");
	}
	else if(i==3)
	{
		printf("\n You have ordered Moroccan chicken Shawarma roll!");
		printf("\n Price: 130 Rs");
		printf("\n Thank you visit again >3\n\n");
	}
	else if(i==4)
	{
		printf("\n You have ordered Mexican chicken Shawarma roll!");
		printf("\n Price: 140 Rs");
		printf("\n Thank you visit again >3\n\n");
	}
	else if(i==5)
	{
		printf("\n You have ordered Arabian chicken Shawarma roll!");
		printf("\n Price: 150 Rs");
		printf("\n Thank you visit again >3\n\n");
	}
	else
	{
		printf("\n Incorrect option\n\n");
	}

	return 0;

}
