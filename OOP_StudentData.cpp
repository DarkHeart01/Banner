#include <iostream>
#include <string>
using namespace std;

class Student {
    static int count; 

    int div;
    string name;

public:
    // Parameterized constructor
    Student(int div, string name) {
        this->div = div;
        this->name = name;
        count++; // Increment count
    }

    // Copy constructor
    Student(const Student& s) {
        name = s.name;
        div = s.div;
        count++; // Increment count
    }

    // Default constructor
    Student() {
        div = 0;
        name = "";
        count++; // Increment count
    }

    // Input method
    void input() {
        cout << "Enter name and division: ";
        cin >> name >> div;
    }

    // Display method
    void display() {
        cout << "Name = " << name << ", Division = " << div << endl;
    }

    // Static method to get count
    static void get_count() {
        cout << "Total number of students = " << count << endl;
    }

    // Friend class declaration
    friend class NEW;

    // Destructor
    ~Student() {
        count--; // Decrement count
    }
};

// Friend class NEW
class NEW {
    int marks;

public:
    NEW() {
        marks = 0;
    }

    void input() {
        cout << "Enter marks: ";
        cin >> marks;
    }

    void display(Student& s) {
        cout << "Name = " << s.name << ", Division = " << s.div << ", Marks = " << marks << endl;
    }
};

// Initialize static variable
int Student::count = 0;

int main() {
    int n;
    cout << "How many students? ";
    cin >> n;

    // Dynamically allocate array of students
    Student* arr = new Student[n];

    // Input details for each student
    for (int i = 0; i < n; i++) {
        cout << "Student " << i + 1 << ": " << endl;
        arr[i].input();
    }

    // Display details of each student
    for (int i = 0; i < n; i++) {
        cout << "Details of Student " << i + 1 << ": ";
        arr[i].display();
    }

    // Display total count of students
    Student::get_count();

    // Free allocated memory
    delete[] arr;

    return 0;
}
