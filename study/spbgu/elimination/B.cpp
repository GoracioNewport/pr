//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

// Author: @GoracioNewport
  
typedef int ll;
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
#define INF 2e9
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

int main() {
  fast_cin();

  ll n;
  cin >> n;
  v64 p(n);
  forn(i,n) {
  	cin >> p[i];
  	p[i]--;
  } vector <vector <pair <ll, p64>>> dp((1 << n), vector <pair <ll, p64>> (n, {INF, {-1, -1}})); // { ans, { prevI, prevJ } };

 //  for(auto& i : a) cout << i << ' ';
 //  cout << ln;

	// for(auto& i : p) cout << i << ' ';
	// cout << ln;


	forn(i,n) dp[(1 << i)][i] = { i + p[i], { 0, 0 } };

	for (ll i = 1; i < (1 << n); i++) { // состояние
		for (ll j = 0; j < n; j++) { // последний посещенный
			if (!(i & (1 << j))) continue;
			for (ll k = 0; k < n; k++) { // куда идем
				if (i & (1 << k)) continue;
				pair <ll, p64> ans;
				ans = { dp[i][j].fi + abs(j - k) + abs(p[j] - p[k]) , { j, p[j] } };
				dp[i | (1 << k)][k] = min(dp[i | (1 << k)][k], ans);
			}
		}
	} 

	pair <ll, p64> ans = {INF, {INF, INF}};
	forn(i,n) ans = min(ans, {dp[(1 << n) - 1][i].fi, {i, p[i]}});


	// cout << ans.fi << ' ' << ans.se.fi << ' '  << ln;

	// forn(i, (1 << n)) {
	// 	forn(j,n) {
	// 		cout << i << ' ' << j << ' ' << dp[i][j].fi << ' ' << dp[i][j].se.fi << ' ' << dp[i][j].se.se << ln;
	// 	}
	// }

	string Ans;

	ll curState = (1 << n) - 1;
	ll curPosX = ans.se.fi;
	ll curPosY = ans.se.se;

	// cout << ans.fi << ln;

	// cout << curState << ln;

	while(dp[curState][curPosX].se.fi != -1) {
		ll prevPosX = dp[curState][curPosX].se.fi;
		ll prevPosY = dp[curState][curPosX].se.se;

		// cout << curState << ' ' << curPos << ' ' << prevPos << ln;

		char u = (prevPosX < curPosX ? 'R' : 'L');
		char l = (prevPosY < curPosY ? 'r' : 'l');
		forn(i, abs(curPosX - prevPosX)) Ans.pb(u);
		forn(i, abs(curPosY - prevPosY)) Ans.pb(l);

		// cout << curState << ' ' << (1 << curPos) << ln;
		curState = curState & ((1 << curPosX) ^ ((1 << 20) - 1));
		// cout << curState << ln;
		curPosX = prevPosX;
		curPosY = prevPosY;
	} reverse(all(Ans));

	cout << Ans << ln;


}
