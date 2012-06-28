/**
 * Class to implement various graph routines
 */
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <iomanip>
#include <algorithm>
using namespace std;

typedef vector<int> VI;
typedef vector< VI > VVI;

#define debug(args...) dbg(),args
#define FOR(A,B,C) for(int A=B;A<C;++A)
#define RFOR(A,B,C) for(int A=B;A>=C;--A)
#define PB(A,B) A.push_back(B);

enum C
{
    WHITE, GRAY, BLACK
};

class Graph 
{
    VI p, d_time, f_time;
    vector<C> color;
    int time;
    
    public:
        VVI trans_closure(VVI adj, int n);
        VVI floyd_warshall(VVI adj, int n);

    private:
        VVI prod(VVI m1, VVI m2, int n);

};

#endif // GRAPH_H