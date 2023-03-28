#include<myHeader.h>

int main() {
    FILE *fp;

	
    fp = fopen("data.cdr", "r");

    if (fp == NULL)
	{
        perror("Error opening file.\n");
        exit(1);
    }

    struct User *us=dataProcess(fp);
	datadisplay(us);

	return EXIT_SUCCESS;

}


