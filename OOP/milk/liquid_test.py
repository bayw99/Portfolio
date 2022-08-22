import unittest
from liquid import Liquid
from water import Water
from milk import Milk
from typing import List,cast

class LiquidTest(unittest.TestCase):

    def testLiquidGo(self):
        milk = Milk()
        self.assertEqual(milk.going,False)
        milk.start()
        self.assertEqual(milk.going,True)
        milk.stop()
        self.assertEqual(milk.going,False)

    def testMilkAndWater(self):
        movers : List[Liquid] = []
        movers.append(Milk(10, 0.5))
        movers.append(Milk(15, 0.25))
        movers.append(Water("mineral"))
        for mover in movers:
            mover.start()
        for i in range(len(movers)):
            self.assertEqual(movers[i].going,True, f"i={i}")

        milk : Milk = cast(Milk,movers[1])
        milk.thurst = 1.0
        self.assertEqual(movers[1].going, True)

if __name__ == '__main__':
    unittest.main()