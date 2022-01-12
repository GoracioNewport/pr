//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

// Author: @GoracioNewport
  
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

enum { END, BEGIN, POINT };

struct event {
  ll type, x, a = 0;
  bool operator< (event o) {
    if (x != o.x) return x < o.x;
    return type < o.type;
  }
};

ll mod = 1e9 + 7;

int main() {
  fast_cin();

  ll t;
  cin >> t;
  v64 powers(1e6 + 1, 1);
  for (ll i = 1; i <= 1e6; i++) {
    powers[i] = (powers[i - 1] * 2) % mod;
  }
  
  while(t--) {
    ll n, m;
    cin >> n >> m;
    vector <event> q;
    v64 ans(n);
    forn(i,n) q.pb({POINT, i, 0});
    forn(i,m) {
      ll l, r, x;
      cin >> l >> r >> x; l--;
      q.pb({BEGIN, l, x});
      q.pb({END, r, x});
    } sort(all(q));

    // for (auto& i : q) cout << i.x << ' ' << i.type << ' ' << i.x << ln;
    
    ll curVal = 0, cnt = 0;
    vector <ll> pw(32, 0);
    for (auto& i : q) {
      if (i.type == BEGIN) {
        
        cnt++;
        bitset <32> w(i.a);
        forn(i,32) if (w[i]) pw[i]++;
        w.reset();
        forn(i,32) if (pw[i] == cnt) w[i] = 1;
        curVal = w.to_ullong();

        // for (auto& i : pw) cout << i << ' ';
        // cout << ln;
        // cout << curVal << ' ' << cnt << ln;

      } else if (i.type == END) {

        cnt--;
        bitset <32> w(i.a);
        forn(i,32) if (w[i]) pw[i]--;
        w.reset();
        forn(i,32) if (pw[i] == cnt) w[i] = 1;
        curVal = w.to_ullong();

      } else ans[i.x] = curVal;
    } 


    forn(i,32) pw[i] = 0;
    for (auto& i : ans) {
      bitset <32> q(i);
      forn(i,32) if (q[i]) pw[i]++;
    }

    ll Ans = 0;
    forn(i,32) {
      if (!pw[i]) continue;
      Ans = (Ans + (((powers[n - pw[i]] * powers[pw[i] - 1]) % mod) * powers[i])) % mod;
    } cout << Ans << ln;



  }  

}
