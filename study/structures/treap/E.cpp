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

struct Node {
  Node *l;
  Node *r;

  ll key, prior;
  ll size;

  Node (ll key): key(key), prior(rand()), size(1), l(nullptr), r(nullptr) {};

};

Node* root = nullptr;

ll getSize(Node *a) {
  if (!a) return 0;
  return a->size;
}

void upd(Node *a) {
  if (!a) return;
  a->size = getSize(a->l) + getSize(a->r) + 1;
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

pair <Node*, Node*> splitSize(Node* a, ll i) {
  if (!a) return {nullptr, nullptr};

  if (getSize(a->l) >= i) {
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

void print(Node *a) {
  if (!a) return;
  print(a->l);
  cout << a->key + 1 << ' ';
  print(a->r);
}



int main() {
  fast_cin();
  srand(time(0));

  freopen("movetofront.in", "r", stdin);
  freopen("movetofront.out", "w", stdout);

  ll n, q;
  cin >> n >> q;
  forn(i,n) root = merge(root, new Node(i));

  while(q--) {
    ll l, r;
    cin >> l >> r;
    l--; r--;
    auto p = splitSize(root, r + 1);
    auto q = splitSize(p.fi, l);
    root = merge(merge(q.se, q.fi), p.se);
  } print(root);

}