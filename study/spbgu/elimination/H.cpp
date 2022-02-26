//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

// Author: @GoracioNewport
  
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
#define INF (ll)2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

struct Node {
  ll add, min;
};

struct Tree {
  vector <Node> t;
  ll n;

  Tree (ll _n) {
    n = _n;
    t.assign(4 * n, {0, 0});
  }

  void addX(ll v, ll l, ll r, ll L, ll R, ll x) {
    if (l >= L && r <= R) {
      t[v].add += x;
      t[v].min += x;
      return;
    } if (l >= R || r <= L) return;
    ll m = (l + r) / 2;
    addX(2 * v + 1, l, m, L, R, x);
    addX(2 * v + 2, m, r, L, R, x);
    t[v].min = min(t[2 * v + 1].min, t[2 * v + 2].min) + t[v].add;
  }

  ll getMin(ll v, ll l, ll r, ll L, ll R) {
    if (l >= L && r <= R) return t[v].min;
    if (l >= R || r <= L) return INF;
    ll m = (l + r) / 2;
    return min(getMin(2 * v + 1, l, m, L, R), getMin(2 * v + 2, m, r, L, R)) + t[v].add;
  }
};

int main() {
  fast_cin();

  ll t;
  cin >> t;
  while(t--) {
  	ll n;
  	cin >> n;
  	v64 a(n);
  	for (auto& i : a) cin >> i;

    if (n == 0) {
      cout << a[0] << ln;
      return 0;
    }

  	v64 d = {0};
  	partial_sum(all(a), back_inserter(d));

  	v64 dp(n + 1, INF);
  	dp[0] = INF;

    ll minDp = dp[0];

    Tree tree(n + 1);

  	forn(i,n) {

      tree.addX(0, 0, n + 1, 0, i + 1, a[i]);

//  		for (ll j = 0; j <= i; j++) dp[i + 1] = min(dp[i + 1], min(dp[j], d[i + 1] - d[j]));

      dp[i + 1] = min(minDp, tree.getMin(0, 0, n + 1, 0, i + 1));

      minDp = min(minDp, dp[i + 1]);
    } cout << dp.back() << ln;

  }

}
