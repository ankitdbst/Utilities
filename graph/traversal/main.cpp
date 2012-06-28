#include "graph.h"

bool DBG;

int main (int argc, char *argv[])
{
    DBG = (argc > 1 && *argv[1]);

    int t;
    cin >> t;

    while (t-- > 0) {
        Graph g;

        int n;
        cin >> n;
        VVI adj(n);

        FOR(i, 0, n) {
            int m;
            cin >> m;
            PB(adj, VI(m));
            FOR(j, 0, m) {
                int v;
                cin >> v;
                PB(adj[i], v-1);
            }
        }

        g.dfs(adj);

        VI dt = g.discover_time(), ft = g.finish_time(), p = g.predecessor();

        cout
            << "Node" << setw(15) << "Predecessor"
            << setw(15) << "Start" << setw(15) << "Finish" << endl;

        FOR(i, 0, n) {
            cout
                << i+1 << setw(15) << p[i]+1
                << setw(15) << dt[i] << setw(15) << ft[i] << endl;
        }

        cout << endl;
    }
}
