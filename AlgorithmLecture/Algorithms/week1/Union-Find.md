
- by Friedman and Sachs, it was proved that there is **no linear time algorithm** for the union find problem.


## Quick-find 
[code](https://github.com/JungminKo/AlgorithmStudy/blob/master/AlgorithmLecture/Algorithms/week1/UnionFind/QuickFind.py)
- Running time
    - initialize : N
    - union : N 
    - find : 1
- Defect
    - union too expensive (N array accesses)
    - Trees are flat, but too expensive to keep them flat

## Quick-union
[code](https://github.com/JungminKo/AlgorithmStudy/blob/master/AlgorithmLecture/Algorithms/week1/UnionFind/QuickUnion.py)
- Running time
    - initialize : N
    - union : N 
    - find : N
- Defect
    - Trees can get tall
    - Find too expensive (could be N array accesses)

### Improvement 
1. Weighting
- Weighted quick-Union
    - [code](https://github.com/JungminKo/AlgorithmStudy/blob/master/AlgorithmLecture/Algorithms/week1/UnionFind/WeightedQuickUnion.py)
    - Modify quick-union to avoid tall trees
    - keep track of size of each tree (number of objects)
    - Balance by linking root of smaller tree to root of larger tree

    - Running time
        - Find : log(N)
        - Union : log(N)

2. path compression
- path compression union
    - [code](https://github.com/JungminKo/AlgorithmStudy/blob/master/AlgorithmLecture/Algorithms/week1/UnionFind/PathCompressionQuickUnion.py)  
