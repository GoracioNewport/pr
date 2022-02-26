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

  string longMul(ll a, ll b) {
    string A = to_string(a);
    string B = to_string(b);
    reverse(all(A));
    reverse(all(B));
    vector <ll> res(sz(A) + sz(B) + 5);
    for (ll i = 0; i < sz(A); i++) {
      for (ll j = 0; j < sz(B); j++) {
        ll x = (A[i] - '0') * (B[j] - '0');
        res[j + i] += x;
      }
    }

    forn(i,sz(res) - 1) {
      res[i + 1] += (res[i] / 10);
      res[i] %= 10;
    } reverse(all(res));

    bool c = false;
    string ans;
    forn(i,sz(res)) {
      if (res[i] != 0) c = true;
      if (c) ans += (char)(res[i] + '0');
    } return ans;
  }

  int main() {
    fast_cin();

    ll t;
    cin >> t;
    while(t--) {
      ll n, k, x;
      cin >> n >> k >> x; x--;
      string s;
      cin >> s;
      vector <pair <char, ll>> zip;
      ll buf = 0;


      forn(i, n) {
        if (s[i] == '*') buf++;
        else {
          if (buf > 0) zip.pb({'*', buf});
          buf = 0;
          zip.pb({'a', 1});
        }
      }
      if (buf > 0) zip.pb({'*', buf});

      v64 pos = {1};
      string K = to_string(k);
      reverse(all(zip));
      for (auto &i: zip) {
        if (i.fi == 'a') continue;
        if (pos.back() == INF) {
          pos.pb(INF);
          continue;
        } string longStr = longMul(pos.back(), (i.se * k + 1));
        if (sz(longStr) >= 19) pos.pb(INF);
        else pos.pb(stoll(longStr));
      }
      reverse(all(pos));

      reverse(all(zip));
      string ans = "";
      ll ind = 0;

      for (auto &i: zip) {
        if (i.fi == 'a') ans += 'a';
        else {
          string q = "";
          if (pos[ind + 1] != INF) {
            forn(i, x / pos[ind + 1]) q += 'b';
            ans += q;
            x %= pos[ind + 1];
          }
          ind++;
        }
      } cout << ans << ln;

    }

  }