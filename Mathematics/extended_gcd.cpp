#include <iostream>

typedef long long lld;
typedef unsigned long long llu;
using namespace std;

inline pair<lld, pair<lld, lld>> egcd(lld a, lld b) {
    lld aa = 1, ab = 0, ba = 0, bb = 1;
    while (true) {
        lld q = a / b;
        if (a == b * q) 
            return make_pair(b, make_pair(ba, bb));
        lld tmp_a = a;
        lld tmp_aa = aa;
        lld tmp_ab = ab;
        a = b;
        b = tmp_a - b * q;
        aa = ba;
        ab = bb;
        ba = tmp_aa - ba * q;
        bb = tmp_ab - bb * q;
    }
}

inline lld modinv(lld a, lld b) {
    lld b0 = b;
    lld aa = 1, ba = 0;
    while (true) {
        lld q = a / b;
        if (a == b * q) {
            if (b != 1) {
                return -1;
            }
            while (ba < 0)
                ba += b0;
            return ba;
        }
        lld tmp_a = a;
        lld tmp_aa = aa;
        a = b;
        b = tmp_a - b * q;
        aa = ba;
        ba = tmp_aa - ba * q;
    }
}

int main() {
    lld a = 2250, b = 360;
    pair<lld, pair<lld, lld>> ret = egcd(a, b);
   //  printf("gcd(%lld, %lld) = %lld = %lld * %lld + %lld * %lld\n", a, b, ret.first, a, ret.second.first, b, ret.second.second);
   
    return 0;
}
