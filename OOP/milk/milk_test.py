from liquid import Liquid
import unittest
from milk import Milk
from typing import List,cast

class MilkTest(unittest.TestCase):

    def testDefaults(self):
        milk = Milk()
        self.assertEqual(milk.thurst,Milk.DEFAULT_THURST)
        self.assertEqual(milk.started,False)


    def testMilkThurst(self):
        milk : Milk = Milk()
        self.assertEqual(milk.thurst,Milk.DEFAULT_THURST)
        milk.thurst = 0.0
        self.assertEqual(milk._thurst,0.0)
        milk.thurst = 0.5
        self.assertEqual(milk._thurst,0.5)

    def testMilkLiquidThurst(self):
        liquid : Liquid = Milk()
        milk : Milk = cast(Milk,liquid)        
        milk.thurst = 0.0
        self.assertEqual(milk._thurst,0.0)
        self.assertEqual(liquid.going, False)
        self.assertEqual(milk.going, False)

if __name__ == '__main__':
    unittest.main()