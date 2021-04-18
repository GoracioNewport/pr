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

void count_sort(v64 &p, v64 &c) { // Сортировка подсчетом. P - массив, который мы будем сортировать. C - класс.
  ll n = sz(p);
  v64 cnt(n); // Сколько раз каждое число встречается в массиве P
  for (auto &i : c) cnt[i]++; // Считаем
  v64 pNew(n); // Новый, отсортированый массив
  v64 pos(n); // Последний незанятый индекс для чисел n
  forsn(i,1,n) pos[i] = pos[i - 1] + cnt[i - 1]; // Раземчаем последние не занятые индексы
  for (auto &i : p) pNew[pos[c[i]]++] = i; // Распихиваем старые элементы в новый массив
  p = pNew;
}

int main() {
  fast_cin();

  string s;
  cin >> s;
  s += '$';
  ll n = sz(s);
  v64 p(n), c(n); { // База
    vector <pair <char, ll>> a(n); // Массив первых буковок
    forn(i,n) a[i] = {s[i], i}; // Пихаем букву и ее индекс
    sort(a.begin(), a.end()); // Сортируем в тупую
    forn(i,n) p[i] = a[i].se; // Обновляем наш суффиксный массив
    forsn(i,1,n) { // Обновляем классы
      if (a[i].fi == a[i - 1].fi) c[p[i]] = c[p[i - 1]]; // Если предыдущее равно текущему, то класс такой же
      else c[p[i]] = c[p[i - 1]] + 1; // Иначе следующий класс
    }
  } ll k = 0; // На каждом шагу мы посчитали все суффиксы длиной 2^k
  while ((1 << k) < n) { // Переход, пока мы не досчитаем до конца строки
    forn(i,n) p[i] = (p[i] - (1 << k) + n) % n; // Сдвиг на половинку вправо, модуль нужен что бы брать по циклу.
    count_sort(p, c); // Теперь осталось отсортировать только одни половинки
    v64 cNew(n); // Новые классы
    forsn(i,1,n) { // Заполняем классы. Если Две половинки равны, то все классы равны. Иначе разные.
      if ((c[p[i]] == c[p[i - 1]]) && (c[p[i] + (1 << k) % n] == c[p[i - 1] + (1 << k) % n])) cNew[p[i]] = cNew[p[i - 1]];
      else cNew[p[i]] = cNew[p[i - 1]] + 1;
    } c = cNew; // Присваиваем новый класс.
    k++; // Увеличиваем длину в два раза.
  } for (auto &i : p) cout << i << ' ';
  cout << ln;


}