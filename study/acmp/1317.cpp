// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")
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

ll n, m;
vector <vector <char>> p;
vv64 used;

void dfs(ll i, ll j) {
	used[i][j] = true;
	if (i > 0 && !used[i - 1][j] && p[i - 1][j] == '#') dfs(i - 1, j);
	if (i < n - 1 && !used[i + 1][j] && p[i + 1][j] == '#') dfs(i + 1, j);
	if (j > 0 && !used[i][j - 1] && p[i][j - 1] == '#') dfs(i, j - 1);
	if (j < m - 1 && !used[i][j + 1] && p[i][j + 1] == '#') dfs(i, j + 1);
}

int main() {
    fast_cin();


    cin >> n >> m;
    p.resize(n, vector <char> (m));
    used.resize(n, v64 (m, 0));
    forn(i,n) {
    	string s;
    	cin >> s;
    	forn(j,m) p[i][j] = s[j];
    } ll ans = 0;
    
    forn(i,n) {
    	forn(j,m) {
    		// cout << i << ' ' << j << ln;
    		// cout << used[i][j] << ln;
    		// cout << p[i][j] << ln;
    		if (!used[i][j] && p[i][j] == '#') {
    			dfs(i,j);
    			ans++;
    		}
    	}
    } cout << ans << ln;


}
