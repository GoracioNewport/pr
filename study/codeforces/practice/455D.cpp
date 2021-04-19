//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

// Author: @GoracioNewport
  
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

struct block {
	v64 cnt;
	deque <ll> q;
	ll len;
	ll l;
	ll r;
};

int main() {
  fast_cin();

  ll n;
  cin >> n;
  ll len = sqrt(n) + 1;
  v64 a(n);
  for (auto &i : a) cin >> i;
  vector <block> d(n / len + 1);
	for (auto &i : d) {
		i.cnt.resize(n + 1, 0);
		i.l = INF;
		i.r = -1;
	}

	forn(i,n) {
		d[i / len].q.push_back(a[i]);
		d[i / len].cnt[a[i]]++;
		d[i / len].len++;
		d[i / len].l = min(d[i / len].l, i);
		d[i / len].r = max(d[i / len].r, i);
	}

	bool debug = false;
	// debug = true;

	// for (auto &i : d) {
	// 	cout << i.len << ' ' << i.l << ' ' << i.r << ln;
	// } 

	ll q;
	cin >> q;
	ll lastAns = 0;
	while(q--) {
		ll t;
		cin >> t;
		if (t == 1) {
			ll li, ri;
			cin >> li >> ri;
			ll l = ((li + lastAns - 1) + n) % n;
			ll r = ((ri + lastAns - 1) + n) % n;
			if (l > r) swap(l,r);

			if (debug) cout << "ROTATE " << l << ' ' << r << ln; 

			if (debug) { 
				for (auto &i : d) {
				for (auto &j : i.q) cout << j << ' ';
					cout << "| "; 
				} cout << ln;
			}
			ll prev = -1;
			bool fullBlockBegin = false, fullBlockEnd = false;
			if (l % len == 0) fullBlockBegin = true;
			if (r + 1 % len == 0) fullBlockEnd = true;


			for(ll i = l; i <= r;) {
				// cout << "Hello " << i << ln; 
				if (i % len == 0 && i + len <= (r + 1)) {
					if (debug) cout << "FULL BLOCK " << i << ' ' << i + d[i / len].len - 1 << ln;
					if (prev != -1) { // Добавляем в начало, если это не первый блок
						d[i / len].q.push_front(prev);
						d[i / len].cnt[prev]++;
					} prev = d[i / len].q.back(); // Удаляем последний
					d[i / len].cnt[prev]--;
					d[i / len].q.pop_back();
					i += len;
				} else {
					if (((l / len) * len) == ((r / len) * len)) {
						if (debug) cout << "Shit" << ln; // Если запрос попал только в один блок
						prev = *(d[i / len].q.begin() + (r % len));
						d[i / len].cnt[prev]--;
						d[i / len].q.erase(d[i / len].q.begin() + (r % len));
					} else if (i == l) { // begin
						if (debug) cout << "Begin" << ln;
						// надо удалить из текущего блока какой-то элемент
						prev = d[i / len].q.back();
						d[i / len].cnt[prev]--;
						d[i / len].q.pop_back();
					}	else { // end
						if (debug) cout << "End" << ln;
						// надо удалить из конца
						ll stac = 0;
						if (prev != -1) {
							// cout << "Pushing " << prev << ln; 
							d[i / len].q.push_front(prev);
							d[i / len].cnt[prev]++;
							stac++;
						} 
						prev = *(d[i / len].q.begin() + (r % len) + stac);
						d[i / len].cnt[prev]--;
						d[i / len].q.erase(d[i / len].q.begin() + (r % len) + stac);
					} i = d[i / len].r + 1; 
				}
			} if (fullBlockBegin) d[l / len].q.push_front(prev);
			else d[l / len].q.emplace(d[l / len].q.begin() + (l % len), prev);
			d[l / len].cnt[prev]++;

			if (debug) {
				for (auto &i : d) {
					for (auto &j : i.q) cout << j << ' ';
					cout << "| "; 
				} cout << ln;
			}
		} else {
			ll li, ri, ki;
			cin >> li >> ri >> ki;
			ll l = ((li + lastAns - 1) + n) % n;
			ll r = ((ri + lastAns - 1) + n) % n;
			ll k = (((ki + lastAns - 1) + n) % n) + 1;
			if (l > r) swap(l,r);

			if (debug) cout << "Query " << l << ' ' << r << ' ' << k << ln;
		
			ll ans = 0;
			for (ll i = l; i <= r;) {
				if (i % len == 0 && i + len <= (r + 1)) {
					if (debug) cout << "Full Block add " << d[i / len].cnt[k] << ln;
					ans += d[i / len].cnt[k];
					i += len;
				} else {
					ll pra = ans;
					if (((l / len) * len) == ((r / len) * len)) { 
						if (debug) cout << "Shit" << ln;
						ll ind = 0;
						ll l1 = l % len;
						ll r1 = r % len;
						for (auto &j : d[i / len].q) {
							if (ind >= l1 && ind <= r1) ans += (j == k);
							ind++;
						}
					} else if (i == l) {
						if (debug) cout << "Begin ";
						ll ind = 0;
						ll l1 = l % len;
						for (auto &j : d[i / len].q) {
							if (ind++ >= l1) ans += (j == k);
						}
					} else {
						if (debug) cout << "End ";
						ll ind = 0;
						ll r1 = r % len;
						for (auto &j : d[i / len].q) {
							if (ind++ <= r1) ans += (j == k);
						}
					} if (debug) cout << "add " << ans - pra << ln;
					i = d[i / len].r + 1; 
				}
			} cout << ans << ln;
			lastAns = ans;
		}
	}

}
