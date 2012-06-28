/*
 * A class to implement various graph operations
 * Refer to : http://en.wikipedia.org/wiki/Depth-first_search
 * For more on cross-edges, back-edges, tree-edges
 */
#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

typedef vector<int> VI;
typedef vector<VI > VVI;

#define debug(args...) dbg(),args
#define PB(A,B) A.push_back(B);
#define FOR(A,B,C) for(int A=B;A<C;++A)
#define RFOR(A,B,C) for(int A=B;A>=C;--A)

/*
 * Standard debugging template
 */
struct dbg
{
    template<typename T> dbg& operator , (const T& v) {
        cerr << v << " "; return *this;
    }
    ~dbg() {
        cerr << endl;
    }
};

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
        void dfs(VVI adj);
        VI predecessor();
        VI discover_time();
        VI finish_time();
    private:
        void dfs_visit(VVI adj, int u);
};

#endif // GRAPH_H
