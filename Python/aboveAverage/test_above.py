import unittest
from aboveAverage import answer

class TestAboveAverage(unittest.TestCase):
    def test1_answer(self):
        self.assertEqual(answer(3, 5), 60.0)
    def test2_answer(self):
        self.assertEqual(answer(5, 10), 50.0)
    def test3_answer(self):
        self.assertEqual(answer(1, 4), 25.0)


if __name__ == '__main__':
    unittest.main()