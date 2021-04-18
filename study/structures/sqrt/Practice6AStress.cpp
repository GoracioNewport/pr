#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

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

mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

int main() {
  fast_cin();
  while (true) {
    ll n = (rng() % 10) + 1;
    ll q = (rng() % 5) + 1;
    cout << "-----------" << endl;
    cout << n << ' ' << q << endl;
    v64 aStupid(n, 0);
    v64 a(n, 0);
    ll len = sqrt(n) + 1;
    v64 Min(n / len + 1, 0);
    v64 add(n / len + 1, 0);
    while(q--) {
      ll t = (rng() % 2) + 1;
      ll l = (rng() % n);
      ll r = min(n, (ll)(rng() % (n - l)) + l + 1); r--;
      if (t == 1) {
        ll x = (rng() % (ll)10);
        cout << t << ' ' << l << ' ' << r + 1 << ' ' << x << endl;
        for(ll i = l; i <= r;) {
          if (i % len == 0 & i + len <= r) {
            add[i / len] += x;
            Min[i / len] += x;
            i += len;
          } else {
            if (i == l || i == (r / len) * len) {
              // cout << "Minimum update" << endl;
              ll l1 = (i / len) * len;
              ll r1 = min(l1 + len, n);
              // cout << "AAAA " << l1 << ' ' << r1 << endl;
              Min[l1 / len] = INF;
              forsn(j,l1,r1) {
                if (j >= l && j <= r) Min[j / len] = min(Min[j / len], a[j] + x);
                else Min[j / len] = min(Min[j / len], a[j]);
                // cout << Min[l1 / len] << endl;
              }
            } a[i] += x;
            i++;
          }
        }  forsn(i,l,r + 1) aStupid[i] += x;
      } else {
        cout << t << ' ' << l << ' ' << r + 1 << endl;
        ll ans = a[l] + add[l / len];
        for(ll i = l; i <= r;) {
          if (i % len == 0 && i + len <= r) {
            ans = min(ans, Min[i / len] + add[i / len]);
            i += len;
          } else {
            ans = min(ans, a[i] + add[i / len]);
            i++;
          }
        } ll ansStup = aStupid[l];
        forsn(i,l,r + 1) ansStup = min(ansStup, aStupid[i]);
        if (ans != ansStup) {
          cout << "ASSSS" << endl;
          return(0);
        }
      }
    }
  }
}
