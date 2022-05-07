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

int main() {
  fast_cin();

  ll n;
  cin >> n;
  string s, p;
  cin >> s;
  forn(i,n + 2) {
    if (i % 3 == 0) p.pb('R');
    else if (i % 3 == 1) p.pb('G');
    else p.pb('B');
  } ll cnt1 = 0, cnt2 = 0, cnt3 = 0;
  for (ll i = 0; i < n; i++) if (s[i] != p[i]) cnt1++;
  for (ll i = 0; i < n; i++) if (s[i] != p[i + 1]) cnt2++;
  for (ll i = 0; i < n; i++) if (s[i] != p[i + 2]) cnt3++;
  ll mi = min(cnt1, min(cnt2, cnt3));
  if (mi == cnt1) {
    cout << cnt1 << ln;
    forn(i,n) cout << p[i];
  } else if (mi == cnt2) {
    cout << cnt2 << ln;
    forn(i,n) cout << p[i + 1];
  } else {
    cout << cnt3 << ln;
    forn(i,n) cout << p[i + 2];
  }
}