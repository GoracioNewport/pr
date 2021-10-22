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


const ll N = 20;
ll dp[N + 1][3][3];
string opt[N + 1][3][3];

ll get_nf(ll f, ll new_d, char sd) {
  sd -= '0';
  if (f == 0 || f == 2)
    return f;
  if (new_d < sd)
    return 0;
  if (new_d == sd)
    return 1;
  if (new_d > sd)
    return 2;
}

bool is_ok(ll l, ll lena, ll lenb, ll f1, ll f2) {
  bool ok1 = (l == lena && (f1 == 2 || f1 == 1)) || l > lena; // x >= a
  bool ok2 = (l == lenb && (f2 == 1 || f2 == 0)) || l < lenb; // x <= b
  return ok1 && ok2;
}

int main() {
  ll a, b;
  cin >> a >> b;

  string sa = to_string(a), sb = to_string(b);
  ll la = sa.size(), lb = sb.size();

  ll max_product = -1;
  string ans;
  memset(dp, -1, sizeof dp);
  dp[0][1][1] = 1;
  for (ll l = 0; l < N; ++l) {
    for (ll f1 = 0; f1 < 3; ++f1) {
      for (ll f2 = 0; f2 < 3; ++f2) {
        if (dp[l][f1][f2] == -1)
          continue;

        for (ll d = 0; d <= 9; ++d) {
          // dp[i][f1][f2] + d -> dp[i + 1][nf1][nf2]
          ll nf1 = get_nf(f1, d, l < la ? sa[l] : '0'), nf2 = get_nf(f2, d, l < lb ? sb[l] : '0');
          if (dp[l + 1][nf1][nf2] <= dp[l][f1][f2] * d) {
            dp[l + 1][nf1][nf2] = dp[l][f1][f2] * d;
            opt[l + 1][nf1][nf2] = opt[l][f1][f2];
            opt[l + 1][nf1][nf2].push_back('0' + d);
          }

          if (is_ok(l, la, lb, f1, f2)) {
            if (max_product < dp[l][f1][f2]) {
              max_product = dp[l][f1][f2];
              ans = opt[l][f1][f2];
            }
          }
        }
      }
    }
  }

  cout << ans << ln;
}