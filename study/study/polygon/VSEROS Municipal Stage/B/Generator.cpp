#include "testlib.h"
#include <iostream>
#define ll long long

using namespace std;

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    ll l = atoi(argv[2]);
    ll r = atoi(argv[3]);

    for (int i = l; i <= r; i++) {
      startTest(i);
      string n = to_string(rnd.next(1, atoi(argv[1]) - 1));
      cout << rnd.next("[1-9][0-9]{" + n + "}") << " ";
      n = to_string(rnd.next(1, atoi(argv[1]) - 1));
      cout << rnd.next("[0-9][0-9]{" + n + "}") << " ";
      n = to_string(rnd.next(1, atoi(argv[1]) - 1));
      cout << rnd.next("[0-9][0-9]{" + n + "}") << endl;
    }
}