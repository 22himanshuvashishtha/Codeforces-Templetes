#include <bits/stdc++.h>
using namespace std;

#define int long long
const int n=1e7;


void solve() {
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
      v[i]=i;
    }
    for(int i=2;i*i<=n;i++){
      if(v[i]==i){
        for(int j=i*i;j<=n;j+=i){
          if(v[j]==j){
            v[j]=i;
          }
        }
      }
    }
    for(auto it:v){
      cout<<it<<" ";
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //int t;
    //cin >> t;
    //while (t--) 
    solve();

    return 0;
}
