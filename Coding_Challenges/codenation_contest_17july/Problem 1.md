``` cpp
You are given an array A with N elements, not necessarily distinct. 
You can swap any element with any other element, and you have to answer the number of ways in which you can get a good array.
A good array is defined as an array for which A[1] > A[N], (1-indexed). 
Note that if there are two arrays with same A[1] and A[N], and the other elements are different,
then both the arrays are considered same.

1 <= N <= 10^4

1 <= A[i] <= 10^5

Input consists of N and the array A.
```

```
Solution : 

The simple solution is to count the number of distinct elements in the array, 
lets denote it by p, then the answer is C(p, 2) = p*(p-1)/2.

```
