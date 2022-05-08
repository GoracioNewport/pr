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

struct event {
  ll time, floor, type, id;
};

class Compare {
  public:
    bool operator() (event a, event b) {
      if (a.time != b.time) return a.time > b.time;
      else if (a.type != b.type) return a.type > b.type;
      else return a.floor > b.floor;
    }
};

enum { IDLE, UP, DOWN };
enum { CALL, FLOOR };

int main() {
  fast_cin();

  priority_queue <event, vector <event>, Compare> q;
  ll n, m;
  cin >> n >> m;

  forn(i,n) {
    ll t, a;
    cin >> t >> a;
    q.push({t, a, CALL, i});
  } ll status = IDLE, arriveTime = 0, callFloor = 0, leftTime = 0;

  queue <event> calls;
  map <ll, v64> waiting;

  v64 ans(n);
  while(!q.empty()) {
    auto i = q.top();
    q.pop();

    if (i.type == CALL) {
      waiting[i.floor].pb(i.id);
      calls.push(i);

      if (status == IDLE) {
        while(ans[calls.front().id]) calls.pop();
        auto call = calls.front();
        calls.pop();

        status = UP;
        callFloor = call.floor;
        leftTime = max(arriveTime, call.time);
        arriveTime = leftTime + (call.floor - 1) * 2;

        q.push({leftTime + call.floor - 1, call.floor, FLOOR, 0});
      } else if (status == DOWN) {
        ll elevatorPosition = arriveTime - i.time + 1;
        if (elevatorPosition >= i.floor) q.push({arriveTime - i.floor - 1, i.floor, FLOOR, 0});
      }
    } else if (i.type == FLOOR) {
      if (status == UP) {
        

        status = DOWN;
      } else if (status == DOWN) {

      }
    }

  }


}