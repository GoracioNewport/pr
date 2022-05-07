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

ll reqB = 0, reqS = 0, reqC = 0, havB, havS, havC, priB, priS, priC, r;

bool ok(ll x) {
  ll rB = reqB * x;
  ll rS = reqS * x;
  ll rC = reqC * x;
  return (r >= ((max((ll)0, rB - havB) * priB) + (max((ll)0, rS - havS) * priS) + (max((ll)0, rC - havC) * priC)));
}

int main() {
  fast_cin();
  
  string s;
  cin >> s;  
  for(auto &i : s) {
    if (i == 'B') reqB++;
    else if (i == 'S') reqS++;
    else reqC++;
  } cin >> havB >> havS >> havC >> priB >> priS >> priC >> r;

  ll l = 0;
  ll r = 2e14;
  while (l + 1 < r) {
    ll m = (l + r) / 2;
    if (ok(m)) l = m;
    else r = m; 
  } cout << l << endl;

}
