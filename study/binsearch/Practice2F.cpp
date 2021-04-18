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
bool ok(string &s1, string &s2, v64 &indp, ll m) { v64 ind; forn(i,m) ind.pb(indp[i] - 1); sort(all(ind)); string s3; ll lin = 0; forn(i, sz(s1)) { if (i == ind[lin]) lin++; else s3 += s1[i]; } lin = 0; forn(i, sz(s3)) if (s3[i] == s2[min(sz(s2) - 1, lin)]) lin++; return (lin >= sz(s2)); }
int main() { fast_cin(); string t, p; cin >> t >> p; ll n = sz(t); v64 ind(n); for (auto &i : ind) cin >> i; ll l = 0; ll r = n; while (l + 1 < r) { ll m = (l + r) / 2; if (ok(t, p, ind, m)) l = m; else r = m;} cout << l << endl; }
 