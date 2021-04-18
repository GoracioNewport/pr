#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define INF 2e18
#define eps = 10e-6

bool good(ld c, ld x) {
	return ((x * x + sqrt(x)) >= c);
}

int main() {
	ld c;
	cin >> c;
	ld l = 0;
	ld r = INF;
	for(ll z = 0; z < 200; z++) {
		ld m = (l + r) / 2;
		if (good(c,m)) r = m;
		else l = m;
	} cout << setprecision(20) << fixed << l << endl;
}