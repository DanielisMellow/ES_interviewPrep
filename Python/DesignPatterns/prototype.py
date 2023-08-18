import copy

class Prototype:
    
    def __init__(self):
        self._object = {}
        
    def register_object(self, name, obj):
        """Register an object"""
        self._object[name] = obj
        
    def unregister_object(self, name):
        """Unregister an object"""
        del self._object[name]
        
    def clone(self, name, **attr):
        """Clone a registered object and update its attributes"""
        obj = copy.deepcopy(self._object.get(name))
        obj.__dict__.update(attr)
        return obj


class Car:
    def __init__(self):
        self.name = "Mustang"
        self.color = "Black"
        self.options = "Ex"
        
    def __str__(self):
        return '{} | {} | {}'.format(self.name, self.color, self.options)


x = Car()
print(x)

proto = Prototype()
proto.register_object('betty',x)
x1 = proto.clone('betty',color = 'Red')

print(x1)
