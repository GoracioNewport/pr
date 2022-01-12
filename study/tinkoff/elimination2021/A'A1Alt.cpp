//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

// Author: @GoracioNewport

using namespace std;

typedef int ll;
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
#define INF 2e9
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<
        pair<ll,ll> ,
        null_type,
        less< >,
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;

//struct Node {
//    Node* l;
//    Node* r;
//    ll key, prior, size;
//    Node (ll key): l(nullptr), r(nullptr), key(key), prior(rng()), size(1) {};
//};
//
//
//ll getSize(Node* a) {
//  if (a == nullptr) return 0;
//  return a->size;
//}
//
//void upd(Node* a) {
//  if (a == nullptr) return;
//  a->size = getSize(a->l) + getSize(a->r) + 1;
//}
//
//Node* merge(Node* a, Node* b) {
//  if (a == nullptr) return b;
//  if (b == nullptr) return a;
//
//  if (a->prior > b->prior) {
//    a->r = merge(a->r, b);
//    upd(a);
//    return a;
//  } else {
//    b->l = merge(a, b->l);
//    upd(b);
//    return b;
//  }
//}
//
//pair <Node*, Node*> split(Node* a, ll x) {
//  if (a == nullptr) return {nullptr, nullptr};
//
//  if (x <= a->key) {
//    auto p = split(a->l, x);
//    a->l = p.se;
//    upd(a);
//    return {p.fi, a};
//  } else {
//    auto p = split(a->r, x);
//    a->r = p.fi;
//    upd(a);
//    return {a, p.se};
//  }
//}
//
//pair <Node*, Node*> splitSize(Node* a, ll i) {
//  if (a == nullptr) return {nullptr, nullptr};
//
//  if (i <= getSize(a->l)) {
//    auto p = splitSize(a->l, i);
//    a->l = p.se;
//    upd(a);
//    return {p.fi, a};
//  } else {
//    auto p = splitSize(a->r, i - getSize(a->l) - 1);
//    a->r = p.fi;
//    upd(a);
//    return {a, p.se};
//  }
//}
//
//void print(Node* a) {
//  if (a == nullptr) return;
//  if (a->l) print(a->l);
//  cout << a->key << ' ';
//  if (a->r) print(a->r);
//}
//
//Node* L = nullptr;
//Node* R = nullptr;
//
//void insert(ll x) {
//  auto p = split(L, x);
//  L = merge(p.fi, new Node(x));
//  L = merge(L, p.se);
//}
//
//void insertR(ll x) {
//  auto p = split(R, x);
//  R = merge(p.fi, new Node(x));
//  R = merge(R, p.se);
//}
//
//void erase(ll x) {
//  auto p = split(R, x);
//  auto q = splitSize(p.se, 1);
//  R = merge(p.fi, q.se);
//}
//
//ll findMax(Node* a) {
//  if (!a) return -INF;
//  if (a->r) return findMax(a->r);
//  return a->key;
//}
//
//ll findMin(Node* a) {
//  if (!a) return INF;
//  if (a->l) return findMin(a->l);
//  return a->key;
//}
//


ll n;
vp64 a;

ordered_set rBase;

bool cntAns(ll m) {

//  swap(l, r);

  ordered_set l, r;
  r = rBase;

  forn(i,n) {
    ll X = a[i].fi;
    while(a[i].fi == X && i < n) {
      r.erase({a[i].se, a[i].fi});
      l.insert({a[i].se, a[i].fi});
      i++;
    } i--;
    ll lL, lR;
    if (sz(l) <= m) {
      lL = INF;
      lR = -INF;
    } else {
      lL = (*l.find_by_order(m)).fi - 1;
      lR = (*l.find_by_order(sz(l) - m - 1)).fi + 1;
    } ll rL, rR;
    if (sz(r) <= m) {
      rL = INF;
      rR = -INF;
    } else {
      rL = (*r.find_by_order(m)).fi - 1;
      rR = (*r.find_by_order(sz(r) - m - 1)).fi + 1;
    } //if ((lL <= lR) && (rL <= rR) && (max(lL, rL) <= min(lR, rR))) return true;
    if ((lR <= lL && rR <= rL) && ((rR <= lL && lL <= rL) || (lR <= rL && rL <= lL))) return true;

//    cout << X << ' ' << m << ' ' << lL << ' ' << lR << ' ' << rL << ' ' << rR << ln;

  } return false;
}

int main() {
  fast_cin();

  cin >> n;
  a.resize(n);
//  v64 posX;
  for (auto &i : a) {
    cin >> i.fi >> i.se;
//    posX.pb(i.fi + 1);
  } // sort(all(posX));
  sort(all(a));
//  auto it = unique(all(posX));
//  posX.erase(it, posX.end());

  for (auto &i : a) rBase.insert({i.se, i.fi});

  ll L = ceil((ld)n / 4.0) - 1;
  ll R = n;
  while(L + 1 < R) {
    ll m = (L + R) / 2;
    if (cntAns(m)) R = m;
    else L = m;
  } cout << R << ln;

}