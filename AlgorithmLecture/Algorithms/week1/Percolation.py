'''
https://coursera.cs.princeton.edu/algs4/assignments/percolation/specification.php

Python Code
'''
import sys
sys.path.append("./")
from AlgorithmLecture.Algorithms.week1.UnionFind.WeightedQuickUnion import WeightedQuickUnionUF

CONFIDENCE_95 = 1.96

# creates n-by-n grid, with all sites initially blocked
class Percolation:
    def __init__(self, n):
        if (n <= 0):
            raise ValueError
        
        self.n = n
        self.sites = [False] * (n * n)
        self.unionUF_topBottom = WeightedQuickUnionUF(n * n + 2)
        self.unionUF_top = WeightedQuickUnionUF(n * n + 1)
        self.OpenSiteNum = 0

        for i in range(n):
            self.unionUF_topBottom.union(n * n, i)
            self.unionUF_topBottom.union(n * n + 1, n * n - i - 1)
            self.unionUF_top.union(n * n, i)

    # opens the site (row, col) if it is not open already
    def open(self, row, col):
        if (row <= 0 or col <= 0 or row > self.n or col > self.n):
            raise ValueError

        cur = self.getIndex(row, col)

        if (not self.isOpen(row, col)):
            self.sites[cur] = True
            self.OpenSiteNum +=1

        if (row > 1 and self.isOpen(row - 1, col)):
            self.unionUF_topBottom.union(cur, cur - self.n)
            self.unionUF_top.union(cur, cur - self.n)

        if (row < self.n and self.isOpen(row + 1, col)):
            self.unionUF_topBottom.union(cur, cur + self.n)
            self.unionUF_top.union(cur, cur + self.n)

        if (col > 1 and self.isOpen(row, col - 1)):
            self.unionUF_topBottom.union(cur, cur - 1)
            self.unionUF_top.union(cur, cur - 1)

        if (col < self.n  and self.isOpen(row, col + 1)):
            self.unionUF_topBottom.union(cur, cur + 1)
            self.unionUF_top.union(cur, cur + 1)
    
    # is the site (row, col) open?
    def isOpen(self, row, col):
        if (row <= 0 or col <= 0 or row > self.n or col > self.n):
            raise ValueError
        
        return self.sites[self.getIndex(row, col)]

    # is the site (row, col) full?
    def isFull(self, row, col):
        if (row <= 0 or col <= 0 or row > self.n or col > self.n):
            raise ValueError
        return (self.isOpen(row, col) and 
                self.unionUF_top.connected(self.n * self.n, self.getIndex(row, col)))

    # returns the number of open sites
    def numberOfOpenSites(self):
        return self.OpenSiteNum

    # does the system percolate?
    def percolates(self):
        if self.n == 1:
            return self.isOpen(1, 1)

        return self.unionUF_topBottom.connected(self.n * self.n, self.n * self.n + 1)

    def getIndex(self, row, col):
        return (row - 1) * self.n + (col - 1)


def main():
    percolation = Percolation(3)

    percolation.open(1, 3)
    percolation.open(2, 3)
    percolation.open(3, 3)
    percolation.open(2, 1)

    assert (not percolation.isFull(3, 1))
    assert (percolation.percolates())

if __name__ == "__main__":
    main()
