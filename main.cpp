#include <iostream>
#include "Student.h"

double AverageScoreGroup(int number, Student *st[], int group, int sem){
    double result=0;
    int num=0;
    for(int i=0; i<number; i++){
        if(st[i]->get_group() == group  &&  st[i]->getType() == sem){
            result+= st[i]->AverageScore();
            ++num;
        }
    }
    if(num!=0){
        result/= num;
        return result;
    }
    else
        return 0;
}

double AverageScoreMassiv(int number, Student *st[]){
    double result=0;
    for(int i=0; i<number; i++){
            result+= st[i]->AverageScore();
    }
    result/= number;
    return result;
}

int main() {
    Student *students[9];
    students[0] = new Student ("Alisa", 1, 3, 799456);
    students[1] = new StudentAfter1("Marina", 1, 1, 789452, 9,7,8,8);
    students[2] = new StudentAfter2("Dasha", 1, 1, 789780, 9,7,7,8, 9,9,10,8,7);
    students[3] = new Student("Masha", 1, 1, 778356);
    students[4] = new StudentAfter1 ("Alina", 1, 4, 778390, 5,8,5,6);
    students[5] = new StudentAfter2("Ania", 1, 9, 779056, 5,7,5,9,9,4,4,7,8);
    students[6] = new Student("Katia", 1, 3, 786593);
    students[7] = new StudentAfter1("Ksiusha", 1, 4, 786590, 7,8,9,5);
    students[8] = new StudentAfter2("Julia", 1, 3, 784593, 5,8,9,10,4,9,10,7,8);


    std::cout << "average score for massiv: " << AverageScoreMassiv(9, students)<<'\n';
    std::cout << "average score for 4th after 1st sem: " << AverageScoreGroup(9, students, 4, 1) << '\n';
    return 0;
}
