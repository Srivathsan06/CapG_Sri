#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<unistd.h>

#define MAX_LINE_LENGTH 1024

struct User
{
    char msisdn[20];
    char opbrandname[64];
    char opmmc[20];
    char caltype[10];
	char dur[10];
	char down[10];
	char upload[10];
    char thirdparmsisdn[10];
    char thirdparmmc[10];
};

int main() {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    char *token;
    struct User *us=NULL;

    fp = fopen("data.cdr", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(0);
    }
	int n=0;

    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) 
	{
		printf("\n%s\n",line);
		n++;
		struct User *temp=realloc(us,n*sizeof(struct User));
		us=temp;
		sleep(1);
		token = strtok(line, "|");
        strcpy(us[n-1].msisdn, token);
        token = strtok(NULL, "|");
        strcpy(us[n-1].opbrandname, token);
        token = strtok(NULL, "|");
        strcpy(us[n-1].opmmc, token);
        token = strtok(NULL, "|");
        strcpy(us[n-1].caltype, token);
        token = strtok(NULL, "|");
        strcpy(us[n-1].dur, token);
        token = strtok(NULL, "|");
        strcpy(us[n-1].down, token);
        token = strtok(NULL, "|");
        strcpy(us[n-1].upload, token);
        token = strtok(NULL, "|");
        strcpy(us[n-1].thirdparmsisdn, token);
        token = strtok(NULL, "|");
        strcpy(us[n-1].thirdparmmc, token);
        printf("\nUser %d details:",n);
        printf("\nMSISDN: %s \nOP BRAND NAME: %s \nOP MMC/MNC: %s\nCALL TYPE: %s \nDURATION: %s\nDOWNLOAD: %s\nUPLOAD: %s\nTHIRD PARTY MSISDN: %s\nTHIRD PARTY OPERATOR MMC/MNC: %s\n", us[n-1].msisdn, us[n-1].opbrandname, us[n-1].opmmc, us[n-1].caltype, us[n-1].dur, us[n-1].down, us[n-1].upload, us[n-1].thirdparmsisdn, us[n-1].thirdparmmc);
   
   }

    fclose(fp);

    return 0;
}
