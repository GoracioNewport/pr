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

void countSort(v64 &p, v64 &c) {
  ll n = sz(p);
  v64 cnt(n), pos(n), pNew(n);
  for (auto &i : c) cnt[i]++;
  forsn(i,1,n) pos[i] = pos[i - 1] + cnt[i - 1];
  for (auto &i : p) pNew[pos[c[i]]++] = i;
  p = pNew;
}

int main() {
  fast_cin();

  string s;
  cin >> s;
  s += '$';
  ll n = sz(s);
  v64 p(n), c(n); {
    vector <pair <char, ll>> a(n);
    forn(i,n) a[i] = {s[i], i};
    sort(all(a));
    forn(i,n) p[i] = a[i].se;
    forsn(i,1,n) {
      if (a[i].fi == a[i - 1].fi) c[p[i]] = c[p[i - 1]];
      else c[p[i]] = c[p[i - 1]] + 1;
    }
  } ll k = 0;
  while ((1 << k) < n) {
    forn(i,n) p[i] = (p[i] - (1 << k) + n) % n;
    countSort(p, c);
    v64 cNew(n);
    forsn(i,1,n) {
      if ((c[p[i]] == c[p[i - 1]]) && (c[p[i] + (1 << k) % n] == c[p[i - 1] + (1 << k) % n])) cNew[p[i]] = cNew[p[i - 1]];
      else cNew[p[i]] = cNew[p[i - 1]] + 1;
    } c = cNew;
    k++;
  }

//  for (auto &i : p) cout << i << ' ' << s.substr(i) << ln;

  ll Q;
  cin >> Q;
  while(Q--) {
    string q;
    cin >> q;
    ll l1 = -1;
    ll r1 = n;
    while (l1 + 1 < r1) {
      ll m = (l1 + r1) / 2;
      string t = s.substr(p[m], sz(q));
      if (t <= q) l1 = m;
      else r1 = m;
    } ll l2 = -1;
    ll r2 = n;
    while (l2 + 1 < r2) {
      ll m = (l2 + r2) / 2;
      string t = s.substr(p[m], sz(q));
      if (t < q) l2 = m;
      else r2 = m;
    } cout << r1 - l2 - 1 << ln;
  }

}