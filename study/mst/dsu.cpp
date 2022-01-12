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
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

v64 p, r; // Массив с представителями вершины и рангами вершины.
ll n, m; // Кол-во вершин, кол-во ребер.

void init() { // Инициализация DSU.
  p.resize(n);
  r.resize(n, 0);
  forn(i,n) p[i] = i;
}

ll findP(ll v) { // Рекурсивная функция нахождения представителя. За каждый запрос подвешивает все вершины на пути за представителя, первая евристика.
  return (p[v] == v) ? v : (p[v] = findP(p[v]));
}

void unionSet(ll a, ll b) { // Объединение множеств.
  a = findP(a);
  b = findP(b); // Находим оба представителя.
  if (a == b) return; // Если множество уже объединено, то ничего не делаем.
  if (r[a] > r[b]) swap(a, b); // Ранг указывает на высоту дерева. Если ранг первого больше второго, меняем их местами, вторая евристика.
  if (r[a] == r[b]) r[b]++; // Если ранги оказались равны, то прибавляем к одному из них еденицу.
  p[a] = b; // Подвешиваем представителя первого ко второму.
}

int main() {
  fast_cin();
  cin >> n >> m;  
  init();

}
