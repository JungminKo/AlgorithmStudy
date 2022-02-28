### [신규 아이디 추천](https://programmers.co.kr/learn/courses/30/lessons/72410?language=python3)
- 210327
```Python
def solution(new_id):
    answer = new_id.lower()
    answer = re.sub(r"[^a-z0-9-_\.]", "", answer)
    answer = re.sub(r"\.+", ".", answer)
    answer = re.sub(r"^\.", "", answer)
    answer = re.sub(r"\.$", "", answer)
    if len(answer)==0:
        answer = "a"
    elif len(answer)>=16:
        answer = answer[:15]
        answer = re.sub(r"\.$", "", answer)
    while(len(answer)<3):
        answer = answer + answer[-1]
    return answer
```
