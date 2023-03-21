//-----------------DSPD ASSIGNMENT-------------------//
// Code By BT21CSE087 Aniket Wani

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define MAX_STUDENTS 100
#define MAX_COURSES 10
#define MAX_CLASSROOMS 10
#define ROWS 4
#define SEATS_PER_ROW 3
#define MAX_SLOTS 10

// Structures
typedef struct course
{

    char course_name[10];
    int slot;
    int semester;
    int num_students;
    int classroom_number;
    struct student *students_Course; // Linked list of students taking this course
    struct course *next;
} Course;

typedef struct student
{
    char name[50];
    int enrollment_num;
    int num_courses;
    int seat_row, seat_col;
    char courses[5][10];
    int slots[MAX_SLOTS];
    struct student *next;

} Student;

typedef struct classroom
{
    int number;
    int capacity;
    int num_courses;
    int seat[ROWS][SEATS_PER_ROW];
    char course_course_names[MAX_COURSES][10];
    struct classroom *next;
} Classroom;

// Global variables
Student *students[MAX_STUDENTS];
int num_students = 0;

Course courses[MAX_COURSES] = {
    {"DSPD", 1}, {"CPL", 2}, {"IOOM", 2}, {"CO", 3}, {"DSPD2", 4}, {"COMM", 5}, {"MATH1", 5}, {"MATH2", 6}};
int num_courses = 0;

Classroom *classrooms[MAX_CLASSROOMS];
int num_classrooms = 0;

Course *courses_head = NULL;

Student *students_head = NULL;

// Function to add a course to the course Course
void add_course()
{
    int name;
    int slot;
    struct course *temp = &courses_head;
    printf("Enter name of course to be added\n");
    scanf("%s", name);
    printf("Enter slot of the course\n");
    scanf("%d", &slot);

    // Allocate memory for the new course
    struct course *new_course = (struct course *)malloc(sizeof(struct course));

    strcpy(new_course->course_name, name);
    new_course->slot = slot;
    new_course->num_students = 0;
    new_course->students_Course = NULL;
    new_course->next = NULL;

    // Add the new course to the Course
    if (temp == NULL)
    {
        // If the Course is empty, make the new course the head of the Course
        temp = new_course;
    }
    else // Traverse courses Course till end
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_course;
    }
}

// returns the slot number of a course given its course_name
int course_slot(char course_name)
{
    for (int i = 0; i < num_courses; i++)
    {
        if (strcmp(course_name, courses[i].course_name) == 0)
        {
            return courses[i].slot;
        }
    }
    return -1;
}

// adds a student to a course
void add_student_to_course(Course *course, Student *new_student)
{
    // Check if the course already has the maximum number of students
    if (course->num_students == MAX_STUDENTS)
    {
        printf("Error: Course %s is full, cannot add student %s\n", course->course_name, new_student->name);
        return;
    }

    // Add the student to the course's students Course
    Student *temp_student = course->students_Course;
    if (temp_student == NULL)
    {
        course->students_Course = new_student;
    }
    else
    {
        while (temp_student->next != NULL)
        {
            temp_student = temp_student->next;
        }
        temp_student->next = new_student;
    }

    // Increment the number of students in the course
    course->num_students++;

    printf("Successfully added student %s to course %s\n", new_student->name, course->course_name);
}

int check_same_slot(int slots[], int slot)
{
    for (int y = 0; y < 5; y++)
    {
        if (slots[y] == slot)
        {
            return -1;
        }
    }
    return 0;
}

