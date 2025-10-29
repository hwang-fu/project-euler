#include <stdio.h>
#include <stdint.h>

/// Even Fibonacci Numbers

// Fibonacci Series defined in the Problem 2:
// fib(0) = 1
// fib(1) = 2
// fib(2) = 3
// fib(3) = 5
// fib(4) = 8
// ...
// fib(n) = fib(n-1) + fib(n-2)

#define FOUR_MILLION (4000000ul)

uint64_t fib(uint64_t n)
{
    if (n == 0)
    {
        return 1;
    }

    if (n == 1)
    {
        return 2;
    }

    return fib(n-1) + fib(n-2);
}

uint64_t solve()
{
    uint64_t sum = 0;
    uint64_t n = 0;
    while (1)
    {
        uint64_t term = fib(n);
        if (term > FOUR_MILLION)
        {
            break;
        }
        if (term % 2 == 0)
        {
            sum += term;
        }
        n++;
    }
    return sum;
}

int main()
{
    printf("The sum of the even-valued fibonacci numbers whose value do not exceed 4 million: %lu\n", solve());
    return 0;
}
