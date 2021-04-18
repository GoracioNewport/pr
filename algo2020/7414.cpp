#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {
	ll a, b, d;
	cin >> a >> b >> d;
	
	ll scd = abs(a - b);
	ll f, s;
	if (scd > 1) {
		f = scd / 2;
		s = scd - f;
	} else {
		f = -1;
		s = 2;
	}

	ll leftPoint = min(a, b);

	ll p1 = leftPoint + f;
	ll p2 = leftPoint + s;

	ll r1 = p1 % d;
	ll r2 = p2 % d;

	ll leftKiosk = min(r1, d - r1);
	ll rightKiosk = min(r2, d - r2);

	if (leftKiosk <= rightKiosk) cout << p1 << ' ' << leftKiosk << endl; 
	else cout << p2 << ' ' << rightKiosk << endl;

}
