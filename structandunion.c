#include<stdio.h>
#include<string.h>

struct type1
{
	int t1;
	double t2;
	char a;
	char aa[20];
};

union type2
{
	int t1;
	double t2;
	char a;
	char aa[20];
};

int main()
{
	struct type1 st;
	union type2 u1;

	printf("\n%ld",sizeof(st));

	st.t1=5;
	st.t1=5.5;
	st.a='b';
	strcpy(st.aa,"Srivathsan");

	printf("\nt1=%d",st.t1);
	printf("\nt2=%lf",st.t2);
	printf("\na=%c",st.a);
	printf("\naa=%s",st.aa);

	return 0;

}
