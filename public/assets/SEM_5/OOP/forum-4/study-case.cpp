#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;

// Kasus pertama: Menampilkan angka berdasarkan kelipatan 3, 5, dan 7
class MultiplicityNumbers {
public:
    void showNumbers(int n) {
        cout << "Numbers based on multiplicity 3, 5, and 7:" << endl;
        for (int i = 1; i <= n; ++i) {
            if (i % 3 == 0 || i % 5 == 0 || i % 7 == 0) {
                cout << i << ", ";
            }
        }
        cout << endl;
    }
};

// Kasus kedua: Menampilkan daftar siswa berdasarkan nilai dalam urutan menurun
class Student {
public:
    string name;
    string subject;
    int score;
    string grade;
    string description;

    Student(string n, string sub, int s) : name(n), subject(sub), score(s) {
        grade = calculateGrade();
        description = getGradeDescription();
    }

    string calculateGrade() {
        if (score >= 90)
            return "A";
        else if (score >= 85)
            return "A-";
        else if (score >= 80)
            return "B+";
        else if (score >= 75)
            return "B";
        else if (score >= 70)
            return "B-";
        else if (score >= 65)
            return "C";
        else if (score >= 50)
            return "D";
        else if (score >= 0)
            return "E";
        else
            return "F";
    }

    string getGradeDescription() {
        static const map<string, string> gradeDescription = {
            {"A", "High Distinction"},
            {"A-", "High Distinction"},
            {"B+", "High Distinction"},
            {"B", "Distinction"},
            {"B-", "Distinction"},
            {"C", "Pass"},
            {"D", "Near Pass"},
            {"E", "Fail"}
        };

        auto it = gradeDescription.find(grade);
        if (it != gradeDescription.end()) {
            return it->second;
        } else {
            return "Incomplete";
        }
    }
};

bool compareByGrade(const Student &a, const Student &b) {
    return a.grade > b.grade;
}

class StudentList {
public:
    void showStudentList(vector<Student> &students) {
        sort(students.begin(), students.end(), compareByGrade);
        cout << "List of students order by grade descending:" << endl;
        for (const auto &student : students) {
            cout << "Name: " << student.name << ", Subject: " << student.subject << ", Score: " << student.score << ", Grade: " << student.grade << ", Description: " << student.description << endl;
        }
    }
};

// Kasus ketiga: Menampilkan apakah sebuah angka adalah ganjil/genap dan bilangan prima
class NumberProperties {
public:
    bool isPrime(int num) {
        if (num <= 1)
            return false;
        for (int i = 2; i <= sqrt(num); ++i) {
            if (num % i == 0)
                return false;
        }
        return true;
    }

    void showNumberProperties(int num) {
        cout << num << " is ";
        if (num % 2 == 0)
            cout << "Even";
        else
            cout << "Odd";

        if (isPrime(num))
            cout << " and Prime." << endl;
        else
            cout << " and Not Prime." << endl;
    }
};

int main() {
    // Kasus Pertama
    MultiplicityNumbers mn;
    cout << "Case 1: " << endl;
    mn.showNumbers(21); // Contoh angka 21

    // Kasus Kedua
    StudentList sl;
    cout << "\nCase 2: " << endl;
    vector<Student> students = {
        {"John", "Computer", 100},
        {"John", "Math", 95},
        {"Alice", "Physics", 88},
        {"Bob", "Biology", 72},
        {"Mom", "Math", 60},
        {"Ace", "Physics", 51},
        {"Kone", "Physics", 42},
        {"Rew", "Physics", 33},
        {"Luffy", "Biology", 24},
        {"Kuro", "Math", 15},
        {"Hige", "Biology", 0},
    };
    sl.showStudentList(students);

    // Kasus Ketiga
    NumberProperties np;
    cout << "\nCase 3: " << endl;
    np.showNumberProperties(13); // Contoh angka 13

    return 0;
}
