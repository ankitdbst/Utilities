/*
 * A class to implement a ternary search tree
 * Uses : Autocomplete, spell - check
 * Refer to : http://en.wikipedia.org/wiki/Ternary_search_tree
 */
#ifndef TERNARY_H
#define TERNARY_H

#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

#define debug(args...) dbg(),args
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

struct node
{
    char ch;
    node *left, *center, *right;
    bool wordend;
    int weight;
};

class TernarySearchTree
{
    node *root;
    string match;

    public:
        TernarySearchTree();
        void add(string s, int w);
        bool query(string s);
        string getmatch();
    private:
        node* add(string s, int pos, int w, node *n);
        void findmatch(node *n);
};

#endif // TERNARY_H
