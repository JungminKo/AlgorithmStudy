from QuickFind import QuickFindUF

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

if __name__ == "__main__":
    main()