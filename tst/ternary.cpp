#include "ternary.h"

TernarySearchTree::TernarySearchTree()
{
    root = NULL;
    match = "";
}

/*
 * This method adds a node of string to the tree
 */
void TernarySearchTree::add(string s, int w)
{
    root = add(s, 0, w, root);
}

/*
 * Use together with query(...)
 * This method returns the weighted match for the given query string.
 */
string TernarySearchTree::getmatch()
{
    return match;
}

/*
 * This method queries for a given string among the pool of
 * strings and returns whether prefix is present in any
 */
bool TernarySearchTree::query(string s)
{
    int pos = 0;
    node *n = root;

    match = "";

    while(n != NULL) {
        if (s[pos] < n->ch) {
            n = n->left;
        } else if (s[pos] > n->ch) {
            n = n->right;
        } else {
            match += n->ch;
            if (++pos == s.length()) {
                findmatch(n->center);
                return true;
            }
            n = n->center;
        }
    }

    return false;
}

/*
 * Adds a node character by character recursively to the tree
 */
node* TernarySearchTree::add(string s, int pos, int w, node *n)
{
    if (n == NULL) {
        node *temp;
        temp = (node *) malloc(sizeof(node));
        temp->ch = s[pos];
        temp->wordend = false;
        temp->weight = w;
        temp->left = temp->right = temp->center = NULL;
        n = temp;
    }

    if (s[pos] < n->ch) {
        n->left = add(s, pos, w, n->left);
    } else if (s[pos] > n->ch) {
        n->right = add(s, pos, w, n->right);
    } else {
        if (pos + 1 == s.length()) {
            n->wordend = true;
        } else {
            n->center = add(s, pos + 1, w, n->center);
        }
    }

    return n;
}

/*
 * This finds the possible weighted match for the query string
 * once query(...) returns true
 */
void TernarySearchTree::findmatch(node *n)
{
    node *max;

    while (!n->wordend) {
        max = n;
        if (n->right != NULL && n->right->weight > max->weight) {
            max = n->right;
        }
        if (n->left != NULL && n->left->weight > max->weight) {
            max = n->left;
        }
        if (max == n) {
            match += max->ch;
            n = n->center;
        } else {
            n = max;
        }
    }

    match += n->ch;
}
