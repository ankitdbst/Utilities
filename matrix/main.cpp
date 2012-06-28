/*
 * Import Matrix Class
 */
#include "matrix.h"

int main (int argc, char *argv[]) {

    Matrix mat;

    int nrows, ncols;
    cin >> nrows >> ncols;

    VVD m1, m2;

    FOR(i, 0, nrows) {
        PB(m1, VD());
        FOR(j, 0, ncols) {
            double field;
            cin >> field;
            PB(m1[i], field);
        }
    }

    cin >> nrows >> ncols;

    FOR(i, 0, nrows) {
        PB(m2, VD());
        FOR(j, 0, ncols) {
            double field;
            cin >> field;
            PB(m2[i], field);
        }
    }

    VVD s = mat.subtract(m1, m2);
    mat.printmat(s);

    return 0;
}
