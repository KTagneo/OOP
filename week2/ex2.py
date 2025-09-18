class Temperature:
    unit = "Celsius"

    def __init__(self, value):
        self.value = value
    
    def display(self):
        print(str(self.value)+self.unit)
    
    @classmethod
    def change_unit(cls, new_unit):
        cls.unit = new_unit

    @staticmethod
    def to_fahrenhe(celsius):
        return celsius * 9/5 + 32
    
temp = Temperature(100)

temp.display()
print(Temperature.to_fahrenhe(100))
Temperature.change_unit("Kelvin")
temp.display()

#D: because the class attribute has been changed.