const N: u64 = 1000;

fn main() {
    let mut sum: u64 = 0;

    for n in 3..N {
        if n % 3 == 0 || n % 5 == 0 {
            sum += n;
        }
    }

    println!("{}", sum);
}
