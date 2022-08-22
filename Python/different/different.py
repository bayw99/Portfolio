import sys
from sys import stdin

def answer(n1, n2):
    return abs(n1 - n2)

def test():
    assert answer(10, 20) == 10
    assert answer(100023451, 10029372) == 89994079
    assert answer(100201, 365) == 99836
    print('All test cases passed...')

def solve():
    for line in sys.stdin:
        n1, n2 = line.split()
        n1 = int(n1)
        n2 = int(n2)
        print(answer(n1, n2))


if __name__ == "__main__":
    if len(sys.argv) > 1 and sys.argv[1] == 'test':
        test()
    else:
        solve()