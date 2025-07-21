#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin>>n;
    vector<int>fact;
    for(int i=2;i*i<=n;i++){
      if(n%i==0){
        while(n%i==0){
          fact.push_back(i);
          n/=i;  
        }
        
      }
    }
    if(n>1){
      fact.push_back(n);
    }
    for(auto it:fact){
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
