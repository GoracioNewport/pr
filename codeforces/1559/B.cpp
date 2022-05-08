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

string calc(string s) {
  forn(i,sz(s) - 1) if (s[i + 1] == '?') (s[i] == 'B' ? s[i + 1] = 'R' : s[i + 1] = 'B');
  return s;
}

int main() {
  fast_cin();

  ll t;
  cin >> t;
  while(t--) {
  	ll n;
  	cin >> n;
  	string s;
  	cin >> s;
    ll ind = -1;
    forn(i,n) if (s[i] == '?') {
      ind = i;
      break;
    } if (ind == -1) cout << s << ln;
    else {
      string s1 = s, s2 = s;
      s1[ind] = 'B';
      s2[ind] = 'R';
      s1 = calc(s1);
      s2 = calc(s2);
      
      ll a = 0, b = 0;
      forn(i,n - 1) {
        if (s1[i + 1] == s1[i]) a++;
        if (s2[i + 1] == s2[i]) b++;
      } cout << (a < b ? s1 : s2) << ln;

    }
  }

}
