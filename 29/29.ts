
// Just like `BigInt(base) ** BigInt(exp)` but faster.
const BigIntPower = (base: bigint, exp: number): bigint => {
    let ans = 1n;

    while (exp > 0) {
        if (exp % 2 !== 0) {
            ans *= base;
        }

        base *= base;
        exp   = Math.floor(exp / 2);
    }

    return ans;
};

const distinctPowers = (a: number = 100, b: number = 100): number => {
    if (a < 2 || b < 2) {
        throw new Error("a and b must be at least 2.");
    }

    const memo = new Set<bigint>();

    for (let i = 2; i <= a; i++) {
        for (let j = 2; j <= b; j++) {
            memo.add( BigIntPower(BigInt(i), j) );
        }
    }

    return memo.size;
};

(() => {
    console.log(
        distinctPowers(100, 100)
    );
})();

export {};
