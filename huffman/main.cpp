#include "huffman.h"

int main (int argc, char *argv[]) 
{
    freopen("hfin", "r", stdin);

    string s;
    cin >> s;

    Huffman hf;
    cout << hf.encode(s) << endl;

    return 0;    
}