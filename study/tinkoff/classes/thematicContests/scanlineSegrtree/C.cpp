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
#define INF 2e9 + 10
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

struct seg {
    int min, add, cntMin, l, r;
    seg () {
      l = r = -1;
      min = add = 0;
      cntMin = r - l;
    }
};

bool DEBUG = false;


ll N = 2e9 + 1;
vector <seg> t(5e6, seg());

struct Tree {

    ll ind = 1;

    Tree() {
      t[0].min = 0;
      t[0].cntMin = N;
      t[0].add = 0;
    }

    void touchChildren(ll v, ll l, ll r) {
      if (l + 1 == r) return;
      ll m = (l + r) / 2;
      if (t[v].l == -1) {
        t[v].l = ind++;
        t[t[v].l].min = 0;
        t[t[v].l].cntMin = m - l;
        t[t[v].l].add = 0;
      }

      if (t[v].r == -1) {
        t[v].r = ind++;
        t[t[v].r].min = 0;
        t[t[v].r].cntMin = r - m;
        t[t[v].r].add = 0;
      }
    }

    void addSeg(ll v, ll l, ll r, ll L, ll R, ll x) {
      if (DEBUG) cout << "Seg: " << v << ' ' << l << ' ' << r << ln;
      if (l >= L && r <= R) {
        t[v].min += x;
        t[v].add += x;
        return;
      }  if (l >= R || r <= L) return;
      touchChildren(v, l, r);
      ll m = (l + r) / 2;
      addSeg(t[v].l, l, m, L, R, x);
      addSeg(t[v].r, m, r, L, R, x);
      t[v].min = min(t[t[v].l].min, t[t[v].r].min) + t[v].add;
      t[v].cntMin = 0;
      if (t[v].min - t[v].add == t[t[v].l].min) t[v].cntMin += t[t[v].l].cntMin;
      if (t[v].min - t[v].add == t[t[v].r].min) t[v].cntMin += t[t[v].r].cntMin;
    }

    p64 getMin(ll v, ll l, ll r, ll L, ll R) {
      if (l >= L && r <= R) return {t[v].min, t[v].cntMin};
      if (l >= R || r <= L) return {INF, 0};
      touchChildren(v, l, r);
      ll m = (l + r) / 2;
      p64 ansL = getMin(t[v].l, l, m, L, R);
      p64 ansR = getMin(t[v].r, m, r, L, R);
      p64 ans = {0, 0};
      ans.fi = min(ansL.fi, ansR.fi);
      if (ans.fi == ansL.fi) ans.se += ansL.se;
      if (ans.se == ansR.fi) ans.se += ansR.se;
      return ans;
    }

};

enum { BEGIN, END };

struct event {
    ll x, y1, y2, type;
    bool operator<(event& o) {
      return x < o.x;
    }
};

int main() {
  fast_cin();

  ll n;
  cin >> n;
  vector <event> scan;
  ll offset = 1e9;
  Tree tree;

//  for (auto& i : t) cout << i.min << ' ' << i.cntMin << ' ' << i.add << ' ' << i.l << ' ' << i.r << ln;

  forn(i,n) {
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x1 += offset;
    y1 += offset;
    x2 += offset;
    y2 += offset;
    scan.pb({x1, y1, y2, BEGIN});
    scan.pb({x2, y1, y2, END});
  } sort(all(scan));
  ll prevX = (sz(scan) ? scan[0].x : -1);
  ll Ans = 0;
  for (auto &i: scan) {
    p64 ans = tree.getMin(0, 0, N, 0, N);
    Ans += (N - (ans.fi == 0 ? ans.se : N)) * (i.x - prevX);

    if (DEBUG) {
      cout << i.x << ' ' << i.y1 << ' ' << i.y2 << ' ' << (i.type == BEGIN ? "Begin" : "End") << " add: " << (N - (ans.fi == 0 ? ans.se : N)) * (i.x - prevX) << ln;
      cout << "Min: " << ans.fi << ' ' << ans.se << ln;
    }

    if (i.type == BEGIN) tree.addSeg(0, 0, N, i.y1, i.y2, 1);
    if (i.type == END) tree.addSeg(0, 0, N, i.y1, i.y2, -1);

    prevX = i.x;
  } cout << Ans << ln;

//  for (auto& i : t) cout << i.min << ' ' << i.cntMin << ' ' << i.add << ' ' << i.l << ' ' << i.r << ln;

}