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

  ll n, m;
  cin >> n >> m;
  v64 moves(n + m);
  for (auto& i : moves) {
    string s;
    cin >> s;
    if (s == "UD") i = 0;
    else if (s == "DU") i = 1;
    else if (s == "LR") i = 2;
    else i = 3;
  }

  ll q;
  cin >> q;
  while(q--) {
    char cmd;
    ll i, j;
    cin >> cmd >> i >> j; i--; j--;

    bool inv = true;
    ll a = (1 << n);
    ll b = (1 << m);

    if (cmd == 'v') {
      for (auto& o : moves) {
        if (o == 0) {
          a /= 2;
          if (i < a) {
            i = a - i;
            inv = !inv;
          }
        } else if (o == 1) {
          a /= 2;
          if (i >= a) inv = !inv;
          i = a;
        }
      }
    }
  }

}