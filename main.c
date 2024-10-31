#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MaxNumOfStudents 100
// welcome to jacobs kino coding tutorial

struct Student {
    int id;
    char name[100];
    int age;
    double grade;
};

int main() {
    // arrays
    struct Student students[MaxNumOfStudents];

    // size of
    int numOfStudents = 0;



    // The program should start by welcoming the user 
    // and then continuously display the menu after each operation, until the user chooses to exit.
    printf("welcome!\n");

    while (1)
    {
        // value for selecting the menu
        int menuValue = 0;

        //menu
        printf("----- menu -----\n");
        printf("print all students - 1\n");
        printf("add new student - 2\n");
        printf("remove student by id - 3\n");
        printf("grade statistics - 4\n");
        printf("quit - 5\n");
        scanf("%d", &menuValue);

        
        if (menuValue == 1) {
            // Display the details (ID, Name, Age, and Grade) of all the students currently in the system.
            for (int i = 0; i < numOfStudents; i++) {
                {
                    printf("ID: %d\n", students[i].id);
                    printf("Name: %s\n", students[i].name);
                    printf("Age: %d\n", students[i].age);
                    printf("Grade: %.2f\n", students[i].grade); // note to self: %.2f is the amount of decimal spaces you want it to print
                }
            }
        }else if (menuValue == 2){
            // Allow the user to enter details for a new student, making sure the ID is unique.
            // Ensure that the student’s name is no longer than 40 characters
            // and the age and grade are within reasonable ranges. If the list is full (100 students),
            // the program should inform the user that no more students can be added.


            //maxed out check

            if (numOfStudents >= MaxNumOfStudents) {
                printf("Too many students!, max amount reached!\n");
                continue;
            }
            //id input and validation
            while (1)
            {
                int idInput = 0;
                printf("enter the id of the student!\n");
                scanf("%d", &idInput);
                if (idInput >= 0 && idInput <= 100)
                {
                    students[numOfStudents].id = idInput;
                    break;
                }
                printf("Error!, please try again\n");
            }

            //name input and "validation"
            while (1)
            {
                char nameInput[41];
                printf("enter the name of the student!");
                fgets(nameInput, sizeof(nameInput), stdin);
                strcpy(students[numOfStudents].name, nameInput);
                printf("\n");
                break;
            }

            //age input and validation // DONE
            while (1)
            {
                int ageInput = 0;
                printf("enter the age of the student!\n");
                scanf("%d", &ageInput);
                if (ageInput >= 0 && ageInput <= 100)
                {
                    students[numOfStudents].age = ageInput;
                    break;
                }
                printf("Error!, please try again\n");
            }

        // Grade input and validation // DONE
        while (1)
        {
            int gradeInput = 0;
            printf("Enter the grade of the student!\n");
            scanf("%lf", &gradeInput);

            if (gradeInput >= 0 && gradeInput <= 100)
            {
                students[numOfStudents].grade = gradeInput;
                break;
            }
            printf("Error! Please enter a valid grade between 0 and 100.\n");
        }

                numOfStudents++;

            } else if (menuValue == 3){
                // The user should be able to remove a student by entering their ID. If the ID does not exist, prompt the user to try again.
                int idInput = 0;

                while (1)
                {
                    printf("please enter the id of the student you would like to remove!");
                    scanf("%d", &idInput);
                    for (int i = 0; i < numOfStudents; i++) {
                        if (students[i].id == idInput) {
                            students[i].id = 0;
                            strcpy(students[i].name, " ");
                            students[i].age = 0;
                            students[i].grade = 0;
                            break;
                        }
                    }
                    printf("ERROR!, no student is assined to this id");

                }




            } else if (menuValue == 4){   // DONE
                // Calculate and display the average, minimum, and maximum grades of all students.
                int valueOfGrade = 0;
                // vars for grade calculation
                int highistGrade = 0;
                int lowestGrade = 100;
                int averageGrade = 0;
                int sumOfGrades = 0;

                for (int i = 0; i < numOfStudents ;i++)
                {
                    valueOfGrade = students[i].grade;
                    sumOfGrades += valueOfGrade;
                    if (valueOfGrade > highistGrade){highistGrade = valueOfGrade;}
                    if (valueOfGrade < lowestGrade){lowestGrade = valueOfGrade;}
                    sumOfGrades += valueOfGrade;
                }

                averageGrade = sumOfGrades / numOfStudents;
                printf("\nHighest Grade: %d" ,highistGrade);
                printf("\nLowest Grade: %d" ,lowestGrade);
                printf("\nAverage Grade: %d" ,averageGrade);

            } else if (menuValue == 5){   // DONE
                // End the program when this option is selected.
                printf("goodbye!");
                break;
            }
        }
    }