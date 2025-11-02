#include <stdio.h>
#include <stdint.h>

// Idea:
//
// For any positive integer N, the number of decimal digits D is
// D = floor(log10(N)) + 1
//
// For 2^1000, log10(2^1000) = 1000 * log10 (2) = 1000 * (ln 2 / ln 10) ~= 301.0299xxxx

#define K (1000)


void Solve()
{
    // allocate enough space.
    uint8_t digits[350] = { 0 };

    // 2^0 = 1
    digits[0] = 1;

    // current `digits` length is 1.
    uint64_t length = 1;

    for (uint64_t i = 1; i <= K; i++)
    {
        uint8_t carry = 0;
        for (uint64_t i = 0; i < length; i++)
        {
            uint8_t value = digits[i] * 2 + carry;
            digits[i] = (value % 10);
            carry = (value / 10);
        }
        if (carry)
        {
            digits[length++] = carry;
        }
    }

    uint64_t sum = 0;
    for (uint64_t i = 0; i < length; i++)
    {
        sum += digits[i];
    }
    fprintf(stdout, "%lu\n", sum);
}

int main()
{
    Solve();
    return 0;
}
