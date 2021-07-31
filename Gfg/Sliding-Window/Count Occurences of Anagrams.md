

### []()
Author:@Siddharth Akar<br>
Problem Statement:

author:@siddharth akar
	time complexity:o(n*k)
	space complexity:o(K)
## Approach1

``` cpp
class Solution{
public:
	int search(string pat, string txt) {
	    int k=pat.size();
	    int h[26]={0};
	    for(int i=0;i<k;i++){
	        h[pat[i]-'a']++;
	    }
	    int i=0,j=0,cnt=0;
	    while(j<txt.size()){
	        h[txt[j]-'a']--;
	        if(j-i+1<k)
	            j++;
	        else if(j-i+1==k){
	            int flag=0;
	            for(int k=0;k<26;k++){
	                if(h[k]!=0){
	                    flag=1;
	                    break;
	                }
	            }
	            if(flag==0)
	                cnt++;
	            h[txt[i]-'a']++;
	            i++,j++;
	        }
	    }
	    return cnt;
	}

};

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
