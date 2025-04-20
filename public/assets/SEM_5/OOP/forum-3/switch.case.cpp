 // fig04_06.cpp
 2   // Using a switch statement to count letter grades.
 3   #include <iostream>
 4   #include <iomanip>
 5   using namespace std;
 6
 7   int main() {
 8      int total{0}; // sum of grades
 9      int gradeCounter{0}; // number of grades entered
10      int aCount{0}; // count of A grades
11      int bCount{0}; // count of B grades
12      int cCount{0}; // count of C grades
13      int dCount{0}; // count of D grades
14      int fCount{0}; // count of F grades
15
16      cout << "Enter the integer grades in the range 0-100.\n"
17         << "Type the end-of-file indicator to terminate input:\n"
18         << " On UNIX/Linux/macOS type <Ctrl> d then press Enter\n"
19         << " On Windows type <Ctrl> z then press Enter\n";
20
21      int grade;
22
23      // loop until user enters the end-of-file indicator
24      while (cin >> grade) {
25         total += grade; // add grade to total
26         ++gradeCounter; // increment number of grades
27
28         // increment appropriate letter-grade counter
29         switch (grade / 10) {
30            case 9: // grade was between 90
31            case 10: // and 100, inclusive
32               ++aCount;
33               break; // exits switch
34
35            case 8: // grade was between 80 and 89
36               ++bCount;
37               break; // exits switch
38
39            case 7: // grade was between 70 and 79
40               ++cCount;
41               break; // exits switch
42
43            case 6: // grade was between 60 and 69
44               ++dCount;
45               break; // exits switch
46
47            default: // grade was less than 60
48               ++fCount;
49               break; // optional; exits switch anyway
50         } // end switch
51      } // end while
52
53      // set floating-point number format
54      cout << fixed << setprecision(2);
55
56      // display grade report
57      cout << "\nGrade Report:\n";
58
59      // if user entered at least one grade...
60      if (gradeCounter != 0) {
61         // calculate average of all grades entered
62         double average{static_cast<double>(total) / gradeCounter};
63
64         // output summary of results
65         cout << "Total of the " << gradeCounter << " grades entered is "
66            << total << "\nClass average is " << average
67            << "\nNumber of students who received each grade:"
68            << "\nA: " << aCount << "\nB: " << bCount << "\nC: " << cCount
69            << "\nD: " << dCount << "\nF: " << fCount << "\n";
70      }
71      else { // no grades were entered, so output appropriate message
72         cout << "No grades were entered" << "\n";
73      }
74   }