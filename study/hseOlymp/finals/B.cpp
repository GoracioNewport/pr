#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> p64;
typedef vector <ll> v64;
typedef vector <ld> vdd;
typedef vector <v64> vv64;
typedef vector <p64> vp64;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define forn(i,e) for(ll i = 0; i < e; i++)
#define ln '\n'
#define fastCin() ios::ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define pb(x) push_back(x)

ll INF = 2e18;
ld eps = 2e-12;
ll mod = 1791791791;

istream& operator>>(istream& in, v64& a) {
  for (auto& i : a) in >> i;
  return in;
}

ostream& operator<<(ostream& out, v64& a) {
  for (auto& i : a) out << i << ' ';
  return out;
}

istream& operator>>(istream& in, vp64& a) {
  for (auto& i: a) in >> i.fi >> i.se;
  return in;
}

ostream& operator<<(ostream& out, vp64& a) {
  for (auto& i : a) out << i.fi << ' ' << i.se << ln;
  return out;
}

vp64 prefixLeft, prefixRight, suffixLeft, suffixRight;

bool ok(vp64& p, ll x) {
  for (auto& i : p) {
    ll L = i.fi;
    ll R = i.fi + x - 1;

    ll l = 0;
    ll r = prefixLeft.size(); // l - всегда подходит, r - нет
    while(l + 1 < r) {
      ll m = (l + r) / 2;
      if (prefixLeft[m].fi < L) l = m;
      else r = m;
    }

    ll leftUp = prefixLeft[l].se;

    l = 0;
    r = prefixRight.size();

    while(l + 1 < r) {
      ll m = (l + r) / 2;
      if (prefixRight[m].fi < L) l = m;
      else r = m;
    }

    ll rightUp = prefixRight[l].se;

    l = 0;
    r = suffixLeft.size(); // l - всегда подходит, r - нет

    while(l + 1 < r) {
      ll m = (l + r) / 2;
      if (suffixLeft[m].fi > R) l = m;
      else r = m;
    }

    ll leftDown = suffixLeft[l].se;

    l = 0;
    r = suffixRight.size();

    while(l + 1 < r) {
      ll m = (l + r) / 2;
      if (suffixRight[m].fi > R) l = m;
      else r = m;
    }

    ll rightDown = suffixRight[l].se;

    ll len = max(rightUp, rightDown) - min(leftUp, leftDown) + 1;
    if (len <= x) return true;
  } return false;
}

int main() {
  fastCin();

  ll w, h, n;
  cin >> w >> h >> n;
  vp64 points(n);

  cin >> points;
  for (auto& i : points) {
    swap(i.fi, i.se);
    i.fi = h - i.fi + 1;
  }
  sort(all(points));

  prefixLeft.push_back({0, w + 1});
  prefixRight.push_back({0, -1});
  suffixLeft.push_back({(h + 1), w + 1});
  suffixRight.push_back({(h + 1), -1});

  for (auto& i : points) {
    if (i.se < prefixLeft.back().se) prefixLeft.push_back(i);
    if (i.se > prefixRight.back().se) prefixRight.push_back(i);
  } reverse(all(points));

  for (auto& i : points) {
    if (i.se < suffixLeft.back().se) suffixLeft.push_back({i.fi, i.se});
    if (i.se > suffixRight.back().se) suffixRight.push_back({i.fi, i.se});
  } reverse(all(points));

//  cout << prefixLeft << ln << prefixRight << ln << suffixLeft << ln << suffixRight << ln;

  ll l = 0;
  ll r = min(w, h); // l - нельзя, r - можно

  while(l + 1 < r) {
    ll m = (l + r) / 2;
    if (ok(points, m)) r = m;
    else l = m;
  } cout << r << ln;


}