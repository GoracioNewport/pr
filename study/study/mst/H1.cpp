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

ll n, m, k;
v64 p;
v64 r;


struct Query {
  string type;
  ll v;
  ll u;
};

void init() {
  p.resize(n);
  r.resize(n, 0);
  forn(i, n) p[i] = i;
}

ll findP(ll v) {
  return (p[v] == v) ? v : p[v] = findP(p[v]);
}

void unionSet(ll a, ll b) {
  a = findP(a);
  b = findP(b);
  if (a == b) return;
  if (r[a] > r[b]) swap(a, b);
  if (r[a] == r[b]) r[b]++;
  p[a] = b;
}

int main() {
  fast_cin();
  cin >> n >> m >> k;
  vector <Query> q(k);
  forn(i, m) {
    ll a, b;
    cin >> a >> b;
  } for (auto &i : q) {
    cin >> i.type >> i.v >> i.u;
    i.v--;
    i.u--;
  } reverse(q.begin(), q.end());
  init();
  vector <string> ans;
  for (auto &i : q) {
    // cout << i.v << ' ' << i.u << endl;
    if (i.type == "cut") {
      unionSet(i.u, i.v);
    } else {
      if (findP(i.u) == findP(i.v)) {
        ans.pb("YES");
      } else ans.pb("NO");
    }
  } reverse(ans.begin(), ans.end());
  for (auto &i : ans) cout << i << ln;

}
