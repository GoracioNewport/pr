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


ll gcd(ll a, ll b) {
  if (b == 0) return a;
  else return gcd(b, a % b);
}

int main() {
//  fast_cin();

  ll t;
  cin >> t;
  while(t--) {
    ll n;
    cin >> n;
    v64 a(n);
    for (auto &i : a) cin >> i;
//    if (n == 1) {
//      cout << 0 << ln;
//      continue;
//    } else if (n == 2) {
//      if (gcd(a[0], a[1]) != 1) cout << 0 << ln;
//      else cout << 1 << ' ' << 2 << ln;
//      continue;
//    }
    v64 ans;
    set <ll> inds;
    forn(i,n) inds.insert(i);
    bool debug = false;
    debug = true;
    set <ll> tracks;
    forn(i,n-1) if (gcd(a[i], a[i + 1]) == 1) tracks.insert(i + 1);
    if (gcd(a[0], a.back()) == 1) tracks.insert(0);
    ll pos = -1;
    while(!tracks.empty()) {
      if (debug) {
        cout << "------" << ln;
        for (auto &i : inds) cout << a[i] << ' ';
        cout << ln;
        for (auto &i : tracks) cout << i << ' ';
        cout << ln;
      }
      // Удаляем *ind
      auto ind = tracks.upper_bound(pos);
      if (ind == tracks.end()) ind = tracks.begin();
      pos = (*ind) + 1;
      if (pos >= (n - 1)) pos = -1;

      // Удаляем эту позицию

      auto deleteIndPos = inds.lower_bound(*ind);
      auto nextIndPos = next(deleteIndPos);
      auto prevIndPos = prev(deleteIndPos);
      if (nextIndPos == inds.end()) nextIndPos = inds.begin();
      if (prevIndPos == prev(inds.begin())) prevIndPos = prev(inds.end());
      if (debug) {
        cout << "Cur: " << *deleteIndPos << ln;
        cout << "Next: " << *nextIndPos << ln;
        cout << "Prev: " << *prevIndPos << ln;
      }
      if (gcd(a[*deleteIndPos], a[*nextIndPos]) == 1 && (*deleteIndPos != *nextIndPos)) tracks.erase(*nextIndPos);
      if (gcd(a[*prevIndPos], a[*nextIndPos]) == 1) tracks.insert(*nextIndPos);

      ans.pb(*ind);
      inds.erase(*ind);
      tracks.erase(ind);
    }
    if (debug) {
      cout << "------" << ln;
      for (auto &i : inds) cout << a[i] << ' ';
      cout << ln;
      for (auto &i : tracks) cout << i << ' ';
      cout << ln;
    }
    cout << sz(ans);
    for (auto &i : ans) cout << ' ' << i + 1;
    cout << ln;

  }

}