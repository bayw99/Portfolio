import unittest

from gastank import Gas


class WheelTest(unittest.TestCase):

    def testDefaults(self):
        gas = Gas()
        self.assertEqual(gas.tanksize, Gas.DEFAULT_TANK)
        self.assertEqual(gas.gallons, gas.DEFAULT_GALLONS)
        self.assertEqual(gas.miles, 4.5)
        self.assertEqual(gas.empty, Gas.DEFAULT_TANK == 0.0)

    def testSpecific(self):
        testTank : float = 4.0
        testGallons : float = Gas.DEFAULT_TANK/2.0
        gas = Gas(gallons = testGallons, tanksize = testTank)
        self.assertEqual(gas.tanksize, testTank)
        self.assertEqual(gas.gallons, testGallons)
        self.assertEqual(gas.miles,112.5)
        self.assertEqual(gas.empty,False)

    def testEmpty(self):
        testMiles = Gas.TOTAL_MILES / 2.0
        gas = Gas()
        Gas.miles = testMiles
        self.assertEqual(gas.miles, testMiles)
        self.assertEqual(gas.empty, False)
        gas.miles = 0.0
        self.assertEqual(gas.empty, False)
    
    def testFull(self):
        gas = Gas()
        gas.tank = Gas.DEFAULT_TANK / 2.0
        self.assertEqual(gas.empty,False)
        self.assertEqual(gas.tanksize,4.5)
        gas.tanksize = Gas.DEFAULT_TANK
        self.assertEqual(gas.tanksize,4.5)
        self.assertEqual(gas.empty,False)
        self.assertEqual(gas.tanksize,4.5)
        gas.tanksize = Gas.DEFAULT_TANK / 2.0
        self.assertEqual(gas.tanksize,4.5)
        self.assertEqual(gas.empty,False)
        self.assertEqual(gas.tanksize,2.25)

if __name__ == '__main__':
    unittest.main()