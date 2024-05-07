#ifndef STUDENT_H
#define STUDENT_H

#include "gender.h"
#include "dorm.h"

/**
 * @brief define your structure, enums, globally accessible variables, and function prototypes here.
 * The actual function implementation should be defined in the corresponding source file.
 *
 */

struct student_t
{
    char id[12];
    char name[40];
    char year[5];
    enum gender_t gender;
    struct dorm_t *dorm;
};

struct student_t create_student(char *_id, char *_name, char *_year,
                                enum gender_t _gender);
int find_index_student(struct student_t *_student, short _student_size, char *_id);
char *gender_to_text(enum gender_t _gender);
void student_print_all(struct student_t *_student,
                                short _student_size);
void student_print_all_detail(struct student_t *_student, 
                                short _student_size);
void assign_student(struct student_t *_student, struct dorm_t *_dorm, short indexStudent, short indexDorm);
void move_student(struct student_t *_student, struct dorm_t *_dorm, short indexStudent, short indexDorm, short _temp_dorm);

#endif
