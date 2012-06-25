#include "huffman.h"

/**
 * Standard debugging code
 */

bool DBG = 1;
struct dbg 
{
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

/**
 * Main Code starts here 
 */

string Huffman::encode(string s) 
{
    map<char, int> freq = calcfreq(s);

    map<char, node*> position;
    
    node *p;
    foreach(v, freq) {    
        node *p = maketree(v->second);
        position[v->first] = p;
        rootnodes.push(p);
    }
        
    buildtree();

    map<char, string> codes;
    codes = getcodes(position);

    string hfcode = "";
    rep(i, 0, s.length()) {
        hfcode += codes[s[i]];
    }

    return hfcode;
}

/**
 * Return the pointer to the newly allocated node
 */
node* Huffman::maketree(int data) 
{
    node *p = new node;
    p->info = data;
    p->parent = NULL;
    return p;
}

/**
 * Calculates the frequency of the characters
 * in the input string
 */
map<char, int> Huffman::calcfreq(string s) 
{
    map<char, int> f;

    rep(i, 0, len(s)) {
        f[s[i]]++;
    }

    return f;    
}

/**
 * Makes the tree for the huffman encoding
 */
void Huffman::buildtree() 
{       
    node *p, *p1, *p2;
    while(rootnodes.size() > 1) {
        p1 = rootnodes.top();
        rootnodes.pop();
        p1->isleft = true;        
        p2 = rootnodes.top();
        rootnodes.pop();
        p2->isleft = false;
        p = maketree(p1->info+p2->info);
        p1->parent = p2->parent = p;
        rootnodes.push(p);
    }
}

/*
 * Returns the codes for the distinct chars in 
 * input string
 */
map<char, string> Huffman::getcodes(map<char, node*> pos)
{   
    node *p, *root = rootnodes.top();
    rootnodes.pop(); 
    
    map<char, string> codes;

    foreach(v, pos) {
        p = v->second;
        string cd = "";
        while (p != root) {            
            if (p->isleft) {
                cd += '0';
            } else {
                cd += '1';
            }
            p = p->parent;
        }
        strrev(cd, 0);
        codes[v->first] = cd;
    }

    return codes;
}

/**
 * Display the codes 
 */
void Huffman::printcodes(map<char, string> codes)
{   
    foreach(v, codes) {
        debug(v->first, v->second);
    }
}

/*
 * Reverses the string
 */
void Huffman::strrev(string& s, int pos)
{
    if (pos < len(s)/2) {
        int rpos = len(s)-pos-1;
        char ch = s[pos];
        s[pos] = s[rpos];
        s[rpos] = ch;        
        strrev(s, pos+1);
    }
}