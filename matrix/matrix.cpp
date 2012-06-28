/*
 * Import Matrix Header
 */
#include "matrix.h"

/*
 * This method returns the cofactor
 * for a particular row, col index
 */
double Matrix::cofactor(VVD m, int row, int col)
{
    if (m.size() == 1) {
        return m[0][0];
    } else {
        int sign = 1;
        if ((row + col) % 2) {
            sign = -1;
        }
        return sign * det(submatrix(m, row, col));
    }
}

/*
 * This method calculates the determinant
 * of the matrix using m[0][i] * cofactor(m, 0, i)
 */
double Matrix::det(VVD m)
{
    double d;

    switch (m.size()) {
        case 1:
            d = m[0][0];
            break;
        case 2:
            d = m[0][0]*m[1][1] - m[0][1]*m[1][0];
            break;
        case 3:
            d = m[0][0]*(m[1][1]*m[2][2] - m[1][2]*m[2][1]) -
                m[0][1]*(m[1][0]*m[2][2] - m[1][2]*m[2][0]) +
                m[0][2]*(m[1][0]*m[2][1] - m[1][1]*m[2][0]);
            break;
        default:
            d = 0.0;
            FOR(i, 0, m.size()) {
                d += m[0][i] * cofactor(m, 0, i);
            }
    }

    return d;
}

/*
 * This method returns the transpose of the matrix M
 */
VVD Matrix::transpose(VVD m)
{
    VVD tm;

    FOR(i, 0, m.size()) {
        PB(tm, VD());
        FOR(j, 0, m[i].size()) {
            PB(tm[i], m[j][i]);
        }
    }

    return tm;
}

/*
 * This method returns the sum
 * of the diagonal entries of the square matrix M
 */
double Matrix::trace(VVD m)
{
    double tr = 0;

    FOR(i, 0, m.size()) {
        tr += m[i][i];
    }

    return tr;
}

/*
 * This method returns the transpose of the cofactor matrix
 */
VVD Matrix::adjoint(VVD m)
{
    VVD adj;

    FOR(i, 0, m.size()) {
        PB(adj, VD());
        FOR(j, 0, m[i].size()) {
            PB(adj[i], cofactor(m, i, j));
        }
    }

    return transpose(adj);
}

/*
 * This method returns the inverse of a non-singular matrix
 * Contains exit() instance
 */
VVD Matrix::inverse(VVD m)
{
    VVD inv;

    double d = det(m);

    if (d == 0) {
        cout << "Singular Matrix!" << endl;
        exit(0);
    }

    VVD adj = adjoint(m);

    FOR(i, 0, m.size()) {
        PB(inv, VD());
        FOR(j, 0, m[i].size()) {
            PB(inv[i], (1.0 / d) * adj[i][j]);
        }
    }

    return inv;
}

/*
 * This method returns the addition M1+M2
 * Contains exit() instance
 */
VVD Matrix::add(VVD m1, VVD m2)
{
    int nrows1 = m1.size(), ncols1 = m1[0].size();
    int nrows2 = m2.size(), ncols2 = m2[0].size();

    VVD a;

    if (nrows1 != nrows2 || ncols1 != ncols2) {
        cout << "Incompatible matrix addition!" << endl;
        exit(0);
    }

    FOR(i, 0, nrows1) {
        PB(a, VD());
        FOR(j, 0, ncols1) {
            PB(a[i], m1[i][j] + m2[i][j]);
        }
    }

    return a;
}

/*
 * This method returns the subtraction M1-M2
 * Contains exit() instance
 */
VVD Matrix::subtract(VVD m1, VVD m2)
{
    int nrows1 = m1.size(), ncols1 = m1[0].size();
    int nrows2 = m2.size(), ncols2 = m2[0].size();

    VVD s;

    if (nrows1 != nrows2 || ncols1 != ncols2) {
        cout << "Incompatible matrix subtraction!" << endl;
        exit(0);
    }

    FOR(i, 0, nrows1) {
        PB(s, VD());
        FOR(j, 0, ncols1) {
            PB(s[i], m1[i][j] - m2[i][j]);
        }
    }

    return s;
}

/*
 * This method returns the product M1*M2
 * Contains exit() instance
 */
VVD Matrix::mult(VVD m1, VVD m2)
{
    int nrows1 = m1.size(), ncols1 = m1[0].size();
    int nrows2 = m2.size(), ncols2 = m2[0].size();

    if (ncols1 != nrows2) {
        cout << "Incompatible matrix multiplication!" << endl;
        exit(0);
    }

    VVD m;

    FOR(i, 0, nrows1) {
        PB(m, VD());
        FOR(j, 0, ncols2) {
            double sum = 0;
            FOR(k, 0, ncols1) {
                sum += m1[i][k] * m2[k][j];
            }
            PB(m[i], sum);
        }
    }

    return m;
}

/*
 * This method returns the scalar multipication matrix a*M
 */
VVD Matrix::scalarmult(VVD m, double s)
{
    VVD sm;

    FOR(i, 0, m.size()) {
        PB(sm, VD());
        FOR(j, 0, m[i].size()) {
            PB(sm[i], s * m[i][j]);
        }
    }

    return sm;
}

/*
 * This method returns a submatrix of M
 * with 'row' & 'col' removed
 */
VVD Matrix::submatrix(VVD m, int row, int col)
{
    int nrows, ncols;
    nrows = ncols = m.size() - 1;

    VVD sm;
    int r = 0;

    FOR(i, 0, m.size()) {
        if (i != row) {
            PB(sm, VD());
            FOR(j, 0, m[i].size()) {
                if (j != col) {
                    PB(sm[r], m[i][j]);
                }
            }
            r++;
        }
    }

    return sm;
}

/*
 * Prints the matrix
 */
void Matrix::printmat(VVD m)
{
    FOR(i, 0, m.size()) {
        FOR(j, 0, m[i].size()) {
            cout << setw(10) << m[i][j] << ' ';
        }
        cout << endl;
    }
}
