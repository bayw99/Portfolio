import unittest
from death import answer

class TestDeath(unittest.TestCase):
    def test1_answer(self):
        self.assertEqual(answer("CD",0), 0)
    def test2_answer(self):
        self.assertEqual(answer("OOOOODC",0), 1)
    def test3_answer(self):
        self.assertEqual(answer("DCOODC",1), 2)


if __name__ == '__main__':
    unittest.main()