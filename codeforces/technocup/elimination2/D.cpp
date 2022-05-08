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
  
  ll n;
  cin >> n;
  vector <ll> a(n);
  for (auto &i : a) cin >> i;

  ll s = (a[0] ^ a[1]);
  ll ans1 = INF, ans2 = INF, ind2 = 0;
  for (int i = 2; i < n; i++) {
    if (s > a[i]) {
      ans1 = i - 1;
      break;
    } s = (s ^ a[i]);
  } s = (a[n - 2] ^ a[n - 1]); 
  for (int i = n - 3; i >= 0; i--) {
    if (s < a[i]) {
      ans2 = (n - 3) - i + 1;
      ind2 = i;
      break;
    } 
  } 
  
  if (ans1 != INF) {
    ll sa = (a[ans1] ^ a[ans1 - 1]);
    for (int i = ans1 - 2; i >= 0; i--) {
      if (sa < a[i]) {
        ans1 = min((ans1 - 2) - i, ans1);
        break;
      } sa = (sa ^ a[i]);
    }
  } if (ans2 != INF) {
    ll sa = (a[ind2 + 1] ^ a[ind2 + 2]);
    for (int i = ind2 + 3; i < n; i++) {
      if (sa > a[i]) {
        ans2 = min((ind2 + 3) - i, ans2);
        break;
      } sa = (sa ^ a[i]);
    }
  }
  
  ll ans = min(ans1, ans2);
  if (ans == INF) cout << -1 << endl;
  else cout << ans << endl;

}
