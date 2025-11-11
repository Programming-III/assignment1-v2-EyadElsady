#include <iostream>
#include <string>
using namespace std;
class Person {
protected:
    string name;
    int id;
    public:
    Person(string name, int id){
        this->name = name;
        this->id = id;
    }
    virtual void display(){
      cout<<"name: "<<name<<endl;
      cout<<"id :"<<id<<endl;

    }
    ~Person();
};
class Student{
 protected:
 int yearLevel;
 string major;
 public:
 Student(){

 }
    Student(int yearLevel, string major){
        this->yearLevel = yearLevel;
        this->major = major;
    }
    void display(){
        cout<<"Year Level: "<<yearLevel<<endl;
        cout<<"Major: "<<major<<endl;
    }
    ~Student();
};
class Instructor :public Person{
    private:
    string department;
    int experienceYears;
    public:
    Instructor(string name, int id, string department, int experienceYears){
        Person(name, id);
        this->department = department;
        this->experienceYears = experienceYears;
    }
    void display(){
        cout<<"Department: "<<department<<endl;
        cout<<"Years of Experience: "<<experienceYears<<endl;
    }
    ~Instructor();


};
class Course : public Student{
    private:
   string courseCode;
   string courseName;
   int maxStudents;
   Student* students;
   int currentStudents;
   public:
   Course(string courseCode, string courseName, int maxStudents, int yearLevel, string major)
   : Student(yearLevel, major){
        this->courseCode = courseCode;
        this->courseName = courseName;
        this->maxStudents = maxStudents;
        this->students = new Student[maxStudents];
        this->currentStudents = 0;
   }
    void addStudent(const Student& student){
          if(currentStudents < maxStudents){
                students[currentStudents++] = student;
          } else {
                cout<<"Cannot add more students, class is full."<<endl;
          }
    }
    void displayCourseInfo(){
        cout<<"Course Code: "<<courseCode<<endl;
        cout<<"Course Name: "<<courseName<<endl;
        cout<<"Max Students: "<<maxStudents<<endl;
        cout<<"Current Students: "<<currentStudents<<endl;
        cout<<"Enrolled Students Info: "<<endl;
        for(int i = 0; i < currentStudents; i++){
            students[i].display();
            cout<<"---"<<endl;

    }
    }
    ~Course();


};
int main() {
    Person person("Omar Nabil", 2002);
    person.display();
    Student student(2, "Informatics");
    student.display();

    Instructor instructor("Dr.Lina khaled", 3001, "Computer Science", 5);
    instructor.display();


    Course course("CS101", "Intro to programming", 3, 2, "Informatics");
    course.addStudent(Student(2, "Informatics"));
    course.displayCourseInfo();

    return 0;
}
