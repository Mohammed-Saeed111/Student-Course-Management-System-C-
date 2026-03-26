# 🎓 Student Course Management System (C++)

## 📌 Overview
This is a console-based C++ application that manages students and their enrolled courses.  
The system demonstrates Object-Oriented Programming (OOP) concepts and uses the Standard Template Library (STL).

---

## 🚀 Features

- Add Student (ID, Name, GPA)
- Remove Student by ID
- Search Student by ID
- Display All Students
- Enroll Student in Courses
- Show Student Courses
- Sort Students by GPA
- Save Data to File
- Load Data from File

---

## 🧠 Concepts Used

### ✅ OOP
- Classes & Objects
- Inheritance
- Encapsulation
- Constructors
- Member Functions

### ✅ STL
- vector (for storing students)
- set (to avoid duplicate courses)

### ✅ Algorithms
- find_if (searching)
- sort (sorting students by GPA)

---

## 📂 File Handling
- Data is saved in `students.txt`
- Data is automatically loaded when the program starts

---

## 🖼 UML Diagram
## 🖼 UML Diagram

The UML diagram shows all classes, attributes, methods, and inheritance relationships.

![UML Diagram](https://drive.google.com/uc?export=view&id=1rYNh7GShbdWnLEQAxkZHueMIdsB2LDfC)
---

## ⚙️ How to Run

1. Open project in VS Code
2. Compile:

g++ main.cpp -o app

3. Run:

./app


---

## 📌 Constraints

- Student ID must be unique
- GPA must be between 0.0 and 4.0
- Courses are not duplicated (using set)
- Invalid input is handled

---

## 🎯 Example


Enter ID: 1001
Enter Name: Mohamed Saeed
Enter GPA: 3.5

Student added successfully


---

## 💡 Bonus Features

- File Save & Load
- Input Validation
- Prevent Duplicate Courses

---

## 👨‍💻 Author
Mohamed Saeed Abdel Haleem
