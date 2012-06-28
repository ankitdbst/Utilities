#include "graph.h"

/**
 * Transistive Closure of the path matrix O(n^4)
 */
VVI Graph::trans_closure(VVI adj, int n) 
{
    VVI path, adjn;
    // Initialize the path matrix
    FOR(i, 0, n) {
        PB(path, VI());
        PB(adjn, VI());
        FOR(j, 0, n) {
            PB(path[i], adj[i][j]);
            PB(adjn[i], adj[i][j]);
        }
    }

    FOR(i, 1, n) {
        adjn = prod(adjn, adj, n);
        FOR(j, 0, n) {
            FOR(k, 0, n) {
                path[j][k] |= adjn[j][k];
            }
        }
    }

    return path;
}

/**
 * Implements the floyd warshall algorithm to 
 * calculate the transistive closure of path 
 * matrix O(n^3)
 */
VVI Graph::floyd_warshall(VVI adj, int n) 
{
    VVI path;

    FOR(i, 0, n) {
        PB(path, VI());
        FOR(j, 0, n) {
            PB(path[i], adj[i][j]);
        }
    }

    FOR(k, 0, n) {
        FOR(i, 0, n) {
            if (path[i][k]) {
                FOR(j, 0, n) {
                    path[i][j] |= path[k][j];
                }
            }
        }
    }

    return path;
}

/**
 * Method to return the boolean product of 
 * adjacency matrices
 */
VVI Graph::prod(VVI m1, VVI m2, int n) 
{
    VVI p;

    FOR(i, 0, n) {
        PB(p, VI());
        FOR(j, 0, n) {  
            bool path = false;
            FOR(k, 0, n) {
                path |= (m1[i][k] && m2[k][j]);
            }
            PB(p[i], path); 
        }
    }

    return p;
}
