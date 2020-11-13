#ifndef LAB7_STUDENT_H
#define LAB7_STUDENT_H

#include <iostream>
static int idCounter =1000;

class Student
{
protected:
    int _id;
    char* _name;
    int _course;
    int _group;
    int _number;
    Student(){}
public:

    Student (char* name, int course, int group, int number);
    Student (Student &a);

    int get_id();
    int get_number();
    char* get_name();
    int get_course();
    int get_group();

    void set_name(char* name);
    void set_course(int course);
    void set_group(int group);

    virtual int getType();

    virtual double AverageScore();

    virtual void print(std::ostream &out);
    friend std::ostream & operator<< (std::ostream &out, Student &st);
};



class StudentAfter1: public Student{
protected:
    int sem1[4];
    StudentAfter1(){}
public:
    StudentAfter1(char* name, int course, int group, int number,int a, int b, int c, int d);
    StudentAfter1(StudentAfter1 &st);
    StudentAfter1(Student &a);

    void set_score(int number, int score);
    int get_score(int number);

    virtual int getType();

    virtual double AverageScore();

    virtual void print(std::ostream &out);
    friend std::ostream & operator<< (std::ostream &out, StudentAfter1 &st);
};



class StudentAfter2: public StudentAfter1{
protected:
    int sem2[5];
    StudentAfter2(){}
public:
    StudentAfter2(char* name, int course, int group, int number,int a, int b, int c, int d, int e, int f, int g, int h, int i);
    StudentAfter2(StudentAfter2 &st);
    StudentAfter2(StudentAfter1 &a);

    void set_score(int sem, int number, int score);
    int get_score(int sem, int number);

    int getType();

    double AverageScore();

    void print(std::ostream &out);
    friend std::ostream & operator<< (std::ostream &out, StudentAfter2 &st);
};
#endif