void add_student()
{
    struct student *new_student = (Student *)malloc(sizeof(Student));
    struct student *temp = &students_head;
    struct course *course_temp = &courses_head;
    int name, p = 0;
    char course_name[10];
    int enrollment_number;
    printf("Enter name of student to be added\n");
    scanf("%s", new_student->name);
    printf("Enter enrollment number of the student\n");
    scanf("%d", &enrollment_number);
    while (temp != NULL)
    {
        if (strcmp(temp->enrollment_num, new_student->enrollment_num) == 0)
        {
            printf("Error: Enrollment No. %s already exists.\n", new_student->enrollment_num);
            return;
        }
        temp = temp->next;
    }

    new_student->enrollment_num = enrollment_number;
    for (int k = 0; k < 5; k++)
    {
        printf("Enter Course name %d", k + 1);
        scanf("%s", new_student->courses[k]);
        for (int j = 0; j < 5; j++)
        {
            if (strcmp(course_name, courses[j].course_name) == 0)
            {
                if (check_same_slot(new_student->slots, course_slot(course_name)) == 0)
                {
                    new_student->slots[p++] = courses[j].slot;
                }
                else
                {
                    printf("Cant assign two courses from same slot\n");
                    return;
                }
            }
        }
    }

    new_student->next = NULL;

    if (students_head == NULL)
    {
        students_head = new_student;
        printf("Student added successfully!\n");
        return;
    }

    if (temp->next == NULL)
    {
        temp->next = new_student;
    }
    // add the student to the courses they are taking
    for (int i = 0; i < num_courses; i++)
    {
        Course *course = &courses_head;
        while (course != NULL)
        {
            if (strcmp(course->course_name, new_student->courses[i]) == 0)
            {
                add_student_to_course(course, new_student);
                break;
            }
            course = course->next;
        }
    }

    printf("Student %s added successfully! \n", name);
}

// Function to remove a student from a course
void remove_student_from_course(Course *c, Student *s)
{
    // Remove course from student's course Course
    int i, j;
    for (i = 0; i < s->num_courses; i++)
    {
        if (strcmp(c->course_name, s->courses[i]) == 0)
        {
            // Course found, remove it from Course
            for (j = i; j < s->num_courses - 1; j++)
            {
                strcpy(s->courses[j], s->courses[j + 1]);
            }
            s->num_courses--;
            break;
        }
    }

    // Remove student from course's student Course
    Student *curr = c->students_Course;
    Student *prev = NULL;
    while (curr != NULL)
    {
        if (curr == s)
        {
            if (prev == NULL)
            {
                c->students_Course = curr->next;
            }
            else
            {
                prev->next = curr->next;
            }
            c->num_students--;
            break;
        }
        prev = curr;
        curr = curr->next;
    }
}

