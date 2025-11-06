#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

#define K (1001)

void Solve()
{
    uint64_t sum = 1;

    uint64_t last = 1;
    for (uint64_t i = 3; i <= K; i += 2)
    {
        uint64_t shift = i - 1;

        // uint64_t buttomRight = last        + shift; // last + shift
        // uint64_t buttomLeft  = buttomRight + shift; // last + shift + shift
        // uint64_t topLeft     = buttomLeft  + shift; // last + shift + shift + shift
        // uint64_t topRight    = topLeft     + shift; // last + shift + shift + shift + shift
        // -> last * 4 + shift * 10

        sum += (last * 4 + shift * 10);

        last += (shift * 4);
    }

    printf("%" PRIu64 "\n", sum);
}

int main()
{
    Solve();
    return 0;
}
