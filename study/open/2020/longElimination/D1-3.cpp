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

vector <char> z;
vv64 p;
string s;
ll ans = 0;
v64 used;

void dfs(ll v, string sr) {
  used[v] = 1;
  if (sr <= s) ans++;
  for (auto &i : p[v]) if (!used[i]) dfs(i, sr + z[i]);
}

int main() {
  fast_cin();
  
  ll n, m;
  cin >> n >> m;
  cin >> s;
  z.resize(n);
  p.resize(n, v64 (0));
  used.resize(n, 0);
  {
    string s1;
    cin >> s1;
    forn(i,s1.size()) z[i] = s1[i];
  } forn(i, n - 1) {
    ll x;
    cin >> x;
    x--;
    p[i + 1].pb(x);
    p[x].pb(i + 1);
  } forn(i,n) {
    used.assign(n, 0);
    dfs(i, {z[i]});
  } cout << ans << endl;

}
