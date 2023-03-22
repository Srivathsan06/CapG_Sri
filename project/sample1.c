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
    struct User user;

    fp = fopen("data.cdr", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(0.5);
    }
	int count=0;

    // read user details from file using fgets and tokenization
    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) 
	{
		printf("\n%s\n",line);
		sleep(1);
		count++;
        token = strtok(line, "|");
        strcpy(user.msisdn, token);
        token = strtok(NULL, "|");
        strcpy(user.opbrandname, token);
        token = strtok(NULL, "|");
        strcpy(user.opmmc, token);
        token = strtok(NULL, "|");
        strcpy(user.caltype, token);
        token = strtok(NULL, "|");
        strcpy(user.dur, token);
        token = strtok(NULL, "|");
        strcpy(user.down, token);
        token = strtok(NULL, "|");
        strcpy(user.upload, token);
        token = strtok(NULL, "|");
        strcpy(user.thirdparmsisdn, token);
        token = strtok(NULL, "|");
        strcpy(user.thirdparmmc, token);
        printf("\nUser %d details:",count);
        printf("\nMSISDN: %s \nOP BRAND NAME: %s \nOP MMC/MNC: %s\nCALL TYPE: %s \nDURATION: %s\nDOWNLOAD: %s\nUPLOAD: %s\nTHIRD PARTY MSISDN: %s\nTHIRD PARTY OPERATOR MMC/MNC: %s\n", user.msisdn, user.opbrandname, user.opmmc, user.caltype, user.dur, user.down, user.upload, user.thirdparmsisdn, user.thirdparmmc);
   
   }

    fclose(fp);

    return 0;
}
