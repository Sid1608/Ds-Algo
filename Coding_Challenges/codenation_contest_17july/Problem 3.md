``` cpp
You are a fruitshop owner and you have A fruits each with different size, denoted by array B. You also have a special essence with which you attract customers. You can use the essence on any number of fruits. You need to find the minimum number of fruits on which you have to use the essence so that the following conditions hold:

If you have used the essence on the ith fruit, then you have to use it on all fruits having size greater than the ith fruit.

There must be atleast one subarray(contiguous) of length atleast C, such that the number of fruits having essence is greater than the number of fruits not having essence in that subarray.

1 <= A <= 10^5

1 <= B[i] <= A

1 <= C <= A

The input consists of A, the array B and an integer C.

```

``` cpp
The idea is to use binary search on the minimum size of fruit to get the answer. 
This works because if we apply essence to that fruit, then all other fruits having size greater than them will be applied with essence, so we need to find the maximum among all such minimums. To check whether this works or not we can apply another binary search on the length of segment to find the maximum segment for which the 2nd condition holds and check whether that length is greater than or equal to C or not. We can do this using a prefix array in which we store 1 for the values which have value greater than or equal to the current fruit size in binary search and -1 for the others. If there is some segment for which the sum is greater than 0 for the current length, then we can check if it works for some greater length or not. If the final length is greater than or equal to C, we check if it is possible to do the same thing with some greater fruit size or not. 
So the final answer for the fruit size will give us the answer.
```

``` cpp
Binary search on fruit size:
  build an array with 1s(for indices having elements greater than or equal to current fruit size) and -1s(for others)
  Binary search on length:
    check for every index if there exists an index such that the sum of that subarray is greater than 0 and the second index is atleast (current length) distance away from the first index.
    return maximum length for which the 2nd condition holds.
  Check whether maximum length returned is greater than or equal to C or not, if yes, try to increase the fruit size, else decrease it.
return final fruit size

```
