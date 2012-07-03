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

typedef long long ll;

#define debug(args...) dbg(),args
#define FOR(A,B,C) for(int A=B;A<C;++A)
#define RFOR(A,B,C) for(int A=B;A>=C;--A)
#define PB(A,B) A.push_back(B);)
#define MEM(A,B) memset(A,B,sizeof(A))

bool DBG;

struct dbg {
    template<typename T> dbg& operator , (const T& v) {
        if (DBG)
            cerr << v << " ";
        return *this;
    }
    ~dbg() {
        if (DBG) cerr << endl;
    }
};

class Sort
{
    public:
        /**
         * Recursive procedure to sort an array using
         * quicksort
         * Uses a_0 to partition the given array
         */
        void quicksort(int x[], int lb, int ub)
        {
            if (lb >= ub) {
                return;
            }
            int pos = partition(x, lb, ub);
            quicksort(x, lb, pos-1);
            quicksort(x, pos+1, ub);
        }

        /**
         * Print the array
         */
        void debugarr(int x[], int lb, int ub)
        {
            if (DBG) {
                FOR(i, lb, ub) {
                    cout << x[i] << " ";
                }
                cout << endl;
            }
        }

    private:
        /**
         * Returns the partition index for the element a_lb
         */
        int partition(int x[], int lb, int ub)
        {
            int down = lb, up = ub;
            while (up >= down) {
                while (x[down] <= x[lb]) { // x[down] > a_lb
                    down++;
                }
                while (x[up] > x[lb]) { // x[up] <= a_lb
                    up--;
                }
                if (up > down) {
                    swap(x[down], x[up]);
                }
            }

            swap(x[lb], x[up]); // swap the pivot element finally

            debugarr(x, lb, ub);
            return up;
        }

        /**
         * Swaps 2 elements by reference
         */
        void swap(int &a, int &b)
        {
            int temp = a;
            a = b;
            b = temp;
        }

};

int main (int argc, char *argv[])
{
    DBG = (argc > 1 && *argv[1]);

    Sort s;

    int n;
    cin >> n;

    int a[n];
    FOR(i, 0, n) {
        cin >> a[i];
    }

    s.quicksort(a, 0, n-1);

    FOR(i, 0, n) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}

