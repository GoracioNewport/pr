#include "testlib.h"
#include <iostream>
#define ll int

using namespace std;

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    ll t = atoi(argv[1]); // 1 - тип, 2 - граница N, 3 - граница скоростей, 4 - граница начальных позиций
    ll nMax = atoi(argv[2]); // Тип 1 - Одинаковые скорости, 2 - одинаковые начальные позиции, 3 - полный рандом
    ll speedMax = atoi(argv[3]);
    ll posMax = atoi(argv[4]);
    ll l = atoi(argv[5]);
    ll r = atoi(argv[6]);


    for (ll i = l; i <= r; i++) {
    	startTest(i);
	    ll n = rnd.next(1, nMax);
	    speedMax = min(n, speedMax);
	    posMax = min(n, posMax);

	    if (t == 1) {
	    	ll s = rnd.next(1, speedMax);
	    	cout << n << ' ';
	    	cout << s << ' ' << s << ' ';
	    	cout << rnd.next(1, posMax) << ' ';
	    	cout << rnd.next(1, posMax) << endl;
	    } else if (t == 2) {
	    	ll p = rnd.next(1, posMax);
	    	cout << n << ' ';
	    	cout << rnd.next(1, speedMax) << ' ';
	    	cout << rnd.next(1, speedMax) << ' ';
	    	cout << p << ' ' << p << endl;
	    } else {
	    	cout << n << ' ';
	    	cout << rnd.next(1, speedMax) << ' ';
	    	cout << rnd.next(1, speedMax) << ' ';
	    	cout << rnd.next(1, posMax) << ' ';
	    	cout << rnd.next(1, posMax) << endl;
	    }
	}
}