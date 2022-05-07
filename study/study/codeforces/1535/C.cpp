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

string s;
v64 nonQuestion;

bool ok(ll l, ll r) {
  if (r - l == 0) return true;
  if (s[r] == '?') return true;
  if (s[l] == '?') {
    auto it = lower_bound(all(nonQuestion), l);
    if (it == nonQuestion.end()) return true;
    else return ok(*it, r);
  }
  if ((r - l) % 2) { // even
    if ((s[l] == '0' && s[r] == '1') || (s[l] == '1' && s[r] == '0')) return true;
  } else {
    if ((s[l] == '0' && s[r] == '0') || (s[l] == '1' && s[r] == '1')) return true;
  } return false;
}

int main() {
  fast_cin();

  ll t;
  cin >> t;
  while(t--) {
    cin >> s;
    ll n = sz(s);
    nonQuestion.clear();
    ll ind = 0;
    for (auto &i : s) {
      if (i != '?') nonQuestion.pb(ind);
      ind++;
    }

//    for (auto &i : nonQuestion) cout << i << ' ';
//    cout << endl;


    ll r = 0;
    ll ans = 0;
    for (ll l = 0; l < n; l++) {
      while (ok(l, r + 1) && (r != n - 1)) r++;
      ans += r - l + 1;
//      cout << l << ' ' << r << ln;
    } cout << ans << ln;
  }

}