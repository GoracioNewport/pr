#include <bits/stdc++.h>
using namespace std;

// Author: GoraicoNewport

typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> p64;
typedef pair <ld, ld> pdd;
typedef vector <ll> v64;
typedef vector <v64> vv64;
typedef vector <p64> vp64;
typedef vector <vp64> vvp64;

#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define fi first
#define se second
#define ln '\n'
#define fastCin() ios::ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define sz(x) (x).size()
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for (ll i = s; i < e; i++)


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
    out << ln;
  } return out;
}

ostream& operator<<(ostream& out, vvp64& a) {
  for (auto& i : a) {
    for (auto &j: i) out << j.fi << ' ' << j.se << ln;
    out << ln;
  } return out;
}

ll INF = 2e18;
ll mod = 1791791791;

ll binPow(ll a, ll n) {
  if (n == 0) return 1;
  else if (n % 2) return binPow(a, n - 1) * a;
  else {
    ll b = binPow(a, n / 2);
    return b * b;
  }
}

ll binPow(ll a, ll n, ll Mod) {
  if (n == 0) return 1;
  else if (n % 2) return binPow(a, n - 1, Mod) * a % Mod;
  else {
    ll b = binPow(a, n / 2, Mod);
    return b * b % Mod;
  }
}

ll gcd(ll a, ll b) {
  if (b == 0) return a;
  else return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
  return a * b / gcd(a, b);
}

bool isPrime(ll x) {
  for (ll i = 2; i * i <= x; i++) {
    if (x % i == 0) return false;
  } return true;
}

v64 factorize(ll x) {
  v64 ans;
  for (ll i = 2; i * i <= x; i++) {
    while(x % i == 0) {
      x /= i;
      ans.pb(i);
    }
  } if (x > 1) ans.pb(x);
  return ans;
}

void fastSieve(ll n, v64& primes, v64& d) {
  for (ll i = 2; i <= n; i++) {
    if (d[i] == 0) {
      d[i] = i;
      primes.pb(i);
    } for (auto& x : primes) {
      if (i * x > n) break;
      d[i * x] = x;
    }
  }
}

struct r {
  ld x, y;

  r(ld x, ld y): x(x), y(y) {};
  r(pdd a, pdd b) {
    x = b.fi - a.fi;
    y = b.se - a.se;
  } r (p64 a, p64 b) {
    x = b.fi - a.fi;
    y = b.se - a.se;
  }

  ld len() {
    return sqrt(x * x + y * y);
  }

  ld operator*(r &o) const {
    return x * o.x + y * o.y;
  }

  ld operator^(r &o) const {
    return x * o.y - y * o.x;
  }
};

//ld getAngle(r a, r b) {
//  return atan2(a * b, a ^ b) * 180 / M_PI;
//}

struct sparceTableMin {
  ll n, maxLog;
  v64 nextPower;
  vv64 t;

  sparceTableMin(v64& a) {
    n = sz(a);
    nextPower.resize(n + 1);

    forsn(i,2,n + 1) nextPower[i] = nextPower[i / 2] + 1;
    maxLog = nextPower.back();

    t.resize(n, v64(maxLog + 1));

    forn(i,n) t[i][0] = a[i];

    for(ll len = 1; len <= maxLog; len++) {
      for(ll i = 0; i < n - (1 << len) + 1; i++) {
        t[i][len] = min(t[i][len - 1], t[i + ((len - 1) << 1)][len - 1]);
      }
    }

  }

  ll getMin(ll l, ll r) {
    ll len = nextPower[r - l + 1];
    return min(t[l][len], t[r - (1 << len) + 1][len]);
  }
};


















int main() {
  fastCin();

  ll t;
  cin >> t;
  while(t--) {
    string s;
    cin >> s;
    unordered_map <char, ll> z;
    for (auto& c : s) z[c]++;

    forn(i,sz(s)) {
      z[s[i]]--;
      if (z[s[i]] == 0) {
        cout << s.substr(i) << ln;
        break;
      }
    }
  }

}