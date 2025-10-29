const N = 1000;

let sum = 0;

for (let n = 1; n < N; n++)
{
    if (n % 3 === 0 || n % 5 === 0) sum += n;
}

console.log(sum);
