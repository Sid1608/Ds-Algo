class DSU{
public:
    vector<int>parent(n,0);
    vector<int>rank(n,0);
    for(int i=0;i<n;i++)parent[i]=i;
    int Find(int node,vector<int>&parent){
        if(node==parent[node])
            return node;
        return parent[node]=Find(parent[node],parent);
    }
    void Union(int u,int v,vector<int>&parent,vector<int>&rank){
        int a=Find(u,parent);
        int b=Find(v,parent);
        if(rank[a]>rank[b])
            parent[b]=a;
        else if(rank[a]<rank[b])
            parent[a]=b;
        else{
            parent[a]=b;
            rank[a]++;
        }
        
    }
    
};