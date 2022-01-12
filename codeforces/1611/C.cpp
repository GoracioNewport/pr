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
    while(t--) {
      ll n;
      cin >> n;
      v64 a(n);
      for (auto& i : a) cin >> i;
      deque <ll> q;
      q.push_back(max(a[0], a.back()));

      ll l = 0;
      ll r = n - 1;
      if (q.front() == a[0]) l++;
      else r--;

      bool good = true;
      while(l <= r) {

        // a - конечная
        // q - начальная

  //      cout << l << ' ' << r << ln;
        if (a[l] == min(a[l], q.back())) {
          q.push_front(a[l]);
          l++;
        } else if (a[r] == min(a[r], q.front())) {
          q.push_back(a[r]);
          r--;
        } else {
          good = false;
          break;
        }
      } if (good) {
        while(!q.empty()) {
          ll x = q.front();
          cout << x << ' ';
          q.pop_front();
        } cout << ln;
      } else {
        cout << -1 << ln;
      }

    }

  }