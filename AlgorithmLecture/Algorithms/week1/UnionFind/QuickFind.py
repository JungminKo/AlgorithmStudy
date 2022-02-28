'''
UnionFind Algorithm

initialize : N
union : N 
find : 1
'''

class QuickFindUF():
    def __init__(self, n):
        self.id = list(range(n))

    def connected(self, p, q):
        return self.id[p] == self.id[q]
    
    def union(self, p, q):
        pid = self.id[p]
        qid = self.id[q]

        for i in range(len(self.id)):
            if (self.id[i] == pid):
                self.id[i] = qid
