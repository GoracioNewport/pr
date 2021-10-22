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

struct block {
  ll ans = -INF, pref, suf, len; // Максимальная длина нулей подряд в блоке, максимальный префикс и суффикс, длинна блока
};

bool DEBUG = false;

block merge(block a, block b) {

  if (DEBUG) {
    cout << "Merging: " << ln;
    cout << a.len << ' ' << a.ans << ' ' << a.pref << ' ' << a.suf << ln;
    cout << b.len << ' ' << b.ans << ' ' << b.pref << ' ' << b.suf << ln;
  }

  if (a.ans == -INF) {
    if (DEBUG) cout << "Return b" << ln;
    return b;
  }
  if (b.ans == -INF) {
    if (DEBUG) cout << "Return a" << ln;
    return a;
  }

  block c;

  c.len = a.len + b.len;

  if (a.pref == a.len) c.pref = a.pref + b.pref;
  else c.pref = a.pref;

  if (b.suf == b.len) c.suf = b.suf + a.suf;
  else c.suf = b.suf;

  c.ans = max(a.ans, b.ans);
  c.ans = max(c.ans, c.pref);
  c.ans = max(c.ans, c.suf);
  c.ans = max(c.ans, a.suf + b.pref);
  if (DEBUG) cout << "Return: " << c.len << ' ' << c.ans << ' ' <<  c.pref << ' ' << c.suf << ln;

  return c;
}

struct Tree {
    ll n;
    v64 a;
    vector <block> t;

    Tree (v64& _a) {
      a = _a;
      n = sz(a);
      t.assign(4 * n, {0, 0, 0, 1});
      build(0, 0, n);
    }

    void build(ll v, ll l, ll r) {
      if (l + 1 == r) {
        t[v].len = 1;
        if (a[l] == 0) t[v].ans = t[v].pref = t[v].suf = 1;
        else t[v].ans = t[v].pref = t[v].suf = 0;
        return;
      } ll m = (l + r) / 2;
      build(2 * v + 1, l, m);
      build(2 * v + 2, m, r);
      t[v] = merge(t[2 * v + 1], t[2 * v + 2]);
    }

    void setX(ll v, ll l, ll r, ll i, ll x) {
      if (l + 1 == r) {
        a[l] = x;
        if (a[l] == 0) t[v].ans = t[v].pref = t[v].suf = 1;
        else t[v].ans = t[v].pref = t[v].suf = 0;
        return;
      } ll m = (l + r) / 2;
      if (i < m) setX(2 * v + 1, l, m, i, x);
      else setX(2 * v + 2, m, r, i, x);
      t[v] = merge(t[2 * v + 1], t[2 * v + 2]);
    }

    block getAns(ll v, ll l, ll r, ll L, ll R) {

//      {
//        cout << "CUR BLOCK: " << l << ' ' << r << ln;
//        cout << t[v].ans << ' ' << t[v].
//      }

      if (l >= L && r <= R) return t[v];
      if (l >= R || r <= L) {
        block c;
        c.ans = -INF;
        c.len = 0;
        return c;
      } ll m = (l + r) / 2;
      return merge(getAns(2 * v + 1, l, m, L, R), getAns(2 * v + 2, m, r, L, R));
    }
};

int main() {
  fast_cin();

  ll n;
  cin >> n;
  v64 a(n);
  for (auto &i : a) cin >> i;
  Tree tree(a);
  ll q;
  cin >> q;
  while(q--) {
    string cmd;
    ll a, b;
    cin >> cmd >> a >> b;
    if (cmd[0] == 'Q') {
      block ans = tree.getAns(0, 0, n, a - 1, b);
      if (DEBUG) cout << ans.len << ' ' << ans.pref << ' ' << ans.suf << ' ';
      cout << ans.ans << ln;
    }
    else tree.setX(0, 0, n, a - 1, b);
  }

}