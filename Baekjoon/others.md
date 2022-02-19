### 1004번 어린왕자(https://www.acmicpc.net/problem/1004)
```Python
from math import sqrt

def distance_check(x1, y1, x2, y2, r):
    return sqrt((x1-x2)**2 + (y1-y2)**2) < r

num = int(input())

for _ in range(num):
    sx, sy, ex, ey = map(int, input().split(" "))
    circle_num = int(input())

    count = 0
    for _ in range(circle_num):
        c1, c2, r = map(int, (input().split(" ")))
        if distance_check(sx, sy, c1, c2, r) ^ distance_check(ex, ey, c1, c2, r):
            count +=1
    print(count)
```

