import unittest
from printingCost import answer

class TestAboveAverage(unittest.TestCase):
    def test1_answer(self):
        cost=0
        self.assertEqual(answer(cost, "hello hello"), 192)
    def test2_answer(self):
        cost=0
        self.assertEqual(answer(cost, "this is a sentence"), 293)
    def test3_answer(self):
        cost=0
        self.assertEqual(answer(cost, "HELLO"), 109)


if __name__ == '__main__':
    unittest.main()