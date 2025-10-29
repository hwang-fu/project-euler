N = 1000
sum = 0

for n in range(3, N):
    if n % 3 == 0 or n % 5 == 0:
        sum += n

print(sum)
