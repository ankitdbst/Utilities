#include "priority-queue.h"
int main (int argc, char *argv[])
{
    PriorityQueue<int> pq(true);

    pq.push_back(3);
    pq.print_tree();
    cout << endl;

    debug(pq.pop());
    pq.print_tree();
    cout << endl;

    return 0;
}    