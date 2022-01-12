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

struct Set {
  ll Min;
  ll Max;
  ll Cardinality;
  ll Leader;
};

vector <Set> info;
v64 r;
ll n; 

void init() {
  // cout << "Init... " << n << endl;
  r.resize(n, 0);
  info.resize(n);
  forn(i,n) info[i] = {i,i,1,i};
}

ll findP(ll v) {
  // cout << "SHIT " << sz(info) << endl;
  // cout << info[v].Min << ' ' << info[v].Max << ' ' << info[v].Cardinality << ' ' << info[v].Leader << endl;
  return (info[v].Leader == v ? v : info[v].Leader = findP(info[v].Leader));
}

void unionSet(ll a, ll b) {
  // cout << "Hi" << endl;
  a = findP(a);
  b = findP(b);
  if (a == b) return;
  if (r[a] > r[b]) swap(a, b);
  if (r[a] == r[b]) r[b]++;


  info[b].Min = min(info[a].Min, info[b].Min);
  info[b].Max = max(info[a].Max, info[b].Max);
  info[b].Cardinality += info[a].Cardinality;
  info[a].Leader = b;
}

int main() {
  fast_cin();
  
  ll q;
  cin >> n >> q;
  init();
  while (q--) {
    string s;
    cin >> s;
    if (s == "get") { 
      ll i;
      cin >> i;
      i--;
      i = findP(i);
      cout << info[i].Min + 1 << ' ' << info[i].Max + 1 << ' ' << info[i].Cardinality << ln;
    } else {
      ll v, u;
      cin >> v >> u;
      unionSet(v - 1, u - 1);
    }
  }

}
