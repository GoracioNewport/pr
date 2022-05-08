#include "testlib.h"

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int n = inf.readInt(1, 1e7, "n");
    inf.readSpace();
    int x = inf.readInt(1, 1e6, "x");
    inf.readSpace();
    int y = inf.readInt(1, 1e6, "y");
    inf.readSpace();
    int a = inf.readInt(1, 1e7, "a");
    inf.readSpace();
    int b = inf.readInt(1, 1e7, "b");
    inf.readEoln();

    ensure(a <= n);
    ensure(b <= n);

    inf.readEof();
}