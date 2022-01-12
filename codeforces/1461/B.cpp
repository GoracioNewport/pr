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
  forn(z, t) {
    ll n, m;
    cin >> n >> m;
    ll ans = 0;
    vector <vector <char>> p(n, vector <char> (m));
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      for (int j = 0; j < m; j++) p[i][j] = s[j];
    } vector <vector <p64>> pr;
    for (int i = 0; i < n; i++) {
      ll cnt = 0;
      vector <p64> b;
      for (int j = 0; j < m; j++) {
        if (p[i][j] != '*') cnt = 0;
        else cnt++;
        b.pb(mp(cnt - 1, -1));
      } cnt = 0; 
      for (int j = m - 1; j >= 0; j--) {
        if (p[i][j] != '*') cnt = 0;
        else cnt++;
        b[j].se = cnt - 1;
      } pr.pb(b);
    } 
    for (auto &i : pr) {
      for (auto &j : i) cout << '[' << j.fi << ' ' << j.se << ']';
      cout << endl;
    }
    
    
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (p[i][j] == '*') {
          for (int I = i; I < n; I++) {
            if (pr[I][j].fi < (I - i) || pr[I][j].se < (I - i) || I == (n - 1)) {
              ans += ((I - i) + 1);
              break;
            }
          }
        }
      }
    } cout << ans << endl;

  }  

}
