<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  ll n, m;
  cin >> n >> m;
  vector <ll> a(n + m);
  for (auto &i : a) cin >> i;

  if (n == m) {
    for (ll i = 0; i < n; i++) {
      swap(a[i], a[i + n]);
    }
  }

  else {
    ll p = m;
    for (ll i = 0; i < (n + m) - 1; i++) {
      swap(a[0], a[p]);
      p = (p + m) % (n + m);
      if (p == 0 && i < (n + m) - 2) {
        p = (p + m) % (n + m);
        swap(a[0], a[p]);
        p = (p + m) % (n + m);
      }
    }
  }

  for (auto &i : a) cout << i << ' ';
  cout << endl;
=======
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ll n, m;
	cin >> n >> m;
	vector <ll> a(n + m);
	for (auto &i : a) cin >> i;
	ll p;
	ll cnt = n + m;
	ll offset = 0;
	while (cnt > 0) {
		// cout << "New Cycle, offset " << offset << endl;
		p = (m + offset) % (n + m);
		ll b = p;
		do {
			swap(a[offset % (n + m)], a[p % (n + m)]);
			p = (p + m) % (n + m);
			// cout << p << endl;	
			cnt--;	
		} while (b != p && cnt > 0);
		offset++;
	} for (auto &i : a) cout << i << ' ';
	cout << endl;
	
>>>>>>> 687ac2dc6a6be5ff52518558462a7a29bf8e3088
}