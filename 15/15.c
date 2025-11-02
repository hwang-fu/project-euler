#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

// Idea:
//
// In a M x N grid you must take exactly M downs and N rights.
// Therefore, pahts(m, n) = (m + n) = (m + n)
//                          (  m  ) = (  n  )
//
// pahts(20, 20) = 137846528820


#define ROW (20)
#define COL (20)

uint64_t Cache[ROW][COL] = { 0 };

uint64_t LatticePath(uint64_t m, uint64_t n)
{
    if (m == 0 || n == 0)
    {
        return 1;
    }

    if (Cache[m][n] != 0)
    {
        return Cache[m][n];
    }

    Cache[m][n] = LatticePath(m-1, n) + LatticePath(m, n-1);
    return Cache[m][n];
}

void Solve()
{
    fprintf(stdout, "%lu\n", LatticePath(20, 20));
}

int main()
{
    Solve();
    return 0;
}
