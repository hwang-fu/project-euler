
const FifthPowerSum = (n: number) => {
    let sum = 0;
    while (n) {
        sum += Math.pow(n % 10, 5);
        n = Math.floor(n / 10);
    }
    return sum;
};

(() => {
    let sum = 0;
    for (let i = 2; i <= 354294; i++) {
        if (i === FifthPowerSum(i)) {
            sum += i;
        }
    }
    console.log(sum);
})();

export {};
