#include "Student.h"
#include <iostream>
enum StydentType{
    ST,
    ST1,
    ST2,
};
Student::Student (char* name, int course, int group, int number){
    this->_id = ++idCounter;
    this->_name = name;
    this->_course = course;
    this->_group = group;
    this->_number = number;
}

Student::Student (Student &a){
    this->_id = ++idCounter;
    this->_name = a._name;
    this->_course = a._course;
    this->_group = a._group;
    this->_number = a._number;
}


StudentAfter1::StudentAfter1(char* name, int course, int group, int number,int a, int b, int c, int d)
:Student(name, course, group, number){
    this->sem1[0]=a;
    this->sem1[1]=b;
    this->sem1[2]=c;
    this->sem1[3]=d;
}

StudentAfter1::StudentAfter1(StudentAfter1 &a) :Student(a){
    this->sem1[0]=a.sem1[0];
    this->sem1[1]=a.sem1[1];
    this->sem1[2]=a.sem1[2];
    this->sem1[3]=a.sem1[3];
}

StudentAfter1::StudentAfter1(Student &a) :Student(a){
    this->sem1[0]=-1;
    this->sem1[1]=-1;
    this->sem1[2]=-1;
    this->sem1[3]=-1;
}

StudentAfter2::StudentAfter2(char* name, int course, int group, int number,int a, int b, int c, int d, int e, int f, int g, int h, int i)
:StudentAfter1(name, course, group, number, a,b,c,d){
    this->sem2[0]=e;
    this->sem2[1]=f;
    this->sem2[2]=g;
    this->sem2[3]=h;
    this->sem2[4]=i;

}
StudentAfter2::StudentAfter2(StudentAfter2 &a) :StudentAfter1(a){
    this->sem2[0]=a.sem2[0];
    this->sem2[1]=a.sem2[1];
    this->sem2[2]=a.sem2[2];
    this->sem2[3]=a.sem2[3];
    this->sem2[4]=a.sem2[4];
}
StudentAfter2::StudentAfter2(StudentAfter1 &a) :StudentAfter1(a){
    this->sem2[0]=-1;
    this->sem2[1]=-1;
    this->sem2[2]=-1;
    this->sem2[3]=-1;
    this->sem2[4]=-1;
}

int Student::getType(){
    return ST;
}
int StudentAfter1::getType(){
    return ST1;
}
int StudentAfter2::getType(){
    return ST2;
}

int Student::get_id(){
    return this->_id;
}
int Student::get_number(){
    return this->_number;
}
char* Student::get_name(){
    return this->_name;
}
int Student::get_course(){
    return this->_course;
}
int Student::get_group(){
    return this->_group;
}

void Student::set_name(char* name){
    this->_name = name;
}
void Student::set_course(int course){
    this->_course = course;
}
void Student::set_group(int group){
    this->_group = group;
}

void StudentAfter1::set_score(int number, int score){
    this->sem1[number] = score;
}
void StudentAfter2::set_score(int sem, int number, int score){
    if(sem==2){
        this->sem2[number] = score;
    }
    else{
        this->sem1[number] = score;
    }
}

int StudentAfter1::get_score(int number){
    return this->sem1[number];
}
int StudentAfter2::get_score(int sem, int number){
    if(sem==2){
        return this->sem2[number];
    }
    else{
        return this->sem1[number];
    }
}
double Student::AverageScore(){
    return 0;
}
double StudentAfter1::AverageScore() {
    return (double)(sem1[0]+sem1[1]+sem1[2]+sem1[3])/4;
}

double StudentAfter2::AverageScore(){
    return (double)(sem1[0]+sem1[1]+sem1[2]+sem1[3]+sem2[0]+sem2[1]+sem2[2]+sem2[3]+sem2[4])/9;
}

std::ostream & operator<< (std::ostream &out, const Student &st){
    out << "Name of the Student: " << st._name << ", his id - " << st._id <<" and his number - " << st._number << "\n";
    out <<" This student is in group number "<< st._group << ", " << st._course << " course";
    return out;
}

std::ostream & operator<< (std::ostream &out, StudentAfter1 &st){
    out << "Student: " << st.get_name() << '\n';
    out << "(" << st.sem1[0] << ", "<< st.sem1[1]<< ", "<<st.sem1[2]<< ", " << st.sem1[3] << ")";
    return out;
}

std::ostream & operator<< (std::ostream &out, StudentAfter2 &st){
    out << "Student: " << st.get_name() << '\n';
    out << "(sem1:" << st.sem1[0] << ", "<< st.sem1[1]<< ", "<<st.sem1[2]<< ", " << st.sem1[3] << ")\n";
    out << "(sem2:" << st.sem2[0] << ", "<< st.sem2[1]<< ", "<<st.sem2[2]<< ", " << st.sem2[3] << ", " << st.sem2[4]  << ")";
    return out;
}