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

void countSort(v64& c, v64& p) {
  ll n = sz(p);
  v64 cnt(n), pos(n), newP(n);
  for (auto& i : c) cnt[i]++;
  forsn(i,1,n) pos[i] = pos[i - 1] + cnt[i - 1];
  for (auto& i : p) newP[pos[c[i]]++] = i;
  p = newP;
}

int main() {
  fast_cin();

  ll n, m;
  cin >> n >> m;
  v64 s(n);
  for (auto& i : s) cin >> i;

  v64 p;

  s.pb(0);
  n++;
  v64 c(n), p(n); {
    vp64 a(n);
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
    countSort(c, p);
    v64 newC(n);
    forsn(i,1,n) {
      if ((c[p[i]] == c[p[i - 1]]) && (c[(p[i] + (1 << k)) % n] == c[(p[i - 1] + (1 << k)) % n])) newC[p[i]] = newC[p[i - 1]];
      else newC[p[i]] = newC[p[i - 1]] + 1;
    } c = newC;
    k++;
  } k = 0;
  v64 lcp(n - 1);
  forn(i, n - 1) {
    ll j = p[c[i] - 1];
    while(s[i + k] == s[j + k]) k++;
    lcp[c[i] - 1] = k;
    k = max(0ll, k - 1);
  }

  stack <p64> q;
  q.push({-INF, -1});

  vp64 ans(n - 1, { -1 , n - 1 });

  forn(i, n - 1) {
    while(q.top().fi > lcp[i]) {
      ans[q.top().se].se = i;
      q.pop();
    } q.push({lcp[i], i});
  }

  while(!q.empty()) q.pop();

  q.push({-INF, -1});

  rforn(i, n - 1) {
    while(q.top().fi > lcp[i]) {
      ans[q.top().se].fi = i;
      q.pop();
    } q.push({lcp[i], i});
  }

  pair <ll, p64> Ans = {n - 1, {0, n - 1}};
  forn(i, n - 1) {
    ll x = lcp[i] * (ans[i].se - ans[i].fi);
    Ans = max(Ans, {x, {p[i], lcp[i]}});
  } cout << Ans.fi << ln << Ans.se.se << ln;
  for (ll i = Ans.se.fi; i < Ans.se.fi + Ans.se.se; i++) cout << s[i] << ' ';
  cout << ln;

}