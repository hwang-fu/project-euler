// multiplicand a
// multiplier   b
// product      p
// len(a) + len(b) + len(p) = 9 and uses exactly the diigits 1..9

const isPandigital = (a: number, b: number, p: number): boolean => {
    const s = `${a}${b}${p}`;

    if (s.length !== 9) {
        return false;
    }

    if (s.includes("0")) {
        return false;
    }

    return s.split("").sort().join("") === "123456789";
};

(() => {
    const products = new Set<number>();

    // Case 1: 1-digit x 4-digit = 4-digit
    for (let a  = 1; a <= 9; a++) {
        for (let b = 1234; b <= 9876; b++) {
            const p = a * b;
            if (isPandigital(a, b, p)) {
                products.add(p);
            }
        }
    }

    // Case 2: 2-digit x 3-digit = 4-digit
    for (let a = 12; a <= 98; a++) {
        for (let b = 123; b <= 987; b++) {
            const p = a * b;
            if (isPandigital(a, b, p)) {
                products.add(p);
            }
        }
    }

    // Sum up.
    let sum = 0;
    for (const p of products) {
        sum += p;
    }
    console.log(sum);
})();

export {};
