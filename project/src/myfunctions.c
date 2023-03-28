#include<myHeader.h>

int n=0;
struct User *dataProcess(FILE *fp)
{
    char line[MAX_LINE_LENGTH]={0,};
	int i=0,j=0,token_count = 0;
	char tokens[9][MAX_LINE_LENGTH]={0,};
	struct User *us=NULL;

    while (fgets(line,MAX_LINE_LENGTH,fp) != NULL) 
	{
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

	return us;
}

void datadisplay(struct User *us)
{
	printf("\nEnter msisdn number: ");
	long int msisdn,opn=0;
	scanf("%ld",&msisdn);
	int k=0,flag=0;
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
			flag=1;
			break;
		}
		k++;
	}
	if(flag==0)
	{
		printf("\nUser not found!!\n\n");
	}
	k=0;
	printf("\n\nEnter operator number: ");
	scanf("%ld",&opn);
	flag=0;
	long int incomingcall=0,outgoingcall=0,incomingsms=0,outgoingsms=0,downloaded=0,uploaded=0;
	char opname[1024]={0,};
	char *mtc="MTC", *moc="MOC", *smsin="SMS-MT", *smsout="SMS-MO", *gprs="GPRS";
	while(k<n)
	{
		if(opn==atol(us[k].opmmc))
		{
			if(strcmp(us[k].caltype,mtc)==0)
			{
				incomingcall=incomingcall+atol(us[k].dur);
			}
			else if(strcmp(us[k].caltype,moc)==0)
			{
				outgoingcall=outgoingcall+atol(us[k].dur);
			}
			else if(strcmp(us[k].caltype,smsin)==0)
			{
				incomingsms=incomingsms+atol(us[k].dur);
			}
			else if(strcmp(us[k].caltype,smsout)==0)
			{
				
				outgoingsms=outgoingsms+atol(us[k].dur);
			}
			else if(strcmp(us[k].caltype,gprs)==0)
			{
				downloaded=downloaded+atol(us[k].down);
				uploaded=uploaded+atol(us[k].upload);
			}
			flag=1;
			strcpy(opname,us[k].opbrandname);
		}
		k++;
	}
	if(flag==1)
	{
		printf("\n\nInter operator billing!\n");
		printf("==============================\n");
		printf("\n\nOperator Brand : %s(%ld)",opname,opn);
		printf("\nIncoming voice call duration: %ld",incomingcall);
		printf("\nOutgoing voice call duration: %ld",outgoingcall);
		printf("\nIncoming SMS messages: %ld",incomingsms);
		printf("\nOutgoing SMS messages: %ld",outgoingsms);
		printf("\nMB downloaded: %ld | MB uploaded: %ld",downloaded,uploaded);
		printf("\n\n");
	}
	else
	{
		printf("\nOperator not found!!!\n\n");
	}


	free(us);

}
	
