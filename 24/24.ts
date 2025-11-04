// For each first digit, there are 9! = 362_880 possibilities.
// Since 1_000_000 lies in the "2" range, the first digit is 2.

const ONE_MILLION = 1_000_000;

// Return the k-th (1-indexed) lexicographic permutation of `arr`.
const kthPermutation = (arr: number[], k: number) => {

    // Since we work on a sorted copy so we start with the smallest.
    const pool = arr.slice().sort((a, b) => a - b);
    const len  = pool.length;

    // Simple factorial helper.
    const factorial = (x: number) => {
        let f = 1;
        for (let i = 2; i <= x; i++) f *= i;
        return f;
    };

    // We convert `k` to zero-based for math. 1st -> 0, 2nd -> 1, ...
    let kZeroBased = k - 1;

    // With n remaining digits, there are (n-1)! permutations per choice of the next digit.
    let permutationPerLeadingDigit = factorial(len - 1);

    const result: number[] = [];

    // We will choose one digit at a time, from left to right (since it is sorted).
    for (let remaining = len; remaining > 0; remaining--) {
        // Which block are we in? 
        // Each block has the same next digit and each block has (remaing-1)! permutations.
        // 0 - first smallest digit
        // 1 - second smallest digit
        // 2 - ...
        const idx = (remaining === 1) ? 
            0 
            : Math.floor(kZeroBased / permutationPerLeadingDigit);

        // Take that digit out of the `pool`.
        result.push(pool[idx]);
        pool.splice(idx, 1);

        // Move inside the chosen block and shrink block.
        if (remaining > 1) {
            // Position within the chosen block.
            kZeroBased %= permutationPerLeadingDigit;
            // now (remaining-2)!
            permutationPerLeadingDigit /= (remaining - 1);
        }
    }

    return result.join('');
};

(function solve() {
    console.log(kthPermutation([0, 1, 2, 3, 4, 5, 6, 7, 8, 9], ONE_MILLION));
})();

// Tiny sanity check: permutations of [0,1,2] in order
// k=1..6 => 012, 021, 102, 120, 201, 210
// for (let k = 1; k <= 6; k++) {
//  console.log(k, kthPermutation([0,1,2], k));
// }