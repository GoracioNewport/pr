#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ios::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	ll m;
	cin >> s >> m;
	ll n = s.size();

	ll a = m / n + 1;
	if (m % n == 0) a--;

	ll b = m % n;
	if (m % n == 0) b = n;

	if (((b + (a - 1)) % n) == 0) cout << s[0] << endl;
	else cout << s[((b + (a - 1)) % n) - 1] << endl;
}