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

int main() {
  fast_cin();
  
  ll t;
  cin >> t;
  while(t--) {
    ll a, b, k;
    cin >> a >> b >> k;
    vp64 ks(k);
    for (auto &i : ks) cin >> i.fi;
    for (auto &i : ks) cin >> i.se;

    v64 an(a, 0);
    v64 bn(b, 0);

    forn(i,k) {
      ll x = ks[i].fi - 1;
      ll y = ks[i].se - 1;
      an[x]++;
      bn[y]++;
    } ll c = 0;
    // for (auto &i : an) cout << i << ' ';
    // cout << endl;
    // for (auto &i : bn) cout << i << ' ';
    // cout << endl;
    for(auto &i : an) {
      if (i > 1) c += (i * (i - 1)) / 2;
    } for(auto &i : bn) {
      if (i > 1) c += (i * (i - 1)) / 2;
    } 
    
    // cout << ((k * (k - 1)) / 2) << ' ' << c << ln;
    
    cout << ((k * (k - 1)) / 2) - c << ln;
  }

}
