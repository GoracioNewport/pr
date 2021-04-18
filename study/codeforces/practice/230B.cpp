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

int main() {
  fast_cin();

  v64 prime(1e6, 1);
  prime[0] = prime[1] = 0;
  for (int i = 2; i < 1e6; i++) {
    // cout << i << endl;
    if (!prime[i] || 1ll * i * i >= 1e6) continue;
    for (int j = i * i; j < 1e6; j += i) prime[j] = 0;
  } // for (int i = 1; i <= 20; i++) cout << prime[i] << ' ';
  // cout << endl;
  
  ll n;
  cin >> n;
  while (n--) {
    double x;
    cin >> x;
    x = sqrt(x);
    // cout << ((ll)x == x) << endl;
    if ((ll)x == x && prime[(ll)x]) cout << "YES\n";
    else cout << "NO\n"; 

  }  

}