// Function to delete a student from the student Course
void delete_student()
{
    int enrollment_number;
    printf("Enter Enrollment number of student to delete\n");
    scanf("%d", enrollment_number);
    // Check if there are any students to delete
    int count = 0;
    Student *s;
    Student **pptr = &students_head;
    while (*pptr != NULL)
    {
        count++;
        s = *pptr;
        pptr = &((*pptr)->next);
    }
    int num_students = count;
    if (num_students == 0)
    {
        printf("No students to delete.\n");
        return;
    }
    // Remove student from student Course
    if (students_head->enrollment_num == enrollment_number)
    {
        // Student is the first element in the Course
        *pptr = students_head->next;
        free(students_head);
        printf("Student with enrollment number %d deleted\n", enrollment_number);
        num_students--;
        return;
    }
    Student *prev = students_head;
    Student *curr = students_head->next;
    while (curr != NULL)
    {
        if (curr->enrollment_num == enrollment_number)
        {
            // Remove student from courses they are taking
            int j;
            Course *c;
            for (j = 0; j < curr->num_courses; j++)
            {
                c = curr->courses[j];
                if (c != NULL)
                {
                    remove_student_from_course(c, curr);
                }
            }
            // Remove student from student Course
            prev->next = curr->next;
            free(curr);
            printf("Student with enrollment number %d deleted\n", enrollment_number);
            num_students--;
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    printf("Student not found\n");
}

int count_students(char *course_name)
{
    int count = 0;
    for (int i = 0; i < num_courses; i++)
    {
        if (strcmp(course_name, courses[i].course_name) == 0)
        {
            Student *current_student = &students_head;
            while (current_student != NULL)
            {
                for (int j = 0; j < 5; j++)
                {
                    if (strcmp(current_student->courses[j], course_name) == 0)
                    {
                        count++;
                        break;
                    }
                }
                current_student = current_student->next;
            }
            break;
        }
    }
    // printf("/n %d /n", count);
    return count;
}
// remove the student from the students Course

// Function to delete a course from the course Course
void delete_course()
{
    char course_name_supplied;
    printf("Enter course name to delete\n");
    scanf("%s", course_name_supplied);
    int count = 0;
    // Find the course to be deleted
    struct course *prev = NULL;
    struct course *curr = &courses_head;
    // Check if any of the students have taken the course

    while (curr != NULL && curr->course_name != course_name_supplied)
    {
        prev = curr;
        curr = curr->next;
    }
    // If the course was not found, return
    if (curr == NULL)
    {
        printf("Course not found!\n");
        return;
    }

    // Check if any of the students have taken the course
    count = count_students(curr->course_name);
    if (count == 0)
    {
        if (prev == NULL)
        {
            // If the course is the head of the Course
            courses_head = curr->next;
        }
        else
        {
            prev->next = curr->next;
        }
        // Free memory for the deleted course
        free(curr);
    }
    else
    {
        printf("%d students have already taken the course\n", count);
    }
}

// return number of courses in a Course
int count_courses(Course *courses)
{
    int count = 0;
    while (courses != NULL)
    {
        count++;
        courses = courses->next;
    }
    return count;
}

// return number of courses in a Course that are in the same slot
int count_slot_courses(Course *courses, int slot)
{
    int count = 0;
    while (courses != NULL)
    {
        if (courses->slot == slot)
        {
            count++;
        }
        courses = courses->next;
    }
    return count;
}

// check if a course can be allotted a given slot in a given classroom
int check_slot_allotment(Course *course, Classroom *classroom, int slot)
{
    int allotted = 0;
    for (int i = 0; i < num_classrooms; i++)
    {
        if (strcmp(classroom[i].course_course_names[0], "") == 0 || strcmp(classroom[i].course_course_names[0], course->course_name) == 0)
        {
            if (classroom[i].capacity >= course->num_students && count_slot_courses(course->students_Course, slot) == 0)
            {
                allotted = 1;
                break;
            }
        }
    }
    return allotted;
}

// return the slot number of a course
int course_slot(Course *course)
{
    return course->slot;
}

// return the course that comes first in a given slot
Course *slot_first_course(Course *courses, int slot)
{
    Course *first_course = NULL;
    while (courses != NULL)
    {
        if (courses->slot == slot)
        {
            if (first_course == NULL || courses->num_students < first_course->num_students)
            {
                first_course = courses;
            }
        }
        courses = courses->next;
    }
    return first_course;
}

int get_course_index(char course_name, int num_courses)
{
    for (int i = 0; i < num_courses; i++)
        if (strcmp(course_name, courses[i].course_name == 0))
        {
            return i;
        }
    return -1;
}
void allot_classrooms(Course *courses_Course, Classroom *classrooms_Course)
{
    // create an array to keep track of which courses have been allotted a classroom
    int num_courses = count_courses(courses_Course);
    int *allotted = (int *)calloc(num_courses, sizeof(int));

    // iterate over all the classrooms and allot courses to them
    Classroom *classroom = classrooms_Course;
    while (classroom != NULL)
    {
        // iterate over all the slots for this classroom and allot courses to them
        for (int slot = 1; slot <= MAX_SLOTS; slot++)
        {
            // create an array to keep track of which courses in this slot have been allotted a classroom
            int num_slot_courses = count_slot_courses(courses_Course, slot);
            int *slot_allotted = (int *)calloc(num_slot_courses, sizeof(int));

            // iterate over all the courses in this slot and allot classrooms to them
            Course *course = courses_Course;
            while (course != NULL)
            {
                if (course->slot == slot)
                {
                    // check if the course has already been allotted a classroom
                    if (allotted[get_course_index(course->course_name, num_courses)] == 1)
                    {
                        course = course->next;
                        continue;
                    }

                    // check if the course can be allotted to this classroom
                    if (count_students(course) > classroom->capacity)
                    {
                        course = course->next;
                        continue;
                    }

                    // check if any other course in this slot has been allotted the same classroom
                    if (check_slot_allotment(classroom, slot, course))
                    {
                        course = course->next;
                        continue;
                    }

                    // if all conditions are satisfied, allot the classroom to the course
                    strcpy(classroom->course_course_names[classroom->num_courses], course->course_name);
                    classroom->num_courses++;
                    course->classroom_number = classroom->number;
                    allotted[get_course_index(course->course_name, num_courses)] = 1;
                    slot_allotted[get_course_index(course->course_name, num_slot_courses)] = 1;
                }
                course = course->next;
            }

            // if no courses in this slot were allotted a classroom, print an error message
            if (count_slot_allotment(classroom, slot, courses_Course) == 0)
            {
                printf("Error: No classroom available for slot %d\n", slot);
            }

            free(slot_allotted);
        }
        classroom = classroom->next;
    }

    free(allotted);
}

// helper function to check if two students are in the same course
int same_course(Student *s1, Student *s2, char *course_course_name)
{
    for (int i = 0; i < s1->num_courses; i++)
    {
        if (strcmp(s1->courses[i], course_course_name) == 0)
        {
            for (int j = 0; j < s2->num_courses; j++)
            {
                if (strcmp(s2->courses[j], course_course_name) == 0)
                {
                    return 1;
                }
            }
            break;
        }
    }
    return 0;
}

// helper function to check if two students are adjacent
int is_adjacent(Student *s1, Student *s2)
{
    return (abs(s1->seat_row - s2->seat_row) <= 1 &&
            abs(s1->seat_col - s2->seat_col) <= 1);
}

void allot_seat_for_exam(Course *courses, int num_courses, Classroom *classrooms, int num_classrooms, int slot)
{
    // first, assign seats to all students in each course
    for (int i = 0; i < num_courses; i++)
    {
        Course *course = &courses[i];
        if (course->slot == slot)
        {
            Student *temp = course->students_Course;
            int seat_row = 1, seat_col = 1;
            while (temp != NULL)
            {
                // find a free seat in any classroom
                int seat_found = 0;
                for (int j = 0; j < num_classrooms; j++)
                {
                    Classroom *classroom = &classrooms[j];
                    if (strcmp(classroom->course_course_names[0], course->course_name) == 0)
                    {
                        // skip classrooms that are not assigned to this course
                        int num_rows = (classroom->capacity + SEATS_PER_ROW - 1) / SEATS_PER_ROW;
                        for (int r = 1; r <= num_rows; r++)
                        {
                            for (int c = 1; c <= SEATS_PER_ROW; c++)
                            {
                                int is_occupied = 0;
                                // check if any adjacent seats are occupied by students of the same course
                                Student **students_Course = course->students_Course;
                                while (*students_Course != NULL)
                                {
                                    if (*students_Course != temp && is_adjacent(*students_Course, temp))
                                    {
                                        is_occupied = 1;
                                        break;
                                    }
                                    *students_Course = (*students_Course)->next;
                                }
                                if (!is_occupied)
                                {
                                    temp->seat_row = seat_row;
                                    temp->seat_col = seat_col;
                                    seat_found = 1;
                                    break;
                                }
                                seat_col++;
                            }
                            if (seat_found)
                            {
                                break;
                            }
                            seat_row++;
                            seat_col = 1;
                        }
                        if (seat_found)
                        {
                            break;
                        }
                    }
                }
                if (!seat_found)
                {
                    printf("Error: no seat available for student %s in course %s\n", temp->name, course->course_name);
                }
                temp = temp->next;
            }
        }
    }
}

// Main function
int main()
{
    int choice;
    do
    {
        printf("\n--- MENU ---\n");
        printf("1. Add student\n");
        printf("2. Delete student\n");
        printf("3. Add course\n");
        printf("4. Delete course\n");
        printf("5. Allot classrooms for lectures\n");
        printf("6. Allot classrooms for exams\n");
        printf("7. Print exam seats\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:

            add_student();
            break;
        case 2:
            delete_student();
            break;
        case 3:
            add_course();
            break;
        case 4:
            delete_course();
            break;
        case 5:
            allot_classrooms_for_lectures();
            break;
        case 6:
            allot_classrooms_for_exams();
            break;
        case 7:
            print_exam_seats();
            break;
        case 8:
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice, please try again.\n");
            break;
        }
    } while (choice != 8);
    return 0;
}
