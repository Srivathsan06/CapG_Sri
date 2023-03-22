#include<stdio.h>
#include<stdlib.h>

int main()
{
	enum Week {MON=10,TUE,WED,THU,FRI,SAT};

	enum Week day1;
	day1=WED;

	printf("day1 = %d",day1);

	printf("\n\n");

	return EXIT_SUCCESS;

}

