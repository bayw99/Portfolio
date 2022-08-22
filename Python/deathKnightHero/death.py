import sys

def answer(m, k):
    if "CD" not in m:
        k += 1
    return k

def test():
    assert answer("DCOOO",0) == 1
    assert answer("DODOCD",1) == 1
    assert answer("COD",1) == 2
    print('All test cases passed...')

def solve():

    n = int(input())
    k=0
    for i in range(n):
        m = input()
        k = answer(m,k)
    print(k)

if __name__ == "__main__":
    if len(sys.argv) > 1 and sys.argv[1] == 'test':
        test()
    else:
        solve()
