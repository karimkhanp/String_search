//KMP algorithm which search for presence  of string S into main text string "str" by comparing the characters of S from beginning  with characters of string "str" observing that when mismatch occurs. When mismatch occurs we continue comparison by considering first char of S, by passing re-examination of previously matched characters.
#include "stdafx.h"
#include <stdio.h>
#include "kmp.h"
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[])
{
	char target[200];
	char *ch = target;
	char pattern[20];
	int i,k,count,l;
	printf("\nEnter the string: \n");
	fgets(target,100,stdin);
	printf("Enter the string to be matched: \n");
	fgets(pattern,20,stdin);
	l=strlen(pattern);
	i = kmp(target, strlen(target)-1, pattern, strlen(pattern)-1);
	//printf("I is : %d\n",i);
	if (i == -1)
		puts("False");
	else
		puts("True");
//	getch();
	return 0;
}
