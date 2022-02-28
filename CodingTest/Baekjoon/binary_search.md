### 1654번 랜선 자르기(https://www.acmicpc.net/problem/1654)
```Python
def main():
    line_num, num = input().split()
    line_num = int(line_num)
    num = int(num)
    line_list = []
    for _ in range(line_num):
        line_list.append(int(input()))

    result = binary_search(0, max(line_list), line_list, num)
    print(result)


def binary_search(left, right, line_list, num):
    while (left <= right):
        mid = left + (right-left)//2
        if (right - left <= 1):
            if condition(line_list, num, right):
                return right
            return left
        
        if condition(line_list, num, mid):
            left = mid
        else:
            right = mid - 1
    return -1

def condition(line_list, num, mid):
    calculate = 0
    
    for line in line_list:
        calculate += line//mid

    if num <= calculate:
        return True

    return False

main()
```
