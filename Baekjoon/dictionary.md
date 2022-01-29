### 10816번 숫자 카드2(https://www.acmicpc.net/problem/10816)
```Python
from collections import defaultdict

n = int(input())
card_list = input().split()
count_dict = defaultdict(int)
for i in range(n):
    count_dict[card_list[i]] +=1

m = int(input())
num_list = input().split()
for i in range(m):
    print(count_dict[num_list[i]], end=" ")
```
