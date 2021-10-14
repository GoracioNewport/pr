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
#define forn(i,e) for(int i = 0; i < e; i++)
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

const ll k = 113, mod = 1791791791;
const ll k2 = 239, mod2 = 1e9 + 7;
bool DEBUG = true;

void solve(ll n) {
  ll m;
  unordered_map <ll, int> f;
  forn(z,n) {
    string s;
    cin >> s;
    ll h = 0;
    forn(i,sz(s)) h = (h * k + (s[i] - '#' + 1)) % mod;
    f[h]++;
  } cin >> m;
  forn(z,m) {
    string s;
    cin >> s;
    ll h = 0;
    forn(i,sz(s)) h = (h * k + (s[i] - '#' + 1)) % mod;
    cout << f[h] << ln;
  }

}

int main() {
  fast_cin();

  freopen("search.in", "r", stdin);
  freopen("search.out", "w", stdout);

  int n, p;
  cin >> n >> p;
  if (p == 2) {
    solve(n);
    return 0;
  }
  map <p64, int> f;

  forn(z,n) {
    string s;
    cin >> s;
    ll h = 0;
    ll h2 = 0;
    forn(i,sz(s)) {
      h = (h * k + (s[i] - '#' + 1)) % mod;
      h2 = (h2 * k2 + (s[i] - '#' + 1)) % mod2;
    }
    f[{h, h2}]++;
  }


  int m;
  cin >> m;
  forn(z,m) {
    string s;
    cin >> s;
    string buf = "";
    vector <string> refA, refB;
    char prev = '.';
    for (auto& c : s) {
      if (c == '.' || c == '/') {
        if (prev == '.') refA.emplace_back(buf);
        else refB.emplace_back(buf);
        buf = "";
        prev = c;
      } else buf += c;
    } if (prev == '.') refA.emplace_back(buf);
    else refB.emplace_back(buf);
    buf = "";
//    reverse(all(refA));

//    for (auto &i : refA) cout << i << ' ';
//    cout << ln;
//    for (auto &i : refB) cout << i << ' ';
//    cout << ln;

    vector <string> posA, posB;
    string ss = refA.back();
    for(int i = sz(refA) - 2; i >= 0; i--) ss = refA[i] + '.' + ss;
    posA.emplace_back(ss);
    if (sz(refB)) ss = '/' + refB[0];
    else ss = "";
    for (int i = 1; i < sz(refB); i++) ss = ss + '/' + refB[i];
    posB.emplace_back(ss);
    posB.emplace_back("/*");

    ss = "";
    forn(i, sz(refA)) {
      ss = refA[sz(refA) - i - 1] + ss;
      posA.emplace_back("*." + ss);
      ss = '.' + ss;
    } ss = "/";
    for (auto &i : refB) {
      ss += i;
      posB.emplace_back(ss + "/*");
      ss += '/';
    }

//    cout << "A: " << ln;
//    for (auto &i : posA) cout << i << ln;
//    cout << ln;
//    cout << "B: " << ln;
//    for (auto &i : posB) cout << i << ln;
//    cout << ln << ln;

    ll ans = 0;

    for (auto &i : posA) {
      for (auto &j : posB) {
        string S = i + j;
        ll h = 0;
        ll h2 = 0;
        forn(I, sz(S)) {
          h = (h * k + (S[I] - '#' + 1)) % mod;
          h2 = (h2 * k2 + (S[I] - '#' + 1)) % mod2;
        }
        ans += f[{h, h2}];
      }
    } cout << ans << ln;






  }

}