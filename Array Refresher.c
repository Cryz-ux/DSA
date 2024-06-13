#include <stdio.h>
#include <string.h>

typedef struct {
    char fname[20];
    char lname[20];
} studName;

typedef struct {
    int month;
    int year;
} bday;

typedef struct {
    studName name;
    bday birthdate;
    int age;
    int idnum;
} studentInfo;

typedef struct {
    studentInfo studList[20];
    int studCount;
} classRecord;

void insertStudent(classRecord *classRec, studentInfo newStudent) {
    if (classRec->studCount < 20) {
        classRec->studList[classRec->studCount++] = newStudent;
        printf("Student inserted successfully.\n");
    } else {
        printf("Class record is full. Cannot insert more students.\n");
    }
}

void printStudentInfo(classRecord classRec) {
    printf("Student Information:\n");
    printf("----------------------------------------------------\n");
    printf("ID\tFirst Name\tLast Name\tBirthdate\tAge\n");
    printf("----------------------------------------------------\n");
    for (int i = 0; i < classRec.studCount; i++) {
        printf("%d\t%s\t\t%s\t\t%d/%d\t\t%d\n", 
               classRec.studList[i].idnum, 
               classRec.studList[i].name.fname, 
               classRec.studList[i].name.lname, 
               classRec.studList[i].birthdate.month,
               classRec.studList[i].birthdate.year, 
               classRec.studList[i].age);
    }
    printf("----------------------------------------------------\n");
}

void deleteStudentByID(classRecord *classRec, int id) {
    int found = 0;
    for (int i = 0; i < classRec->studCount; i++) {
        if (classRec->studList[i].idnum == id) {
            found = 1;

            for (int j = i; j < classRec->studCount - 1; j++) {
                classRec->studList[j] = classRec->studList[j + 1];
            }
            classRec->studCount--; 
            printf("Student with ID %d deleted successfully.\n", id);
            break;
        }
    }
    if (!found) {
        printf("Student with ID %d not found.\n", id);
    }
}


int main() {
    classRecord myClass = {{}, 0};

    studentInfo newStudent1 = {{"John", "Doe"}, {10, 2000}, 24, 1001};
    insertStudent(&myClass, newStudent1);
    
    studentInfo newStudent2 = {{"Yani", "Castro"}, {03, 2003}, 21, 1002};
    insertStudent(&myClass, newStudent2);
    
    printStudentInfo(myClass);
    
    deleteStudentByID(&myClass, 1001);

    printf("\nAfter deletion:\n");
    printStudentInfo(myClass);


    return 0;
}

