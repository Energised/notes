#!/usr/local/bin/python3
# implementation_order.py

from abc import ABC, abstractmethod
from collections import namedtuple

Customer = namedtuple("Customer", "name fidelity")

class LineItem:

    """ Product stocked in online shop """

    def __init__(self, product, quantity, price):
        self.product = product
        self.quantity = quantity
        self.price = price

    def total(self):
        return self.price * self.quantity

class Order:

    """ Order information with total calculations """

    def __init__(self, customer, cart, promotion=None):
        self.customer = customer
        self.cart = list(cart)
        self.promotion = promotion

    def total(self):
        if not hasattr(self, '__total'):
            self.__total = sum(item.total() for item in self.cart)
        return self.__total

    def due(self):
        if self.promotion == None:
            discount = 0
        else:
            discount = self.promotion.discount(self, self) # refer to self, then to Order instance
        return self.total() - discount

    def info(self):
        fmt = "<Order total: {:.2f} due: {:.2f}>"
        return fmt.format(self.total(), self.due())

class Promotion(ABC): # abstract base class

    @abstractmethod
    def discount(self, order):
        """ return discount as a positive dollar amount """

class FidelityPromotion(Promotion):

    """ 5% discount for customers w/ >1000 fidelity points """

    def discount(self, order):
        return order.total() * .05 if order.customer.fidelity >= 1000 else 0

class BulkItemPromotion(Promotion):

    """ 10% discount for each LineItem with >=20 units """

    def discount(self, order):
        discount = 0
        for item in order.cart:
            if item.quantity >= 20:
                discount += item.total() * .1
        return discount

class LargeOrderPromotion(Promotion):

    """ 7% discount for orders with >= 10 distinct LineItems """

    def discount(self, order):
        distinct_items = {item.product for item in order.cart}
        if len(distinct_items) >= 10:
            return order.total() * .07
        return 0

def test():
    joe = Customer("Joe Doe", 0)
    ann = Customer("Ann Smith", 1100)
    cart = [LineItem("Banana",4,.5),
            LineItem("Apple",10,1.5),
            LineItem("Pear",5,5.0)]
    order = Order(ann, cart, promotion=FidelityPromotion)
    print(order.info())

if __name__ == "__main__":
    test()
