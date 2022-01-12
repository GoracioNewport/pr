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

enum { A, C, G, T };

struct block {
  ll c;
  ll n;
  ll i;
};

int main() {
  fast_cin();
  
  string s;
  cin >> s;

  vector <block> p;
  ll mul = 0;
  ll ind = 0;
  forn(i, sz(s)) {
    while(!isalpha(s[i])) {
      mul = (mul * 10 + (s[i] - '0'));
      i++;
    } ll c;
    if (s[i] == 'A') c = A;
    else if (s[i] == 'C') c = C;
    else if (s[i] == 'G') c = G;
    else c = T;
    block bl = {c, max((ll)1,mul), ind};
    p.pb(bl);
    ind += max((ll)1, mul);
    mul = 0;
  } // for (auto &i : p) cout << i.c << ' ' << i.n << ' ' << i.i << endl;

  // MIN

  {
    ll ans = 0;
    ll ansInd = 0;
    for(auto &i : p) {
      if (i.n <= 2) {
        if (ans < 1) {
          ans = 1;
          ansInd = i.i;
        }
      } else {
        ll x = i.n;
        while (x % 10 == 0) x /= 10;
        if (x == 1) {
          ans = 1;
          ansInd = i.i;
        }
      }
    } for (int i = 1; i < sz(p) - 1; i++) {
      if (p[i - 1].c == p[i + 1].c && p[i].n == 1) {
        ll oldLen = sz(to_string(p[i - 1].n)) + sz(to_string(p[i + 1].n)) + 3;
        if (p[i - 1].n == 1) oldLen--;
        if (p[i + 1].n == 1) oldLen--;
        ll newLen = sz(to_string(p[i - 1].n + p[i + 1].n)) + 1;
        if (oldLen - newLen > ans) {
          ans = oldLen - newLen;
          ansInd = p[i].i;
          // cout << "hi" << endl;
        }
      }
    } cout << 2 << ' ' << ansInd + 1 << endl; 
    // cout << ans << endl;
  }


  // MAX 

  {
    ll ans = 1;
    ll ansInd = 0;
    ll ansChar = !p[0].c;
    for(auto &i : p) {
      if (i.n == 3) {
        if (ans < 2) {
          ans = 2;
          ansInd = i.i;
          ansChar = !i.c;
        }
      } else if (i.n > 3) {
        ll r = max((ll)2, (ll)pow(10, sz(to_string(i.n - 1)) - 1) );
        // cout << r << endl;
        ll oldLen = sz(to_string(i.n)) + 1;
        ll newLen = sz(to_string(r)) + sz(to_string(i.n - r)) + 3;
        if (newLen - oldLen > ans) {
          ans = newLen - oldLen;
          ansInd = i.i + r - 1;
          ansChar = !i.c;
        }

        r = i.n / 2;
        newLen = sz(to_string(r)) + sz(to_string(i.n - r)) + 3;
        if (newLen - oldLen > ans) {
          ans = newLen - oldLen;
          ansInd = i.i + r - 1;
          ansChar = !i.c;
        } 
      }
    } char ch;
    if (ansChar == 0) ch = 'A';
    else if (ansChar == 1) ch = 'C';
    else if (ansChar == 2) ch = 'G';
    else ch = 'T';
    cout << 1 << ' ' << ansInd + 1 << ' ' << ch << endl;
  }
  

}
