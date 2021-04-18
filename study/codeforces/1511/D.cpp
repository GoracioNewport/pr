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

  ll n, k;
  cin >> n >> k;

  if (n == 1) {
    cout << 'a' << ln;
    exit(0);
  }

  char fin = ('a' + k - 1);

  vector <string> m;

  forn(i,k) {
    forn(j,k) {
      char a = ('a' + i);
      char b = ('a' + j);
      string s = {a,b};
      m.pb(s);
    }
  }

  v64 used(sz(m), 0);
  used[0] = 1;

//  reverse(all(used));
//  reverse(all(m));

  string eth = "aa";

  pair <char, char> last = {'a', 'a'};

  ll c = k * k;

  map <pair <char, char>, ll> cnt;
  cnt[{'a', 'a'}]++;



  forn(z,c - 1) {

    pair <ll, string> mi = {INF, ""};
    p64 mins = {INF, INF};

    forn(i,sz(m)) {
      if (used[i]) continue;
      pair <char, char> a = {m[i][0], m[i][1]};
      pair <char, char> b = {last.se, m[i][0]};
      ll cntA = cnt[a];
      ll cntB = cnt[b];
      if ((cntA + cntB) < (mins.fi + mins.se)) {
        if ((cntA + cntB) == (mins.fi + mins.se)) if (cntB > mins.se) continue;
        mi.fi = i;
        mi.se = m[i];
        mins.fi = cntA;
        mins.se = cntB;
      }
    } used[mi.fi] = 1;
    eth += mi.se;
    pair <char, char> b = {last.se, mi.se[0]};
    last = {mi.se[0], mi.se[1]};
    cnt[last]++;
    cnt[b]++;

//    cout << eth << ln;
//    cout << mi.fi << ln;

  }

//  cout << eth << ln;

  string ans = eth;
  eth.erase(prev(eth.end()));
  while(sz(ans) < n) ans += eth;


  cout << eth << ln;
  cout << ans.substr(0, n) << ln;




}