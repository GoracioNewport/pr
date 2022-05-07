#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

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
    ll n, m;
    cin >> n >> m;
    v64 memr(n);
    for (auto &i : memr) cin >> i;
    v64 o;
    v64 t;
    forn(i,n) {
      ll x;
      cin >> x;
      if (x == 1) o.pb(memr[i]);
      else t.pb(memr[i]);
    } ll l = sz(o) - 1;
    ll s = 0;
    ll a = sz(o);
    ll b = sz(t);
    sort(all(o));
    sort(all(t));
    reverse(o.begin(), o.end());
    reverse(t.begin(), t.end());
    ll ans = -1;
    forn(i, a) {
      s += o[i];
      if (s >= m) {
        l = i;
        ans = (l + 1);
        break;
      }
    } ll r = 0;
    forn(i, b) {
      r = i;
      s += t[i];
      if (s < m) continue;
      if (s >= m) {
        // cout << "shit " << l << ' ' << r << endl;
        if (ans == -1) ans = (l + 1) + ((r + 1) * 2);
        ans = min(ans, (l + 1) + (r * 2 + 2));
      }
      while (s > m && l >= 0) {
        s -= o[l];
        l--;
        if (s >= m) {
          if (ans == -1) ans = (l + 1) + ((r + 1) * 2);
          ans = min(ans, (l + 1) + (r * 2 + 2));
        }
      } if (s >= m) {
        // cout << (l + 1) + (r * 2 + 2) << endl;
        if (ans == -1) ans = (l + 1) + ((r + 1) * 2);
        ans = min(ans, (l + 1) + (r * 2 + 2));
      }
    } cout << ans << endl;
  }

}
