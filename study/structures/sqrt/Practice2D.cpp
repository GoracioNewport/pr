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
  
  ll n, q;
  cin >> n >> q;
  v64 a(n);
  for (auto &i : a) cin >> i;
  ll len = 1000;
  v64 d(n / len + 1, -1);
  forn(i,n) d[i / len] = max(d[i / len], a[i]);
  while(q--) {
    ll t;
    cin >> t;
    if (t == 1) {
      ll i, x;
      cin >> i >> x;
      a[i] = x;
      d[i / len] = a[i];
      ll l = (i / len) * len;
      ll r = min(l + len, n);
      forsn(j,l,r - 1) d[i / len] = max(d[i / len], a[j]);
      // cout << "SQRT contains: " << ln;
      // for (auto &i : d) cout << i << ' ';
      // cout << ln;
    } else {
      ll x, j;
      cin >> x >> j;

      // Сначала дойдем до ближайшего блока
      ll closetBlock = (j / len) * len + len;
      if (j % len == 0 && j != 0) closetBlock -= len;
      // if (j % len == 0) closetBlock -= len;
      // cout << "Closet block: " << closetBlock << endl;
      ll ans = -1;
      for (int i = j; i <= min(closetBlock, n - 1); i++) {
        // cout << i << ln;
        if (a[i] >= x) {
          ans = i;
          // cout << "hi" << ln;
          break;
        }
      } if (ans != -1) {
        // cout << "uuu" << ln;
        cout << ans << ln;
        continue;
      }

      // Теперь от него пойдем по блокам, пока не найдем с максимумом...
      ll ind = -1;
      for (int i = closetBlock / len; i < sz(d); i++) {
        if (d[i] >= x) {
          ind = i;
          break;
        }
      } if (ind == -1) {
        cout << -1 << ln;
        continue;
      }

      // Проходимся по блоку и ищем первый максимум

      for (int i = ind * len; i <= min(ind * len + len, n - 1); i++) {
        if (a[i] >= x) {
          // cout << "3!!!" << ln;
          cout << i << ln;
          break;
        }
      }
    }
  }  

}
