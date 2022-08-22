import abc
import pizzashop
from pizzashop import Bacon
import sys

#BUILDER PATTERN
class Builder:
      def getToppings(self): pass
      def getSauce(self): pass
      def getCrust(self): pass

# Pizza parts
class Toppings:
   kind = 'pepperoni and olives'

class Sauce:
   flavor = 'marinara'

class Crust:
   shape = 'thin'

# The whole product
class Pizza:
   def __init__(self):
      self.__toppings = None
      self.__sauce = None
      self.__crust = None

   def setCrust(self, crust):
      self.__crust = crust

   def attachToppings(self, toppings):
      self.__toppings = toppings

   def setSauce(self, sauce):
      self.__sauce = sauce

   def specification(self):
      print ("crust: %s" % self.__crust.shape)
      print ("sauce: %s" % self.__sauce.flavor)
      print ("topping: %s" % self.__toppings.kind)

class Director:
   __builder = None
   
   def setBuilder(self, builder):
      self.__builder = builder
   
   def getPizza(self):
      pizza = Pizza()

      # First goes the crust
      crust = self.__builder.getCrust()
      pizza.setCrust(crust)
    
    
      # Then sauce
      sauce = self.__builder.getSauce()
      pizza.setSauce(sauce)
      
      # And toppings
      toppings = self.__builder.getToppings()
      pizza.attachToppings(toppings)

      return pizza


class PizzaBuilder(Builder):
   
   def getToppings(self):
      toppings = Toppings()
      top = input("What toppings would you like: ")
      toppings.kind = top
      return toppings
   
   def getSauce(self):
      sauce = Sauce()
      sau = input("What sauce would you like: ")
      sauce.flavor = sau
      return sauce
   
   def getCrust(self):
      crust = Crust()
      cru = input("What kind of crust would you like: ")
      crust.shape = cru
      return crust

#TEMPLATE DESIGN
class MakeMeal:

   def prepare(self): pass
   def cook(self): pass
   def eat(self): pass

   def go(self):
      self.prepare()
      self.cook()
      self.eat()

class MakePizza(MakeMeal):
   def prepare(self):
      print ("Preparing Pizza")
   
   def cook(self):
      print ("Cooking Pizza")
   
   def eat(self):
      print ("Pizza Is Served")
    
def main():
    login()
    
def login():
    print("---------- PIZZA PLACE --------")
    print("***** ONLINE ORDERING LOGIN *****")
    username="username"
    password="password"
    print("Enter username : ")
    answer1=input()
    print("Enter password : ")
    answer2=input()
    if answer1==username and answer2==password:
        print("Welcome - Access Granted")
        print(" ")
        print('****DETAILED MENU****')
        cheesePizza = pizzashop.ConcretePizza()
        print('Cheese Pizza - Ingredients: '+cheesePizza.get_ingredients()+
        '; Cost: '+str(cheesePizza.get_cost())+'; sales tax = '+str(cheesePizza.get_tax()))

        pepperoniPizza = pizzashop.Pepperoni(cheesePizza)
        print('Pepperoni Pizza - Ingredients: '+pepperoniPizza.get_ingredients()+
        '; Cost: '+str(pepperoniPizza.get_cost())+'; sales tax = '+str(pepperoniPizza.get_tax()))

        sausagePizza = pizzashop.Sausage(cheesePizza)
        print('Sausage Pizza - Ingredients: '+sausagePizza.get_ingredients()+
        '; Cost: '+str(sausagePizza.get_cost())+'; sales tax = '+str(sausagePizza.get_tax()))

        meatPizza = pizzashop.Meat(cheesePizza)
        print('Meat Pizza - Ingredients: '+meatPizza.get_ingredients()+
        '; Cost: '+str(meatPizza.get_cost())+'; sales tax = '+str(meatPizza.get_tax()))

        veggiePizza = pizzashop.Veggie(cheesePizza)
        print('Veggie Pizza - Ingredients: '+veggiePizza.get_ingredients()+
        '; Cost: '+str(veggiePizza.get_cost())+'; sales tax = '+str(veggiePizza.get_tax()))

        hawaiianPizza = pizzashop.Hawaiian(cheesePizza)
        print('Hawaiian Pizza - Ingredients: '+hawaiianPizza.get_ingredients()+
        '; Cost: '+str(hawaiianPizza.get_cost())+'; sales tax = '+str(hawaiianPizza.get_tax()))

        bqqPizza = pizzashop.BQQ(cheesePizza)
        print('BQQ Pizza - Ingredients: '+bqqPizza.get_ingredients()+
        '; Cost: '+str(bqqPizza.get_cost())+'; sales tax = '+str(bqqPizza.get_tax()))

        print(" ")
        menu()

def menu():
    print("SELECT YOUR CHOICE: ")
    print(" ")

    choice = input("""
                      1: Cheese Pizza
                      2: Pepperoni Pizza
                      3: Sausage Pizza
                      4: Meat Pizza
                      5: Veggie Pizza
                      6: Hawaiian Pizza
                      7: BQQ Pizza
                      8: Custom Pizza
                      Q: Quit

                      Please enter your choice: """)

    if choice == "1":
        cheesePizza()
    elif choice == "2":
        pepperoniPizza()
    elif choice == "3":
        sausagePizza()
    elif choice=="4":
        meatPizza()
    elif choice=="5":
        veggiePizza()
    elif choice=="6":
        hawaiianPizza()
    elif choice=="7":
        bqqPizza()
    elif choice=="8":
        customPizza()
    elif choice=="Q":
        sys.exit
    else:
        print("You must only select either 1-8 or Q")
        print("Please try again")
        menu()

def cheesePizza():
    print("You're Cheese Pizza is on its way...")
    print("Updates: ")
    makePizza = MakePizza()
    makePizza.go()
    print (25*"-")

def pepperoniPizza():
    print("You're Pepperoni Pizza is on its way...")
    print("Updates: ")
    makePizza = MakePizza()
    makePizza.go()
    print (25*"-")

def sausagePizza():
    print("You're Sausage Pizza is on its way...")
    print("Updates: ")
    makePizza = MakePizza()
    makePizza.go()
    print (25*"-")

def meatPizza():
    print("You're Meat Pizza is on its way...")
    print("Updates: ")
    makePizza = MakePizza()
    makePizza.go()
    print (25*"-")

def veggiePizza():
    print("You're Veggie Pizza is on its way...")
    print("Updates: ")
    makePizza = MakePizza()
    makePizza.go()
    print (25*"-")

def hawaiianPizza():
    print("You're Hawaiian Pizza is on its way...")
    print("Updates: ")
    makePizza = MakePizza()
    makePizza.go()
    print (25*"-")

def bqqPizza():
    print("You're BQQ Pizza is on its way...")
    print("Updates: ")
    makePizza = MakePizza()
    makePizza.go()
    print (25*"-")

director = Director()
def customPizza():
    pizzaBuilder = PizzaBuilder()
    print ("Here you can create your own custom pizza for $16.")
    print ("If you would like to choose a basic pizza,")
    print ("please leave answers blank.")
    # Build Pizza
    director.setBuilder(pizzaBuilder)
    pizza = director.getPizza()
    print(" ")
    print ("My Custom Pizza : Cost $16")
    pizza.specification()
    print (" ")
    print("You're Custom Pizza is on its way...")
    print("Updates: ")
    makePizza = MakePizza()
    makePizza.go()
    print (25*"-")

if __name__ == "__main__":
   main()