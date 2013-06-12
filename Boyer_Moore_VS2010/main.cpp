//#include "stdafx.h"
#include <stdio.h>
#include "BM1.h"
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char target[200];
	char *ch = target,*str;
	char pattern[20];
	int i,k,count,l;
	
	printf("Enter the string: \n");
	fgets(target,100,stdin);
	//scanf ("%[^\n]%*c", target);
	printf("Enter the string to be matched: \n");
	fgets(pattern,20,stdin);
	chomp(target);
	chomp(pattern);
	str = BoyerMoore( target, strlen(target)-1, pattern, strlen(pattern)-1 );
	//scanf ("%[^\n]%*c", pattern);
    if (str == NULL)
	puts( "False" );
    else
		puts( "true" );
	   // getch();
	return 0;
}