'''
https://coursera.cs.princeton.edu/algs4/assignments/percolation/specification.php

Python Code
'''
import sys
sys.path.append("./")

from AlgorithmLecture.Algorithms.week1.Percolation import Percolation
import statistics
import random

CONFIDENCE_95 = 1.96

class PercolationStats:
    def __init__(self, n, trials):
        if (n<=0 or trials<=0):
            raise ValueError

        self.results = []
        for _ in range(trials):
            percolation = Percolation(n)
            while (not percolation.percolates()):
                randomRow = random.randint(1, n)
                randomCol = random.randint(1, n)
                
                if (not percolation.isOpen(randomRow, randomCol)):
                    percolation.open(randomRow, randomCol)

            self.results.append(percolation.numberOfOpenSites()/(n*n))
            
    # sample mean of percolation threshold
    def mean(self):
        return statistics.mean(self.results)

    # sample standard deviation of percolation threshold
    def stddev(self):
        return statistics.stdev(self.results)

    # low endpoint of 95% confidence interval
    def confidenceLo(self):
        return self.mean() - CONFIDENCE_95 * self.stddev() / (len(self.results)**(1/2))

    # high endpoint of 95% confidence interval
    def confidenceHi(self):
        return self.mean() + CONFIDENCE_95 * self.stddev() / (len(self.results)**(1/2))


def main():
    n = int(input())
    trials = int(input())
    percolationStats = PercolationStats(n, trials)

    print("mean = ", percolationStats.mean())
    print("stddev = ", percolationStats.stddev())
    print("95% confidence interval = [", percolationStats.confidenceLo(), ", ", percolationStats.confidenceHi(), "]")

if __name__ == "__main__":
    main()
