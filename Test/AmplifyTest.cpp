#include <stdio.h>
#include "../RacingUtil.hpp"

int main() {
    int fromMin = -100;
    int fromMax = 0;
    int toMin = 10;
    int toMax = 90;
    int toTotal = toMax + toMin;
    printf("%d %d\n", fromMin, fromMax);
    for (int toMinLocal = toMin; toMinLocal <= toMax; toMinLocal++) {
        int toMaxLocal = toTotal - toMinLocal;
        for (int target = fromMin; target <= fromMax; target++) {
            printf("%d %d %d\n", toMinLocal, toMaxLocal, amplify(target, fromMin, fromMax, toMinLocal, toMaxLocal));
        }
    }

    return 0;
}
