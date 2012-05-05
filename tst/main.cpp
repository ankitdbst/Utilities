#include "ternary.h"

bool DBG;

int main (int argc, char *argv[])
{
    DBG = (argc > 1 && *argv[1]);

    TernarySearchTree tst;

    int n;
    cin >> n;

    string recipe;
    int p;

    FOR(i, 0, n) {
        cin >> recipe >> p;
        tst.add(recipe, p);
    }

    int q;
    cin >> q;

    FOR(i, 0, q) {
        string s;
        cin >> s;
        if (tst.query(s)) {
            cout << tst.getmatch() << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
