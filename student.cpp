#include <iostream>
#include <vector>

struct Student{
    std::string name;
    std::vector<double> grades;
};


void print_student(const Student& student);
double average(Student& student);
void add_grade(Student& student, double grade);
Student best_student(std::vector<Student>& students);
void apply_bonus(std::vector<Student>& students, double bonus);


int main(){
    Student alice;
    alice.name = "Alice";
    alice.grades = {80, 75, 90};

    Student bob;
    bob.name = "Bob";
    bob.grades = {65, 70, 72};

    Student charlie;
    charlie.name = "Charlie";
    charlie.grades = {95, 88, 91};

    std::vector<Student> students = {alice, bob, charlie};

    add_grade(alice, 95);
    print_student(alice);

    print_student(best_student(students));

    apply_bonus(students, 5);

    for (Student& student : students){
        print_student(student);
    }

    return 0;
}

void print_student(const Student& student){
    std::cout << student.name << ": ";

    for (const double& grade : student.grades){
        std::cout << grade << ' ';
    }
}

double average(Student& student){
    double total = 0;
    int size = student.grades.size();

    for (double& grade : student.grades){
        total += grade;
    }
    total /= size;
    return total;
}

void add_grade(Student& student, double grade){
    student.grades.push_back(grade);
}

Student best_student(std::vector<Student>& students){
    double max = 0;
    Student best;

    for (Student& student : students){
        if (average(student) > max){
            max = average(student);
            best = student;
        }
    }

    return best;
}

void apply_bonus(std::vector<Student>& students, double bonus){
    for (Student& student : students){
        for (double& grade : student.grades){
            grade += bonus;
        }
    }
}