#include <iostream>

using namespace std;

typedef long long lld;

inline lld mod_pow(lld num, lld pow, lld mod) {
    lld ret = 1;
    while (pow) {
        if (pow & 1) {
            ret = (ret * num) % mod;
        }
        pow >>= 1;
        num = (num * num) % mod;
    }
    return ret;
}

inline lld mod_inv(lld num, lld mod) {
    return mod_pow(num, mod - 2, mod);
}

int main() {
    // printf("%lld\n", mod_pow(5, 2, 10));
    // printf("%lld\n", mod_inv(1423, 13));
    
    return 0;
}
