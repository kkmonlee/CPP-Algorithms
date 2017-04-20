#include <iostream>

using namespace std;

typedef long long lld;

int n, r;
int skup[100];
int inSet[100];

void rCombinations(int pos, int amt) {
    if (n - pos < r - amt)
        return;
    if (amt == r) {
        for (int i = 0; i < n; i++)
            if (inSet[i])
                printf("%d ", skup[i]);
        printf("\n");
        return;
    }
    inSet[pos] = true;
    rCombinations(pos + 1, amt + 1);
    inSet[pos] = false;
    rCombinations(pos + 1, amt);
}

int main() {
    n = 5, k = 2;
    skup[0] = 1;
    skup[1] = 2;
    skup[2] = 3;
    skup[3] = 4;
    skup[4] = 5;
    // rCombinations(0, 0);

    return 0;
}
