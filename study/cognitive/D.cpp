// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")
 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
// Author: @GoracioNewport
 
using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<int> v32;
typedef vector<ll> v64;
typedef vector<ld> vdd;
typedef vector<v32> vv32;
typedef vector<v64> vv64;
typedef vector<vdd> vvdd;
typedef vector<p64> vp64;
typedef vector<vp64> vvp64;
 
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define ln "\n"
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define fastCin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
 
mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
 
istream& operator>>(istream& in, v64& a) {
  for (auto& i : a) in >> i;
  return in;
}
 
istream& operator>>(istream& in, vp64& a) {
  for (auto& i : a) in >> i.fi >> i.se;
  return in;
}
 
istream& operator>>(istream& in, vv64& a) {
  for (auto& i : a) for (auto& j : i) in >> j;
  return in;
}
 
istream& operator>>(istream& in, vvp64& a) {
  for (auto& i : a) for (auto& j : i) in >> j.fi >> j.se;
  return in;
}
 
ostream& operator<<(ostream& out, v64& a) {
  for (auto& i : a) out << i << ' ';
  return out;
}
 
ostream& operator<<(ostream& out, vp64& a) {
  for (auto& i : a) out << i.fi << ' ' << i.se << ln;
  return out;
}
 
ostream& operator<<(ostream& out, vv64& a) {
  for (auto& i : a) {
    for (auto& j : i) out << j << ' ';
    cout << ln;
  } return out;
}
 
ostream& operator<<(ostream& out, vvp64& a) {
  for (auto& i : a) {
    for (auto& j : i) out << j.fi << ' ' << j.se << ln;
    cout << ln;
  } return out;
}
 
ll mod = 1791791791;
ld eps = 1e-12;
ll INF = 2e18;
 
bool DEBUG = false;

