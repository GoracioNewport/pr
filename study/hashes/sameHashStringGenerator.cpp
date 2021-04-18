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

ll k = 31, mod = 1013;
ll hashEx;

map <ll, ll> cnt;


ll hashCalc (string &s) {
  ll h = 0;
  forn(i,sz(s)) h = (h * k + (s[i] - 'a' + 1)) % mod;
  return h;
}

vector <char> alpha;

void generate(ll left, ll h, string &s) {
  if (!left) {
//    cnt[h]++;
    if (h == hashEx) cout << s << ln;
    return;
  } for (auto &c : alpha) {
    s += c;
    generate(left - 1, (h * k + (c - 'a' + 1)) % mod, s);
    s.erase(--s.end());
  }
}

int main() {
  fast_cin();
  alpha.resize(26);
  iota(all(alpha), 'a');

  cin >> hashEx;
  string s;
  forsn(len,1,5) generate(len, 0, s);
//  p64 ma = {cnt[0], 0};
//  p64 mi = {cnt[0], 0};
//  for (auto &i : cnt) {
//    cout << i.fi << ':' << i.se << ln;
//    ma = max(ma, {i.se, i.fi});
//    mi = min(mi, {i.se, i.fi});
//  } cout << "Max: " << ma.se << ", cnt: " << ma.fi << ln;
//  cout << "Min: " << mi.se << ", cnt: " << mi.fi << ln;

}