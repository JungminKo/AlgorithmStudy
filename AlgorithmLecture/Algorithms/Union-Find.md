
- by Friedman and Sachs, it was proved that there is no linear time algorithm for the union find problem.


## Quick-find 
- Running time
    - initialize : N
    - union : N 
    - find : 1
- Defect
    - union too expensive (N array accesses)
    - Trees are flat, but too expensive to keep them flat

## Quick-union
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
    - Modify quick-union to avoid tall trees
    - keep track of size of each tree (number of objects)
    - Balance by linking root of smaller tree to root of larger tree

    - Running time
        - Find : log(N)
        - Union : log(N)

2. path compression
