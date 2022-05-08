#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 2e18;

struct line {
  double x;
  double y;
  bool hole = false;
  bool mirror = false;
};

int main() {
  ll n, le, k;
  cin >> n >> le >> k;
  vector <ll> holes(k);
  for(auto &i : holes) {
    cin >> i;
    i--;
  } double curCord = 0;
  vector <line> lines;
  vector <pair <double, double>> cords(n);

  for(auto &i : cords) cin >> i.first >> i.second;
  for(int i = 1; i < n; i++) {
    double x1 = cords[i - 1].first;
    double y1 = cords[i - 1].second;
    double x2 = cords[i].first;
    double y2 = cords[i].second;
    double x = abs(x1 - x2);
    double y = abs(y1 - y2);
    double len = sqrt((x * x) + (y * y));
    line l;
    l.x = curCord;
    l.y = curCord + len;
    lines.push_back(l);
    curCord += len;
  } // Добавляем ребро между последним и первым столбом
  {
    double x1 = cords[n - 1].first;
    double y1 = cords[n - 1].second;
    double x2 = cords[0].first;
    double y2 = cords[0].second;
    double x = abs(x1 - x2);
    double y = abs(y1 - y2);
    double len = sqrt((x * x) + (y * y));
    line l;
    l.x = curCord;
    l.y = curCord + len;
    lines.push_back(l);
    curCord += len;
  } double holeTotalLen = 0;
  for (auto &i : holes) {
    lines[i].hole = true;
    holeTotalLen += (lines[i].y - lines[i].x);
  } for (int i = 0; i < n; i++) {
    line l = lines[i];
    l.x += curCord;
    l.y += curCord;
    l.mirror = true;
    lines.push_back(l);
  }
  // vector <ll> prefSum(lines.size());
  vector <double> prefSumHoles(lines.size());
  // prefSum[0] = 0;
  prefSumHoles[0] = 0;

  ll ind = 1;

  // for (auto &i : lines) {
  //   cout << ind << " - " << i.x << ' ' << i.y;
  //   if (i.mirror) cout << " MIRROR";
  //   if (i.hole) cout << " HOLE";
  //   cout << endl;
  //   ind++;
  // }

  for (int i = 1; i < lines.size(); i++) {
    // prefSum[i] = prefSum[i - 1] + (lines[i].y - lines[i].x);
    prefSumHoles[i] = prefSumHoles[i - 1];
    if (lines[i - 1].hole) prefSumHoles[i] += (lines[i - 1].y - lines[i - 1].x);
  } double ans = 0;

  // for (auto &i : prefSumHoles) cout << i << ' ';
  // cout << endl;

  for (int i = 0; i < n; i++) {
    double cover = 0;
    double lenLeft = le;
    ll l = i;
    ll r = i + n;
    while (l + 1 < r) {
      ll m = (l + r) / 2;
      if ((lines[m].x - lines[i].x) < le) l = m;
      else r = m;
    } cover = (prefSumHoles[l] - prefSumHoles[i]);
    double lenD = (lines[l].y - lines[l].x);
    lenLeft = (le - (lines[l].x - lines[i].x));
    if (lines[l].hole) cover += min(lenLeft, lenD);

    // cout << "START AT " << i + 1 << endl;
    // cout << "FOUND LAST EDGE: " << l + 1 << endl;
    // cout << cover << endl;

    // for (int j = i; j < lines.size(); j++) {
    //   if (j >= i + n) break;
    //   // cout << i << ' ' << j << endl;
    //   double len = (lines[j].y - lines[j].x);
    //   if (len <= lenLeft) {
    //     lenLeft -= (lines[j].y - lines[j].x);
    //     if (lines[j].hole) cover += len;
    //   } else {
    //     if (lines[j].hole) cover += lenLeft;
    //     lenLeft = 0;
    //     break;
    //   }
    // }
    // cout << cover << endl;
    ans = max(ans, cover);
  }
  // cout << ans << endl;
  ans = (holeTotalLen - ans);
  cout << setprecision(10) << fixed << max(0.0, ans) << endl;
}