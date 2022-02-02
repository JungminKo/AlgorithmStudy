# Karatsuba Multiplication

```Python
def karastsuba(x : int , y : int):
    # First, compute a, b, c, d
    
    str_x = str(x)
    str_y = str(y)

    if len(str_x)!=len(str_y):
        print("wrong input! Make sure two input integers have same length ")
        return

    if len(str_x) % 2 !=0:
        print("wrong input! Make sure integers are 2*n length (not odd) ")
        return

    n = len(str_x)//2
    a = int(str_x[:n])
    b = int(str_x[n:])

    c = int(str_y[:n])
    d = int(str_y[n:])

    ''' 
    otherwise you can do this
    a = integer1 // 10**n
    b = integer1 % 10**n
    '''

    # step1: compute a*c
    ac = a*c
    # step2 : compute b*d
    bd = b*d
    # step3 : compute (a+b)(c+d)
    abcd = (a+b)*(c+d)
    # step4 : Gauss' Trick : compute ad+bc by computing abcd-ac-bd
    adbc = abcd-ac-bd
    # Final : compute multplication!
    xy = ac * 10**(2*n) + adbc * 10**n + bd
    print("final outcome :" , xy )
```
