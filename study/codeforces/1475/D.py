f = [1]
for i in range(2000):
  f.append(f[i] * (i + 1))

# print(f[:10])


t = int(input())
for _ in range(t):
  n, k = map(int, input().split())
  a = [int(i) for i in input().split()]
  a.sort(reverse = True)
  k -= 1
  # print(a)
  t = a[k]
  b = 0
  for i in range(n):
    if (a[i] <= t):
      b = i
      break
  num = 0
  for i in a: 
    if (i == t): num += 1
  N = num
  K = (k - b + 1)
  print(k, b)
  print(N, K)
  # num1 = 1
  # for i in range(K, N + 1): num1 *= i
  # ans = (num1 / f[N - K]) % 1000000007 
  # print(num1, f[N - K])
  # print(int(ans))
  print((int(f[N] / (f[K] * f[N - K])) % 1000000007)) 
