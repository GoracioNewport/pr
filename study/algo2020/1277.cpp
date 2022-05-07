#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int d = gcd(b, a % b, x, y);
    x -= (a / b) * y;
    swap(x, y);
    return d;
}

int main() {
	
}