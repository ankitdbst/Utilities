#include "graph.h"

/**
 * Standard debugging template
 */
bool DBG;
struct dbg {
    template<typename T> dbg& operator , (const T& v) {
        if (DBG)
            cerr << v << " ";
        return *this; 
    }
    ~dbg() {
        if (DBG)
            cerr << endl; 
    }
};

int main (int argc, char *argv[]) 
{
    DBG = (argc > 1 && *argv[1]);

    Graph g;

    int n;
    cin >> n;

    VVI mat;

    FOR(i, 0, n) {
        PB(mat, VI());
        FOR(j, 0, n) {
            int p;
            cin >> p;
            PB(mat[i], p);
        }
    }

    cout << "Transistive closure of the path matrix.." << endl;

    VVI path = g.trans_closure(mat, n);

    FOR(i, 0, n) {
        FOR(j, 0, n) {
            cout << setw(5) << path[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
