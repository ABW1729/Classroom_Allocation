# 🎓 Classroom Allocation System (C++ with B+ Tree)

A **menu-driven C++ project** for managing classrooms, courses, and student allocations.  
It uses **B+ Tree indexing** for efficient storage and retrieval of schedules, supporting operations like adding/deleting courses, managing students, and allocating classrooms for exams.

---

## 🚀 Features
- Add / Delete Students  
- Add / Delete Courses  
- Create and Manage Course List  
- Allocate Classrooms (based on capacity & availability)  
- Exam Allotment Module  
- View Existing Allocations  

---

## 🛠️ Tech Stack
- **Language:** C++ (C++11/14 standard)  
- **Data Structures:** B+ Tree for indexing classrooms  
- **Paradigm:** Object-Oriented, Modularized code  

---

## 📂 Project Structure
```
.
├── main.cpp                  # Menu-driven driver program
├── allocation.h              # Combined header file for all functions
├── exam_allotment.cpp        # Exam allocation logic
├── add_delete_student.cpp    # Student add/remove functionality
├── classroom_allotment.cpp   # Classroom allocation logic
├── course_add.cpp            # Add courses
├── course_delete_and_id.cpp  # Delete courses & handle IDs
├── course_include.cpp        # Course inclusion utilities
├── course_list_creator.cpp   # Creates course list
```

---

## ▶️ How to Run
### Compile
```bash
g++ main.cpp exam_allotment.cpp add_delete_student.cpp classroom_allotment.cpp course_add.cpp course_delete_and_id.cpp course_include.cpp course_list_creator.cpp -o classroom_allocation
```

### Run
```bash
./classroom_allocation
```

---

## 📖 Menu Options
The program is **menu-driven**. On running, you’ll see options like:

```
===== Classroom Allocation System =====
1. Add Student
2. Delete Student
3. Add Course
4. Delete Course
5. Create Course List
6. Allocate Classroom
7. Exam Allotment
8. Exit
======================================
```

---

## ✅ Future Improvements
- Add GUI (Qt or React frontend + C++ backend API).  
- Integrate Database (Postgres / MySQL) instead of flat file storage.  
- Enhance Scheduling with ML-based optimization.  
