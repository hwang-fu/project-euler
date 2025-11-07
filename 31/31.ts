const K = 200;

// Reversed order also works.
const Coins = [200, 100, 50, 20, 10, 5, 2, 1];

const CoinSums = (amount: number, startIdx: number) => {
    if (amount < 0) {
        return 0;
    }

    if (amount === 0) {
        return 1;
    }

    let sum = 0;

    for (let i = startIdx; i < Coins.length; i++) {
        sum += CoinSums(amount - Coins[i], i);
    }

    return sum;
};

(() => {
    const combinations = CoinSums(K, 0);
    console.log(combinations);
})();

export {};
