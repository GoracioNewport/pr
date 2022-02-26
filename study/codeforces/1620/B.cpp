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

  ll t;
  cin >> t;
  while(t--) {
    ll w, h, k;
    cin >> w >> h;
    cin >> k;
    v64 T(k);
    for (auto& i : T) cin >> i;
    cin >> k;
    v64 B(k);
    for (auto& i : B) cin >> i;
    cin >> k;
    v64 L(k);
    for (auto& i : L) cin >> i;
    cin >> k;
    v64 R(k);
    for (auto& i : R) cin >> i;

//    cout << ((*max_element(all(T)) - *min_element(all(T))) * h) << ln;

    ll ans = max((*max_element(all(T)) - *min_element(all(T))) * h, (*max_element(all(B)) - *min_element(all(B))) * h);
    ans = max(ans,  max((*max_element(all(L)) - *min_element(all(L))) * w, (*max_element(all(R)) - *min_element(all(R))) * w));
    cout << ans << ln;
  }

}