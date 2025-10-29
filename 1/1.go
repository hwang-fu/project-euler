package main

import "fmt"

const N = 1000

func main() {
	sum := 0
	for n := 1; n < N; n++ {
		if n % 3 == 0 || n % 5 == 0 {
			sum += n
		}
	}
	fmt.Println(sum);
}
