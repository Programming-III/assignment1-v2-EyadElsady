[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/qUWOP-to)
# Programming III – Assignment 01: Educational Learning Portal System

The German International University
Faculty of Informatics and Computer Science

Dr. Nada Sharaf

Programming III, Winter Semester 2025/26

In-lab assignment 01



## General Description

In this project, you are required to implement a simple Educational Learning Portal System as a console-based application. The system models how students and instructors interact with courses in an educational environment.
The main goal of this milestone is to practice some fundamental Object-Oriented Programming (OOP) concepts.
In this phase, you will build the basic class structure of the system. The complete functionality and relationships between components will be implemented later in Milestone 2 (Assignment 2).



## Milestone 01: Required Classes and Methods

### a) Person Class

This class represents a general person within the system. It will serve as a base class for both Student and Instructor.

**Private Attributes:**
- `string name` — stores the person's full name
- `int id` — stores a unique identifier for the person

**Methods:**
- `display()` — displays the person's basic information (name and ID)

**Subclasses:**

#### 1. Student Class

Represents a student in the system and has the following attributes:
- `int yearLevel` 
- `string major`

**Methods:**
- `display()` — displays all student information 
 
#### 2. Instructor Class

Represents an instructor in the system and has the following attributes:
- `string department` 
- `int experienceYears` 

**Methods:**
- `display()` — displays all instructor information 

### b) Course Class

This class represents a course offered in the system. Each course can have a limited number of students enrolled.

**Private Attributes:**
- `string courseCode` — unique course identifier 
- `string courseName`  
- `int maxStudents` 
- `Student* students` — dynamically allocated array of Student objects
- `int currentStudents` 

**Methods:**
- `addStudent(const Student& s)` — adds a new student to the course 
- `displayCourseInfo()` — displays the course's information and all enrolled students info


## Console Output 


Course: CS101 - Introduction to Programming  
Max Students: 3  
Currently Enrolled: Omar Nabil (ID: 2202)  

Instructor Info:  
Name: Dr. Lina Khaled  
Department: Computer Science  
Experience: 5 years  

Student Info:  
Name: Omar Nabil  
Year: 2  
Major: Informatics


## Deliverables

1. **Header files** for each of the mentioned classes.

2. **A single source file (main.cpp)** containing:
   - All class implementations
   - A `main()` function that demonstrates:
     - Creating objects of Student, Instructor, and Course
     - Adding students to a course
     - Display all course, instructor and student information in the **exact** same format shown in the console output above.

3. **Edit your information** in text file named **yourInformation.txt** following the same format: **TutorialNumber_StudentID_StudentName** 
Example: T2_16007163_Ahmed Mohamed


## Important Notes

- **Cheating = 0 in the assignment**
- **AI-generated code = 0 in the project**
- Each class must include:
  - A default constructor
  - A parameterized constructor
  - A destructor (even if empty)
- **All attributes must be private, and data access must be controlled through setter and getter methods.**

 


