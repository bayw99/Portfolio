import pizza
import pizzashop
import unittest
from pizza import Builder, Crust, Director, Sauce, Toppings

from pizzashop import Abstract_Pizza_Decorator, ConcretePizza, Meat, Pepperoni

class SimpleTest(unittest.TestCase):

 def test_cheese(self):  
    pizza = pizzashop.ConcretePizza()
    temp = str(pizza.get_cost())
    self.assertEqual(str(pizza.get_cost()), temp)
    self.assertEqual(str(pizza.get_ingredients()), 'crust, marinara, cheese')      
    temp = str(pizza.get_tax())
    self.assertEqual(str(pizza.get_tax()), temp)

 def test_meat(self):
    cheese = pizzashop.ConcretePizza()
    meat = pizzashop.Meat(cheese)
    temp = str(meat.get_cost())
    self.assertEqual(str(meat.get_cost()), temp)
    self.assertEqual(str(meat.get_ingredients()), 'crust, marinara, cheese, pepperoni, sausage, bacon, ham')
    temp = str(meat.get_tax())
    self.assertEqual(str(meat.get_tax()), temp)

 def test_builder(self):
    self.assertEqual(Toppings.kind, 'pepperoni and olives')
    self.assertEqual(Crust.shape, 'thin')
    self.assertEqual(Sauce.flavor, 'marinara')
    
    

if __name__ == '__main__': 
    unittest.main() 