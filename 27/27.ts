const Cache = new Map<number, boolean>();

const isPrime = (n: number) => {
    if (Cache.has(n)) {
        return Cache.get(n);
    }

    if (n % 2 === 0) {
        Cache.set(n, false);
        return Cache.get(n);
    }

    for (let i = 3; i * i <= n; i += 2) {
        if (n % i === 0) {
            Cache.set(n, false);
            return Cache.get(n);
        }
    }

    Cache.set(n, true);
    return Cache.get(n);
};

(() => {
    Cache.set(0, false);
    Cache.set(1, false);
    Cache.set(2, true);

    const A = 1000;
    const B = 1000;

    let bestN = 0;
    let ab = 0;

    for (let b = 3; b <= B; b += 2) {
        if (!isPrime(b)) {
            continue;
        }

        for (let a = -999; a < A; a += 2) {
            let n = 0;
            for (;; ++n) {
                const fn = n * n + a * n + b;
                // For some (a, b), f(1) = 1 + a + b can be negative, sadly in our implementation isPrime treats a negative b as prime.
                if (fn < 2 || !isPrime(fn)) break;
            }

            if (n > bestN) {
                bestN = n;
                ab = a * b;
            }
        }
    }

    console.log(ab);
})();

export {};
