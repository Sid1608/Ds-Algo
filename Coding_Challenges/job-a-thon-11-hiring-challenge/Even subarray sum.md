<img width="953" alt="image" src="https://user-images.githubusercontent.com/57083596/180362163-9b6bab18-8914-4dce-b06f-baa7cf2cf0b5.png">

``` cpp
class Solution {
    public:
    string solve(int n, vector<int> &a){
        // code here
        int x=a[0],f=1;;
        x*=-1;
        for(int i=1;i<n;i++){
            if(a[i]!=x){
                f=0;
                break;
            }
            x*=-1;
        }
        if(f){
            return "YES";
        }else{
            return "NO";
        }
        
    }
};

```
