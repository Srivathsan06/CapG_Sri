#include<myHeader.h>

int main() {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    char *token;
    struct User *us=NULL;

    fp = fopen("data.cdr", "r");
    if (fp == NULL) {
        perror("Error opening file.\n");
        exit(1);
    }
	int n=0;

    while (fgets(line,MAX_LINE_LENGTH,fp) != NULL) 
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
