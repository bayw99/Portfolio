import unittest 
from strategy import NinjaFighter, QuietSoundStrategy, quiet
from strategy import SumoFighter
from strategy import BoxFighter
from strategy import KungFuFighter
from strategy import Fighter
  
class SimpleTest(unittest.TestCase): 
    
    def test_ninja(self):  
        self.assertEqual(NinjaFighter.sound, Fighter.sound)    
        self.assertEqual(NinjaFighter.move, Fighter.move)  
        
    def test_sumo(self):
        self.assertEqual(SumoFighter.sound, Fighter.sound)
        self.assertEqual(SumoFighter.move, Fighter.move)
        
    def test_box(self):
        self.assertEqual(BoxFighter.sound, Fighter.sound)
        self.assertEqual(BoxFighter.move, Fighter.move)

    def test_kungfu(self):
        self.assertEqual(KungFuFighter.sound, Fighter.sound)
        self.assertEqual(KungFuFighter.move, Fighter.move)
  
if __name__ == '__main__': 
    unittest.main() 
sz
