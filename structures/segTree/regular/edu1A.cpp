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

struct Tree {
    v64 a, t; // a - исходный массив, t - дерево
    ll n; // количество элементов
    Tree (v64 &_a) {
      a = _a;
      n = sz(a);
      t.assign(n * 4, 0);
      build(0,0,n); // строим дерево на сумму
    }

    void build(ll v, ll l, ll r) { // рекурсивная функция построения дерева
      if (l + 1 == r) { // если подотрезок состоит из одного элемента...
        t[v] = a[l]; // его сумма равна ему самому и брейкаемся
        return;
      } ll m = (l + r) / 2; // разбиваем подотрезок на два
      build(2 * v + 1, l, m); // строим левый
      build(2 * v + 2, m, r); // строим правый
      t[v] = t[2 * v + 1] + t[2 * v + 2]; // текущий отрезок = левая половина + правая половина
    }

    void updateSingle(ll v, ll l, ll r, ll i, ll x) { // рекурсивная функция, спускается до нужной вершины i и меняет на x.
      if (l + 1 == r) { // если подторезок состоит из одного элемента, то меняем его
        a[l] = x;
        t[v] = x;
        return;
      } ll m = (l + r) / 2; // Разбиваем на две половинки
      if (i < m) updateSingle(2 * v + 1, l, m, i, x);
      else updateSingle(2 * v + 2, m, r, i, x);
      t[v] = t[2 * v + 1] + t[2 * v + 2]; // Обновляем минимум
    }

    ll getSum(ll v, ll l, ll r, ll L, ll R) {
      if (r <= L || l >= R) return 0; // Если отрезок вообще не попадает в интервал
      if (l >= L && r <= R) return t[v]; // Если отрезок полностью входит в интервал
      ll m = (l + r) / 2;
      return getSum(2 * v + 1, l, m, L, R) + getSum(2 * v + 2, m, r, L, R); // Сумма = сумма левой половины + сумма правой половины
    }
};

int main() {
  fast_cin();

  ll n, m;
  cin >> n >> m;
  v64 a(n);
  for (auto &i : a) cin >> i;
  Tree tree(a);
  while(m--) {
    ll t, l, r;
    cin >> t >> l >> r;
    if (t == 1) tree.updateSingle(0, 0, n, l, r);
    else cout << tree.getSum(0,0,n,l,r) << ln;
  }

}