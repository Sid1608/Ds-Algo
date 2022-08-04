# Graphs



### Bridges
- If two nodes lie on the same path from root to some leaf then node having lower in time is ancestor and one having higher in time is decendent.
- low time indicates for each node what is the lowest acestor which can be reached directly from that node.
- for bridges low time is greater then equal to in time. if its smaller it will indicate that the node is connectece to the ancestor of even it parent even if we 
remove the graph will not disconnect.
- we will also minimise low of parent as if child can reach the minimum then parent can also reach that minimum
``` cpp
void dfs(int node,int par){
  vis[node]=1;
  in[node]=low[node]=timer++;
  for(int child:ar[node]){
    if(child==par)continue;
    if(vis[child]){
      //edge node: child is back edge
      low[node]=min(low[node],in[child]);
    }else{
      //edge node child is a forward edge
       dfs(child,node);
       if(low[child]>in[node]){
          cout<<node<<" -> "<<child<<"is a bridge\n";
       }
       low[node]=min(low[node],low[child]);
    }
  }
}
```
### Articulation Point (Cut Vertex) O(N+M) N->No of vertices in the graph M->no of edges in the graph
[codeforces](https://codeforces.com/blog/entry/68138)
[cp algorithm](https://cp-algorithms.com/graph/cutpoints.html)


``` cpp
void dfs(int node,int p=-1){
  vis[node]=1;
  in[node]=low[node]=timer++;
  int children=0;
  for(int child:ar[node]){
    if(child==p)continue;
    if(vis[child]){
      //edge node: child is back edge
      low[node]=min(low[node],in[child]);
    }else{
      //edge node child is a forward edge
       dfs(child,node);
       if(low[child]>=in[node] and p!=-1){
          cout<<node<<" -> "<<child<<"is a ap\n";
       }
       low[node]=min(low[node],low[child]);
       children++;
    }
  }
  if(p==-1 and children>1)
    cout<<"node is ap";
}
```

### Topological Sorting
