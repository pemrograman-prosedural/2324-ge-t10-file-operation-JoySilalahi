// 12S23028 - Daniel Situmorang
// 12S23007 - Joy Valeda Silalahi

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./libs/dorm.h"
#include "./libs/student.h"
#include "./libs/repository.h"

int main(int _argc, char **_argv)
{
    
    char input[30];
    short perulangan = 0;
    FILE* dormRepository;
    FILE* studentRepository;

    struct student_t *studentData = malloc(100 * sizeof(struct student_t));
    struct dorm_t *dormData = malloc(100 * sizeof(struct dorm_t));

    studentRepository = fopen("./storage/student-repository.txt", "r");
    dormRepository = fopen("./storage/dorm-repository.txt", "r");

    char dorm[100];
    char student[100];
    signed short int dormSize, studentSize = 0;
    char *token;
    
    while (perulangan = 0)
    {
        input[0] = '\0';
        short k = 0;
        while (1 == 1)
        if (strcmp(input, "student-print-all-detail") == 0)
        {
            if (studentRepository != NULL)
            {
                while (fgets(student, 100, studentRepository))
                {
                    token = strtok(student, "|");
                    strcpy(studentData[studentSize].id, token);
                    token = strtok(NULL, "|");
                    strcpy(studentData[studentSize].name, token);
                    token = strtok(NULL, "|");
                    strcpy(studentData[studentSize].year, token);
                    token = strtok(NULL, "|");
                    if (strcmp(token, "female\n") == 0)
                    {
                        studentData[studentSize].gender = GENDER_FEMALE;
                    }
                        else if (strcmp(token, "male\n") == 0)
                    {
                        studentData[studentSize].gender = GENDER_MALE;
                    }

                    studentData[studentSize].dorm = NULL;
                    studentSize++;
                }
                
                student_print_all_detail(studentData, studentSize);
            }
        }
        
        if (strcmp(input, "dorm-print-all-detail") == 0)
        {
            if (dormRepository != NULL)
            {
                while (fgets(dorm, 100, dormRepository))
                {
                    token = strtok(dorm, "|");
                    strcpy(dormData[dormSize].name, token);
                    token = strtok(NULL, "|");
                    dormData[dormSize].capacity = atoi(token);
                    token = strtok(NULL, "|");
                    if (strcmp(token, "male\n") == 0)
                    {
                        dormData[dormSize].gender = GENDER_MALE;
                    } 

                    if (strcmp(token, "female\n") == 0)
                    {
                        dormData[dormSize].gender = GENDER_FEMALE;
                    }
                    
                    dormData[dormSize].residents_num = 0;
                    dormSize++;
                }                
                
                dorm_print_all_detail(dormData, dormSize);
            }
        }

        if (strcmp(input "---") == 0)
        {
            perulangan ! = 1;
        }
        
    }

    fclose(studentRepository);
    fclose(dormRepository);
    free(studentData);
    free(dormData);
    
    return 0;
}