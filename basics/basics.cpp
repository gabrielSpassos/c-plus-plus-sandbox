#include <boost/uuid/uuid.hpp>            // uuid class
#include <boost/uuid/uuid_generators.hpp> // generators
#include <boost/uuid/uuid_io.hpp>         // streaming operators etc.
#include <iostream> //header file library that lets us work with input and output objects
#include <sstream>
#include <string>// streaming operators etc.
#include <cmath> // Include the cmath library 

using namespace std; //means that we can use names for objects and variables from the standard library.
using namespace boost;
using namespace uuids;

void variables() {
    int number = 323;
    cout << number << "\n"; // way to break line
    int negativeNumber = -4;
    cout << negativeNumber << "\n";

    float fNumber = 43.74;
    cout << fNumber << "\n";

    double dNumber = 23.54;
    cout << dNumber << "\n";
    double negativeDNumber = -5431.01;
    cout << negativeDNumber << endl; //other way to break line

    /*
    float --> 6 or 7 digits precision
    double --> 15 digits precision
    */

    char a = 'A';
    cout << a << "\n";
    char b = 'b';
    cout << b << "\n";
    char c = 90;
    cout << c << "\n";

    string s = "Hello World!\n";
    cout << s;

    bool x = true;
    cout << x << "\n";
    bool y = false;
    cout << y << "\n";

    int v;
    v = 5435;
    cout << v << "\n";

    double foo = 0, bar = 43, tar = 65.42;
    cout << foo << " " << bar << " " << tar << "\n";

    string alpha, beta, charlie;
    alpha = beta = charlie = "Test";
    cout << alpha << " " << beta << " " << charlie << "\n";

    const double pi = 3.14;
    cout << pi << "\n";
}

void operators() {
    int a = 100 + 50;
    cout << a << "\n";

    int b = 100 - 50;
    cout << b << "\n";

    int c = 100 * 50;
    cout << c << "\n";

    int d = 100 / 50;
    cout << d << "\n";

    int e = 100 % 50;
    cout << e << "\n";

    int f = 150;
    cout << ++f << "\n";

    int g = 150;
    cout << --g << "\n";

    int h = 1;
    h += 3;
    cout << h << "\n";

    bool r;
    r = f == g;
    cout << f << " == " <<  g << ": " << r << "\n";

    r = f != g;
    cout << f << " != " <<  g << ": " << r << "\n";

    r = f > g;
    cout << f << " > " <<  g << ": " << r << "\n";

    r = f < g;
    cout << f << " < " <<  g << ": " << r << "\n";

    r = f >= g;
    cout << f << " >= " <<  g << ": " << r << "\n";

    r = f <= g;
    cout << f << " <= " <<  g << ": " << r << "\n";

    r = true && false;
    cout << "true && false: " << r << "\n";

    r = true || false;
    cout << "true || false: " << r << "\n";

    r = !false;
    cout << "!false: " << r << "\n";
}

void strings() {
    string name = "Gabriel";
    string lastName = "Passos";
    cout << name + " " + lastName + "\n";
    cout << name.append(" ").append(lastName).append("\n");

    string txt = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    cout << txt.length() << endl;
    cout << txt.size() << "\n"; 

    string word = "fit";
    word[0] = 'h';
    cout << word << "\n";

    uuid uuid = boost::uuids::random_generator()();
    cout << uuid << "\n";
}

void math() {
    cout << max(5, 10) << "\n";
    cout << min(5, 10) << "\n";
    cout << sqrt(64) << "\n";
    cout << round(2.6) << "\n";
    cout << log(2) << "\n";
    cout << abs(-1) << "\n";
    cout << pow(2, 3) << "\n";
}

