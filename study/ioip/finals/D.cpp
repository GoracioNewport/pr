// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

// Author: @GoracioNewport

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<int> v32;
typedef vector<ll> v64;
typedef vector<ld> vdd;
typedef vector<v32> vv32;
typedef vector<v64> vv64;
typedef vector<vdd> vvdd;
typedef vector<p64> vp64;
typedef vector<vp64> vvp64;

#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define ln "\n"
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define fastCin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

istream& operator>>(istream& in, v64& a) {
  for (auto& i : a) in >> i;
  return in;
}

istream& operator>>(istream& in, vp64& a) {
  for (auto& i : a) in >> i.fi >> i.se;
  return in;
}

istream& operator>>(istream& in, vv64& a) {
  for (auto& i : a) for (auto& j : i) in >> j;
  return in;
}

istream& operator>>(istream& in, vvp64& a) {
  for (auto& i : a) for (auto& j : i) in >> j.fi >> j.se;
  return in;
}

ostream& operator<<(ostream& out, v64& a) {
  for (auto& i : a) out << i << ' ';
  return out;
}

ostream& operator<<(ostream& out, vp64& a) {
  for (auto& i : a) out << i.fi << ' ' << i.se << ln;
  return out;
}

ostream& operator<<(ostream& out, vv64& a) {
  for (auto& i : a) {
    for (auto& j : i) out << j << ' ';
    cout << ln;
  } return out;
}

ostream& operator<<(ostream& out, vvp64& a) {
  for (auto& i : a) {
    for (auto& j : i) out << j.fi << ' ' << j.se << ln;
    cout << ln;
  } return out;
}

ll mod = 1791791791;
ld eps = 1e-12;
ll INF = 2e18;

ll Q = 10;

ll popcnt(ll x) {
  bitset <32> a(x);
  return a.count();
}

//ll popcnt(ll x) {
//  ll ans = 0;
//  while(x) {
//    ans++;
//    x /= 2;
//  } return ans;
//}

struct block {
  ll sum, push, assign;
  v64 pushSums;
  bool updated;
};

void update1(block& q, v64& a, ll I, ll len) {
  if (q.pushSums.size() == 0) return;
  ll sum = 0;
  for (ll i = I; i < I + len; i++) {
    if (q.assign != INF) a[i] = q.assign;
    forn(z,min(q.push, Q)) a[i] = popcnt(a[i]);
    sum += a[i];

    ll y = a[i];
    forn(j,Q) {
      y = popcnt(y);
      q.pushSums[j] += y;
    }
  } q.updated = true;
  q.assign = INF;
  q.sum = sum;
  q.push = 0;
}

int main() {
  fastCin();

  ll n, q;
  cin >> n >> q;


  v64 a(n);
  cin >> a;

  ll len = sqrt(n);

  vector <block> d(n / len + 1);

  forn(i,n) {
    if (d[i / len].pushSums.size() == 0) {
      d[i / len].pushSums.resize(Q);
      d[i / len].updated = true;
      d[i / len].push = 0;
      d[i / len].assign = INF;
    }
    d[i / len].sum += a[i];

    ll x = a[i];
    forn(j,Q) {
      x = popcnt(x);
      d[i / len].pushSums[j] += x;
    }
  }

  forn(i,sz(d)) update1(d[i], a, i * len, len);

//  for (auto& i : d) if (i.pushSums.size() == 0) i.pushSums.resize(Q);

  while(q--) {
    ll t, l, r;
    cin >> t >> l >> r; l--;

    if (t == 1) {
      ll ans = 0;
      for (ll i = l; i < r;) {
        if (i % len == 0 && i + len < r) {
          ans += d[i / len].sum;
          i += len;
        } else {
          if (!d[i / len].updated) update1(d[i / len], a, i / len * len, len);
          ans += a[i];
          i++;
        }
      } cout << ans << ln;
    }

    else if (t == 2) {
      ll x; cin >> x;
      v64 inds;
      for (ll i = l; i < r;) {
        if (i % len == 0 && i + len < r) {
          d[i / len].assign = x;
          d[i / len].sum = x * len;
          d[i / len].push = 0;
          d[i / len].updated = false;

          ll y = x;
          forn(j,Q) {
            y = popcnt(y);
            d[i / len].pushSums[j] = y * len;
          } i += len;
        } else {
          if (!d[i / len].updated) {
            update1(d[i / len], a, i / len * len, len);
            inds.pb(i);
          }
          d[i / len].sum -= a[i];
          d[i / len].sum += x;
          a[i] = x;
          i++;
        }
      } for (auto& j : inds) update1(d[j / len], a, j / len * len, len);
    }

    else {
      v64 inds;
      for (ll i = l; i < r;) {
        if (i % len == 0 && i + len < r) {
          d[i / len].push++;
          d[i / len].updated = false;
          i += len;
        } else {
          if (!d[i / len].updated) {
            update1(d[i / len], a, i / len * len, len);
            inds.pb(i);
          }
          d[i / len].sum -= a[i];
          a[i] = popcnt(a[i]);

          d[i / len].sum -= a[i];
          i++;
        }
      } for (auto& j : inds) update1(d[j / len], a, j / len * len, len);
    }

//    forn(i,sz(d)) update1(d[i], a, i * len, len);


  }




}