int main() {
  fastCin();
 
	ll n, k, q;
	cin >> n >> k >> q;
	v64 A(n);

	vv64 a(k);

	forn(i,n) a[i % k].pb(0);

	vector <set <pair <ll, p64>>> inds(k);

	forn(i,k) inds[i].insert({0, {sz(a[i]) - 1, 0}}); // <l, <r, color>>

	ll ans = 0;

	forn(i,k) {
		ll x = sz(a[i]);
		ans += x * (x + 1) / 2 - x;
	} 

	while(q--) {

		if (DEBUG) cout << ln << ln << "------" << ln;
		
		ll m, r;
		cin >> m >> r; m--;
		if (A[m] == r) {
			cout << ans << ln;
			continue;
		} A[m] = r;

		ll c = m % k;
		ll i = m / k;

		auto it = prev(inds[c].upper_bound({i, {INF, INF}}));
		pair <ll, p64> curColor = *it;

		if (DEBUG) {
			cout << "CURRENT STATE: " << ln;
			for (auto& i : inds[c]) {
				cout << i.fi << ' ' << i.se.fi << ' ' << i.se.se << ln;
			}

		}
		if (DEBUG) cout << "CUR: " << curColor.fi << ' ' << curColor.se.fi << ' ' << curColor.se.se << ln;

		auto prevIt = prev(it, 1);
		auto nextIt = next(it, 1);

		pair <ll, p64> prevColor, nextColor;

		if (it == inds[c].begin()) prevColor = {-1, {-1, -1}};
		else prevColor = (*prevIt);

		if (nextIt == inds[c].end()) nextColor = {-1, {-1, -1}};
		else nextColor = (*nextIt);

		if (DEBUG) {
			cout << "PREV: ";
			if (prevColor.fi == -1) cout << "none";
			else cout << prevColor.fi << ' ' << prevColor.se.fi << ' ' << prevColor.se.se;
			cout << ln; 

			cout << "NEXT: ";
			if (nextColor.fi == -1) cout << "none";
			else cout << nextColor.fi << ' ' << nextColor.se.fi << ' ' << nextColor.se.se;
			cout << ln;
		}

		{ // Вычитаем ответ для текущего отрезка
			ll x = curColor.se.fi - curColor.fi + 1;
			ans -= x * (x + 1) / 2 - x;
		} if (DEBUG) cout << "AAA " << ans << ln;

		{ // Добавляем ответ для новых трех (двух (одного))) отрезков, образовавшихся после разделения
			if (i == curColor.fi && i == curColor.se.fi) { // Попали в отрезок длиной один

				if (DEBUG) cout << "SINGLE SEGMENT" << ln;

				inds[c].erase(it);

				if (r == prevColor.se.se && r == nextColor.se.se) { // Если оба соседа нашего цвета, склеиваем
				
					ll x = (prevColor.se.fi - prevColor.fi + 1);
					ans -= x * (x + 1) / 2 - x;
					
					x = (nextColor.se.fi - nextColor.fi + 1);
					ans -= x * (x + 1) / 2 - x;

					inds[c].erase(prevIt);
					inds[c].erase(nextIt);

					inds[c].insert({prevColor.fi, {nextColor.se.fi, r}});

					x = (nextColor.se.fi - prevColor.fi + 1);
					ans += x * (x + 1) / 2 - x;
				
				} else if (r == prevColor.se.se) { // Если левый сосед нашего цвета, склеиваем
				
					ll x = (prevColor.se.fi - prevColor.fi + 1);
					ans -= x * (x + 1) / 2 - x;

					inds[c].erase(prevIt);
					inds[c].insert({prevColor.fi, {prevColor.se.fi + 1, r}});

					x = (prevColor.se.fi + 1) - (prevColor.fi) + 1;
					ans += x * (x + 1) / 2 - x;
				
				} else if (r == nextColor.se.se) { // Если правый сосед нашего цвета, склеиваем
					
					ll x = (nextColor.se.fi - nextColor.fi + 1);
					ans -= x * (x + 1) / 2 - x;
				
					inds[c].erase(nextIt);
					inds[c].insert({nextColor.fi - 1, {nextColor.se.fi, r}});

					x = (nextColor.se.fi - (nextColor.fi - 1)) + 1;
					ans += x * (x + 1) / 2 - x;

				} else inds[c].insert({i, {i, r}}); // Иначе просто заменяем на новый еденичный отрезок
			} 


			else if (i == curColor.fi) { // Попали в левый край отрезка

				if (DEBUG) cout << "LEFT EDGE" << ln;

				inds[c].erase(it);

				// if (DEBUG) cout << r << ' ' << prevColor.se.se << ln; 

				if (r == prevColor.se.se) { // Если стали одного цвета с левым соседом, склеиваем

					ll x = (prevColor.se.fi - prevColor.fi + 1);
					ans -= x * (x + 1) / 2 - x;

					inds[c].erase(prevIt);
					inds[c].insert({prevColor.fi, {prevColor.se.fi + 1, r}});

					x = (prevColor.se.fi + 1) - (prevColor.fi) + 1;
					ans += x * (x + 1) / 2 - x;
				} else inds[c].insert({i, {i, r}});

				inds[c].insert({i + 1, {curColor.se.fi, curColor.se.se}});

				ll x = curColor.se.fi - (i + 1) + 1;
				ans += x * (x + 1) / 2 - x;
			} 


			else if (i == curColor.se.fi) { // Попали в правый край отрезка
				inds[c].erase(it);

				if (r == nextColor.se.se) { // Если стали одного цвета с правым соседом, склеиваем
					ll x = (nextColor.se.fi - nextColor.fi + 1);
					ans -= x * (x + 1) / 2 - x;
				
					inds[c].erase(nextIt);
					inds[c].insert({nextColor.fi - 1, {nextColor.se.fi, r}});

					x = (nextColor.se.fi - (nextColor.fi - 1)) + 1;
					ans += x * (x + 1) / 2 - x;
				
				} else inds[c].insert({i, {i, r}});

				inds[c].insert({curColor.fi, {i - 1, curColor.se.se}});
				ll x = (i - 1) - (curColor.fi) + 1;
				ans += x * (x + 1) / 2 - x;
			} 


			else { // Просто разделяем текущий отрезок на три части

				inds[c].erase(it);

				ll l = curColor.fi;
				ll R = curColor.se.fi;
				
				inds[c].insert({l, {i - 1, curColor.se.se}});
				inds[c].insert({i, {i, r}});
				inds[c].insert({i + 1, {R, curColor.se.se}});

				ll x = (i - 1) - l + 1;
				ans += x * (x + 1) / 2 - x;

				x = R - (i + 1) + 1;
				ans += x * (x + 1) / 2 - x;
			}
		} cout << ans << ln;
		
	}
 
}

