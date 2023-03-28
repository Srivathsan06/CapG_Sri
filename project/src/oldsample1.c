#include<myHeader.h>

int main() {
    FILE *fp;
    char line[MAX_LINE_LENGTH]={0,};
    struct User *us=NULL;
	int i=0,j=0,token_count = 0;
	char tokens[9][MAX_LINE_LENGTH]={0,};

    fp = fopen("data.cdr", "r");
    if (fp == NULL) {
        perror("Error opening file.\n");
        exit(1);
    }
	int n=0;

    while (fgets(line,MAX_LINE_LENGTH,fp) != NULL) 
	{
		printf("\n%s",line);
		for(i=0;line[i]!='\0';i++)
		{
			if(line[i]=='|')
			{
				tokens[token_count][j]='\0';
				token_count++;
				j=0;
				continue;
			}
			tokens[token_count][j]=line[i];
			j++;
		}
		n++;
		us=realloc(us,n*sizeof(struct User));
        strcpy(us[n-1].msisdn, tokens[0]);
        strcpy(us[n-1].opbrandname, tokens[1]);
        strcpy(us[n-1].opmmc, tokens[2]);
        strcpy(us[n-1].caltype, tokens[3]);
        strcpy(us[n-1].dur, tokens[4]);
        strcpy(us[n-1].down, tokens[5]);
        strcpy(us[n-1].upload, tokens[6]);
        strcpy(us[n-1].thirdparmsisdn, tokens[7]);
        strcpy(us[n-1].thirdparmmc, tokens[8]);
		token_count=0;
		j=0;
   }
	printf("\nEnter msisdn number: ");
	long int msisdn;
	scanf("%ld",&msisdn);
	int k=0;
	while(k<n)
	{
		if(msisdn==atol(us[k].msisdn))
		{
    		printf("\nUser details:\n");
			printf("================\n");
			printf("\nMSISDN: %s",us[k].msisdn);
			printf("\nOP BRAND NAME: %s",us[k].opbrandname);
			printf("\nOP MMC/MNC: %s",us[k].opmmc);
			printf("\nCALL TYPE: %s",us[k].caltype);
			printf("\nDURATION: %s",us[k].dur);
			printf("\nDOWNLOAD: %s",us[k].down);
			printf("\nUPLOAD: %s",us[k].upload);
			printf("\nTHIRD PARTY MSISDN: %s",us[k].thirdparmsisdn);
			printf("\nTHIRD PARTY OPERATOR MMC/MNC: %s",us[k].thirdparmmc);
			printf("\n");
			break;
		}
		k++;
	}
	free(us);
	
    fclose(fp);

    return 0;
}
