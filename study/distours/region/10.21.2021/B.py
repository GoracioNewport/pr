n, a, b, w, h = map(int, input().split())
l = 0
r = 2000000000000000000

def cnt(a, b, w, h):
    return ((w // a) * (h // b));

while(l + 1 < r):
    m = (l + r) // 2
    if (max(cnt(a + (2 * m), b + (2 * m), w, h), cnt(b + (2 * m), a + (2 * m), w, h)) >= n): l = m
    else: r = m

print(l)