// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

// Author: @GoracioNewport

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

vv64 p;
v64 used;

void dfs(ll v, ll c) {
  used[v] = c;
  for (auto &i : p[v]) if (used[i] > (c + 1) || used[i] == -1) dfs(i, c + 1);
}

int main() {
  fast_cin();

  ll n;
  cin >> n;
  set <string> ss;
  map <string, ll> m;
  vector <string> indToName(n * 3);
  p.resize(n * 3, v64());
  used.resize(n * 3, -1);
  ll ind = 0;
  forn(i,n) {
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    ll i1, i2, i3;
    ll siz = sz(ss);
    ss.insert(s1);
    if (siz != sz(ss)) {
      i1 = ind;
      m[s1] = ind++;
    } else i1 = m[s1];

    siz = sz(ss);
    ss.insert(s2);
    if (siz != sz(ss)) {
      i2 = ind;
      m[s2] = ind++;
    } else i2 = m[s2];

    siz = sz(ss);
    ss.insert(s3);
    if (siz != sz(ss)) {
      i3 = ind;
      m[s3] = ind++;
    } else i3 = m[s3];
    p[i1].pb(i2);
    p[i1].pb(i3);
    p[i2].pb(i1);
    p[i2].pb(i3);
    p[i3].pb(i1);
    p[i3].pb(i2);
  } for (auto &i : m) indToName[i.se] = i.fi;
  if (m.find("Isenbaev") != m.end()) {
    ll start = m["Isenbaev"];
    dfs(start, 0);
  } vector <pair <string, ll>> ans;
  for (auto &i : ss) {
    ll j = m[i];
    ans.pb({i,used[j]});
  } for (auto &i : ans) {
    cout << i.fi << ' ';
    if (i.se == -1) cout << "undefined";
    else cout << i.se;
    cout << ln;
  }


}