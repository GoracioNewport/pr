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

bool DEBUG = false;

ll gcd(ll a, ll b) {
  if (b == 0) return a;
  else return gcd(b, a % b);
}

int main() {
  fast_cin();

  ll t;
  cin >> t;
  while(t--) {
    ll n;
    cin >> n;

    v64 a(n);
    for (auto &i : a) cin >> i;

    set <ll> indsInc, inds;

    forn(i,n) inds.insert(i);

    if (gcd(a[0], a.back()) == 1) indsInc.insert(0);
    forn(i,n - 1) if (gcd(a[i], a[i + 1]) == 1) indsInc.insert(i + 1);

    ll Prev = 0;

    if (DEBUG) {
      for (auto &i : indsInc) cout << i << ' ';
      cout << ln;
    }

    v64 ans;

    while(!indsInc.empty()) {
      if (DEBUG) cout << "-------" << ln;
      if (DEBUG) cout << "Contents: " << ln;
      if (DEBUG) for (auto &i : inds) cout << a[i] << ' ';
      if (DEBUG) cout << endl;

      auto it = indsInc.upper_bound(Prev);
      if (it == indsInc.end()) it = indsInc.begin();

      auto PreviousPoint = prev(inds.lower_bound(*it));
      if (PreviousPoint == prev(inds.begin())) PreviousPoint = prev(inds.end());
      ll Previous = *PreviousPoint;

      auto NextPoint = inds.upper_bound(*it);
      if (NextPoint == inds.end()) NextPoint = inds.begin();
      ll Next = *NextPoint;

      if (DEBUG) cout << "Iterators: " << Previous << ' ' << *it << ' ' << Next << endl;

      auto findS = indsInc.lower_bound(Next);
      if (findS != indsInc.end() && *findS == Next) {
        if (DEBUG) cout << "ERASE" << endl;
        indsInc.erase(findS);
      }


      if (gcd(a[Prev], a[Next]) == 1) {
        if (DEBUG) cout << "INSERT" << endl;
        indsInc.insert(Next);
      }

      Prev = Next;
      ans.pb((*it) + 1);
      indsInc.erase(it);
      inds.erase(*it);
      if (DEBUG) cout << endl;
    } cout << sz(ans) << ' ';
    for (auto &i : ans) cout << i << ' ';
    cout << ln;



  }

}