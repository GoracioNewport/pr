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

bool check(string a, string b) { // sample, text
  if (b.find(a) == string::npos) return false;
  ll ind = b.find(a);

  for(ll i = 0; i < ind; i++) if (b[i] == '0') return false;
  for(ll i = ind + sz(a); i < sz(b); i++) if (b[i] == '0') return false;

  return true;
}

int main() {
  fast_cin();

  ll x, y;
  cin >> x >> y;
  if (x == y) {
    cout << "YES" << ln;
    return 0;
  }
  bitset <64> a(x), b(y);

  string s1 = a.to_string();
  string s2 = b.to_string();


  ll fNonz2 = -1;
  forn(i,sz(s2)) {
    if (s2[i] == '1') {
      if (fNonz2 == -1) fNonz2 = i;
    }
  } s2 = s2.substr(fNonz2);

  ll fNonz = -1;
  forn(i,sz(s1)) {
    if (s1[i] == '1') {
      if (fNonz == -1) fNonz = i;
    }
  }

  string samp = s1.substr(fNonz);

  ll lastOne = 0;
  forn(i,sz(samp)) {
    if (samp[i] == '1') lastOne = i;
  } string cut = samp.substr(0, lastOne + 1);

  bool ans = false;
  samp += '1';

  ans |= check(samp, s2);
  ans |= check(cut, s2);

  reverse(all(samp));
  reverse(all(cut));

  ans |= check(samp, s2);
  ans |= check(cut, s2);

  cout << (ans ? "YES" : "NO") << ln;


}