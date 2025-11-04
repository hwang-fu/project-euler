(() => {
    let a = 1n; // F(1)
    let b = 1n; // F(2)
    let n = 2;  // current index
    while (b.toString().length < 1000) {
        [a, b] = [b, a + b];
        n++;
    }
    console.log(n);
})();