#include <bits/stdc++.h>
using namespace std;

long long lcm(long long a,long long b){
  return (a*b)/__gcd(a,b);
}
void solve() {
    long long n;
    cin>>n;
    long long a=1;
    long long b=n-1;
    long long ans=(a*b)/__gcd(a,b);
    for(long long i=2;i*i<=n;i++){
      if(n%i==0){
        long long temp=lcm(i,n-i);
        if(temp<ans){
          ans=temp;
          a=i;
          b=n-i;
        }if(n/i!=i){
          temp=lcm(n/i,n- n/i);
          if(temp<ans){
            ans=temp;
          a=n/i;
          b=n-n/i;
          }
        }
      }
    }
    cout<<a<<" "<<b<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
