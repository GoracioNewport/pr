// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")
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
  forn(z,t) {
    ll a;
    cin >> a;
    string s = to_string(a);
    set <ll> d;
    for (int i = 0; i < sz(s); i++) {
      if (s[i] != '0') d.insert(-(s[i] - '0'));
    } map <ll, ll> ds;
    for (auto &i : d) {
      if (i == -4) {
        if (ds[2] == 0) ds[2] += 2;
        else if (ds[2] == 1) ds[2]++;
      } else if (i == -6) {
        if (ds[2] == 0) ds[2]++;
        if (ds[3] == 0) ds[3]++;
      } else if (i == -8) {
        ds[2] += 3;
      } else if (i == -9) {
        ds[3] += 2;
      } else if (i == -2) {
        if (ds[2] == 0) ds[2]++;
      } else if (i == -3) {
        if (ds[3] == 0) ds[3]++;
      } else ds[-i]++;
    } ll mul = 1;
    for (auto &i : ds) if (i.se != 0) mul *= (pow(i.fi, i.se));
    for (auto &i : ds) cout << i.fi << ' ' << i.se << endl;
    cout << mul << endl;
    if (a % mul != 0) cout << ((a / mul) * (mul)) + mul << endl;
    else cout << a << endl;
    
  }  

}
