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

ll p, q, k;
ll ans;

void f(ll x, ll c) {
	// cout << x << ln;
	if (x == 1) {
		ans += c;
		return;
	} if (x < q && c == 0) return;
	if (x == q) c = 1;
	if (x % k == 0) f(x / k, c);
	f(x - 1, c);
}

int main() {
    fast_cin();
    ifstream in;
    ofstream out;
    in.open("a2.txt");
    out.open("a2ans.txt");

    ll t;
    in >> t;
    while(t--) {
    	in >> p >> q >> k;
    	ans = 0;
    	f(p, 0);
    	out << ans << ln;
    }

    in.close();
    out.close();

}
