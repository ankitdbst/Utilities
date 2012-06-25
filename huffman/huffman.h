#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <algorithm>
#include <fstream>
#include <queue>

using namespace std;

#define debug(args...) dbg(),args
#define rep(A,B,C) for(int A=B;A<C;++A)
#define foreach(A,B) for(typeof((B).begin()) A = (B).begin();  A != (B).end(); ++A)
#define pb(A,B) A.push_back(B)
#define len(A) A.length()
#define sz(A) A.size()

struct node 
{
    int info;
    bool isleft;
    node *parent;
};

class CompareNodes 
{
    public:
        bool operator()(node* a, node* b) 
        {
            return !(a->info < b->info);
        }
};

class Huffman
{
    priority_queue<node*, vector<node*>, CompareNodes> rootnodes; 

    public:
        string encode(string s);

    private:        
        map<char, int> calcfreq(string s);        
        void buildtree();
        map<char, string> getcodes(map<char, node*> pos);
        void printcodes(map<char, string> codes);
        node* maketree(int data);
        void strrev(string& s, int pos);
};

#endif // HUFFMAN_H