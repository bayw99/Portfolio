import sys

def findAvg(avg, grades, n):
    avg = (sum(grades))/n
    return avg

def aboveAvg(avg, grades, n, above):
    for grade in grades:
        if grade > avg:
            above += 1
    return above

def answer(above, n):
    return (round(above/n*100, 3))

def solve():
    c = int(input())
    if c < 50:
        for _ in range(c):
            grades = tuple(map(int, input().split()))
            n = grades[0]
            grades = grades[1:]
            avg = 0
            avg = findAvg(avg, grades, n)
            above = 0
            above = aboveAvg(avg, grades, n, above)
            print("%.3f%s" % (round(above / n * 100, 3), '%'))

def test():
    assert answer(2, 4) == 50.0
    assert answer(5, 8) == 62.5
    assert answer(2, 6) == 33.3
    print('All test cases passed...')

if __name__ == "__main__":
    if len(sys.argv) > 1 and sys.argv[1] == 'test':
        test()
    else:
        solve()