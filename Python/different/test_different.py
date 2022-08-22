import unittest
from different import answer

class TestAboveAverage(unittest.TestCase):
    def test1_answer(self):
        self.assertEqual(answer(1001001, 100), 1000901)
    def test2_answer(self):
        self.assertEqual(answer(105, 3009), 2904)
    def test3_answer(self):
        self.assertEqual(answer(789, 925), 136)


if __name__ == '__main__':
    unittest.main()