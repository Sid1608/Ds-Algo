

### []()
Author:@Siddharth Akar<br>
Problem Statement:


## Approach1

``` cpp
bool cmp(vector<int>a,vector<int>b){
    return a[2]<b[2];
}
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	int find(int node,vector<int>& parent){
	    if(parent[node]==node)
	        return node;
	    return parent[node]=find(parent[node],parent);
	    
	}
	void Union(int u,int v,vector<int>&parent,vector<int>& rank){
	    int a=find(u,parent);
	    int b=find(v,parent);
	    if(rank[a]>rank[b]){
	        parent[b]=a;
	    }
	    else if(rank[a]<rank[b]){
	        parent[a]=b;
	    }
	    else{
	        parent[a]=b;
	        rank[b]++;
	    }
	    
	}
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<vector<int>>list;
        for(int i=0;i<V;i++){
            for(vector<int>x:adj[i]){
                if(x[0]>i){
                vector<int>temp={i,x[0],x[1]};
                list.push_back(temp);
                }
            }
            
        }
        // cout<<V;
        sort(list.begin(),list.end(),cmp);
        vector<int>parent(V);
        for(int i=0;i<V;i++)
            parent[i]=i;
        vector<int>rank(V,0);
        int cost=0;
        for(int i=0;i<list.size();i++){
            if(list[i].size()==3){
                int u=list[i][0];
                int v=list[i][1];
                int wt=list[i][2];
                // cout<<u<<" "<<v<<" "<<wt<<endl;
                if(find(u,parent)!=find(v,parent)){
                    cost+=wt;
                    Union(u,v,parent,rank);
                }
            }
        }
        return cost;
        
        
        
        
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
