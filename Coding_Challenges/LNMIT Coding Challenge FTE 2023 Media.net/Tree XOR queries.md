https://leetcode.com/discuss/interview-question/820311/tree-xor-queries
``` cpp
You are given a tree with A nodes and A-1 edges which is rooted at 1.
There are C queries and for each query you are given two integers d (the node number) and
e and you have to find the maximum value when e is xor'ed with any of the ancestors of d or
d itself.
Formally, find the maximum value which can be obtained when e is XOR'ed with any node in
the path from d to root. XOR is bitwise XOR operator.

2 <= A <= 100000
1 <= C <= 300000
1 <= D[i] <= A — node number d
1 <= E[i] <= 300000 — the number to be XOR'ed 


A = 8
B = [1, 1, 2, 2, 3, 3, 1]
C = 5
D = [2, 3, 5, 6, 8]
E = [1, 1, 5, 4, 10]
[3, 2, 7, 7, 11]
```
