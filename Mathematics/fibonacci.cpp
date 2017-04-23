#include <iostream>
using namespace std;

typedef unsigned long long int ull;
const int MAX_N = 93;

ull fibonacci(const int n) {
    ull secondprev = 0;
    ull prev = 1;
    ull fibo;

    if (n == 0 or n == 1)
        return n;

    for (int i = 2; i <= n; i++) {
        fibo = prev + secondprev;
        secondprev = prev;
        prev = fibo;
    }
    return fibo;
}
