#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll x; cin >> x;
        for(ll i = 0; i < n - 1; i++) {
            ll y;
            cin >> y;
            x &= y;
        } cout << x << '\n';
    }
    
}