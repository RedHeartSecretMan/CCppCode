class Animal:
    def sound(self):
        print("Animal makes a sound")


class Dog(Animal):
    def sound(self):
        print("Dog barks")


def make_sound(animal):
    animal.sound()


if __name__ == "__main__":
    dog = Dog()
    make_sound(dog)  # Output: Dog barks
