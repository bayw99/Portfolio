import unittest
from hailstone import hailstone

class TestDeath(unittest.TestCase):
    def test1_answer(self):
        self.assertEqual(hailstone(10), 46)
    def test2_answer(self):
        self.assertEqual(hailstone(2), 49)
    def test3_answer(self):
        self.assertEqual(hailstone(4), 56)


if __name__ == '__main__':
    unittest.main()