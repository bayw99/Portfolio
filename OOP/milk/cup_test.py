import unittest

from cup import Cup


class CupTest(unittest.TestCase):

    def testDefaults(self):
        cup = Cup()
        self.assertEqual(cup.amount, Cup.DEFAULT_AMOUNT)
        self.assertEqual(cup.volume, Cup.DEFAULT_VOLUME)
        self.assertEqual(cup.over, False)
        self.assertEqual(cup.empty, Cup.DEFAULT_AMOUNT == 0.0)

    def testNegativeAmount(self):
        testVolume : float = 4.0
        testAmount : float = -1
        self.assertRaises(ValueError, \
            lambda : Cup(volume = testVolume, amount = testAmount))

    def testSpecific(self):
        testVolume : float = 3.0
        testAmount : float = Cup.OVER_AMOUNT/1.25
        cup = Cup(volume = testVolume, amount = testAmount)
        self.assertEqual(cup.amount, testAmount)
        self.assertEqual(cup.volume, testVolume)
        self.assertEqual(cup.over,False)
        self.assertEqual(cup.empty,False)

    def testEmpty(self):
        testAmount = Cup.OVER_AMOUNT / 2.0
        cup = Cup()
        cup.amount = testAmount
        self.assertEqual(cup.amount, testAmount)
        self.assertEqual(cup.empty, False)
        cup.amount = 0.0
        self.assertEqual(cup.empty, True)
    
    def testOver(self):
        cup = Cup()
        cup.amount = Cup.OVER_AMOUNT / 2.0
        self.assertEqual(cup.empty,False)
        self.assertEqual(cup.over,False)
        cup.amount = Cup.OVER_AMOUNT
        self.assertEqual(cup.amount,0.0)
        self.assertEqual(cup.empty,True)
        self.assertEqual(cup.over,True)
        cup.amount = Cup.OVER_AMOUNT / 2.0
        self.assertEqual(cup.amount,0.0)
        self.assertEqual(cup.empty,True)
        self.assertEqual(cup.over,True)

if __name__ == '__main__':
    unittest.main()
