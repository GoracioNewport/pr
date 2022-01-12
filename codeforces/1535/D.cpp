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

bool DEBUG = false;

struct Node {
    ll ans;
    char res;
};

struct Tree {
    ll n;
    vector <Node> t;
    string s;

    Tree (ll _n, string _s) {
      n = _n;
      s = _s;
      t.assign(4 * n, {0,'#'});
      build(0,0,n);
    }

    void build(ll v, ll l, ll r) {
      if (l + 1 == r) {
        t[v].res = s[v];
        t[v].ans = 1;
        if (s[v] == '?') t[v].ans = 2;
        return;
      } ll m = (l + r) / 2;

      build(2 * v + 1, l, m);
      build(2 * v + 2, m, r);

      t[v].res = s[v];
      if (s[v] == '?') t[v].ans = t[2 * v + 1].ans + t[2 * v + 2].ans;
      else if (s[v] == '0') t[v].ans = t[2 * v + 1].ans;
      else t[v].ans = t[2 * v + 2].ans;

    }

    ll getAns() {
      return t[0].ans;
    }

    void modify(ll v, ll l, ll r, ll i, v64 &p, char c, ll T) {
      if (T == sz(p)) {
        s[v] = c;
        t[v].res = c;
        if (l + 1 == r) {
          t[v].ans = 1;
          if (c == '?') t[v].ans = 2;
        } else {
          if (c == '0') t[v].ans = t[2 * v + 1].ans;
          else if (c == '1') t[v].ans = t[2 * v + 2].ans;
          else t[v].ans = t[2 * v + 1].ans + t[2 * v + 2].ans;
        }
        return;
      } ll m = (l + r) / 2;
      if (p[T] == 1) modify(2 * v + 1, l, m, i, p, c, T + 1);
      else modify(2 * v + 2, m, r, i, p, c, T + 1);

      if (s[v] == '?') t[v].ans = t[2 * v + 1].ans + t[2 * v + 2].ans;
      else if (s[v] == '0') t[v].ans = t[2 * v + 1].ans;
      else t[v].ans = t[2 * v + 2].ans;

    }
};

int main() {
  fast_cin();

  ll k;
  cin >> k;
  string s;
  cin >> s;

  ll x = k;
  ll n = (1 << k) - 1;
  ll l = 0;
  while(x--) {
    ll y = (ll)pow(2, x);
    reverse(s.begin() + l, s.begin() + y + l);
    l += y;
  } reverse(all(s));

  Tree tree((1 << (k - 1)), s);

  v64 ref(n);
  iota(all(ref), 0);

  x = k;
  l = 0;
  while(x--) {
    ll y = (ll)pow(2, x);
    reverse(ref.begin() + l, ref.begin() + y + l);
    l += y;
  } reverse(all(ref));

  v64 Ref(n);
  forn(i,n) Ref[ref[i]] = i;

//  for (auto &i : tree.t) cout << i.ans << ' ';
//  cout << ln;

//  for (auto &i : Ref) cout << i << ' ';
//  cout << ln;


  ll q;
  cin >> q;
  while(q--) {
    if (DEBUG) cout << "---" << ln;
    ll x;
    char c;
    cin >> x >> c;
    x--;
    x = Ref[x];
//    cout << "REF: " << x << ln;
    v64 trace;
    ll y = x;
    while(y != 0) {
      if (y % 2 == 0) {
        y = ((y - 2) / 2);
        trace.pb(2);
      }
      else {
        y = ((y - 1) / 2);
        trace.pb(1);
      }
    } reverse(all(trace));

    if (DEBUG) {
      cout << "TRACE: ";
      for (auto &i : trace) cout << i << ' ';
      cout << ln;
    }

    tree.modify(0, 0, (1 << (k - 1)), x, trace, c, 0);
    if (DEBUG) {
      for (auto &i : tree.t) cout << i.ans << ' ';
      cout << ln;
      for (auto &i : tree.t) cout << i.res << ' ';
      cout << ln;
    }
    cout << tree.getAns() << endl;


  }

}