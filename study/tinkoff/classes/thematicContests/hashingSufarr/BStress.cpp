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

ll mod = 1791791791, K = 239;
v64 ks;

ll subHash(v64 &h, ll l, ll r) { // [l, r)
  return ((h[r] - ((h[l] * ks[r - l]) % mod) + mod) % mod);
}

void countSort(v64& p, v64& c) {
  ll n = sz(p);
  v64 cnt(n), pos(n), newP(n);
  for (auto& i : c) cnt[i]++;
  forsn(i,1,n) pos[i] = pos[i - 1] + cnt[i - 1];
  for (auto& i : p) newP[pos[c[i]]++] = i;
  p = newP;
}

string smart(string s, ll x) {
  fast_cin();

  ll n = sz(s);
  v64 h(n + 1);
  ks.clear();
  ks.resize(n + 1, 1);
  forn(i,n) {
    ks[i + 1] = ks[i] * K % mod;
    h[i + 1] = (h[i] * K + (s[i] - (char)0 + 1)) % mod;
  }

  s += (char)0;
  n++;


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
  while((1 << k) < n) {
    for (auto& i : p) i = (i - (1 << k) + n) % n;
    countSort(p, c);
    v64 newC(n);
    forsn(i,1,n) {
      if ((c[p[i]] == c[p[i - 1]]) && (c[(p[i] + (1 << k)) % n] == c[(p[i - 1] + (1 << k)) % n])) newC[p[i]] = newC[p[i - 1]];
      else newC[p[i]] = newC[p[i - 1]] + 1;
    } c = newC;
    k++;
  } n--;

  ll prevH = INF;
  s = s.substr(0, n);
  forn(I,n) {
    ll i = p[I + 1];
    ll H = (subHash(h, i, n) * ks[i] + subHash(h, 0, i)) % mod;
    if (H != prevH) x--;
    if (x == 0) {
      string ans = s.substr(i) + s.substr(0, i);
      return ans;
    } prevH = H;
  } return "IMPOSSIBLE";
}

mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

string stupid(string s, ll k) {
  ll n = sz(s);
  vector <string> q = {s};
  forsn(i,1,n) {
    string p = s.substr(i) + s.substr(0, i);
    q.pb(p);
  } sort(all(q));
  q.erase(unique(all(q)), q.end());
  for (auto& i : q) cout << i << ln;
  if (k > sz(q)) return "IMPOSSIBLE";
  else return q[k - 1];
}

int main() {
  stupid("vcv", 3);
//  while(true) {
//    ll n = rng() % 5 + 1;
//    string s;
//    forn(z,n) s += (char)('a' + (rng() % 26));
//    ll k = (rng() % (n + 10)) + 1;
//    if (stupid(s, k) != smart(s, k)) {
//      cout << s << ' ' << k << ln;
//      return 0;
//    }
//  }
}