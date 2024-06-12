#include <iostream>
#include "Csort.h"
#include <ctime>
int main() {
    Csort csort;
    int n=10;
    int a[n];
    clock_t start,end;
    csort.AutoInput(a,n);
    csort.AutoOut(a,n);
    csort.TestMerge(a,n);
    return 0;
}
