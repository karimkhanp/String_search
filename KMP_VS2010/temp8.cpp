// temp7.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include "kmp.h"
#include <string.h>

int main(int argc, const char *argv[])
{
	char target[]="My name is khan";
	char *ch = target;
	char pattern[]="name";
	int i,k,count,l;
//	printf("\nEnter the string: \n");
	//fgets(target,100,stdin);
//	printf("Enter the string to be matched: \n");
	//fgets(pattern,20,stdin);
	l=strlen(pattern);
	i = kmp(target, strlen(target)-1, pattern, strlen(pattern)-1);
	//printf("I is : %d\n",i);
	if (i == -1)
		puts("False");
	else
		puts("True");
	getch();
	return 0;
}

