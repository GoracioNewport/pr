#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime>
#include <bitset>
#include <complex>
#include <random>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#ifdef DEBUG
	const ll MAXN = 4e3 + 1;
	const ll MAXLOG = 7;
	const ll MAXSQRT = 4;
#else
	const ll MAXN = 1e6 + 10;
	const ll MAXLOG = 29;
	const ll MAXSQRT = 400;
	#define cerr if (false) cerr
#endif

mt19937 rng(time(0));

const ll INF = 1e9;
const ll MOD = 1e9 + 7;

ll n;

ll val[MAXN];
ll lol[MAXN];
ll pos[MAXN];
ll nlol[MAXN];
ll npos[MAXN];

inline void init() {
	for (ll i = 0; i < n; i++) {
		pos[i] = i;
	}
}

inline ll solve(ll log) {
	ll cnt = 0;
	for (ll i = 0; i < n; i++) {
		if (!(val[pos[i]] & (1 << log))) {
			npos[cnt] = pos[i];
			nlol[cnt++] = lol[i];
		}
	}
	for (ll i = 0; i < n; i++) {
		if ((val[pos[i]] & (1 << log))) {
			npos[cnt] = pos[i];
			nlol[cnt++] = lol[i] | (1 << log);
		}
	}
	for (ll i = 0; i < n; i++) {
		lol[i] = nlol[i];
		pos[i] = npos[i];
	}
	ll ans = 0;
	ll ptr_1 = 0;
	ll ptr_2 = 0;
	ll ptr_3 = 0;
	for (ll i = 0; i < n; i++) {
		while (ptr_1 >= 0 && lol[i] + lol[ptr_1] >= (1 << log)) {
			ptr_1--;
		}
		while (ptr_2 >= 0 && lol[i] + lol[ptr_2] >= (1 << (log + 1))) {
			ptr_2--;
		}
		while (ptr_3 >= 0 && lol[i] + lol[ptr_3] >= (1 << (log + 1)) + (1 << log)) {
			ptr_3--;
		}
		ans ^= (ptr_2 - ptr_1) & 1;
		ans ^= (i - ptr_3) & 1;
		ptr_1++;
		ptr_2++;
		ptr_3++;
	}
	return ans;
}

inline void solve() {
	init();
	for (ll i = 0; i < n; i++) {
		cin >> val[i];
	}
	ll ans = 0;
	for (ll i = 0; i < MAXLOG; i++) {
		ans |= solve(i) << i;
	}
	cout << ans << '\n';
}

signed main() {
	#ifdef DEBUG
		freopen("B.in", "r", stdin);
		freopen("B.out", "w", stdout);
	#else
	
	#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while (cin >> n)
		solve();
	return 0;
}