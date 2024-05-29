class Animal {
    public void sound() {
        System.out.println("Animal makes a sound");
    }
}

class Dog extends Animal {
    public void sound() {
        System.out.println("Dog barks");
    }
}

public class polymorphism_runtime {
    public static void main(String[] args) {
        Animal dog = new Dog();
        dog.sound(); // Output: Dog barks
    }
}
