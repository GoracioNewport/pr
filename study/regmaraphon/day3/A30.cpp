#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll gcd(ll a, ll b) {
  if (b == 0) return a;
  else return gcd(b, a % b);
}

int main() {
  ll n;
  cin >> n;
  vector <ll> a(n);
  for(auto &i : a) cin >> i;
  ll q;
  cin >> q;
  for(int z = 0; z < q; z++) {
    ll l, r;
    cin >> l >> r;
    
  }
}