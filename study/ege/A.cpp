#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {

  string s = "";
  for(ll i = 0; i < 200; i++) s += '1';



  s += '1';
  while(s.find("111") != string::npos || s.find("222") != string::npos) {
    auto x = s.find("111");
    if (x != string::npos) s.replace(x, 4, "22");
    auto y = s.find("222");
    if (y != string::npos) s.replace(y, 3, "1");
  } cout << s << endl;

}