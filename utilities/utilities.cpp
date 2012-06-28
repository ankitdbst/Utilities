#include "utilities.h"

/*
 * It uses the nCr property nCr = n-1Cr-1 + n-1Cr
 * Only the previous row is stored in the computation
 * Time Complexity  : O(n*r)
 * Space Complexity : O(r)
 */
ll Utilities::C(int n, int r)
{
    VVL C(2, VL(r+1, 0));

    FOR(i, 0, n+1) {
        FOR(j, 0, MIN(r, i)+1) {
            if (j == 0 || j == i) {
                C[i&1][j] = 1;
            } else {
                C[i&1][j] = C[(i-1)&1][j-1] + C[(i-1)&1][j];
            }
        }
    }

    return C[n][r];
}
