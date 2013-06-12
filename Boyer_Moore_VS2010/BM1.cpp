#include <stdio.h>
#include <stdlib.h>
#include <string.h>

_declspec(dllexport) void chomp(char *s);
_declspec(dllexport) char *BoyerMoore(  char *data,  int dataLength,  char *string, int strLength );

char *BoyerMoore(  char *data,  int dataLength,  char *string,  int strLength )
{
     int skipTable[256], i;
     char *search;
    register  char lastChar;

    if (strLength == 0)
	return NULL;

    // Initialize skip lookup table
    for (i = 0; i < 256; i++)
	skipTable[i] = strLength;

    search = string;

    // Decrease strLength here to make it an index
    i = --strLength;

    do
    {
	skipTable[*search++] = i;
    } while (i--);

    lastChar = *--search;

    // Start searching, position pointer at possible end of string.
    search = data + strLength;
    dataLength -= strLength+(strLength-1);

    while ((int)dataLength > 0 )
    {
	 int skip;

	skip = skipTable[*search];
	search += skip;
	dataLength -= skip;
	skip = skipTable[*search];
	search += skip;
	dataLength -= skip;
	skip = skipTable[*search];

	if (*search != lastChar) /*if (skip > 0)*/
	{
	    // Character does not match, realign string and try again
	    search += skip;
	    dataLength -= skip;
	    continue;
	}

	// We had a match, we could be at the end of the string
	i = strLength;

	do
	{
	    // Have we found the entire string?
	    if (i-- == 0)
		return search;
	} while (*--search == string[i]);

	// Skip past the part of the string that we scanned already
	search += (strLength - i + 1);
	dataLength--;
    }

    // We reached the end of the data, and didn't find the string
    return NULL;
}

void chomp(char *s) {
    int n = strlen(s);
    while (n && (s[n-1]==10 || s[n-1]==13)) s[--n] = 0;
	//return 0;
}
