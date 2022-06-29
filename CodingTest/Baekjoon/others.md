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

### 15501번 부당한 퍼즐(https://www.acmicpc.net/problem/15501)
```Python
def is_correct(num, origin_list, result_list):
    start = origin_list[0]

    # 동일한 시작지점 찾기
    for i in range(num):
        if result_list[i] == start:
            break

    if origin_list[:num-i] != result_list[i:]:
        return False

    if origin_list[num-i:] != result_list[:i]:
        return False

    return True
    
def print_result():
    num = int(input())
    origin_list = list(map(int, input().split(" ")))
    result_list = list(map(int, input().split(" ")))

    if is_correct(num, origin_list, result_list):
        print("good puzzle")
        return None
    
    reverse_list = origin_list[::-1]

    if is_correct(num, reverse_list, result_list):
        print("good puzzle")
        return None

    print("bad puzzle")
    return None

print_result()
```
