#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

bool IsLeapYear(uint16_t year)
{
    if (year % 100 == 0)
    {
        return year % 400 == 0;
    }
    else
    {
        return year % 4 == 0;
    }
}

typedef enum Month
{
    Jan = 0,
    Feb,
    Mar,
    Apr,
    May,
    Jun,
    Jul,
    Aug,
    Sep,
    Oct,
    Nov,
    Dec,
} Month;

uint16_t DaysInMonth(Month month)
{
    switch (month)
    {
        case Jan:
		{
            return 31;
		};

        case Feb:
		{
            return 28; // normally 28, leap year 29, the +1 will be handled else-where.
		};

        case Mar:
		{
            return 31;
		};

        case Apr:
		{
            return 30;
		};

        case May:
		{
            return 31;
		};

        case Jun:
		{
            return 30;
		};

        case Jul:
		{
            return 31;
		};

        case Aug:
		{
            return 31;
		};

        case Sep:
		{
            return 30;
		};

        case Oct:
		{
            return 31;
		};

        case Nov:
		{
            return 30;
		};

        case Dec:
		{
            return 31;
		};

        default:
        {
            fprintf(stderr, "Unknown month: %d\n", month);
        } break;
    }
}

typedef enum Week
{
    Sun = 0,
    Mon,
    Tue,
    Wed,
    Thu,
    Fri,
    Sat,
} Week;


// 1 Jan 1900 was a Monday, so 7 Jan 1900 is a Sunday.
// +7 every seven days is another Sunday.
// Idea: Track the first day of each month.
// From 1 Jan 1901 to 31 Dec 2000, how many first days of a month fell on a Sunday?

void Solve()
{
    uint64_t count = 0;

    Week FirstDayOfEachMonth = Mon;
    for (uint16_t year = 1900; year <= 2000; year++)
    {
        for (Month month = Jan; month <= Dec; month++)
        {
            uint16_t days = DaysInMonth(month);
            if (IsLeapYear(year) && month == Feb)
            {
                days += 1;
            }

            if (year > 1900 && FirstDayOfEachMonth == Sun)
            {
                count += 1;
            }
            FirstDayOfEachMonth = (FirstDayOfEachMonth + (days % 7)) % 7;
        }
    }

    printf("%lu\n", count);
}

int main()
{
    Solve();
    return 0;
}
