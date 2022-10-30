class data :
    def __gantinama(self) :
        self.name = "SEA"

    def ganti(self) :
        self.__gantinama()

class user(data) :
    
    def __init__(self,name):
        self.name=name
        data.__init__(self)

    def printusername(self):
        print(self.name)

user1= user("Budi")
user1.printusername()
user1.ganti()
user1.printusername()