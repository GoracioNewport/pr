//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

// Author: @GoracioNewport

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

struct Node {
  Node* l;
  Node* r;
  ll key, prior, size;
  Node (ll key): l(nullptr), r(nullptr), key(key), prior(rng()), size(1) {};
};


ll getSize(Node* a) {
  if (a == nullptr) return 0;
  return a->size;
}

void upd(Node* a) {
  if (a == nullptr) return;
  a->size = getSize(a->l) + getSize(a->r) + 1;
}

Node* merge(Node* a, Node* b) {
  if (a == nullptr) return b;
  if (b == nullptr) return a;

  if (a->prior > b->prior) {
    a->r = merge(a->r, b);
    upd(a);
    return a;
  } else {
    b->l = merge(a, b->l);
    upd(b);
    return b;
  }
}

pair <Node*, Node*> split(Node* a, ll x) {
  if (a == nullptr) return {nullptr, nullptr};

  if (x <= a->key) {
    auto p = split(a->l, x);
    a->l = p.se;
    upd(a);
    return {p.fi, a};
  } else {
    auto p = split(a->r, x);
    a->r = p.fi;
    upd(a);
    return {a, p.se};
  }
}

pair <Node*, Node*> splitSize(Node* a, ll i) {
  if (a == nullptr) return {nullptr, nullptr};

  if (i <= getSize(a->l)) {
    auto p = splitSize(a->l, i);
    a->l = p.se;
    upd(a);
    return {p.fi, a};
  } else {
    auto p = splitSize(a->r, i - getSize(a->l) - 1);
    a->r = p.fi;
    upd(a);
    return {a, p.se};
  }
}

void print(Node* a) {
  if (a == nullptr) return;
  if (a->l) print(a->l);
  cout << a->key << ' ';
  if (a->r) print(a->r);
}

Node* L = nullptr;
Node* R = nullptr;

void insert(ll x) {
  auto p = split(L, x);
  L = merge(p.fi, new Node(x));
  L = merge(L, p.se);
}

void insertR(ll x) {
  auto p = split(R, x);
  R = merge(p.fi, new Node(x));
  R = merge(R, p.se);
}

void erase(ll x) {
  auto p = split(R, x);
  auto q = splitSize(p.se, 1);
  R = merge(p.fi, q.se);
}

ll findMax(Node* a) {
  if (!a) return -INF;
  if (a->r) return findMax(a->r);
  return a->key;
}

ll findMin(Node* a) {
  if (!a) return INF;
  if (a->l) return findMin(a->l);
  return a->key;
}

bool cntAns(ll x) {
  auto p = splitSize(L, x);
  {
    ll X = findMax(p.fi);
    auto t = split(p.se, X + 1);
    p.fi = merge(p.fi, t.fi);
    p.se = t.se;
  }
//  {
//    ll X = findMin(p.se);
//    auto t = split(p.fi, X);
//    p.fi = t.fi;
//    p.se = merge(t.se, p.se);
//  }
  auto q = splitSize(R, x);
  {
    ll X = findMax(q.fi);
    auto t = split(q.se, X + 1);
    q.fi = merge(q.fi, t.fi);
    q.se = t.se;
  }
//  {
//    ll X = findMin(q.se);
//    auto t = split(q.fi, X);
//    q.fi = t.fi;
//    q.se = merge(t.se, q.se);
//  }
  ll ans = max(max(getSize(p.fi), getSize(p.se)), max(getSize(q.fi), getSize(q.se)));
  L = merge(p.fi, p.se);
  R = merge(q.fi, q.se);
  return ans > x;
}

bool DEBUG = false;

ll getAns() {
  ll l = max((getSize(L) + 1) / 2, (getSize(R) + 1) / 2);
  ll r = max(getSize(L), getSize(R)) + 1;
  while(l + 1 < r) {
    ll m = (l + r) / 2;
    if (cntAns(m)) l = m;
    else r = m;
  } return l;
}

int main() {
  fast_cin();

  ll n;
  cin >> n;
  vp64 a(n);
  for (auto &i : a) cin >> i.fi >> i.se;
  sort(all(a));

  for (auto &i : a) insertR(i.se);
  ll ans = INF;

  forn(i,n) {
    insert(a[i].se);
    erase(a[i].se);
    if (i != (n - 1) && a[i].fi == a[i + 1].fi) continue;
    ans = min(ans, getAns());

    if (DEBUG) {
      cout << "L: ";
      print(L);
      cout << ln << "R: ";
      print(R);
      cout << ln;
      cout << getAns() << ln;
    }


  } cout << ans << ln;

}