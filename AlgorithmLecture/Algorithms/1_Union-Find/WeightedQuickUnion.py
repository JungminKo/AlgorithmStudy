'''
UnionFind Algorithm

initialize : N
union : log(N) 
find : log(N)
'''

class WeightedQuickUnionUF():
    def __init__(self, n):
        self.id = list(range(n))
        self.size = [1]*n

    def _root(self, i):
        while (i != self.id[i]):
            i = self.id[i]
        return i

    def connected(self, p, q):
        return self._root(p) == self._root(q)
    
    def union(self, p, q):
        i = self._root(p)
        j = self._root(q)
        if (i == j):
            return
        
        ##Check!
        if (self.size[i] < self.size[j]):
            self.id[i] = j
            self.size[j] += self.size[i]
        else:
            self.id[j] = i
            self.size[i] += self.size[j]
