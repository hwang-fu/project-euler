#include <stdio.h>
#include <stdint.h>

#define K (1001)

void Solve()
{
    uint64_t sum = 1;

    uint64_t last = 1;
    for (uint64_t i = 3; i <= K; i += 2)
    {
        uint64_t buttomRight = last        + (i - 1);
        uint64_t buttomLeft  = buttomRight + (i - 1);
        uint64_t topLeft     = buttomLeft  + (i - 1);
        uint64_t topRight    = topLeft     + (i - 1);

        sum += (buttomRight + buttomLeft + topLeft + topRight);

        last = topRight;
    }

    printf("%lu\n", sum);
}

int main()
{
    Solve();
    return 0;
}