void conditionals() {
    if (true) {
        cout << "Inside if 1" << "\n";
    }

    if (false) {
        cout << "Inside if 2" << "\n";
    } else {
        cout << "Inside else 2" << "\n";
    }

    if (false) {
        cout << "Inside if 3" << "\n";
    } else if (true) {
        cout << "Inside else if 3" << "\n";
    } else {
        cout << "Inside else 3" << "\n";
    }

    string ternary = true ? "result A" : "result B";
    cout << ternary << "\n";

    int day = 5;
    switch (day) {
        case 1:
            cout << "Monday" << "\n";
            break;
        case 2:
            cout << "Tuesday" << "\n";
            break;
        case 3:
            cout << "Wednesday" << "\n";
            break;
        case 4:
            cout << "Thursday" << "\n";
            break;
        case 5:
            cout << "Friday" << "\n";
            break;
        case 6:
            cout << "Saturday" << "\n";
            break;
        case 7:
            cout << "Sunday" << "\n";
            break;
        default:
            cout << "Invalid day" << "\n";
            break;
    }
}

void loops() {
    int x = 1;
    cout << "While: ";
    while (x < 5) {
        cout << x;
        x++;
    }
    cout << "\n";

    int y = 6;
    cout << "Do/While: ";
    do {
        cout << y;
        y++;
    } while (y < 5);
    cout << "\n";

    cout << "For: ";
    for (int i = 0; i < 5; i++) {
        cout << i;
    }
    cout << "\n";

    int myNumbers[5] = {1, 2, 3, 4, 5};
    cout << "For each: ";
    for (int number : myNumbers) {
        cout << number;
    }
    cout << "\n";

    cout << "For with array size: ";
    for (int i = 0; i < sizeof(myNumbers)/sizeof(int); i++) {
        cout << myNumbers[i];
    }
    cout << "\n";

    cout << "break: ";
    for (int i = 0; i < 5; i++) {
        if (i == 3) {
            break;
        }
        cout << i;
    }
    cout << "\n";

    cout << "continue: ";
    for (int i = 0; i < 5; i++) {
        if (i == 3) {
            continue;
        }
        cout << i;
    }
    cout << "\n";
}

void collections() {
    int numbers[4];
    string cars[3] = {"Argo", "BMW", "Fusca"};
    numbers[0] = 1;

    cout << "My car number #" << numbers[0] << " is a(n) " << cars[0] << "\n";

    string names[] = {"Gabriel", "Fernanda", "Maria", "Jose"};
    // this is the way to get the size of some list
    cout << "We have the size of names: " << sizeof(names) / sizeof(string) << "\n";
}

// single structure 
struct {
    int id;
    string name;
} person; // also could have person1, person2

// create a new type to be used anytime
struct account {
    long number;
    string type;
};

void structures() {
    person.id = 1;
    person.name = "Gabriel";

    cout << "Person Id: " << person.id << ", person name: " << person.name << "\n";

    account account1;
    account1.number = 123456;
    account1.type = "Savings";
    cout << "Account number: " << account1.number << " is type: " << account1.type << "\n";

    account account2;
    account2.number = 987654;
    account2.type = "Checking";
    cout << "Account number: " << account2.number << " is type: " << account2.type << "\n";
}

void references() {
    string food = "Pizza";
    string &meal = food;
    string* pointer = &food;
    cout << food << "\n";
    cout << meal << "\n";
    cout << &food << "\n";
    cout << pointer << "\n";
    cout << *pointer << "\n";

    cout << "Change the pointer" << "\n"; 
    *pointer = "Hamburger";
    cout << food << "\n";
    cout << meal << "\n";
    cout << &food << "\n";
    cout << pointer << "\n";
    cout << *pointer << "\n";
}

void testFunction(string name);

void testFunctionWithDefault(int number = 0);

int add(int x, int y) {
    int result = x + y;
    cout << x << " + " << y << " = " << result << "\n";
    return result;
}

double add(double x, double y) {
    double result = x + y;
    cout << x << " + " << y << " = " << result << "\n";
    return result;
}

