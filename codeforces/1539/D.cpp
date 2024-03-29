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
  vp64 a(n);

  for (auto &i : a) cin >> i.se >> i.fi; // <Discount, Amount>

  sort(all(a));

  ll r = n - 1;
  ll cnt = 0;
  ll ans = 0;

  for (ll l = 0; l < n; l++) {
    if (r < l) break;
    while(cnt < a[l].fi) {
      if (r < 0) break;
      ll reach = a[l].fi - cnt; // Сколько надо купить правой, что бы появилась скидка на левую херню
      if (reach < a[r].se) { // Скупим только часть правой.
        ans += reach * 2;
        cnt += reach;
        a[r].se -= reach;
      } else { // Скупаем всю правую
        ans += a[r].se * 2;
        cnt += a[r].se;
        a[r].se = 0;
        r--;
      }
    } cnt += a[l].se;
    ans += a[l].se;
    a[l].se = 0;
  } cout << ans << ln;




}