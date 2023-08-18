# One of the objects to be returned
class Dog:
    def speak(self):
        return "Woof"

    def __str__(self):
        return "Dog"


# Concrete Factory
class DogFactory:
    def get_pet(self):
        """Returns a Dog Object"""
        return Dog()

    def get_food(self):
        """Returns a Dog Food Object"""
        return "Dog Food!"


class PetStore:
    """PetStore houses our Abstract Factory"""

    def __init__(self, pet_factory):
        """pet_factory is Our Abstract Factory"""
        self._pet_factory = pet_factory

    def show_pet(self):
        """Utility method to display the details of the objects returned by the concrete factory"""
        pet = self._pet_factory.get_pet()
        pet_food = self._pet_factory.get_food()

        print(f"Our pet is a {pet}")
        print(f'Our pet says hello by "{pet.speak()}"')
        print(f'Its food is "{pet_food}"')


# Creates a Concrete Factory
factory = DogFactory()
# Create a pet store hosing our Abstract Factory
shop = PetStore(factory)
# Invoke the utility method to show the details of our pet
shop.show_pet()
