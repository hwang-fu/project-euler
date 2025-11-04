
const UPPER_LIMIT = 28123;

const AbundantNumbers = [];

const isAbundantNumber = (n) => {
    if (n < 12) return false;
    let sum = 0;
    for (let i = 1; i <= n / 2; i++) {
        if (n % i == 0) sum += i;
    }
    return sum > n;
}

const isSumOfTwoAbundantNumbers = (n) => {
    for (const abundantNumber of AbundantNumbers) {
        if (n <= abundantNumber) break;
        const diff = n - abundantNumber;
        if (AbundantNumbers.includes(diff)) return true;
    }
    return false;
}

function main() {
    let sum = 0;
    for (let i = 1; i <= UPPER_LIMIT; i++) {
        if (isAbundantNumber(i)) AbundantNumbers.push(i);
    }
    for (let i = 1; i <= UPPER_LIMIT; i++) {
        if (!isSumOfTwoAbundantNumbers(i)) sum += i;
    }
    console.log(sum);
}

main();