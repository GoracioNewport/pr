#include "testlib.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    string a = inf.readToken();
    inf.readSpace();
    string b = inf.readToken();
    inf.readSpace();
    string i = inf.readToken();
    inf.readEoln();
    ensure(a.size() <= 101);
    ensure(b.size() <= 101);
    ensure(i.size() <= 101);
    inf.readEof();
}