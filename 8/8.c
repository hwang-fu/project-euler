#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

/// Goal:
/// Given a long string of digits and a window size k (e.g., 13),
/// find the maximum product of any k consecutive digits.

/// Idea:
/// Any window containing a 0 has product 0. So the string naturally splits into zero-free segments.
/// In a zero-free segments, use the sliding window and update the product:
///     when you slide right by 1
///         remove the left digit `a` and add the right digit `b`
///         new product = old_product / a * b
///         (if division worries you, try re-compute.)
/// In a segment shorter than k, just ignore it.

#ifndef K
#define K (13)
#endif // K

#ifndef ASCII2DIGIT
#define ASCII2DIGIT(c) ((c) - '0')
#endif // ASCII2DIGIT

char digits[] = "7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450";

uint64_t solve()
{
    uint64_t count = 0;
    char ** segments = NULL;

    char * seg_begin = digits;
    char * seg_end   = digits;
    while (*seg_end != '\0')
    {
        if (*seg_end == '0')
        {
            uint64_t len = ((uint64_t) seg_end - (uint64_t) seg_begin);
            if (len != 0)
            {
                segments = realloc(segments, ++count * sizeof(char*));
                if (!segments)
                {
                    fprintf(stderr, "Memory allocation failure.\n");
                    exit(EXIT_FAILURE);
                }
                segments[count-1] = strndup(seg_begin, len);
            }
            seg_end++;
            seg_begin = seg_end;
        }
        else
        {
            seg_end++;
        }
    }

    uint64_t product = 0;

    for (uint64_t i = 0; i < count; i++)
    {
        char * segment = segments[i];
        uint64_t len = strlen(segment);
        if (len >= K)
        {
            uint64_t window_size = len - K;
            for (uint64_t w = 0; w <= window_size; w++)
            {
                uint64_t temp = 1;
                for (uint64_t k = 0; k < K; k++)
                {
                    temp *= ASCII2DIGIT(segment[w + k]);
                }
                if (temp > product)
                {
                    product = temp;
                }
            }
        }
        free(segment);
    }
    free(segments);

    return product;
}

int main()
{
    fprintf(stdout, "%lu\n", solve());
    return 0;
}
