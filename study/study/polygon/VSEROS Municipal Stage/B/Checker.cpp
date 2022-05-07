#include "testlib.h"
#include <iostream>
using namespace std;
#include <string>

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);
    string pans = ouf.readToken();
    string jans = ans.readToken();
    
    if (pans == jans) quitf(_ok, "OK"); 
    else quitf(_wa, "Got %s, expected %s", pans, jans);
}