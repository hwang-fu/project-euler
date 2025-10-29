#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(uint64_t n)
{
    if (n <= 9)
    {
        return true;
    }

    uint64_t original = n;
    uint64_t reversed = 0;

    while (n)
    {
        reversed *= 10;
        reversed += n % 10;
        n /= 10;
    }

    return original == reversed;
}

uint64_t solve()
{
    uint64_t largestProduct = 0;

    for (uint64_t i = 999; i >= 100; i--)
    {
        for (uint64_t j = i; j >= 100; j--)
        {
            const uint64_t product = i * j;
            if (isPalindrome(product) && product > largestProduct)
            {
                largestProduct = product;
            }
        }
    }

    return largestProduct;
}

int main()
{
    fprintf(stdout, "Largest palindrome made from the product of two 3-digit numbers is %lu\n", solve());
    return 0;
}
