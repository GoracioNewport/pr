//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
//#pragma GCC optimize("unroll-loops")
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

struct Tree {
    v64 t, a;
    ll n;

    Tree (v64& _a) {
      a = _a;
      n = sz(a);
      t.assign(4 * n, INF);
      build(0, 0, n);
    }

    void build(ll v, ll l, ll r) {
      if (l + 1 == r) {
        t[v] = a[l];
        return;
      } ll m = (l + r) / 2;
      build(2 * v + 1, l, m);
      build(2 * v + 2, m, r);
      t[v] = min(t[2 * v + 1], t[2 * v + 2]);
    }

    ll findR(ll v, ll l, ll r, ll L, ll R, ll x) { // Возвращает минимальный r такой, что a[r] < x; INF если такого нет
      if (l >= R || r <= L || t[v] >= x) return n;
      if (l + 1 == r) {
        if (a[l] < x) return l;
        else return n;
      } ll m = (l + r) / 2;


      if (t[2 * v + 1] < x) {
        ll ansL = findR(2 * v + 1, l, m, L, R, x);
        if (ansL == n) return findR(2 * v + 2, m, r, L, R, x);
        else return ansL;
      } else return findR(2 * v + 2, m, r, L, R, x);
    }


};

int main() {
  fast_cin();

  ll t;
  cin >> t;
  while(t--) {
    ll n, s;
    cin >> n >> s;
    v64 q(n);
    for (auto& i : q) cin >> i;

    v64 a(n);
    a[0] = q[0];
    for(ll i = 1; i < n; i++) a[i] = a[i - 1] + q[i];

//    for (auto& i : a) cout << i << ' ';
//    cout << ln << ln;

    Tree tree(a);
    p64 ans = {0, -1};
    forn(i,n) {
      ll x = tree.findR(0, 0, n, i, n, -s + (i == 0 ? 0 : a[i - 1]));
//      cout << i << ' ' << x << ln;
//      cout << -s + (i == 0 ? 0 : a[i - 1]) << ln;
      ans = max(ans, {x - i, i});
    } if (ans.fi > 0) cout << ans.se + 1 << ' ' << ans.se + ans.fi << ln;
    else cout << -1 << ln;
  }

}


//1
//9 17
//8 -14 -7 -3 -3 3 10 -16 -5

// ANS : 3 8