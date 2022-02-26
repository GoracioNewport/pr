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

const ll k = 26;
vv64 ans;


struct Node {
  map <ll, Node*> to; // Переход по бору, автоматные переходы
  v64 ter; // Список индексов строк, которые заканчиваются в этой вершине
  Node *sufLink, *parent, *superSuf; // Суффиксная ссылка, предок и следующая по автоматным переходам терминальная вершина
  ll parentChar; // Ребро, по которому мы переходим из предка в вершину, высота

  Node (ll pc, Node* p) {
    parentChar = pc;
    parent = p;
    sufLink = nullptr;
    superSuf = nullptr;
  }
};

Node* root = nullptr;

void addString(string &s, ll i) {
  Node* v = root;
  for (auto&c : s) {
    ll x = c - 'a';
    if (!v->to[x]) v->to[x] = new Node(x, v);
    v = v->to[x];
  } v->ter.pb(i);
}

void calcLink(Node* v, ll c) {
  if (v->sufLink) return;
  if (v == root || v->parent == root) {
    v->sufLink = root;
    v->superSuf = root;
    return;
  } Node* x = v->parent->sufLink;

  while(x != root && x->to[c] == nullptr) {
//    calcLink(x, c);
    x = x->sufLink;
  }

  if (x->to[c]) {
    v->sufLink = x->to[c];
    if (v->sufLink->ter.size()) v->superSuf = v->sufLink;
    else v->superSuf = v->sufLink->superSuf;
  } else {
    v->sufLink = root;
    v->superSuf = root;
  }
}

//void dfs(Node* v) {
//  for (auto& i : v->to) {
//    calcLink(i.se, i.fi);
//    dfs(i.se);
//  }
//}

int main() {
  fast_cin();

  freopen("inputik.txt", "r", stdin);
  freopen("outputik.txt", "w", stdout);

  string t;
  cin >> t;

  ll n;
  cin >> n;

  root = new Node(0, nullptr);
  vector <pair <Node*, ll>> stat(n);
  vector <string> ss(n);

  forn(i,n) {
    cin >> ss[i];
    addString(ss[i], i);
    stat[i] = {root, 0};
  }

  ans.resize(n);

  root->parent = root;
  root->sufLink = root;
  root->superSuf = root;
//  dfs(root);

  queue <pair <Node*, ll>> q;
  forn(i,n) q.push({root->to[ss[i][0] - 'a'], i});


  while(!q.empty()) {
    auto x = q.front();
    q.pop();

    stat[x.se].se++;
    calcLink(x.fi, x.fi->parentChar);
    if (stat[x.se].se != sz(ss[x.se])) q.push({x.fi->to[ss[x.se][stat[x.se].se] - 'a'], x.se});
  }

  Node* v = root;

  forn(i,sz(t)) {
    ll c = t[i] - 'a';
    while (v != root && !v->to[c]) v = v->sufLink;
    if (v->to[c]) v = v->to[c];
    else v = root;

    Node* x = v;
    while(x != root) {
      for (auto& j : x->ter) ans[j].pb(i - ss[j].size() + 2);
      x = x->superSuf;
    }
  }

  for (auto& i : ans) {
    cout << sz(i) << ' ';
    for (auto& j : i) cout << j << ' ';
    cout << ln;
  }



}