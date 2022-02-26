// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

// Author: @GoracioNewport

using namespace std;

typedef int ll;
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

ll n, q;

vector <vector <pair <p64, ll>>> mul;
vv64 p;
vp64 closest;
v64 cnt, per, num, ans, pos;

void addX(ll x) {

//  cerr << "ADD " << x << ln;

  ll i = pos[x];
  ll j = closest[cnt[x]].se;

//  cerr << i << ' ' << j << ln;

  swap(per[i], per[j]);
  swap(pos[per[i]], pos[per[j]]);
  closest[cnt[x]].se--;
  closest[cnt[x] + 1].fi--;
  cnt[x]++;

//  for (auto& i : per) cerr << i << ' ';
//  cerr << ln << ln;
}

void subX(ll x) {

//  cerr << "SUB " << x << ln;

  ll i = pos[x];
  ll j = closest[cnt[x]].fi;

  swap(per[i], per[j]);
  swap(pos[per[i]], pos[per[j]]);
  closest[cnt[x]].fi++;
  closest[cnt[x] - 1].se++;
  cnt[x]--;

//  for (auto& i : per) cerr << i << ' ';
//  cerr << ln << ln;
}

void getAns(ll x, ll k, ll ansInd) {

//  cerr << "GET ANS " << x << ' ' << k << ' ' << ansInd << ' ' << closest[x].fi << ln << ln;

  if (closest[x].fi + k < n) ans[ansInd] = per[closest[x].fi + k] + 1;
  else ans[ansInd] = -1;
}

void dfs(ll v) {
  addX(num[v]);
  for (auto& i : mul[v]) {
    getAns(i.fi.fi, i.fi.se, i.se);
  } for (auto& u : p[v]) dfs(u);
  subX(num[v]);
}

int main() {
  fast_cin();

  ll t;
  cin >> t;
  while(t--) {
    cin >> n >> q;

    mul.clear();
    closest.clear();
    p.clear();
    cnt.clear();
    per.clear();
    num.clear();
    ans.clear();
    pos.clear();

    mul.resize(n, vector <pair <p64, ll>> ());
    p.resize(n, v64());
    closest.resize(n + 1, {n, n - 1});
    closest[0] = {0, n - 1};
    cnt.resize(n + 1);
    per.resize(n);
    iota(all(per), 0);
    num.resize(n);
    ans.resize(q);
    pos.resize(n);
    forn(i,n) pos[i] = i;

//    cerr << "ININTIAL: " << ln;
//    for (auto & i : per) cerr << i << ' ';
//    cerr << ln << ln;

    for (auto& i : num) {
      cin >> i;
      i--;
    }

    forn(i,n - 1) {
      ll x; cin >> x; x--;
      p[x].pb(i + 1);
    } forn(i,q) {
      ll v, l, k;
      cin >> v >> l >> k; v--; k--;
      mul[v].pb({{l, k}, i});
    }

    dfs(0);

    for (auto& i : ans) cout << i << ' ';
    cout << ln;


  }

}