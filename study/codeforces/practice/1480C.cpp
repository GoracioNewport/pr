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

int main() {
    fast_cin();

    ll n;
    cin >> n;
    if (n == 1) {
    	cout << "! 1" << endl;
    	return(0);
    } ll x1, y1, x2, y2;
    cout << "? 1" << endl;;
    cin >> x1;
    cout << "? 2" << endl;
    cin >> y1;
    cout << "? " << n - 1 << endl;
    cin >> x2;
    cout << "? " << n << endl;
    cin >> y2;
    if (y1 > x1) {
    	cout << "! 1" << endl;
    	return(0);
    } if (x2 > y2) {
    	cout << "! " << n << endl;
    	return(0);
    }

    ll l = 2;
    ll r = n - 1;
    while(l + 1 < r) {
    	ll m = (l + r) / 2;
    	ll m1 = m + 1;
    	ll x, x1;
    	cout << "? " << m << endl;
    	cin >> x;
    	cout << "? " << m1 << endl;
    	cin >> x1;
    	if (x1 > x) r = m;
    	else l = m;
    } vp64 ans;
    for (ll i = l - 5; i <= l + 5; i++) {
    	if (i >= 1 && i <= n) {
    		cout << "? " << i << endl;
    		ll x;
    		cin >> x;
    		ans.pb({x,i});
    	}
    } for (ll i = 1; i <= sz(ans) - 1; i++) {
    	if (ans[i].fi < ans[i - 1].fi && ans[i].fi < ans[i + 1].fi) {
    		cout << "! " << ans[i].se << endl;
    		return(0);
    	}
    }

}
