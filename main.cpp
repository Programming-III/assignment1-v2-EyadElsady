#include <iostream>
#include <string>

using namespace std;

class Person {
private:
    string name;
    int id;
public:
    Person() : name(""), id(0) {}
    Person(const string& name, int id) : name(name), id(id) {}
    virtual ~Person() {}
    void setName(const string& n) { name = n; }
    void setId(int i) { id = i; }
    string getName() const { return name; }
    int getId() const { return id; }
    virtual void display() const {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
    }
};

class Student : public Person {
private:
    int yearLevel;
    string major;
public:
    Student() : Person(), yearLevel(0), major("") {}
    Student(const string& name, int id, int yearLevel, const string& major)
        : Person(name, id), yearLevel(yearLevel), major(major) {}
    ~Student() {}
    void setYearLevel(int y) { yearLevel = y; }
    void setMajor(const string& m) { major = m; }
    int getYearLevel() const { return yearLevel; }
    string getMajor() const { return major; }
    void display() const override {
        cout << "Name: " << getName() << endl;
        cout << "Year: " << yearLevel << endl;
        cout << "Major: " << major << endl;
    }
};

class Instructor : public Person {
private:
    string department;
    int experienceYears;
public:
    Instructor() : Person(), department(""), experienceYears(0) {}
    Instructor(const string& name, int id, const string& department, int experienceYears)
        : Person(name, id), department(department), experienceYears(experienceYears) {}
    ~Instructor() {}
    void setDepartment(const string& d) { department = d; }
    void setExperienceYears(int y) { experienceYears = y; }
    string getDepartment() const { return department; }
    int getExperienceYears() const { return experienceYears; }
    void display() const override {
        cout << "Name: " << getName() << endl;
        cout << "Department: " << department << endl;
        cout << "Experience: " << experienceYears << " years" << endl;
    }
};

class Course {
private:
    string courseCode;
    string courseName;
    int maxStudents;
    Student* students;
    int currentStudents;
    Instructor* instructor;
public:
    Course() : courseCode(""), courseName(""), maxStudents(0), students(nullptr), currentStudents(0), instructor(nullptr) {}
    Course(const string& code, const string& name, int maxStudents)
        : courseCode(code), courseName(name), maxStudents(maxStudents),
          students(new Student[maxStudents]), currentStudents(0), instructor(nullptr) {}
    ~Course() { delete[] students; }
    void setInstructor(Instructor* instr) { instructor = instr; }
    bool addStudent(const Student& s) {
        if (currentStudents >= maxStudents) return false;
        students[currentStudents++] = s;
        return true;
    }
    void displayCourseInfo() const {
        cout << "Course: " << courseCode << " - " << courseName << endl;
        cout << "Max Students: " << maxStudents << endl;
        if (currentStudents > 0) {
            cout << "Currently Enrolled: " << students[0].getName() << " (ID: " << students[0].getId() << ")" << endl;
        } else {
            cout << "Currently Enrolled: " << endl;
        }
        cout << endl;
        if (instructor) {
            cout << "Instructor Info:" << endl;
            instructor->display();
            cout << endl;
        }
        cout << "Student Info:" << endl;
        if (currentStudents > 0) {
            students[0].display();
        }
    }
};

int main() {
    Instructor instructor("Dr. Lina Khaled", 3001, "Computer Science", 5);
    Student student("Omar Nabil", 2202, 2, "Informatics");
    Course course("CS101", "Introduction to Programming", 3);
    course.setInstructor(&instructor);
    course.addStudent(student);
    course.displayCourseInfo();
    return 0;
}
