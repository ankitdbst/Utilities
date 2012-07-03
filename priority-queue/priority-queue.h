/**
 * Implementing a Priority Queue using Heap as a 
 * the underlying data structure
 *
 * NOTE: Cannot use a separate class file due to the use of templates,
 * as it require instantiating every object with the possible 
 * types that the program could use.
 * See : http://stackoverflow.com/questions/8752837/undefined-reference-to-template-class-constructor
 */
#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;

#define debug(args...) dbg(),args
#define FOR(A,B,C) for(int A=B;A<C;++A)
#define RFOR(A,B,C) for(int A=B;A>=C;--A)

bool DBG = 1;

/**
 * Standard debugging template
 */
struct dbg 
{
    template<typename T> dbg& operator , (const T& v) {
        if (DBG)
            cerr << v << " ";
        return *this;
    }
    ~dbg() {
        if (DBG) cerr << endl;
    }
};

template<class T>
class PriorityQueue
{
    struct node
    {
        T info;
        int id; // id field to maintain complete binary tree
        node *left, *right, *parent;
        node(T data, int index) {
            info = data;
            id = index;
            left = right = parent = NULL;
        }

    } *root;

    bool apq; // default ascending pq
    int items; // stores the no of elements in the pq
    node *lastnode; // stores the latest node added to the pq

    public:
        
        /**
         * Initializes a priority queue with 0 elements
         */
        PriorityQueue() 
        {
            root = NULL;
            items = 0;
            apq = true;
        }

        PriorityQueue(bool asc) 
        {
            root = NULL;
            items = 0;
            apq = asc;
        }

        /**
         * Pushes an element to the leftmost empty branch
         * to maintain a complete binary tree
         */
        void push_back(T obj) 
        {
            ++items; // increase the # of el in the pq
            node *temp = new node(obj, items);
            if (root == NULL) { // empty queue
                root = temp;
                temp->parent = NULL;
            } else {
                node *parent = get_parent_node(root, items);
                temp->parent = parent;
                if (items%2 == 0) {
                    parent->left = temp;
                } else {
                    parent->right = temp;
                }
            }

            lastnode = temp; // store the last_node added
            make_heap(temp);    // creates the heap ordering (min/max)
        }

        /**
         * Pops the first item of the queue and reorders the heap
         */
        T pop()
        {
            if (root == NULL) {
                cout << "Queue is empty!" << endl;
                exit(1);
            }
            
            // store value of top element
            T top = root->info;

            if (items == 1) {
                --items;
                delete root;
                root = NULL;
                return top;
            }

            node *p = get_parent_node(root, items), *last;
            
            if (p->right != NULL) {
                last = p->right;
                p->right = NULL;
            } else {
                last = p->left;                
                p->left = NULL;
            }

            // swap value with root
            swapByValue(root, last);

            // remove node          
            delete last;            
            items--;

            heapify(root);
            return top;
        }

        /**
         * Prints the inorder traversal for the tree
         */
        void print_tree() 
        {
            inorder(root);
        } 

        /**
         * Returns the size of the priority queue
         */
        int size() 
        {
            return items;
        }

    private:

        /**
         * Returns the parent to the node where the new node
         * is to be inserted
         */
        node *get_parent_node(node *p , int id) 
        {
            if (p->id == id/2) {
                return p;
            }

            if (p->left != NULL) {
                return get_parent_node(p->left, id);
            } else if (p->right != NULL) {
                return get_parent_node(p->right, id);
            }
        }

        /**
         * Creates the min/max heap with the comparator
         * in a bottom-up fashion
         */
        void make_heap(node *p)
        {
            while (p != root) {
                if (compare(p, p->parent)) {
                    swapByValue(p, p->parent);
                } else {
                    break;
                }
                p = p->parent;
            }
        }

        /**
         * Restores the heap after the top element is 
         * removed
         */
         void heapify(node *p)
         {
            if (p->left != NULL && !compare(p, p->left) &&
                 (p->right != NULL && compare(p->left, p->right))) {
                swapByValue(p, p->left);
                heapify(p->left);
            } else if (p->right != NULL && !compare(p, p->right)) {
                swapByValue(p, p->right);
                heapify(p->right);
            }
         }

        /**
         * Define the comparator for the objects 
         * Will decide whether, it is a asc or desc pq
         */
         bool compare(node *first, node *second) 
         {
            if (apq) {
                return first->info < second->info;
            } {
                return first->info > second->info;
            }
         }

        /**
         * Swapping nodes by value
         */
        void swapByValue(node * &first, node * &second)
        {
            T temp = first->info;                    
            first->info = second->info;
            second->info = temp;
        }

        /**
         * Inorder tree traversal
         */
        void inorder(node *p) 
        {
            if (p != NULL) {
                inorder(p->left);
                cout << "Item #" << p->id << " " << p->info << endl;
                inorder(p->right);
            }
        }

};

#endif // PRIORITYQUEUE_H