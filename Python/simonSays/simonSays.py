import sys

def answer(line):
    if line.startswith("simon says"):
        simon, answer = line.split("simon says ")
        return answer

def solve():    
    n = int(input())
    for i in range(n):
        line = input()
        ans = answer(line)
        if ans == None:
            print("")
        else:
            print(ans)

def test():
    assert answer("simon says stand") == "stand"
    assert answer("nothing to do here") == ""
    assert answer("simon says eat food") == "eat food"
    print('All test cases passed...')

if __name__ == "__main__":
    if len(sys.argv) > 1 and sys.argv[1] == 'test':
        test()
    else:
        solve()