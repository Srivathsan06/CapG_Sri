#include<myHeader.h>
#define LENGTH 1024

int main()
{
	
	//char ty[]=","; 
	char lines[LENGTH];
	FILE *fp=fopen("data.cdr","r");
	struct User *user=(struct User *)malloc(100000 * sizeof(struct User));	
	int n=0;
//	char ty[]=","; 
	int i,j=0,count=0;
	int msisdn;
	int flag=0;
	char tokens[9][LENGTH];
	if(fp == NULL)
	{
		printf("Error occured in opening File");
		return 0;
	}

	while(fgets(lines,LENGTH,fp)!=NULL)
	{
		
		if(n>100000)
		{
			printf("maximum no of user data entered");
			break;
		}

		for(i=0;lines[i]!='\0';i++)
		{
			if(lines[i]=='|')
			{
				tokens[count][j]='\0';
				count++;
				j=0;
				continue;
			}
			printf("\ntest %d",count);		
			tokens[count][j]=lines[i];
			j++;
		
		}

			
			 strcpy(user[n].msisdn,tokens[0]);
			 strcpy(user[n].opbrandname,tokens[1]);
			 strcpy(user[n].opmmc,tokens[2]);
			 strcpy(user[n].caltype,tokens[3]);
			 strcpy(user[n].dur,tokens[4]);
			 strcpy(user[n].down,tokens[5]);
			 strcpy(user[n].upload,tokens[6]);
			 strcpy(user[n].thirdparmsisdn,tokens[7]);
			 strcpy(user[n].thirdparmmc,tokens[8]);
			
			printf("\n%s",user[n].thirdparmmc);				
	count=0;
	j=0;
	n++;
	
	}
	printf("\n%d\n",n);

	printf("enter the MSISDN\n");
	scanf("%d",&msisdn);
	


	for(int i=0;i<n;i++)
	{
		if(atoi(user[i].msisdn)==msisdn)
		{
		printf("MSISDN         :%s\n",user[i].msisdn);		
		printf("OPNAME         :%s\n",user[i].opbrandname);
		printf("OPMMC          :%s\n",user[i].opmmc);
		printf("CALLTYPE       :%s\n",user[i].caltype);
		printf("DURATION       :%s\n",user[i].dur);
		printf("DOWNLOAD       :%s\n",user[i].down);
		printf("UPLOAD         :%s\n",user[i].upload);
		printf("THIRDPARMSISDN :%s\n",user[i].thirdparmsisdn);
		printf("THIRDPARMMC    :%s\n",user[i].thirdparmmc);
	//	printf("\n%u",user[i].thirdparmsisdn);
	//	printf("\n%u",user[i].thirdparmmc);
//		printf("\n%s",ty);
		printf("\n\n");
		flag=1;
		break;
		}
	}
	if(flag==0)
		printf("user data not found\n");

	fclose(fp);
//	free(user);

	return 0;

}
