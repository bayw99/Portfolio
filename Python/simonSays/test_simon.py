import unittest
from simonSays import answer

class TestSimonSays(unittest.TestCase):
    def test1_answer(self):
        self.assertEqual(answer("simon says jump"), "jump")
    def test2_answer(self):
        self.assertEqual(answer("nothing to do here"), None)
    def test3_answer(self):
        self.assertEqual(answer("simon says run"), "run")


if __name__ == '__main__':
    unittest.main()