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
    ll A, B, n;
    cin >> A >> B >> n;
    vector <pair <pair <ll,ll>, ll>> a;
    v64 ar(n);
    v64 br(n);
    for (auto &i : ar) cin >> i;
    for (auto &i : br) cin >> i;
    forn(i,n) {
      ll c = ceil((double)br[i] / (double)A);
      a.pb({{ar[i] * c, br[i] * c}, c});
    } sort(all(a));
    // reverse(all(a));
    bool ans = false;
    v64 sum(n, 0);
    sum[0] = a[0].fi.fi;
    forsn(i,1,n) sum[i] = sum[i - 1] + a[i].fi.fi;
    ll tot = sum.back();

    // cout << tot << ln;

    forn(i,n) {
      ll hp = B - tot;
      hp += a[i].fi.fi; // hp - количетсво жизней перед дракой с последним монстром
      if (hp > 0) {
        if (a[i].se == 1) ans = true;
        hp -= a[i].fi.fi;
        hp += a[i].fi.fi / a[i].se;
        if (hp > 0) ans = true;
      }
    } cout << (ans ? "YES" : "NO") << ln;
  }
}
