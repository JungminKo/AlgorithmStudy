### [124 나라의 숫자](https://programmers.co.kr/learn/courses/30/lessons/12899)
- 191202
```Python
def solution(n):
    answer =''
    start = 0
    end = 3
    base = 3
    for i in range(20): # n이 500,000,000이하의 자연수이므로
        if (n<=end):
            temp = n-start-1
            for j in range(i):
                num = temp%3
                if num==2:
                    num=4
                else:
                    num +=1
                answer = str(num)+answer
                temp = int(temp/3)
            if temp==2:
                temp=4
            else:
                temp+=1
            answer = str(temp)+answer
            break
        
        base = base*3
        start = end
        end = end + base
        
    return answer
```
