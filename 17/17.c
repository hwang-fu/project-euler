#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define NUMBERS     \
	X(Zero)         \
	X(One)          \
	X(Two)          \
	X(Three)        \
	X(Four)         \
	X(Five)         \
	X(Six)          \
	X(Seven)        \
	X(Eight)        \
	X(Nine)         \
	X(Ten)          \
	X(Eleven)       \
	X(Twelve)       \
    X(Thirteen)     \
    X(Fourteen)     \
    X(Fifteen)      \
    X(Sixteen)      \
    X(Seventeen)    \
    X(Eighteen)     \
    X(Nineteen)     \
    X(Twenty)       \
    X(Thirty)       \
    X(Forty)        \
    X(Fifty)        \
    X(Sixty)        \
    X(Seventy)      \
    X(Eighty)       \
    X(Ninety)       \
    X(Hundred)      \
    X(Thousand)

typedef enum Numbers
{
#ifndef X
#define X(x) x,
    NUMBERS
#undef X
#endif // X
} Numbers;

const char * Words[] = {
#ifndef X
#define X(x) #x,
    NUMBERS
#undef X
#endif // X
};

uint64_t CountLetters(uint64_t n)
{
    if (n == 0)
    {
        return 0;
    }

    if (n <= 20)
    {
        printf("%s", Words[n]);
        return strlen(Words[n]);
    }

    if (n < 100)
    {
        uint64_t fst = (n % 10);
        uint64_t snd = (n / 10);

        if (fst == 0)
        {
            printf("%s", Words[snd - 2 + Twenty]);
            return strlen(Words[snd - 2 + Twenty]);
        }
        else
        {
            printf("%s-", Words[snd - 2 + Twenty]);
            return strlen(Words[snd - 2 + Twenty]) + CountLetters(fst);
        }
    }

    if (n < 1000)
    {
        uint64_t fst = (n % 100);
        uint64_t snd = n / 100;
        uint64_t sndCount = CountLetters(snd);
        if (fst == 0)
        {
            printf(" Hundred");
            return sndCount + strlen("Hundred");
        }
        else
        {
            printf(" Hundred And ");
            return sndCount + strlen("Hundred") + strlen("And") + CountLetters(fst);
        }
    }

    printf("One Thousand");

    return strlen("OneThousand");
}

void Solve()
{
    uint64_t count = 0;

    for (uint64_t i = 1; i <= 1000; i++)
    {
        count += CountLetters(i);
        printf("\n");
    }

    fprintf(stdout, "%lu\n", count);
}

int main()
{
    Solve();
    // printf("\n%lu\n", CountLetters(342));
    // printf("\n%lu\n", CountLetters(115));
    return 0;
}
