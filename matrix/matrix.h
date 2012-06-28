/*
 * A matrix class to implement various matrix operations
 */
#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

typedef vector<double> VD;
typedef vector<vector<double> > VVD;

#define debug(args...) dbg(),args
#define FOR(A,B,C) for(int A=B;A<C;++A)
#define RFOR(A,B,C) for(int A=B;A>=C;--A)
#define PB(A,B) A.push_back(B);

/*
 * Standard debugging template
 */
struct dbg {
    template<typename T> dbg& operator , (const T& v) {
        cerr << v << " "; return *this;
    }
    ~dbg() {
        cerr << endl;
    }
};

class Matrix {
    public:
        double cofactor(VVD m, int row, int col);
        double det(VVD m);
        VVD adjoint(VVD m);
        VVD transpose(VVD m);
        double trace(VVD m);
        VVD inverse(VVD m);
        VVD add(VVD m1, VVD m2);
        VVD subtract(VVD m1, VVD m2);
        VVD mult(VVD m1, VVD m2);
        VVD scalarmult(VVD m, double s);
        void printmat(VVD m);
    private:
        VVD submatrix(VVD m, int row, int col);
};

#endif // MATRIX_H
