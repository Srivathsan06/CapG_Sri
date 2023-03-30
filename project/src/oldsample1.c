#include<myHeader.h>

int main() {
    FILE *fp;

	
    fp = fopen("/home2/trainee37/personal_directory/CapG_Sri/project/data/data.cdr", "r");

    if (fp == NULL)
	{
        perror("Error opening file.\n");
        exit(1);
    }

    struct User *us=dataProcess(fp);
	datadisplay(us);
	fclose(fp);

	return EXIT_SUCCESS;

}


