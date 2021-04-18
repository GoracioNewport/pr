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
  v64 pos(n), cnt(n), pNew(n);
  for (auto &i : c) cnt[i]++;
  forsn(i,1,n) pos[i] = pos[i - 1] + cnt[i - 1];
  for (auto &i : p) pNew[pos[c[i]]++] = i;
  p = pNew;
}

int main() {
  fast_cin();

  string s1, s2, s;
  cin >> s1 >> s2;
  s = s1 + '$' + s2 + '#';
  ll n = sz(s);
  ll n1 = sz(s1) + 1;
  ll n2 = sz(s2) + 1;
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
    countSort(p,c);
    v64 cNew(n);
    forsn(i,1,n) {
      if ((c[p[i]] == c[p[i - 1]]) && (c[p[i] + (1 << k) % n] == c[p[i - 1] + (1 << k) % n])) cNew[p[i]] = cNew[p[i - 1]];
      else cNew[p[i]] = cNew[p[i - 1]] + 1;
    } c = cNew;
    k++;
  } k = 0;
  vp64 lcp(n, {0, n});
  forn(i,n - 1) {
    ll pi = c[i];
    ll j = p[pi - 1];
    while (s[i + k] == s[j + k]) k++;
    lcp[pi] = {k, i};
    k = max((ll)0, k - 1);
  } p64 ans = {0, n};

//  for (auto &i : p) cout << i << ' ' << s.substr(i) << endl;
//  for (auto &i : lcp) cout << i.fi << endl;

  forsn(i,1,n) if (((lcp[i].se >= n1) != (lcp[i - 1].se >= n1)) && (lcp[i].fi > ans.fi)) ans = {lcp[i].fi, lcp[i].se};
  cout << s.substr(ans.se, ans.fi);
}