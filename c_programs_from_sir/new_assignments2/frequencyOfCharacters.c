#include<stdio.h>
#include<string.h>

void charFrequency(char [], int []);

int main()

{
	int alphabets[50]={0,};

	char str1[1024];

	printf("\n\nEnter the string: ");
	scanf("%s",str1);

	charFrequency(str1,alphabets);

	return 0;

}

void charFrequency(char str1[],int alphabets[])
{
	int i=0;
	for(i=0;str1[i]!='\0';i++)
	{
		alphabets[str1[i]-'a']++;
	}
	
	for(i=0;str1[i]!='\0';i++)
	{
		if(alphabets[str1[i]-'a']!=0)
		{
			printf("\n%c : %d\n", str1[i],alphabets[str1[i]-'a']);
			alphabets[str1[i]-'a']=0;
		}

	}
	printf("\n\n");
}
