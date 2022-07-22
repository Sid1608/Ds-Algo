![image](https://user-images.githubusercontent.com/57083596/180362638-fe21be6b-f1a6-4cd1-b13d-4257e1a05e91.png)

- use helicopter only when going from 1-n because if we use in between extra cost will get added.
- ans would be min(a[1]+a[n]+X,dijkstra shortest path);
- time complexity: nlogn for dijkastra
- try to use set as priority takes slighlty more time than set


``` cpp
class Solution {
  public:
    long long minimumCost(int N, int M, int X, vector<int> &A,
                          vector<vector<int>> &B) {
        // code here
        long long cost=A[0]+A[N-1]+X;
        vector<int>adj[N];
        for(auto e:B){
            adj[e[0]-1].push_back(e[1]-1);
            adj[e[1]-1].push_back(e[0]-1);
        }
        set<pair<long long,int>>s;
        vector<long long>dist(N+1,1e18);
        vector<int>vis(N,0);
        dist[0]=0;
        s.insert({0,0});
        return dist[N];
        while(!s.empty()){
            auto x=*s.begin();
            long long d=x.first;
            int node=x.second;
            
            for(auto child:adj[node]){
                if(d+A[child]+A[node]<dist[child]){
                    s.erase({dist[child],child});
                    dist[child]=d+A[child]+A[node];
                    s.insert({dist[child],child});
                }
            }
        }
        cost=min(cost,dist[N-1]);
        return cost;
        
        
    }
};

```
