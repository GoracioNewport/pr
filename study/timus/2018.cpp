<<<<<<< HEAD
<<<<<<< HEAD
=======
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

// Author: @GoracioNewport

using namespace std;

=======
>>>>>>> 4cedac459bab408b206c83f5a244494e5c8c244a
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

// Author: @GoracioNewport
  
<<<<<<< HEAD
=======
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

// Author: @GoracioNewport

using namespace std;

>>>>>>> 3ea0f8c3a53376f9682af1b30d62f919759f2cdf
=======
>>>>>>> 687ac2dc6a6be5ff52518558462a7a29bf8e3088
>>>>>>> 4cedac459bab408b206c83f5a244494e5c8c244a
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

ll mod = 1e9 + 7;

int main() {
  fast_cin();

  ll n, a, b;
  cin >> n >> a >> b;
<<<<<<< HEAD
<<<<<<< HEAD
  if (b < a) swap(a,b);
  vv64 dpA(n + 1, v64 (2, 0));
  vv64 dpB(n + 1, v64 (2, 0));
  dpA[0][0] = dpA[0][1] = 0;
  dpA[1][0] = dpA[1][1] = 1;
  dpB[0][0] = dpB[0][1] = 0;
  dpB[1][0] = dpB[1][1] = 1;
  // for(ll i = 2; i <= a; i++) {
  // 	dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % mod;
  // 	dp[i][1] = (dp[i - 1][0] + dp[i - 1][1]) % mod;
  // }


  
=======
=======
>>>>>>> 4cedac459bab408b206c83f5a244494e5c8c244a

  vv64 dp(n + 1, v64 (2, 0));
  dp[0][0] = dp[0][1] = 0;
  dp[1][0] = dp[1][1] = 1;

  forsn(i,2,a + 1) dp[i][0] = (dp[i - 1][0] * 2) % mod;
  forsn(i,2,b + 1) dp[i][1] = (dp[i - 1][1] * 2) % mod;



  forsn(i,min(a,b) + 1, max(a,b) + 1) {
    if (a < b) dp[i][0] = (dp[i - 1][0] * 2 - dp[i - a][0]) % mod;
    else dp[i][1] = (dp[i - 1][1] * 2 - dp[i - b][1]) % mod;
  }


  forsn(i,max(a,b) + 1, n + 1) {
//    cout << i << ln;
    dp[i][0] = (dp[i - 1][0] * 2 - dp[i - a][0]) % mod;
    dp[i][1] = (dp[i - 1][1] * 2 - dp[i - b][1]) % mod;
  } cout << (dp[n][0] + dp[n][1]) % mod << ln;

//  for (auto &i : dp) {
//    cout << i[0] << ' ' << i[1] << ln;
//  }
<<<<<<< HEAD
>>>>>>> 3ea0f8c3a53376f9682af1b30d62f919759f2cdf
=======
=======
  if (b < a) swap(a,b);
  vv64 dpA(n + 1, v64 (2, 0));
  vv64 dpB(n + 1, v64 (2, 0));
  dpA[0][0] = dpA[0][1] = 0;
  dpA[1][0] = dpA[1][1] = 1;
  dpB[0][0] = dpB[0][1] = 0;
  dpB[1][0] = dpB[1][1] = 1;
  // for(ll i = 2; i <= a; i++) {
  // 	dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % mod;
  // 	dp[i][1] = (dp[i - 1][0] + dp[i - 1][1]) % mod;
  // }


  
>>>>>>> 687ac2dc6a6be5ff52518558462a7a29bf8e3088
>>>>>>> 4cedac459bab408b206c83f5a244494e5c8c244a
}