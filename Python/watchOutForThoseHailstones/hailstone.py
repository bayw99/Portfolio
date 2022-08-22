import sys

s=0
def hailstone(n):
    global s
    s+=n
    assert n > 0
    if n == 1:
        return 1
    elif n % 2 == 0:
        hailstone(n // 2)
    else:
        hailstone(3 * n + 1)
    return s

def solve(): 
    ans=0
    ans = int(hailstone(int(input())))
    print(ans)

def test():
    assert hailstone(10) == 46
    assert hailstone(2) == 49
    assert hailstone(4) == 56
    print('All test cases passed...')

if __name__ == "__main__":
    if len(sys.argv) > 1 and sys.argv[1] == 'test':
        test()
    else:
        solve()