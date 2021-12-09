// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")
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

ll MAXN = 1e7, MAXD = 2e9 + 3, offset = 1e9;
//ll MAXN = 100, MAXD = 100, offset = 0;

struct Node {
  ll sum;
  Node* l;
  Node* r;
  Node (): sum(0), l(nullptr), r(nullptr) {};
};

Node* root = nullptr;

struct Tree {
  ll ind;
  Tree() {
    ind = 1;
    root = new Node();
  }

  void touchLeft(Node* v, ll l, ll r) {
    if (l + 1 == r || v->l != nullptr) return;
    v->l = new Node();
  }

  void touchRight(Node* v, ll l, ll r) {
    if (l + 1 == r || v->r != nullptr) return;
    v->r = new Node();
  }

  void addX(Node* v, ll l, ll r, ll i, ll x) {
    if (l + 1 == r) {
      v->sum += x;
      return;
    } ll m = (l + r) / 2;
    if (i < m) {
      touchLeft(v, l, r);
      addX(v->l, l, m, i, x);
    } else {
      touchRight(v, l, r);
      addX(v->r, m, r, i, x);
    } ll newS = 0;
    if (v->l != nullptr) newS += v->l->sum;
    if (v->r != nullptr) newS += v->r->sum;
    v->sum = newS;
  }

  ll findL(Node* v, ll l, ll r, ll L, ll R) {
    if (l >= R || r <= L || v->sum == (r - l)) return -1;
    if (l + 1 == r) return l;
    ll m = (l + r) / 2;
    if (v->r == nullptr) touchRight(v, l, r);

    if (v->r->sum < (r - m)) {
      ll ansR = findL(v->r, m, r, L, R);
      if (ansR == -1) {
        if (v->l == nullptr) touchLeft(v, l, r);
        return findL(v->l, l, m, L, R);
      } else return ansR;
    } else {
      if (v->l == nullptr) touchLeft(v, l, r);
      return findL(v->l, l, m, L, R);
    }
  }

  ll findR(Node* v, ll l, ll r, ll L, ll R) {
    if (l >= R || r <= L || v->sum == (r - l)) return -1;
    if (l + 1 == r) return l;
    ll m = (l + r) / 2;
    if (v->l == nullptr) touchLeft(v, l, r);

    if (v->l->sum < (m - l)) {
      ll ansL = findR(v->l, l, m, L, R);
      if (ansL == -1) {
        if (v->r == nullptr) touchRight(v, l, r);
        return findR(v->r, m, r, L, R);
      } else return ansL;
    } else {
      if (v->r == nullptr) touchRight(v, l, r);
      return findR(v->r, m, r, L, R);
    }
  }

  ll getX(Node* v, ll l, ll r, ll i) {
    if (l + 1 == r) return v->sum;
    ll m = (l + r) / 2;
    if (i < m) {
      touchLeft(v, l, r);
      return getX(v->l, l, m, i);
    } else {
      touchRight(v, l, r);
      return getX(v->r, m, r, i);
    }
  }

};

int main() {
  fast_cin();

  ll n, l, r;
  cin >> n >> l >> r;
  Tree tree;
  while(n--) {
    char cmd;
    ll x;
    cin >> cmd >> x;
    x += offset;
    if (cmd == '+') {
      ll L = tree.findL(root, 0, MAXD, 0, x + 1);
      ll R = tree.findR(root, 0, MAXD, x, MAXD);
      tree.addX(root, 0, MAXD, L, 1);
      tree.addX(root, 0, MAXD, R, 1);
//      cerr << "+ " << L << ' ' << R << ln;
      ll move = R - x;
//      cerr << "- " << L + move << ln;
      tree.addX(root, 0, MAXD, L + move, -1);
//      cerr << tree.getX(0, 0, MAXD, L + move - 1) << ' ';
//      cerr << tree.getX(0, 0, MAXD, L + move) << ' ';
//      cerr << tree.getX(0, 0, MAXD, L + move + 1) << ln;
    } else cout << tree.getX(root, 0, MAXD, x) << ln;
  }


}