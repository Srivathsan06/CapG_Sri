#include<stdio.h>
int main()
{
	//char str[100];   // = "This is to test string"; //dec with initialisation

	char str[100];// = "This is to test string"; //dec with initialisation
	int len = 0;
	//char *str1;

	strcpy(str,"This is a test"); 
	//strcpy(str,"This is a test");

	fgets(str, 1024, stdin);

	len = strlen(str);

	printf("\n%s and its length=%d",str,len);

	printf("\n%s",str);
	printf("\nstr[0]=%c \t str[1]=%c \n",str[0],str[1]);
	printf("\nstr[strlen-1]=%c and its ascii value=%d", str[len-1], str[len-1]);

	printf("\n\n");

	return 0;
}