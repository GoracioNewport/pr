#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {
  ll n, m;
  cin >> n >> m;
  cout << (n ^ (1 << m)) << endl;
}