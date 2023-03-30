#include<myHeader.h>

int n=0;

void signUp()
{
	char uname[MAX_LINE_LENGTH]={0,};
	char password[MAX_LINE_LENGTH]={0,};
	char repassword[MAX_LINE_LENGTH]={0,};

	printf("\n\nWelcome to SignUp page!!!\n\n");
	printf("Username must be without space and numeric characters can be used and case sensitive\n");
	printf("Password is case sensitive and numeric and special characters can be used\n");

	printf("\nEnter User Name: ");
	scanf("%s",uname);
	printf("\nEnter Password: ");
	scanf("%s",password);
	printf("\nRe-Enter Password: ");
	scanf("%s",repassword);

	if(strcmp(password,repassword)==0)
	{
		int ccec=0;
		ccec=usPassCheck(uname,password);
		if(ccec==1)
		{
			FILE *fp;
			fp= fopen("/home2/trainee37/personal_directory/CapG_Sri/project/data/logindetails.dat","a");
			if(fp == NULL)
			{
				printf("\n\nSorry for the inconvinence!! Please try again later!!\n\n");
				exit(1);
			}
			fprintf(fp,"%s %s\n",uname,password);
			printf("\n\nSignUp successfull!!\n");
			fclose(fp);
		}
		else
		{
			printf("\n\nUsername or password already exists!!\n\n");
		}
	}
	else
	{
		printf("\n\nPassword mismatched");
		printf("\n\nLogin failed");
	}
}

void logIn()
{
	char uname[MAX_LINE_LENGTH]={0,};
	char runame[MAX_LINE_LENGTH]={0,};
	char password[MAX_LINE_LENGTH]={0,};
	char rpassword[MAX_LINE_LENGTH]={0,};
	int flag=0;

	printf("\n\nEnter Username: ");
	scanf("%s",uname);
	printf("\nEnter password: ");
	scanf("%s",password);
	FILE *fp;
	fp=fopen("/home2/trainee37/personal_directory/CapG_Sri/project/data/logindetails.dat","r");
	if(fp==NULL)
	{
		printf("\n\nSorry !! Try again later");
		exit(1);
	}
	else
	{
		while(fscanf(fp,"%s %s\n",runame,rpassword)==2)
		{
			if(strcmp(runame,uname)==0)
			{
				if(strcmp(rpassword,rpassword)==0)
				{
					printf("\n\nLogin successfull!!\n\n");
					processFunc();
					flag=1;
					printf("\n\nLogged out successfully!!\n\n");
					break;
				}
			}
		}
		if(flag!=1)
		{
			printf("\n\nIncorrect username or password!!");
			printf("\n\nLoggin failed");
		}
	}
	fclose(fp);
}

int processFunc()
{
	int ch;
	struct User *us=NULL;
	while(ch>=0)
	{
		printf("\n\n1. Process CDR file");
		printf("\n2. Print/Search for Billing Information");
		printf("\n3. Logout");
		printf("\nChoice: ");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1:
				if(us==NULL){	
				struct User *temp=dataProcess();
				us=temp;
				if(us!=NULL)
				{
										
					printf("\n\nProcessed the data!!\n\n");
				}
				else
				{
					printf("\n\nData process failed!!\n\n");
				}
				}
				else
				{
					printf("\nThe data is processed already!!\n\n");
				}
				break;

			case 2:
				billingFunc(us);				
				break;

			case 3:
				free(us);
				return EXIT_SUCCESS;

			default:
				printf("\n\nWrong choice!!\n\n");

		}
	}
	return EXIT_SUCCESS;
}

void billingFunc(struct User *us)
{
	int chi;
	printf("\n\n1.Customer Billing");
	printf("\n2.Inter operator Billing");
	printf("\nChoice :");
	scanf("%d",&chi);

	switch(chi)
	{
		case 1:
			userDataDisplay(us);
			break;

		case 2:
			operatorDataDisplay(us);
			break;
	}
}

struct User *dataProcess()
{
	FILE *fp;
	fp=fopen("/home2/trainee37/personal_directory/CapG_Sri/project/data/data.cdr","r");
	if(fp == NULL)
	{
		printf("\n\nTry again later!!\n\n");
		return NULL;
	}
	else
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
	fclose(fp);

	return us;
	}
}

void userDataDisplay(struct User *us)
{
	printf("\nEnter msisdn number: ");
	long int msisdn;
	scanf("%ld",&msisdn);
	int k=0,flag=0;
	while(k<n)
	{
		if(msisdn==atol(us[k].msisdn))
		{
			printf("\n\nMSISDN: %s",us[k].msisdn);
			printf("\nOP BRAND NAME: %s",us[k].opbrandname);
			printf("\nOP MMC/MNC: %s",us[k].opmmc);
			printf("\nCALL TYPE: %s",us[k].caltype);
			printf("\nDURATION: %s",us[k].dur);
			printf("\nDOWNLOAD: %s",us[k].down);
			printf("\nUPLOAD: %s",us[k].upload);
			printf("\nTHIRD PARTY MSISDN: %s",us[k].thirdparmsisdn);
			printf("\nTHIRD PARTY OPERATOR MMC/MNC: %s",us[k].thirdparmmc);
			printf("\n\n");
			flag=1;
			break;
		}
		k++;
	}
	if(flag==0)
	{
		printf("\nMSISDN not found!!\n\n");
	}
	
}

void operatorDataDisplay(struct User *us)
{
	long int opn;
	int k=0,flag=0;
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

}
	
int usPassCheck(char uname[],char password[])
{
	int flag=1;
	FILE *fp;
	char un[1024]={0,};
	char pas[1024]={0,};

	fp=fopen("/home2/trainee37/personal_directory/CapG_Sri/project/data/logindetails.dat","r");
	if(fp==NULL)
	{
		printf("\n\nSorry Try again later!!!\n\n");
		exit(1);
	}
	else
	{
		while(fscanf(fp,"%s %s\n",un,pas)==2)
		{
			if(strcmp(uname,un)==0)
			{
				flag=0;
				break;
			}
			else if(strcmp(password,pas)==0)
			{
				flag=0;
				break;
			}
		}
		return flag;
	}
	return EXIT_SUCCESS;
}
