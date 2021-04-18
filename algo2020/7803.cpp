#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {
	queue <ll> q, qm;

	ll n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		ll a;
		cin >> a;

		if (a != 0) {
			q.push(a);
			if (qm.size() == 0 || a < qm.back()) qm.push(a);
			else qm.push(qm.front());
			// cout << q.front() << ' ' << qm.front() << endl;
		} else {
			if (q.size() > 0) {
				cout << qm.back() << endl;
				q.pop();
				qm.pop();
			} else cout << -1 << endl;
		}
	}
}