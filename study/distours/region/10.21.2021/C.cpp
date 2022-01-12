// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")
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

int main() {
  fast_cin();

  string s;
  cin >> s;

  vector <pair <char, ll>> z;

  char prev = s[0];
  ll cnt = 0;
  for (auto& c : s) {
    if (c == prev) cnt++;
    else {
      z.pb({prev, cnt});
      cnt = 1;
    } prev = c;
  } z.pb({prev, cnt});

  map <char, ll> maxSingle;
  map <char, map <char, vp64>> maxDouble;

  for (auto& c : z) maxSingle[c.fi] = max(maxSingle[c.fi], c.se);
  forn(i,sz(z) - 1) maxDouble[z[i].fi][z[i + 1].fi].pb({z[i].se, z[i + 1].se});

  ll ans = 0;
  for (auto& c : maxSingle) ans += c.se;

  for (auto& c : maxDouble) {
    for (auto& i : c.se) {
      sort(all(i.se));
      vp64 q;
      for(ll j = 0; j < sz(i.se) - 1; j++) {
        if (i.se[j].fi != i.se[j + 1].fi) q.pb(i.se[j]);
      } q.pb(i.se.back());

      reverse(all(q));
      v64 maxS(sz(q));
      maxS[0] = q[0].se;
      for(ll j = 1; j < sz(q); j++) maxS[j] = max(maxS[j - 1], q[j].se);

      reverse(all(q));
      reverse(all(maxS));

      ll prev = 0;
      for(ll j = 0; j < sz(q); j++) {
        ans += maxS[j] * (q[j].fi - prev);
        prev = q[j].fi;
      }
    }
  } cout << ans << ln;



}