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
    ll key, prior, size, sum;
    Node (ll key): key(key), prior(rng()), l(nullptr), r(nullptr), size(1), sum(key * key) {};
};

ll getSize(Node* a) {
  if (!a) return 0;
  return a->size;
}

ll getSum(Node* a) {
  if (!a) return 0;
  return a->sum;
}

void upd(Node* a) {
  if (!a) return;
  a->size = getSize(a->l) + getSize(a->r) + 1;
  a->sum = getSum(a->l) + getSum(a->r) + (a->key * a->key);
}

Node* merge(Node *a, Node* b) {
  if (!a) return b;
  if (!b) return a;

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
  if (!a) return {nullptr, nullptr};

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
  if (!a) return {nullptr, nullptr};

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

Node* root = nullptr;

int main() {
  fast_cin();

  freopen("river.in", "r", stdin);
  freopen("river.out", "w", stdout);

  ll n, p;
  cin >> n >> p;
  forn(i,n) {
    ll x; cin >> x;
    root = merge(root, new Node(x));
  } ll q;
  cout << getSum(root) << ln;
  cin >> q;
  while(q--) {
    ll t, v;
    cin >> t >> v; v--;
    if (t == 1) { // Обанкротилось, переходит соседям
      if (v == 0) { // Все правому соседу

        auto p = splitSize(root, 2);
        auto q = splitSize(p.fi, 1);
        q.se->key += q.fi->key;
        upd(q.se);
        root = merge(q.se, p.se);

      } else if (v == n - 1) { // Все левому соседу

        auto p = splitSize(root, n - 1);
        auto q = splitSize(p.fi, n - 2);
        q.se->key += p.se->key;
        upd(q.se);
        root = merge(q.fi, q.se);

      } else { // Пилим

        auto d = splitSize(root, v + 2);
        auto c = splitSize(d.fi, v + 1);
        auto b = splitSize(c.fi, v);
        auto a = splitSize(b.fi, v - 1);

        a.se->key += (b.se->key / 2);
        c.se->key += b.se->key - (b.se->key / 2);
        upd(a.se);
        upd(c.se);
        root = merge(a.fi, a.se);
        root = merge(root, c.se);
        root = merge(root, d.se);
      } n--;
    } else { // Делится на два

      auto p = splitSize(root, v + 1);
      auto q = splitSize(p.fi, v);

      root = merge(q.fi, new Node(q.se->key / 2));
      root = merge(root, new Node(q.se->key - (q.se->key / 2)));
      root = merge(root, p.se);
      n++;
    } cout << getSum(root) << ln;
  }

}