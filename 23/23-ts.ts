const LIMIT = 28123;

const Abundants: number[] = [];
const AbundantsSet = new Set<number>();

const isAbundant = (n: number): boolean => {
    if (n < 12) {
        return false;
    }

    // `1` is always a proper divisor for `n > 1`.
    let sum = 1;
    const r = Math.floor(Math.sqrt(n));
    for (let divisor = 2; divisor <= r; divisor++) {
        if (n % divisor != 0) {
            continue;
        }

        sum += divisor;

        // If `divisor` divides `n`, then `n/divisor` should also divide `n`.
        // And one of the two is ≤ √n and the other is ≥ √n.
        // Therefore, we don't have to iterate over n/2, iterate over √n is sufficient.
        const other = n / divisor;
        if (other !== divisor) {
            sum += other;
        }

        if (sum > n) {
            return true;
        }
    }

    return sum > n;
};

const qualify = (n: number) => {
    for (const abundant of Abundants) {
        if (abundant >= n) {
            break;
        }

        if (AbundantsSet.has(n - abundant)) {
            return true;
        }
    }
    return false;
};

(function Solve() {
    let total = 0;

    for (let i = 1; i <= LIMIT; i++) {
        if (!isAbundant(i)) {
            continue;
        }
        Abundants.push(i);
        AbundantsSet.add(i);
    }

    for (let i = 1; i <= LIMIT; i++) {
        if (!qualify(i)) {
            total += i;
        }
    }

    console.log(total);
})();export {};
