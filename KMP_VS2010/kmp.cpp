//#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


_declspec(dllexport) int kmp(char *target, int tsize, char *pattern, int psize);
static int *compute_prefix_function(char *pattern, int psize); 

int *compute_prefix_function(char *pattern, int psize)
{
	int k = -1;
	int i = 1;
	int *pi = (int *)malloc(sizeof(int)*psize);
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
		//printf("Ini k and psize is : %d  %d\n",k,psize);
		if (k == psize - 1) {
			free(pi);
		//	printf("I- k : %d",i-k);
			return i-k;
		}
	}
	free(pi);
	return -1;
}