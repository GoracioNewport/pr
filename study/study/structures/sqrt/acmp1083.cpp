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
#define INF (ll)2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

struct block {
  ll len;
  ll seg;
  ll add;
  ll sum;
  ll min;
};

ll n;
ll len;
v64 a;
vector <block> sd;

void update(ll l, ll r, ll x) {
  for (ll i = l; i <= r;) {
    if (i % len == 0 && i + len <= (r + 1)) {
      sd[i / len].seg = x;
      sd[i / len].add = 0;
      i += len;
    } else {
      if (i == l || i == (r / len) * len) {
        ll l1 = (i / len) * len;
        ll r1 = min(l1 + len, n);
        sd[i / len].min = INF;
        if (sd[i / len].seg != INF) {
          sd[i / len].sum = 0;
          forsn(i,l1,r1) {
            a[i] = sd[i / len].seg + sd[i / len].add;
            sd[i / len].sum += a[i];
          } sd[i / len].seg = INF;
          sd[i / len].add = 0;
        } else {
          sd[i / len].sum = 0;
          forsn(i,l1,r1) {
            a[i] = a[i] + sd[i / len].add;
            sd[i / len].sum += a[i];
          } sd[i / len].add = 0;
        } forsn(j,l1,r1) {
          if (j >= l && j <= r) sd[j / len].min = min(sd[j / len].min, x); 
          else sd[j / len].min = min(sd[j / len].min, a[j]);
        }
      } sd[i / len].sum -= a[i];
      a[i] = x;
      sd[i / len].sum += a[i];
      i++;
    }
  }
}

void add(ll l, ll r, ll x) {
  for(ll i = l; i <= r;) {
    if (i % len == 0 && i + len <= (r + 1)) {
      sd[i / len].add += x;
      i += len;
    } else {
      if (i == l || i == (r / len) * len) {
        ll l1 = (i / len) * len;
        ll r1 = min(l1 + len, n);
        sd[i / len].min = INF;
        if (sd[i / len].seg != INF) {
          sd[i / len].sum = 0;
          forsn(i,l1,r1) {
            a[i] = sd[i / len].seg + sd[i / len].add;
            sd[i / len].sum += a[i];
          } sd[i / len].seg = INF;
          sd[i / len].add = 0;
        } else {
          sd[i / len].sum = 0;
          forsn(i,l1,r1) {
            a[i] = a[i] + sd[i / len].add;
            sd[i / len].sum += a[i];
          } sd[i / len].add = 0;
        } forsn(j,l1,r1) {
          if (j >= l && j <= r) sd[j / len].min = min(sd[j / len].min, a[j] + x); 
          else sd[j / len].min = min(sd[j / len].min, a[j]);
        }
      } sd[i / len].sum -= a[i];
      a[i] += x;
      sd[i / len].sum += a[i];
      i++;
    }
  }
}

ll rmq(ll l, ll r) {
  ll ans = INF;
  for (ll i = l; i <= r;) {
    if (i % len == 0 && i + len <= (r + 1)) {
      if (sd[i / len].seg == INF) ans = min(ans, sd[i / len].min + sd[i / len].add);
      else ans = min(ans, sd[i / len].seg + sd[i / len].add);
      i += len;
    } else {
      if (sd[i / len].seg == INF) ans = min(ans, a[i] + sd[i / len].add);
      else ans = min(ans, sd[i / len].seg + sd[i / len].add);
      i++;
    }
  } return ans;
}

ll rsq(ll l, ll r) {
  ll ans = 0;
  for (ll i = l; i <= r;) {
    if (i % len == 0 && i + len <= (r + 1)) {
      if (sd[i / len].seg == INF) ans += (sd[i / len].sum + (sd[i / len].add * sd[i / len].len));
      else ans += ((sd[i / len].seg + sd[i / len].add) * sd[i / len].len);
      i += len;
    } else {
      if (sd[i / len].seg == INF) ans += (a[i] + sd[i / len].add);
      else ans += (sd[i / len].seg + sd[i / len].add);
      i++;
    }
  } return ans;
}

ll getI(ll i) {
  if (sd[i / len].seg == INF) return (a[i] + sd[i / len].add);
  else return (sd[i / len].seg + sd[i / len].add);
}


int main() {
  fast_cin();

  cin >> n;
  a.resize(n);
  for (auto &i : a) cin >> i;
  len = sqrt(n) + 1;
  sd.resize(n / len + 1, {len, INF, 0, 0, INF});
  forn(i,n) {
    sd[i / len].sum += a[i];
    sd[i / len].min = min(sd[i / len].min, a[i]);
  } sd.back().len = (n - (sz(sd) - 1) * len);
  ll q;
  cin >> q;
  while (q--) {
    string cmd;
    cin >> cmd;
    if (cmd == "update") {
      ll l, r, x;
      cin >> l >> r >> x; l--; r--;
      update(l,r,x);
      // for (auto &i : a) cout << i << ' ';
      // cout << ln;
      // for (auto &i : sd) {
      //   cout << i.len << ' ' << i.min << ' ' << i.sum << ln;
      // }
    } else if (cmd == "add") {
      ll l, r, x;
      cin >> l >> r >> x; l--; r--;
      add(l,r,x);
    } else if (cmd == "rmq") {
      ll l, r;
      cin >> l >> r; l--; r--;
      cout << rmq(l,r) << ln;
    } else if (cmd == "rsq") {
      ll l, r;
      cin >> l >> r; l--; r--;
      cout << rsq(l,r) << ln;
    } else {
      ll i;
      cin >> i; i--;
      cout << getI(i) << ln;
    }
  }

}
