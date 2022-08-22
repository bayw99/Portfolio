import sys

character = [" ", "!", "", "#", "$", "%",
             "&", "'", "(", ")", "*", "+",
             ",", "-", ".", "/", "0", "1", 
             "2", "3", "4", "5", "6", "7", 
             "8", "9", ":", ";", "<", "=", 
             ">", "?", "@", "A", "B", "C", 
             "D", "E", "F", "G", "H", "I", 
             "J", "K", "L", "M", "N", "O", 
             "P", "Q", "R", "S", "T", "U", 
             "V", "W", "X", "Y", "Z", "[", 
             "\\", "]", "^", "_", "`", "a", 
             "b", "c", "d", "e", "f", "g", 
             "h", "i", "j", "k", "l", "m", 
             "n", "o", "p", "q", "r", "s", 
             "t", "u", "v", "w", "x", "y", 
             "z", "{", "|", "}", "~"]
value = [0, 9, 6, 24, 29, 22,
         24, 3, 12, 12, 17, 13,
         7, 7, 4, 10, 22, 19,
         22, 23, 21, 27, 26, 16,
         23, 26, 8, 11, 10, 14,
         10, 15, 32, 24, 29, 20,
         26, 26, 20, 25, 25, 18,
         18, 21, 16, 28, 25, 26,
         23, 31, 28, 25, 16, 23,
         19, 26, 18, 14, 22, 18,
         10, 18, 7, 8, 3, 23,
         25, 17, 25, 23, 18, 30,
         21, 15, 20, 21, 16, 22,
         18, 20, 25, 25, 13, 21,
         17, 17, 13, 19, 13, 24,
         19, 18, 12, 18, 9]

def answer(cost, line):
    for ch in line:
            i=0
            if ch == '\n':
                break
            else:
                i=character.index(ch)
                cost += value[i]
    return cost

def test():
    cost=0
    assert(answer(cost, "this is a line") == 205)
    assert(answer(cost, "WOWWW") == 130)
    assert(answer(cost, "oh heck yah") == 191)

def solve():
    for line in sys.stdin:
        cost=0
        
        print(answer(cost, line))


if __name__ == '__main__':
    if len(sys.argv) > 1 and sys.argv[1] == 'test':
        test()
    else:
        solve()