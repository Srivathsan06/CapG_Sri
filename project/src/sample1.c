#include<myHeader.h>

int main() 
{
	int choice=1;
	printf("\n\nWelcome to CDR Software!!!\n\n");
	printf("==================================\n");
	
	while(choice>=0)
	{
		printf("\n1. SignUp");
		printf("\n2. Login");
		printf("\n3. exit");
		printf("\nchoice: ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				signUp();				
				break;

			case 2:
				logIn();
				break;

			case 3:
				printf("\n\nThankyou for using our software!!\n\n");
				printf("\n\t\t\t*****\t\t\t\n\n");
				exit(0);

			default:
				printf("\n\nWrong choice!!\n");

		}

	}

	return EXIT_SUCCESS;

}


