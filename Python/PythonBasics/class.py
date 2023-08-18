class Duck:
    sound = "Quack Quack"  ## Data in the form of these variables
    movement = "Walks Like a Duck"

    def quack(self):  ##Methods in the form of these Function definition
        print(
            self.sound
        )  ##Self is not a keyword but it is common practice which is a reference to the object not the class

    def move(self):
        print(self.movement)  ## Period is used to de reference the object


class Animal:
    def __init__(self, type, name, sound):
        self._type = type
        self._name = name
        self._sound = sound

    def type(self):  ##Getters
        return self._type

    def name(self):
        return self._name

    def sound(self):
        return self._sound


class Animals:
    # variables define outside __init__ are class variables not object variables

    # Special Constructor Definition __init__(self,X)
    # Object Variables  bound to the object not to the class itself  (encapsulated Variables)
    def __init__(self, **kwargs):
        self._type = kwargs["type"] if "type" in kwargs else "human"
        self._name = kwargs["name"] if "name" in kwargs else "Joe"
        self._sound = kwargs["sound"] if "sound" in kwargs else "bleep"

    def getType(self):  # Getters
        return self._type

    def getName(self):  # method (self is provided automatically)
        return self._name

    def getSound(self):
        return self._sound

    def setType(self, t=None):  # Setters
        if t:
            self._type = t

    def setName(self, n=None):
        if n:
            self._name = n

    def setSound(self, s=None):
        if s:
            self._sound = s

    # Print Object representation with special function name __str__(self)
    def __str__(self):
        return f'The {self.getType()} is named "{self.getName()}" and says "{self.getSound()}".'


def print_animal(a):
    if not isinstance(a, Animal):
        raise TypeError("print_animal(): requires an Animal")
    print('The {} is named "{}" and says "{}"'.format(a.type(), a.name(), a.sound()))


def print_animals(a):
    if not isinstance(a, Animals):
        raise TypeError("print_animal(): requires an Animal")
    print(
        'The {} is named "{}" and says "{}"'.format(
            a.getType(), a.getName(), a.getSound()
        )
    )


def main():

    Daniel = Duck()
    Daniel.quack()
    Daniel.move()

    A1 = Animal("Kitten", "Godzilla", "RWAR")
    ##print_animal(Daniel)
    print_animal(A1)

    A2 = Animals(name="Daniel", type="Human", sound="Chikibeibi")

    print_animals(A2)
    A3 = Animals()
    A3.setName("Rick")
    A3.setType("Scientist")
    A3.setSound("Wubba Lubba Dub Dub")
    # print_animals(A3)
    print(A3)


if __name__ == "__main__":
    main()
