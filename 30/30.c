#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>

// Idea:
//
// 9^5 = 59049
//
// Assuming the number(s) we are looking for has k digits,
// so its maximal potential value could be: k * (9^5)
//
// if k = 6, a 6-digit number has at most: 6 x (9^5) = 354294
// if k = 7, a 7-digit number has at most: 7 * (9^5) = 413343 which is 6-digit! That means there is NO 7-digit number could possibly fit the criterion.
// So does k = 8, k = 9, ...
// Therefore, we conclude => max(k) = 6, and k >= 1. The biggest number we have to check is `6 x (9^5) = 354294`
// So we can brute-force it from 2 to 354294.

uint64_t DigitFifthPowers(uint64_t n)
{
    uint64_t sum = 0;
    while (n)
    {
        sum += (uint64_t) pow((double) (n % 10), 5.0);
        n /= 10;
    }
    return sum;
}

void Solve()
{
    uint64_t sum = 0;
    for (uint64_t i = 2; i <= 354294; i++)
    {
        if (i == DigitFifthPowers(i))
        {
            sum += i;
        }
    }
    printf("%lu\n", sum);
}

int main()
{
    Solve();
    return 0;
}
