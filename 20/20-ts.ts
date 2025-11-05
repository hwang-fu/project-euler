const K: bigint = 100n;

const Memo: bigint[] = new Array(Number(K) + 1).fill(0n);

function Factorial(n: bigint): bigint {
    if (n === 0n) return 1n;

    if (Memo[Number(n)] != 0n)
    {
        return Memo[Number(n)];
    }

    Memo[Number(n)] = n * Factorial(n - 1n);
    return Memo[Number(n)];
};

function main() {
    let result = Factorial(K);
    let sum = 0n;

    while (result)
    {
        sum += (result % 10n);
        result /= 10n;
    }

    console.log(sum);
}

main();export {};
