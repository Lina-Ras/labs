#include "Student.h"
#include <iostream>
enum StydentType{
    ST,
    ST1,
    ST2,
};

void Student::DataCheck(int course, int group, int number){
    this->CourseCheck(course);
    this->GroupCheck(group);
    this->NumberCheck(number);
}
void Student::CourseCheck(int course){
    if(course<1 || course>6) {
        std::cout<<"Course value can't be lower then 1 and more then 6";
        throw std::invalid_argument("Course can't be lower then 1 and more then 6");
    }
}
void Student::GroupCheck(int group){
    if(group<1) {
        std::cout<<"Group value can't be lower then 1";
        throw std::invalid_argument("Group value can't be lower then 1");
    }
}
void Student::NumberCheck(int number){
    if(number<1) {
        std::cout<<"Number can't be lower then 1";
        throw std::invalid_argument("Number can't be lower then 1");
    }
}

void StudentAfter1::ScoreCheck(int score) {
    if(score<1 || score>10) {
        std::cout<<"Score can't be lower then 1 or more then 10";
        throw std::invalid_argument("Score can't be lower then 1 or more then 10");
    }
}

Student::Student (char* name, int course, int group, int number){
    this->DataCheck(course, group, number);
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
    this->ScoreCheck(a);
    this->ScoreCheck(b);
    this->ScoreCheck(c);
    this->ScoreCheck(d);
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
    this->ScoreCheck(e);
    this->ScoreCheck(f);
    this->ScoreCheck(g);
    this->ScoreCheck(h);
    this->ScoreCheck(i);
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
    this->CourseCheck(course);
    this->_course = course;
}
void Student::set_group(int group){
    this->GroupCheck(group);
    this->_group = group;
}

void StudentAfter1::set_score(int number, int score){
    this->ScoreCheck(score);
    if(number<0 || number>4){
        std::cout<<"Incorrect index";
        throw std::invalid_argument("Incorrect index");
    }
    this->sem1[number] = score;
}
void StudentAfter2::set_score(int sem, int number, int score){
    ScoreCheck(score);
    switch (sem) {
        case 2: {
            if (number < 0 || number > 5) {
                std::cout << "Incorrect index";
                throw std::invalid_argument("Incorrect index");
            }
            this->sem2[number] = score;
            break;
        }
        case 1: {
            if (sem == 1) {
                if (number < 0 || number > 4) {
                    std::cout << "Incorrect index";
                    throw std::invalid_argument("Incorrect index");
                }
                this->sem1[number] = score;
            }
            break;
        }
        default:{
            std::cout << "Wrong semester";
            throw std::invalid_argument("Wrong semester");
            break;
        }
    }
    }

int StudentAfter1::get_score(int number){
    if(number<0 || number>4){
        std::cout<<"Incorrect index";
        throw std::invalid_argument("Incorrect index");
    }
    return this->sem1[number];
}
int StudentAfter2::get_score(int sem, int number){
    if(sem==2){
        if(number<0 || number>5){
            std::cout<<"Incorrect index";
            throw std::invalid_argument("Incorrect index");
        }
        return this->sem2[number];
    }
    else{
        if(number<0 || number>4){
            std::cout<<"Incorrect index";
            throw std::invalid_argument("Incorrect index");
        }
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



void Student::print(std::ostream &out){
    out << "Name of the Student: " << this->_name << ", his id - " << this->_id <<" and his number - " << this->_number << "\n";
    out <<" This student is in group number "<< this->_group << ", " << this->_course << " course";
}

void StudentAfter1::print(std::ostream &out){
    out << "Student: " << this->get_name() << '\n';
    out << "(" << this->sem1[0] << ", "<< this->sem1[1]<< ", "<<this->sem1[2]<< ", " << this->sem1[3] << ")";
}

void StudentAfter2::print(std::ostream &out) {
    out << "Student: " << this->get_name() << '\n';
    out << "(sem1:" << this->sem1[0] << ", " << this->sem1[1] << ", " << this->sem1[2] << ", " << this->sem1[3] << ")\n";
    out << "(sem2:" << this->sem2[0] << ", " << this->sem2[1] << ", " << this->sem2[2] << ", " << this->sem2[3] << ", "
        << this->sem2[4] << ")";
}

std::ostream & operator<< (std::ostream &out, Student &st){
    if(st.getType()==0 ){
        st.print(out);
    }
    if(st.getType()==1){
        st.print (out);
    }
    if(st.getType()==2){
        st.print (out);
    }
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