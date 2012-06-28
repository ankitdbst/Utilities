#include "graph.h"

/*
 * Runs depth-first search for the graph
 */
void Graph::dfs(VVI adj)
{
    FOR(i, 0, adj.size()) {
        PB(color, WHITE);
        PB(p, i);
        PB(d_time, 0);
        PB(f_time, 0);
    }

    time = 0;

    FOR(i, 0, adj.size()) {
        if (color[i] == WHITE) {
            dfs_visit(adj, i);
        }
    }
}

/*
 * Returns the predecessor for the vertex
 */
VI Graph::predecessor()
{
    return p;
}

/*
 * Returns the discovered time for the vertex
 */
VI Graph::discover_time()
{
    return d_time;
}

/*
 * Returns the finished processing time for the vertex
 */
VI Graph::finish_time()
{
    return f_time;
}

/*
 * Populates start, finish and predecessors vectors
 * Detects tree, back, cross or forward edges.
 * Tree edges   : edges part of spanning tree
 * Forward edge : edges from one node of a tree to its descendants
 * Back edge    : edges from one node of a tree to its ancestors
 * Cross edge   : which do neither
 */
void Graph::dfs_visit(VVI adj, int u)
{
    color[u] = GRAY;
    d_time[u] = ++time;

    FOR(i, 0, adj.size()) {
        FOR(j, 0, adj[i].size()) {
            int v = adj[i][j];
            if (color[v] == WHITE) {
                // (u, v) is a tree edge
                p[v] = u;
                dfs_visit(adj, v);
            } else if (color[v] == GRAY) {
                ;// (u, v) is a back edge
            } else if (color[v] == BLACK) {
                ;// (u, v) is a forward or cross edge
            }
        }
    }

    color[u] = BLACK;
    f_time[u] = ++time;
}
