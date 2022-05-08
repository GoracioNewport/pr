#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 1791791791;
double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

p64 findDate(ll n, ll m) {
  for (int i = 2; i <= m; i++) {
    for (int j = 1; j < i; j++) {
      n--;
      if (n == 0) return {i, j};
    }
  } return {0, 0};
}

int main() {
  fast_cin();
  
  ll n = 1;
  while (true) {
    ll k = n;
    ll t = 1;
    pair <ll, p64> ans = {-1, {-1, -1}};
    for (int i = 3; i <= 12; i++) {
      for (int j = 2; j < i; j++) {
        for (int z = 1; z < j; z++) {
          k--;
          if (k == 0) {
            ans = {i, {j, z}};
            // cout << "ok" << i << j << z << endl;
            break;
          }
        } if (k == 0) break;
      } if (k == 0) break;
    } if (ans.fi == -1) {
      ans.fi = (k / 66) + 13;
      if (k % 66 == 0) {
        ans.fi--;
        ans.se = {12, 11};
      } else {
        ans.se = findDate(k % 66, 12);
      }
    }

    pair <ll, p64> ans1 = {-1, {-1, -1}};
    t = n;

    for (int i = 3; i < 1e9; i++) {
      for (int j = 2; j < min(i, 13); j++) {
        for (int k = 1; k < min(j, 12); k++) {
          t--;
          if (t == 0) {
            ans1 = {i, {j, k}};
            break;
          } 
        } if (t == 0) break;
      } if (t == 0) break;
    } if (ans != ans1) {
      cout << "COUNTER TEST FOUND " << n << endl;
      break;
    }
    n++;
  }  

}
