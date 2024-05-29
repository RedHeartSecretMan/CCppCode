interface Animal {
    void sound();
}

class Dog implements Animal {
    public void sound() {
        System.out.println("Dog barks");
    }
}

public class polymorphism_runtime_interface {
    static void makeSound(Animal animal) {
        animal.sound();
    }

    public static void main(String[] args) {
        Animal animal = new Dog();
        makeSound(animal); // Output: Dog barks
    }
}
