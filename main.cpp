#include <iostream>
using namespace std;

#include "allocation.h"

int main() {
    int choice;
    while (true) {
        cout << "\n===== Classroom Allocation System =====\n";
        cout << "1. Add Student\n";
        cout << "2. Delete Student\n";
        cout << "3. Add Course\n";
        cout << "4. Delete Course\n";
        cout << "5. Create Course List\n";
        cout << "6. Allocate Classroom\n";
        cout << "7. Exam Allotment\n";
        cout << "8. Exit\n";
        cout << "======================================\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: deleteStudent(); break;
            case 3: addCourse(); break;
            case 4: deleteCourse(); break;
            case 5: createCourseList(); break;
            case 6: allocateClassroom(); break;
            case 7: examAllotment(); break;
            case 8: cout << "Exiting...\n"; return 0;
            default: cout << "Invalid choice! Try again.\n";
        }
    }
}
