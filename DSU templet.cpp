#include <bits/stdc++.h>
using namespace std;
class disjoint{
   vector<int>rank,parent;
   public:
   disjoint(int n){
    rank.resize(n+1,0);
    parent.resize(n+1);
    for(int i=0;i<n;i++){
        parent[i]=i;
    }
   }
   int findparent(int node){
      if(node==parent[node])return node;
      else{
        return parent[node]=findparent(parent[node]);
      }
   } 
   void unionbyrank(int u,int v){
     int u_u=findparent(u);
     int u_v=findparent(v);
     if(u_u==u_v)return;
     if(rank[u_u]>rank[u_v]){
        parent[u_v]=u_u;
     }else if(rank[u_u]<rank[u_v]){
        parent[u_u]=u_v;
     }else{
        parent[u_v]=u_u;
        rank[u_u]++;
     }       
   }

};
int main() {
	disjoint ds(7);
    ds.unionbyrank(1,2);
    ds.unionbyrank(2,3);
    ds.unionbyrank(4,5);
    ds.unionbyrank(6,7);
    ds.unionbyrank(5,6);
    if(ds.findparent(1)==ds.findparent(7)){
        cout<<"Haa bhaii"<<endl;
    }else{
        cout<<"Na bhaii"<<endl;
    }
    ds.unionbyrank(3,7);
    if(ds.findparent(1)==ds.findparent(7)){
        cout<<"Haa bhaii"<<endl;
    }else{
        cout<<"Na bhaii"<<endl;
    }
}
