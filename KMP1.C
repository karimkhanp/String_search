//KMP algorithm which search for presence  of string S into main text string "str" by comparing the characters of S from beginning  with characters of string "str" observing that when mismatch occurs. When mismatch occurs we continue comparison by considering first char of S, by passing re-examination of previously matched characters. 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *compute_prefix_function(char *pattern, int psize)
{
	int k = -1;
	int i = 1;
	int *pi = malloc(sizeof(int)*psize);
	if (!pi)
		return NULL;

	pi[0] = k;
	for (i = 1; i < psize; i++) {
		while (k > -1 && pattern[k+1] != pattern[i])
			k = pi[k];
		if (pattern[i] == pattern[k+1])
			k++;
		pi[i] = k;
	}
	return pi;
}

int kmp(char *target, int tsize, char *pattern, int psize)
{
	int i;
	int *pi = compute_prefix_function(pattern, psize);
	int k = -1;
	if (!pi)
		return -1;
	for (i = 0; i < tsize; i++) {
		while (k > -1 && pattern[k+1] != target[i])
			k = pi[k];
		if (target[i] == pattern[k+1])
			k++;
		if (k == psize - 1) {
			free(pi);
		//	printf("I- k : %d",i-k);
			return i-k;
		}
	}
	free(pi);
	return -1;
}

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
	i = kmp(target, strlen(target), pattern, strlen(pattern));
	if (i >= 0)
		printf("matched @: %s\n", ch + i);
	getch();
	return 0;
}