void swap(int &x, int &y) {
    cout << "Before swap: " << "\n";
    cout << x << " | " << y << "\n";

    int z = x;
    x = y;
    y = z;

    cout << "After swap: " << "\n";
    cout << x << " | " << y << "\n";
}

int sum(int numbers[], int len = 0) {
    int total = 0;
    cout << "Size: " << len << "\n";
    for(int i = 0; i < len; i++) {
        total += numbers[i];
    }
    return total;
}

class Fruit {
    public:
        int id;
        string name;

        Fruit() {}

        Fruit(int _id, string _name) {
            id = _id;
            name = _name;
        }

        void toString() {
            cout << json();
        }
    
    private:
        string json() {
            ostringstream os;
            os << "{id:" << id << ", name:" << name << "}" << "\n";
            return os.str();
        }
};

class MyClass {
  int x;   // Private attribute
  int y;   // Private attribute
};

class Employee {
    private:
        double salary;
    
    public:
        //setter
        void setSalary(double _salary) {
            salary = _salary;
        }

        //getter
        double getSalary() {
            return salary;
        }
};

class Vehicle {
    public:
        string branch;
        void start() {
            cout << "Started the vehicle" << "\n";
        }
};

class Car : public Vehicle {
    public:
        string model;
};

class Vertible {
    public:
        bool hasBackbone = true;

        void move() {
            cout << "Vertible is moving" << "\n";
        }
};

class Mammal {
    public: 
        bool isBreastfeed = true;

        void breastfeed() {
            cout << "Animal is breastfeeding" << "\n";
        }
};

class Dog: public Mammal, public Vertible {
    public:
        void bark() {
            cout << "Dog is barking" << "\n";
        }
};

class Shape {
    public:
      // "Interface" - pure virtual function providing interface framework.
      virtual double getArea() = 0;

      Shape(double w, double h) {
        width = w;
        height = h;
      };

      void printArea() { 
        cout << "Width: " << width << " | Height: " << height << ". Area = " << getArea() << "\n";
      }
   
   protected:
      int width;
      int height;
};

// Derived classes
class Rectangle: public Shape {
   public:
      Rectangle(double w, double h) : Shape(w, h) {

      }

      double getArea() { 
         return (width * height); 
      }
};

class Triangle: public Shape {
   public:
      Triangle(double w, double h) : Shape(w, h) {

      }

      double getArea() { 
         return (width * height) / 2; 
      }
};

/*
This is the main function
*/
int main() {
    variables();
    operators();
    strings();
    math();
    conditionals();
    loops();
    collections();
    structures();
    references();
    testFunction("Gabriel");
    testFunctionWithDefault();
    testFunctionWithDefault(1);

    int r1 = add(3, 6);
    cout << "Add result: " << r1 << "\n";
    double r2 = add(2.4, 6.5);
    cout << "Add result: " << r2 << "\n";


    int x = 18;
    int y = 76;
    swap(x, y);

    int numbers[] = {100, 321, 92, 9};
    int length = sizeof(numbers)/sizeof(numbers[0]);
    int total = sum(numbers, length);
    cout << "Sum Total: " << total << "\n";

    Fruit banana;
    banana.id = 3;
    banana.name = "Banana";
    banana.toString();

    Fruit apple(4, "Apple");
    apple.toString();

    Employee employee;
    employee.setSalary(5456.98);
    cout << "Salary: " << employee.getSalary() << "\n";

    Car car;
    car.branch = "Fiat";
    car.model = "Argo";
    car.start();

    Dog dog;
    dog.move();
    dog.breastfeed();
    dog.bark();

    Rectangle rectangle(2.0, 3.0);
    cout << "Rectangle: ";
    rectangle.printArea();
    Triangle triangle(2.0, 3.0);
    cout << "Triangle: ";
    triangle.printArea();

    return 0;
}

void testFunction(string name) {
    cout << "Hello " << name << "\n";
}

//default definition above
void testFunctionWithDefault(int number) {
    cout << "Input number is " << number << "\n";
}