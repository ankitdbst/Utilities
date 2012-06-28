/*
 * A utilities class to implement various utility functions
 */
#ifndef UTILITIES_H
#define UTILITIES_H

#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef vector<ll> VL;
typedef vector<vector<ll> > VVL;

#define debug(args...) dbg(),args
#define FOR(A,B,C) for(int A=B;A<C;++A)
#define RFOR(A,B,C) for(int A=B;A>=C;--A)
#define PB(A,B) A.push_back(B);
#define MAX(A,B) ((A > B) ? A : B)
#define MIN(A,B) ((A < B) ? A : B)

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

class Utilities {
    public:
        ll C(int n, int r);
    private:
};

#endif // UTILITIES_H
