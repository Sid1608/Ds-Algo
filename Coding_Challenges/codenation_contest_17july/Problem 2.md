``` cpp
You are given a string A, which only consists of characters 'R' and 'G'. 
You need to pick 4 elements such that they form a good subsequence. 
A good subsequence is defined as substrings in which there are 2 'G' followed by 2 'R' or vice versa, namely "RRGG" or "GGRR". 
You need to find the number of ways in which you can get good subsequences from the string.

1 <= |A| <= 10^6

Input consists of the string A.

```

``` cpp
 Solution :

We store the number of 'G' characters and 'R' characters in a suffix. 
Then we start iterating from the front side of the string and keep a count of the number of 'G' and 'R' till any point.
If the current element is 'R', then we add to answer the number of characters 'R' occuring after the current element multiplied by the number of ways we can choose 2 'G' characters from the previous part. 
This essentially means that we calculate the number of "GGRR" subsequences, in which we fix the position of the first 'R' and then calculate the current answer for it and add it to the final answer. 
Similarly we can calculate the number of "RRGG" subsequences.

```
