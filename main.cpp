#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <fstream>
#include <sstream>

using namespace std;

<<<<<<< HEAD
// ================ Person Class =================
=======
// ================= Person Class =================
>>>>>>> c248ad95fa99e58b77cf81154490098769ead3c5
class Person {
protected:
    string name;
};

<<<<<<< HEAD
// ================ Student Class =================
=======
// ================= Student Class =================
>>>>>>> c248ad95fa99e58b77cf81154490098769ead3c5
class Student : public Person {
private:
    int id;
    double gpa;
    set<string> courses;

public:
    Student(int i, string n, double g) {
        id = i;
        name = n;
        gpa = g;
    }

    int getId() const { return id; }
    double getGpa() const { return gpa; }
    string getName() const { return name; }
    set<string> getCourses() const { return courses; }

    void display() const {
        cout << "ID: " << id
             << " | Name: " << name
             << " | GPA: " << gpa << endl;
    }

    void addCourse(string course) {
        courses.insert(course);
    }

    void showCourses() const {
        if (courses.empty()) {
            cout << "No courses enrolled\n";
            return;
        }

        cout << "Courses: ";
        for (const auto& c : courses) {
            cout << c << " ";
        }
        cout << endl;
    }

    // لتحميل الكورسات من الملف
    void setCourses(set<string> c) {
        courses = c;
    }
};

// ================= Helper =================
void clearInput() {
    cin.clear();
    cin.ignore(1000, '\n');
}

// ================= Functions =================

// Add Student
void addStudent(vector<Student>& students) {
    int id;
    string name;
    double gpa;

    cout << "Enter ID: ";
    if (!(cin >> id)) {
        clearInput();
        cout << "Invalid ID!\n";
        return;
    }

    // Check ID uniqueness
    for (const auto& s : students) {
        if (s.getId() == id) {
            cout << "ID already exists!\n";
            return;
        }
    }

    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, name);

    cout << "Enter GPA: ";
    if (!(cin >> gpa)) {
        clearInput();
        cout << "Invalid GPA!\n";
        return;
    }

    if (gpa < 0 || gpa > 4) {
        cout << "GPA must be between 0 and 4!\n";
        return;
    }

    students.emplace_back(id, name, gpa);
    cout << "Student added successfully\n";
}

// Remove Student
void removeStudent(vector<Student>& students) {
    int id;
    cout << "Enter ID to remove: ";

    if (!(cin >> id)) {
        clearInput();
        cout << "Invalid input!\n";
        return;
    }

    auto it = remove_if(students.begin(), students.end(),
        [&](const Student& s) { return s.getId() == id; });

    if (it != students.end()) {
        students.erase(it, students.end());
        cout << "Removed successfully\n";
    } else {
        cout << "Student not found\n";
    }
}

// Search Student
void searchStudent(vector<Student>& students) {
    int id;
    cout << "Enter ID to search: ";

    if (!(cin >> id)) {
        clearInput();
        cout << "Invalid input!\n";
        return;
    }

    auto it = find_if(students.begin(), students.end(),
        [&](const Student& s) {
            return s.getId() == id;
        });

    if (it != students.end()) {
        it->display();
    } else {
        cout << "Student not found\n";
    }
}

// Display All
void displayAll(vector<Student>& students) {
    if (students.empty()) {
        cout << "No students available\n";
        return;
    }

    for (const auto& s : students) {
        s.display();
    }
}

// Enroll Course
void enrollCourse(vector<Student>& students) {
    int id;
    string course;

    cout << "Enter Student ID: ";
    if (!(cin >> id)) {
        clearInput();
        cout << "Invalid input!\n";
        return;
    }

    cin.ignore();
    cout << "Enter Course Name: ";
    getline(cin, course);

    auto it = find_if(students.begin(), students.end(),
        [&](const Student& s) {
            return s.getId() == id;
        });

    if (it != students.end()) {
        it->addCourse(course);
        cout << "Course added successfully\n";
    } else {
        cout << "Student not found\n";
    }
}

// Show Courses
void showCourses(vector<Student>& students) {
    int id;
    cout << "Enter Student ID: ";

    if (!(cin >> id)) {
        clearInput();
        cout << "Invalid input!\n";
        return;
    }

    auto it = find_if(students.begin(), students.end(),
        [&](const Student& s) {
            return s.getId() == id;
        });

    if (it != students.end()) {
        it->showCourses();
    } else {
        cout << "Student not found\n";
    }
}

// Sort Students
void sortStudents(vector<Student>& students) {
    sort(students.begin(), students.end(),
        [](const Student& a, const Student& b) {
            return a.getGpa() > b.getGpa();
        });

    cout << "Students sorted by GPA\n";
}

// Save to File (CSV Format)
void saveToFile(const vector<Student>& students) {
    ofstream file("students.txt");

    for (const auto& s : students) {
        file << s.getId() << ","
             << s.getName() << ","
             << s.getGpa() << ",";

        // courses
        auto courses = s.getCourses();
        bool first = true;
        for (const auto& c : courses) {
            if (!first) file << "|";
            file << c;
            first = false;
        }

        file << endl;
    }

    file.close();
}

// Load from File
void loadFromFile(vector<Student>& students) {
    ifstream file("students.txt");
    if (!file) return;

    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        string idStr, name, gpaStr, coursesStr;

        getline(ss, idStr, ',');
        getline(ss, name, ',');
        getline(ss, gpaStr, ',');
        getline(ss, coursesStr);

        int id = stoi(idStr);
        double gpa = stod(gpaStr);

        Student s(id, name, gpa);

        // parse courses
        stringstream cs(coursesStr);
        string course;
        set<string> courseSet;

        while (getline(cs, course, '|')) {
            if (!course.empty())
                courseSet.insert(course);
        }

        s.setCourses(courseSet);
        students.push_back(s);
    }

    file.close();
}

// ================= MAIN =================
int main() {
    vector<Student> students;

    loadFromFile(students);

    int choice;

    do {
        cout << "\n===== Student Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. Remove Student\n";
        cout << "3. Search Student\n";
        cout << "4. Display All Students\n";
        cout << "5. Enroll Course\n";
        cout << "6. Show Student Courses\n";
        cout << "7. Sort Students by GPA\n";
        cout << "8. Exit\n";
        cout << "Enter choice: ";

        if (!(cin >> choice)) {
            clearInput();
            cout << "Invalid choice!\n";
            continue;
        }

        switch (choice) {
            case 1: addStudent(students); break;
            case 2: removeStudent(students); break;
            case 3: searchStudent(students); break;
            case 4: displayAll(students); break;
            case 5: enrollCourse(students); break;
            case 6: showCourses(students); break;
            case 7: sortStudents(students); break;
            case 8: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }

    } while (choice != 8);

    saveToFile(students);

    return 0;
}


