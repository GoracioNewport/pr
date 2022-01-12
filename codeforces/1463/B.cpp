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

map <ll, v64> d;

void factor(ll a) {
  v64 ans;
  for (int i = 1; i * i <= a; i++) {
    if (a % i == 0) ans.pb(i);
    if ((a % (a / i) == 0) && (i != (a / i))) ans.pb(a / i);
  } d[a] = ans;
}

int main() {
  fast_cin();
  
  ll t;
  cin >> t;
  forn(z, t) {
    ll n;
    cin >> n;
    v64 a(n);
    for(auto &i : a) cin >> i;
    v64 ans(1, a[0]);
    forsn(i, 1, n) {
      factor(ans[i - 1]);
      ll m = abs(d[ans[i - 1]][0] - a[i]);
      ll man = d[ans[i - 1]][0];
      for (auto &j : d[ans[i - 1]]) {
        if ((j - a[i]) < m) {
          m = abs(j - a[i]);
          man = j;
        }
      } ans.pb(man);
    } for(auto &i : ans) cout << i << ' ';
    cout << endl;
  }

}
