// For each first digit, there are 9! = 362_880 possibilities.
// Since 1_000_000 lies in the "2" range, the first digit is 2.

const ONE_MILLION = 1_000_000;

// Return the k-th (1-indexed) lexicographic permutation of `arr`.
const kthPermutation = (arr: number[], k: number) => {
    const pool = arr.slice().sort((a, b) => a - b);
    const len  = pool.length;

    // Helper: factorial
    const factorial = (x: number) => {
        let f = 1;
        for (let i = 2; i <= x; i++) f *= i;
        return f;
    };

    // We use zero-based index for arithmetic
    let rem = k - 1;
    
    let blockSize = factorial(len - 1);

    const result: number[] = [];

    for (let remainingDigitsCount = len; remainingDigitsCount > 0; remainingDigitsCount--) {
        const idx = (remainingDigitsCount === 1) ? 0 : Math.floor(rem / blockSize);
        result.push(pool.splice(idx, 1)[0]);
        if (remainingDigitsCount > 1) {
            rem %= blockSize;
            blockSize /= (remainingDigitsCount - 1);
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