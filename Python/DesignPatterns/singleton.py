class Borg:
    """The Borg design pattern"""
    _shared_data = {} #Attribute dictionary 

    def __init__(self):
        self.__dict__ = self._shared_data #Make an attribute dictionary 


class Singleton(Borg):
    """The singleton class"""
    def __init__(self,**kwargs):
        Borg.__init__(self)
        self._shared_data.update(kwargs) #Update the attribute dictionary by inserting a new key-value pair 
    
    def __str__(self):
        return str(self._shared_data) #Return the attribute dictionary for printing



def main():
    #Singleton object and add our first acronym 
    x = Singleton(HTTP = "Hyper Text Transfer Protocol")
    #Print the Object
    print(x)
    y = Singleton(SNMP = "Simple Network Management Protocol")
    print(y)
    z = Singleton(KISS = "Keep It Simple Stupid")
    print(z)


if __name__ == '__main__':main()