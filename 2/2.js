const N = 4000000;

function solve() {
    let a = 1;          // first Fibonacci number
    let b = 2;          // second Fibonacci number
    let sum = 0;

    while (a <= N) {
        if (a % 2 === 0) {
            sum += a;
        }

        const next = a + b;
        a = b;
        b = next;
    }

    return sum;
}

console.log(solve());

