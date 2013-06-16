String_search
=============

Optimized algorithm to search string from given string array or long text string with complexity less then O(n)

Here is two algo: Knuth Moore and BM

Step 1: Convert array of string into single string by appending each strings. We can do this by iterating through array.length() times and appending each string by doing str=str.append(S[i]). If the length of string array is p then complexity for this operation is p

Here S is our string that we want to search and str is text string that we get by appending strings of "Array of string". Initially str is initialized by null. Consider length of S is "m" and str is "n".

Step 2: We can use Boyer Moore algorithm to search matching string from str.
Concept of Boyer-Moore's approach is to try to match the last character of the string S instead of the first one with the assumption that if there's not match at the end no need to try to match from the beginning. This allows for big jump of size m for next comparison when miss match occurs. When the string is found then we perform break to exit loop.  See

So the complexity comes to O(n/m). And total complexity O(n/m)+ p.  Which is less then we get using B tree.

Another way is KMP algorithm which search for presence  of string S into main text string "str" by comparing the characters of S from beginning  with characters of string "str" observing that when mismatch occurs. When mismatch occurs we continue comparison by considering first char of S, by passing re-examination of previously matched characters. So in one move of text string "str" we find the matching string. When the string is found then we perform break to exit loop.  See

So complexity is O(n). And total complexity O(n) + p.
There is trade off  between both algorithm depending upon the size of string S but both of them gives better performance compare to B tree
