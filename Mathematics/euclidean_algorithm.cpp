#include <iostream>

using namespace std;
typedef long long lld;

int gcd(int a, int b) {
    if (a % b == 0) return b;
    return gcd(b, a % b);
}

int main() {
    // printf("%d\n", gcd(6, 15));
    return 0;
}
