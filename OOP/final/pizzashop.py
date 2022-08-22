import six
import math
import numbers
from abc import ABCMeta

#DECORATOR  PATTERN
#abstract and cannot be instantiated
@six.add_metaclass(ABCMeta)
class Abstract_Pizza(object):

   def get_cost(self):
      pass

   def get_ingredients(self):
      pass
   
   def get_tax(self):
      return 0.08*self.get_cost()

class ConcretePizza(Abstract_Pizza):
   
   def get_cost(self):
      return 12.00
   
   def get_ingredients(self):
      return 'crust, marinara, cheese'

@six.add_metaclass(ABCMeta)
class Abstract_Pizza_Decorator(Abstract_Pizza):
   
   def __init__(self,decorated_pizza):
      self.decorated_pizza = decorated_pizza
   
   def get_cost(self):
      return self.decorated_pizza.get_cost()
   
   def get_ingredients(self):
      return self.decorated_pizza.get_ingredients()

class Marinara(Abstract_Pizza_Decorator):
   
   def __init__(self,decorated_pizza):
      Abstract_Pizza_Decorator.__init__(self,decorated_pizza)
   
   def get_cost(self):
      return self.decorated_pizza.get_cost()
   
   def get_ingredients(self):
	   return self.decorated_pizza.get_ingredients() + ', marinara'

class Cheese(Abstract_Pizza_Decorator):
   
   def __init__(self,decorated_pizza):
      Abstract_Pizza_Decorator.__init__(self,decorated_pizza)
   
   def get_cost(self):
      return self.decorated_pizza.get_cost() + 0.25
   
   def get_ingredients(self):
      return self.decorated_pizza.get_ingredients() + ', cheese'

class Pepperoni(Abstract_Pizza_Decorator):
   
   def __init__(self,decorated_pizza):
      Abstract_Pizza_Decorator.__init__(self,decorated_pizza)
   
   def get_cost(self):
      return self.decorated_pizza.get_cost() + 0.5
   
   def get_ingredients(self):
      return self.decorated_pizza.get_ingredients() + ', pepperoni'

class Sausage(Abstract_Pizza_Decorator):
   
   def __init__(self,decorated_pizza):
      Abstract_Pizza_Decorator.__init__(self,decorated_pizza)
   
   def get_cost(self):
      return self.decorated_pizza.get_cost() + 0.5
   
   def get_ingredients(self):
      return self.decorated_pizza.get_ingredients() + ', sausage'

class Bacon(Abstract_Pizza_Decorator):
   
   def __init__(self,decorated_pizza):
      Abstract_Pizza_Decorator.__init__(self,decorated_pizza)
   
   def get_cost(self):
      return self.decorated_pizza.get_cost() + 0.5
   
   def get_ingredients(self):
      return self.decorated_pizza.get_ingredients() + ', bacon'

class Meat(Abstract_Pizza_Decorator):
   
   def __init__(self,decorated_pizza):
      Abstract_Pizza_Decorator.__init__(self,decorated_pizza)
   
   def get_cost(self):
      return self.decorated_pizza.get_cost() + 1.25
   
   def get_ingredients(self):
      return self.decorated_pizza.get_ingredients() + ', pepperoni, sausage, bacon, ham'

class Veggie(Abstract_Pizza_Decorator):

   def __init__(self,decorated_pizza):
      Abstract_Pizza_Decorator.__init__(self,decorated_pizza)
   
   def get_cost(self):
      return self.decorated_pizza.get_cost() + 1.00
   
   def get_ingredients(self):
      return self.decorated_pizza.get_ingredients() + ', onion, peppers, olives, mushrooms'

class Hawaiian(Abstract_Pizza_Decorator):

   def __init__(self,decorated_pizza):
      Abstract_Pizza_Decorator.__init__(self,decorated_pizza)
   
   def get_cost(self):
      return self.decorated_pizza.get_cost() + 0.75
   
   def get_ingredients(self):
      return self.decorated_pizza.get_ingredients() + ', ham, pinappple, red peppers'
   
class BQQ(Abstract_Pizza_Decorator):

   def __init__(self,decorated_pizza):
      Abstract_Pizza_Decorator.__init__(self,decorated_pizza)
   
   def get_cost(self):
      return self.decorated_pizza.get_cost() + 0.75
   
   def get_ingredients(self):
      return self.decorated_pizza.get_ingredients() + ', chicken, bqq sauce'
