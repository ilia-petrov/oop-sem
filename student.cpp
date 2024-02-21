#include <iostream>
#include <cstring>
const int MAX_LENGTH = 128;

struct Student
{
    char name[MAX_LENGTH];
    char surname[MAX_LENGTH];
    char EGN[10];

    bool operator ==(const Student& other) const
    {
        return strcmp(name, other.name) == 0 &&
               strcmp(surname, other.surname) == 0 &&
               strcmp(EGN, other.EGN) == 0;
    }
};

struct University
{
    Student students[MAX_LENGTH];
    int numberOfStudents;


    bool hasStudent(const Student& student) const
    {
        for(int i = 0; i < numberOfStudents; ++ i)
        {
            if(student == students[i])
            {
                return true;
            }
        }
        return false;
    }

    bool addStudent(const Student& student)
    {
        if(numberOfStudents == MAX_LENGTH)
        {
            return false;
        }

        strcpy(students[numberOfStudents].name, student.name);
        strcpy(students[numberOfStudents].surname, student.surname);
        strcpy(students[numberOfStudents].EGN, student.EGN);

        ++ numberOfStudents;

        return true;
    }
};