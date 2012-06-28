/* Import Utils */
#include "utilities.h"

int main (int argc, char *argv[])
{
    int n, k;
    cin >> n >> k;

    Utilities u;
    cout << u.C(n, k) << endl;
}
