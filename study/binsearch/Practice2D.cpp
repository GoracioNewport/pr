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

struct Human {
	ll t; // Время надувания одного шара
	ll z; // Сколько надует перед уставанием
	ll y; // Сколько отдыхает
};

ll z, n;
vector <Human> a;

ll findP(Human i, ll t) {
	ll ans = 0;
	ll fullCycleTime = (i.t * i.z) + i.y;
	ans += (t / fullCycleTime) * i.z;
	ans += min(i.z, (t % fullCycleTime) / i.t);
	return ans;
}

bool good(ll x) {
	ll ans = 0;
	for (auto &i : a) ans += findP(i, x);
	return (ans <= z);
}

int main() {
	cin >> z >> n;
	a.resize(n);
	for (auto &i : a) cin >> i.t >> i.z >> i.y;
	ll l = 0;
	ll r = INF;
	while(l + 1 < r) {
		ll m = (l + r) / 2;
		if (good(m)) l = m;
		else r = m;
	} cout << l << ln;
	for (auto &i : a) {
		ll x = findP(i,l);
		cout << min(x, z) << ' ';
		z -= min(x, z);
	} 
}
