#ifndef MYHEADER_H
#define LOGIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

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

struct User * dataProcess();
int processFunc();
void datadisplay(struct User *);
void signUp();
void logIn();
void billingFunc(struct User *);
void userDataDisplay(struct User *);
void operatorDataDisplay(struct User *);
int usPassCheck(char [],char []);

#endif
