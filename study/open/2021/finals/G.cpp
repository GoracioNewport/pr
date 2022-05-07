#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
 
#include <bits/stdc++.h>
// Author: @GoracioNewport
 
using namespace std;
 
typedef long long ll;
typedef vector<int> v32;
typedef vector<pair<ll,ll>> vp64;
typedef vector<ll> v64;
 
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define ln "\n"
#define fastCin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
 
istream& operator>>(istream& in, v64& a) {
  for (auto& i : a) in >> i;
  return in;
}
 
ostream& operator<<(ostream& out, v64& a) {
  for (auto& i : a) out << i << ' ';
  return out;
}
 
ll mod = 998244353;
ll INF = 2e18;

ll binPow(ll a, ll n) {
	if (n == 0) return 1;
	if (n % 2) return binPow(a, n - 1) * a % mod;
	else {
		ll b = binPow(a, n / 2);
		return b * b % mod;
	}
}

ll rev(ll x) {
	return binPow(x, mod - 2);
}

struct Tree {
	v32 t, a;
	int n;

	Tree (v32& _a) {
		a = _a;
		n = a.size();
		t.assign(4 * n, 0);
		build(0, 0, n);
	}

	void build(ll v, ll l, ll r) {
		if (l + 1 == r) {
			t[v] = a[l];
			return;
		} ll m = (l + r) / 2;
		build(2 * v + 1, l, m);
		build(2 * v + 2, m, r);
		t[v] = t[2 * v + 1] + t[2 * v + 2];
	}

	void setX(ll v, ll l, ll r, ll i, ll x) {
		if (l + 1 == r) {
			t[v] = x;
			return;
		} ll m = (l + r) / 2;
		if (i < m) setX(2 * v + 1, l, m, i, x);
		else setX(2 * v + 2, m, r, i, x);
		t[v] = t[2 * v + 1] + t[2 * v + 2];
	}

	ll getSum(ll v, ll l, ll r, ll L, ll R) {
		if (l >= L && r <= R) return t[v];
		if (l >= R || r <= L) return 0;
		ll m = (l + r) / 2;
		return getSum(2 * v + 1, l, m, L, R) + getSum(2 * v + 2, m, r, L, R);
	}
};

bool DEBUG = false;

void solveShort(int n, int m, v32& a, v32& b, int maxC, v32& cnt, v64& factorial) {
	sort(all(a));
	Tree t(cnt);

	ll ans = 0;


	for (ll i = 0; i < m; i++) {
		if (DEBUG) cout << "I: " << i << ln;
		if (i == n) {
			if (DEBUG) cout << "Corner case" << ln;
			bool good = true;
			for (auto& j : cnt) if (j != 0) good = false;
			if (good) ans = (ans + 1) % mod;
			break;
		}


		ll cntSmaller = t.getSum(0, 0, maxC + 1, 0, b[i]);
		if (DEBUG) cout << cntSmaller << ln;
		ans = (ans + (cntSmaller * factorial[n - i - 1]) % mod) % mod;
		t.setX(0, 0, maxC + 1, b[i], 0);
		cnt[b[i]]--;
		if (cnt[b[i]] < 0) break;
 	} cout << ans << ln;

}
 
int main() {
  fastCin();

  ll t = chrono::high_resolution_clock::now().time_since_epoch().count();
 
	int n, m;

	cin >> n >> m;
	// n = 200000, m = 200000;

	int maxN = max(n, m);
	v32 a(n), b(m);
	
	for (int& i : a) cin >> i;
	for (int& i : b) cin >> i;

	// for (int& i : a) i = ((int)rng() % 200) + 1;
	// for (int& i : b) i = ((int)rng() % 200) + 1;

	int maxC = max(*max_element(all(a)), *max_element(all(b)));
	v32 cnt(maxC + 1);
	for (int& i : a) cnt[i]++;
	
	v64 factorial(maxN + 1);
	factorial[0] = 1;

	forsn(i,1,maxN + 1) factorial[i] = (factorial[i - 1] * i) % mod;

	if (maxC > 200) {
		solveShort(n, m, a, b, maxC, cnt, factorial);
		return 0;
	}


	v64 revF(maxN + 1);
	revF[0] = 1;
	revF[maxN] = rev(factorial[maxN]);

	for (int i = maxN; i >= 2; i--) {
		revF[i - 1] = (revF[i] * (ll)i) % mod; 
	}

	ll ans = 0;

	ll x = 1;
	for (auto& i : cnt) x = (x * revF[i]) % mod;


	for (int i = 0; i < m; i++) { // Перебираем место, где произошло расхождение индексов
		if (i == n) {
			bool good = true;
			for (auto& j : cnt) if (j != 0) good = false;
			if (good) ans++;
			break;
		}


		for (int j = b[i] - 1; j >= 1; j--) {
			if (cnt[j] <= 0) continue;
			ans += (((factorial[n - i - 1] * x) % mod) * cnt[j]) % mod;
		} 

		cnt[b[i]]--;
		if (cnt[b[i]] < 0) break;
		x = (x * (cnt[b[i]] + 1)) % mod;
	} 



	cout << ans % mod << ln;



	// cout << fixed << setprecision(20 (ld)(chrono::high_resolution_clock::now().time_since_epoch().count()) / 1e9 << ln;
 
}

