## Min Segment Tree

- Building Segment Tree
- i->2*i, 2*i+1
- n->no of elements
- n=leaft node
- total no of nodes=2*n-1
- array size=2*2^ceil(log2n)-1===4*n+1=>max array size req to build a tree of size N
``` cpp
void buildTree(int si,int ss,int se){
  if(ss==se)
     st[si]=arr[ss];
  int mid=(ss+se)/2;
  buildTree(2*si,ss,mid);
  buildTree(2*si+1,mid+1,se);
  st[si]=min(st[2*si],st[2*si+1]; 
}
```
- Query
- 1. complete overlap, 2.partial overlap, 3.no overlap
``` cpp
int query(int si,int ss,int se,int qs,int qe){
   if(qs>se||qe<ss)
     return INT_MAX;
   if(ss>=qs and se<=qe)
     return st[si];
   int mid=(ss+se)/2;
   int l=query(2*si,ss,mid,qs,qe);
   int r=query(2*si+1,mid+1,se,qs,qe);
   return min(l,r);
  
}

```
- update
- Range update
- point update
```cpp
int update(int si,int ss,int se,int qi){
    if(ss==se){
      st[si]=arr[ss];
      return;
    }
    int mid=(ss+se)/2;
    if(qi<=mid)update(si,ss,mid,qi);
    else update(si,mid+1,se,qi);
}

```

[Help Ashu
](https://www.hackerearth.com/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/practice-problems/algorithm/help-ashu-1/)
``` cpp
//Author:Siddharth Akar	
const int maxN=100001;
//odd->even
pair<int,int>seg[4*maxN];
ll a[maxN];
void buildTree(ll si,ll ss,ll se)
{
    if(ss==se){
        a[ss]%2?seg[si]={1,0}:seg[si]={0,1};
        return;
    }
    ll mid=(ss+se)/2;
    buildTree(2*si,ss,mid);
    buildTree(2*si+1,mid+1,se);
    seg[si]={seg[2*si].F+seg[2*si+1].F,seg[2*si].S+seg[2*si+1].S};
}
ll getEven(ll si,ll ss,ll se,ll qs,ll qe)
{
    if(qs>se||qe<ss)
        return 0;
    if(qs<=ss&&qe>=se)  
        return seg[si].S;
    ll mid=(ss+se)/2;
    ll l=getEven(2*si,ss,mid,qs,qe);
    ll r=getEven(2*si+1,mid+1,se,qs,qe);
    return l+r;
}
ll getOdd(ll si,ll ss,ll se,ll qs,ll qe)
{
    if(qs>se||qe<ss)
        return 0;
    if(qs<=ss&&qe>=se)  
        return seg[si].F;
    ll mid=(ss+se)/2;
    ll l=getOdd(2*si,ss,mid,qs,qe);
    ll r=getOdd(2*si+1,mid+1,se,qs,qe);
    return l+r;
}
void update(ll si,ll ss,ll se,ll node,ll val)
{
    if(se==ss){
        val%2==1?seg[si]={0,1}:seg[si]={1,0};
        a[node]=val;
        return;
    }
    ll mid=(ss+se)/2;
    if(node<=mid)
        update(2*si,ss,mid,node,val);
    else
        update(2*si+1,mid+1,se,node,val);
    seg[si]={seg[2*si].F+seg[2*si+1].F,seg[2*si].S+seg[2*si+1].S};
}
int main() {
    fast;
    ll n,q;
    cin>>n;
    for(ll i=1;i<=n;i++)
        cin>>a[i]; 
    buildTree(1,1,n);        
    cin>>q;
    while(q--){
        ll type,x,y;
        cin>>type;
        if(type==0){
            cin>>x>>y;
            if(a[x]%2==y%2) 
                continue;
            update(1,1,n,x,y);
        }
        else if(type==1){
            cin>>x>>y;
            cout<<getEven(1,1,n,x,y)<<"\n";
        }
        else{
            cin>>x>>y;
            cout<<getOdd(1,1,n,x,y)<<"\n";
        }
    }

    
	return 0;
}

```

## Lazy Propagation
- problem with point update: range update will take o(nlogn) time in worst case using point update
- lazy update is a range update technique which is used for range update in o(logn) time
- lazy: update when only needed
- lazy tree: kind of diary where you keep your pending updates
``` cpp
int ar[maxN];
int st[4*maxN],lazy[4*maxN];
void build(int si,int ss,int se){
    if(ss==se){
      st[si]=ar[ss];
      return;
    }
    int mid=(ss+se)/2;
    build(2*si,ss,mid);
    build(2*si+1,mid+1,se);
    st[si]=st[2*si]+st[2*si+1];
}
int query(int si,int ss,int se,int qs,int qe){
  if(lazy[si]!=0){
    int dx=lazy[si];
    lazy[si]=0;
    st[si]+=dx*(se-ss+1);
    if(ss!=se)
      lazy[2*si]+=dx,lazy[2*si+1]+=dx;
  }
  if(ss>qe || se<qs){
    return 0;
  }
  if(ss>=qs and se<=qe)
    return st[si];
  int mid=(ss+se)/2;
  return query(2*si,ss,mid,qs,qe)+query(2*si+1,mid+1,se,qs,qe);
}
void update(int si,int ss,int se,int qs,int qe,int val){
  if(lazy[si]!=0){
    int dx=lazy[si];
    lazy[si]=0;
    st[si]+=dx*(se-ss+1);
    if(ss!=se)
      lazy[2*si]+=dx,lazy[2*si+1]+=dx;
  }
  if(ss>qe||se<qs){
    return ;
  }
  if(ss>=qs and se<=qe){
    int dx=(se-ss+1)*val;
    st[si]+=dx;
    if(ss!=se){
      lazy[2*si]+=val;
      lazy[2*si+1]+=val;
      return;
    }
    int mid=(ss+se)/2;
    update(2*si,ss,mid,qs,qe,val);
    update(2*si+1,mid+1,se,qs,qe,val);
    st[si]=st[2*si]+st[2*si+1];
  }
}
```
