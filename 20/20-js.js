
const K = 100;

const Cache = Array(K + 1).fill(0n);

const Factorial = (n) => {
    if (Cache[n] !== 0n)
    {
        return Cache[n];
    }

    Cache[n] = BigInt(n) * Factorial(n - 1);
    return Cache[n];
}

const Solve = () => {
    let n = Factorial(K);
    let sum = 0n;

    while (n)
    {
        sum += (n % 10n);
        n /= 10n;
    }

    console.log(sum)
}

function main() {
    Cache[0] = BigInt(1);
    Cache[1] = BigInt(1);
    Cache[2] = BigInt(2);
    Solve();
}

main();