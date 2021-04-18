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

const ll k = 239, mod = 1791791791;

vector <ll> h;
vector <ll> ks;

ll sub_hash(ll l, ll r) {
  return ((h[r] - ((h[l - 1] * ks[r - l + 1]) % mod) + mod) % mod);
}

int main() {
  fast_cin();
  
  string s;
  cin >> s;
  ll n = s.size();

  h.resize(n + 1, 0);
  ks.resize(n + 1, 1);

  for (int i = 0; i < n; i++) { 
    ks[i + 1] = (ks[i] * k) % mod; 
    ll x = (s[i] - 'a' + 1);
    h[i + 1] = ((h[i] * k) % mod) + x;
  }

  ll ans = n;

  for (ll i = 1; i <= n; i++) { // Перебор количества отрезков
    if (n % i == 0) {
      // cout << "----------" << i << "----------" << endl;
      bool find = true;
      ll prev = -1;
      for (ll j = 0; j < n; j += (n / i)) { // Перебор начального индекса отрезка
        // cout << j + 1 << ' ' << j + (n / i) << endl;
        ll a = sub_hash(j + 1, j + (n / i));
        if (a != prev && prev != -1) {
          find = false;
          break;
        } prev = a;
      } if (find) ans = min((n / i), ans);
    }
  } cout << ans << endl;
}
