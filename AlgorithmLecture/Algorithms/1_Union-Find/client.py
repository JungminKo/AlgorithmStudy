from QuickFind import QuickFindUF

class UnionFind():
    def __init__(self, n):
        self.n = n

    def connected(self, p, q):
        ## 추후 정의
        return False
    
    def union(self, p, q):
        ## 추후 정의
        p = q = 1

def main():
    n = int(input())
    uf = QuickFindUF(n)
    while (True) :
        input_string = input()
        if len(input_string) == 0:
            break
        p, q = input_string.split()
        p = int(p)
        q = int(q)

        if (~uf.connected(p, q)):
            uf.union(p, q)
            print(str(p) + " " + str(q))
    print(uf.connection)
main()