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

struct block {
  string type;
  ll x = 0;
  ll y = 0;
};

int main() {
  fast_cin();
  
  ll n, k;
  cin >> n >> k;
  vector <ll> ok(k, 1);
  vector <block> blocks;

  forn(i,n) {
    string s;
    cin >> s;
    if (s == "begin" || s == "end") blocks.pb({s});
    else if (s == "not") {
      ll x;
      cin >> x;
      blocks.pb({s,x});
    } else {
      ll x, y;
      cin >> x >> y;
      blocks.pb({s,x,y});
    }
  } const ll siz = k;
  ll ans = -1;

  for(int i = 0; i < (1 << k); i++) {
    ll cnt = 0;
    bitset <12> a;
    ll origin = a.to_ullong();
    ll ind = 0;
    bool good = true;
    while (ind < n) {
      cnt++;
      if (cnt > 2e7) {
        good = false;
        break;
      }
      block c = blocks[ind];
      if (c.type == "begin") ind++;
      else if (c.type == "end") break;
      else if (c.type == "and") {
        ll z = a[c.x] & a[c.y];
        a[c.x] = z;
        ind++;
      } else if (c.type == "or") {
        ll z = a[c.x] | a[c.y];
        a[c.x] = z;
        ind++;
      } else if (c.type == "xor") {
        ll z = a[c.x] ^ a[c.y];
        a[c.x] = z;
        ind++;
      } else if (c.type == "move") {
        a[c.x] = a[c.y];
        ind++;
      } else if (c.type == "set") {
        a[c.x] = c.y;
        ind++;
      } else if (c.type == "not") {
        a[c.x] = !a[c.x];
        ind++;
      } else if (c.type == "jump") {
        if (a[c.x]) ind = c.y;
        else ind++;
      }
    } if (!good) {
      ans = origin;
      break;
    }
  } if (ans == -1) cout << "Yes\n";
  else {
    cout << "No\n";
    string s = bitset<12> (ans).to_string();
    reverse(s.begin(), s.end());
    s = s.substr(0, k);
    cout << s << endl;
  }

}
