// Think of long division.
// If you do long division of (1 / d):
// - you keep multiplying the remainder by 10
// - use the remainder to divide d
// - every new remainder produces one digit of the decimal in the quotient.

// Examples:

// d = 3
//  1. 1/3  = 0 ... 1
//  2. 10/3 = 3 ... 1
//  3. 10/3 = 3 ... 1
//  4. 10/3 = 3 ... 1
//  ...
// 1/d = 0.(3)

// d = 4
//  1. 1/4  = 0 ... 1
//  2. 10/4 = 2 ... 2
//  3. 20/4 = 5 ... 0
// 1/d = 0.25

// d = 5
//  1. 1/5  = 0 ... 1
//  2. 10/5 = 2 ... 0
// 1/d = 0.2

// d = 6
//  1/6  = 0 ... 1
//  10/6 = 1 ... 4
//  40/6 = 6 ... 4
//  40/6 = 6 ... 4
//  40/6 = 6 ... 4
//  ...
// 1/d = 0.1(6)

// d = 7
//  1/7  = 0 ... 1
//
//  10/7 = 1 ... 3
//  30/7 = 4 ... 2
//  20/7 = 2 ... 6
//  60/7 = 8 ... 4
//  40/7 = 5 ... 5
//  50/7 = 7 ... 1
//
//  10/7 = 1 ... 3
//  30/7 = 4 ... 2
//  20/7 = 2 ... 6
//  60/7 = 8 ... 4
//  40/7 = 5 ... 5
//  50/7 = 7 ... 1
//
//  10/7 = 1 ... 3
//  30/7 = 4 ... 2
//  20/7 = 2 ... 6
//  60/7 = 8 ... 4
//  40/7 = 5 ... 5
//  50/7 = 7 ... 1
//  ...
// 1/d = 0.(142857)

const ReciprocalCycles = (d: number) => {
    const Seen = Array(d).fill(-1);

    let rem = 1 % d;
    let step = 0;
    while (rem !== 0) {
        if (Seen[rem] !== -1) {
            return step - Seen[rem];
        }
        Seen[rem] = step;
        rem = (rem * 10) % d;
        step += 1;
    }

    // terminating decimal, no repetitions, return 0.
    return 0;
};

(() => {
    const K = 1000;
    let d   = 0;
    let len = 0;

    for (let i = 2; i < K; i++) {
        const n = ReciprocalCycles(i);
        if (n > len) {
            len = n;
            d = i;
        }
    }

    console.log(d);
})();export {};
