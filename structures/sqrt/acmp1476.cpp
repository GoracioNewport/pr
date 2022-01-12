// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")
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

const ll n = 1e5 + 20;
const ll len = 1000;
ll q;
v64 a(n, 0);
v64 sum(n / len + 1, 0);

ll cnt = 0;

ll getSum(ll l, ll r) {
  ll ans = 0;
  for(ll i = l; i <= r;) {
    if (i % len == 0 && i + len <= (r - 1)) {
      ans += sum[i / len];
      i += len;
    } else {
      ll l1 = (i / len) * len;
      ll r1 = min(l1 + len, n);
      if (sum[i / len] == (r1 - l1)) ans++;
      else if (sum[i / len] != 0) ans += a[i];
      i++;
    }
  } return ans;
}

void modify(ll x, ll l) {
  ll r = n - 1;
  for(ll i = l; i <= r;) {
    ll l1 = (i / len) * len;
    ll r1 = min(l1 + len, n);
    if (i % len == 0 && i + len <= (r - 1)) {
      if ((x == 0 && sum[i / len] == 0) || (x == 1 && sum[i / len] == (r1 - l1))) {
        if (x == 0) {
          cnt += (r1 - l1);
          sum[i / len] = (r1 - l1);
        } else {
          cnt -= (r1 - l1);
          sum[i / len] = 0;
        } i += len;
      } else {
        forsn(i,l1,r1) {
          if (a[i] == x) {
            a[i] = !x;
            if (!x) {
              sum[i / len]++;
              cnt++;
            } else {
              sum[i / len]--;
              cnt--;
            }
          } else {
            a[i] = x;
            if (x) {
              cnt++;
              sum[i / len]++;
            } else {
              cnt--;
              sum[i / len]--;
            } return;
          }
        }
      }
    } else {
      if (a[i] == x) {
        a[i] = !x;
        if (!x) {
          cnt++;
          sum[i / len]++;
        } else {
          cnt--;
          sum[i / len]--;
        }
      } else {
        a[i] = x;
        if (x) {
          cnt++;
          sum[i / len]++;
        } else {
          cnt--;
          sum[i / len]--;
        } return;
      }
      i++;
    }
  }
}

int main() {
  fast_cin();

  cin >> q;  
  while(q--) {
    string s;
    ll x;
    cin >> s >> x;
    // x = n - x;
    modify((s == "add" ? 1 : 0), x);
    cout << cnt << ln; 

    // for (auto &i : a) cout << i << ' ';
    // cout << endl;
    // for (auto &i : sum) cout << i << ' ';
    // cout << endl;
    

  }

}
