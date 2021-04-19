#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <ll> v64;
#define ln '\n'


int main() {
	ll n,k;
	cin >> n >> k;
	v64 a(n);
	for (auto &i : a) cin >> i;
	v64 ps(n + 1, 0);
	for(ll i = 0; i < n; i++) ps[i + 1] = ps[i] + a[i];
	v64 mp(n + 1, 0);
	v64 ms(n + 1, 0);
	for(ll i = k; i <= n; i++) mp[i] = max(mp[i - 1], ps[i] - ps[i - k])
}
