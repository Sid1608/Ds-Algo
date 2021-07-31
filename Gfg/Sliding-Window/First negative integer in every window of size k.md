

### []()
Author:@Siddharth Akar<br>
Problem Statement:


## Approach1

``` cpp
vector<long long> printFirstNegativeInteger(long long int A[],long long int N, long long int K) {
            vector<long long>ans;
            vector<long long>s;
            long long i=0,j=0;
            while(j<N){
                if(A[j]<0)
                    s.push_back(A[j]);
                if(j-i+1<K){
                    j++;
                }
                else if(j-i+1==K){
                    if(s.size()==0)
                        ans.push_back(0);
                    else 
                        ans.push_back(*s.begin());
                    if(A[i]<0)
                        s.erase(s.begin());
                    i++;
                    j++;
                }
            }
            return ans;
 

```

## Approach2

``` cpp

```
## Approach3

``` cpp

```
## Approach4

``` cpp

```
## Approach5

``` cpp

```
