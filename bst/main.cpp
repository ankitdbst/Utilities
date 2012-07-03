#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <vector>
#include <string>
#include <cmath>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;

#define debug(args...) dbg(),args
#define FOR(A,B,C) for(int A=B;A<C;++A)
#define RFOR(A,B,C) for(int A=B;A>=C;--A)
#define PB(A,B) A.push_back(B);
#define MEM(A,B) memset(A,B,sizeof(A))

bool DBG;
struct dbg
{
    template<typename T> dbg& operator , (const T& v) {
        if (DBG)
            cerr << v << " "; return *this;
    }
    ~dbg() {
        if (DBG)
            cerr << endl;
    }
};

/**
 * Main code starts here
 */

template<class T>
class BinaryTree
{
    public:

        /**
         * Default Constructor
         */
        BinaryTree()
        {
            root = NULL;
        }

        /**
         * This method inserts a given node into the
         * binary search tree
         */
        void insert(T data)
        {
            //makeTree(data, &root);
            nonrecurseMakeTree(data);
        }

        /**
         * Prints the tree inorder using the recursive
         * or non recursive version
         */
        void printTree(bool choice)
        {
            if (choice) {
                recurseInorderTrav(root);
            } else {
                nonrecurseInorderTrav(root);
            }
        }

    private:

        /**
         * Struture to hold the nodes of the tree
         */
        struct node
        {
            T info;
            node *left, *right;
        } *root;

        /**
         * Builds the tree using recursion
         */
        void makeTree(T data, node **root)
        {
            if (*root == NULL) {
                *root = new node;
                (*root)->info   = data;
                (*root)->left   = NULL;
                (*root)->right  = NULL;
                return;
            }
            else {
                if ((*root)->info >= data) {
                    makeTree(data, &(*root)->left);
                } else {
                    makeTree(data, &(*root)->right);
                }
            }
        }

        /**
         * Non recursive version of the makeTree
         */
        void nonrecurseMakeTree(T data)
        {
            node *temp = new node;

            temp->info = data;
            temp->left = temp->right = NULL;

            if (root == NULL) {
                root = temp;
            } else {
                node *p = root, *q;

                while (p != NULL) {
                    q = p;
                    if (p->info >= data) {
                        p = p->left;
                    } else {
                        p = p->right;
                    }
                }
                if (q->info >= data) {
                    q->left = temp;
                } else {
                    q->right = temp;
                }
            }
        }

        /**
         * This is the non recursive version of the
         * inorder tree traversal using the stack
         */
        void nonrecurseInorderTrav(node *root)
        {
            stack<node*> s;

            node *p = root;
            do {
                while (p != NULL) {
                    s.push(p);
                    p = p->left;
                }
                if (!s.empty()) {
                    p = s.top();
                    s.pop();
                    cout << p->info << " ";
                    p = p->right;
                }
            } while (!s.empty() || p != NULL);
        }

        /**
         * This is the inorder tree traversal using recursion
         */
        void recurseInorderTrav(node *root)
        {
            if (root != NULL) {
                recurseInorderTrav(root->left);
                cout << root->info << " ";
                recurseInorderTrav(root->right);
            }
        }

        /**
         * Using operator overloading for >=
         * used when comparing info part of the node.
         */
        T operator>=(const T& other)
        {
            return (this >= other);
        }

};

int main (int argc, char *argv[])
{
    BinaryTree<string> bt;

    int n;
    cin >> n;

    string data;
    FOR(i, 0, n) {
        cin >> data;
        bt.insert(data);
    }

    bt.printTree(true);
    cout << endl;
    bt.printTree(false);
    cout << endl;
}
