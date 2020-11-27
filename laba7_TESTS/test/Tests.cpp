#include "Student.h"
#include <gtest/gtest.h>

Student a("NameA",1,2,3);
Student b("NameB", 4,5,6);
Student c("NameC", 5,8,9);
StudentAfter1 a1(a);
StudentAfter1 b1("NameB1",2,3,4,4,5,6,7);
StudentAfter2 a2(a1);
StudentAfter2 b2("NameB2",2,3,4,4,5,6,7,4,5,6,7,10);

TEST (GetMethods_Student, Get_id){
    EXPECT_EQ(a.get_id(), 1001);
    EXPECT_EQ(b.get_id(), 1002);
    EXPECT_EQ(c.get_id(), 1003);
}

TEST (GetMethods_Student, Get_number){
    EXPECT_EQ(a.get_number(), 3);
}

TEST (GetMethods_Student, Get_name){
    EXPECT_EQ((std::string)a.get_name(), "NameA");
}

TEST (GetMethods_Student, Get_course){
    EXPECT_EQ(a.get_course(), 1);
}

TEST (GetMethods_Student, Get_group){
    EXPECT_EQ(a.get_group(), 2);
}

TEST(GetMethods_Student, Get_Type){
    EXPECT_EQ(a.getType(), 0);
}

TEST (ConstructorsStudent, Copy){
    Student d1("NameCopy", 1, 11, 12);
    Student d(d1);
    EXPECT_EQ(d.get_id(), 1009);
    EXPECT_EQ(d.get_number(), 12);
    EXPECT_EQ((std::string)d.get_name(), "NameCopy");
    EXPECT_EQ(d.get_course(), 1);
    EXPECT_EQ(d.get_group(), 11);
}

TEST (SetMethods_Student, Set_name){
    a.set_name("NameA_New");
    EXPECT_EQ((std::string)a.get_name(), "NameA_New");
}

TEST (SetMethods_Student, Set_course){
    a.set_course(3);
    EXPECT_EQ(a.get_course(), 3);
}

TEST (SetMethods_Student, Set_courseWrong){
    EXPECT_THROW(a.set_course(0), std::invalid_argument);
}

TEST (SetMethods_Student, Set_groupe){
    a.set_group(17);
    EXPECT_EQ(a.get_group(), 17);
}

TEST (SetMethods_Student, Set_groupWrong){
    EXPECT_THROW(a.set_group(0), std::invalid_argument);
}

TEST (AverageScore, Student){
    EXPECT_EQ(a.AverageScore(), 0);
}




TEST (GetMethods_After1, Get_id){
    EXPECT_EQ(a1.get_id(), 1004);
}

TEST (GetMethods_After1, Get_number){
    EXPECT_EQ(a1.get_number(), 3);
}

TEST (GetMethods_After1, Get_name){
    EXPECT_EQ((std::string)a1.get_name(), "NameA");
}

TEST (GetMethods_After1, Get_course){
    EXPECT_EQ(a1.get_course(), 1);
}

TEST (GetMethods_After1, Get_group){
    EXPECT_EQ(a1.get_group(), 2);
}

TEST(GetMethods_After1, Get_Type){
    EXPECT_EQ(a1.getType(), 1);
}
TEST(GetMethods_After1, Get_Score1){
    EXPECT_EQ(b1.get_score(0), 4);
}
TEST(GetMethods_After1, Get_Score4){
    EXPECT_EQ(b1.get_score(3), 7);
}


TEST (ConstructorsAfter1, Copy){
    StudentAfter1 f1("NameCopy", 1, 11, 12,4,5,6,7);
    StudentAfter1 f(f1);
    EXPECT_EQ(f.get_id(), 1011);
    EXPECT_EQ(f.get_number(), 12);
    EXPECT_EQ((std::string)f.get_name(), "NameCopy");
    EXPECT_EQ(f.get_course(), 1);
    EXPECT_EQ(f.get_group(), 11);
    EXPECT_EQ(f.get_score(0),4);
    EXPECT_EQ(f.get_score(1),5);
    EXPECT_EQ(f.get_score(2),6);
    EXPECT_EQ(f.get_score(3),7);
}

TEST (ConstructorsAfter1, CopyStudent){
    Student f1("NameCopy", 1, 11, 12);
    StudentAfter1 f(f1);
    EXPECT_EQ(f.get_id(), 1013);
    EXPECT_EQ(f.get_number(), 12);
    EXPECT_EQ((std::string)f.get_name(), "NameCopy");
    EXPECT_EQ(f.get_course(), 1);
    EXPECT_EQ(f.get_group(), 11);
    EXPECT_EQ(f.get_score(0),-1);
    EXPECT_EQ(f.get_score(1),-1);
    EXPECT_EQ(f.get_score(2),-1);
    EXPECT_EQ(f.get_score(3),-1);
}

TEST (SetMethods_After1, Set_name){
    a1.set_name("NameA1_New");
    EXPECT_EQ((std::string)a1.get_name(), "NameA1_New");
}

TEST (SetMethods_After1, Set_course){
    a1.set_course(4);
    EXPECT_EQ(a1.get_course(), 4);
}

TEST (SetMethods_After1, Set_courseWrong){
    EXPECT_THROW(a1.set_course(0), std::invalid_argument);
}

TEST (SetMethods_After1, Set_groupe){
    a1.set_group(17);
    EXPECT_EQ(a1.get_group(), 17);
}

TEST (SetMethods_After1, Set_groupWrong){
    EXPECT_THROW(a1.set_group(0), std::invalid_argument);
}

TEST (SetMethods_After1, Set_Score){
    a1.set_score(1,6);
    EXPECT_EQ(a1.get_score(1), 6);
}

TEST (SetMethods_After1, Set_ScoreWrongIndex0){
    EXPECT_THROW(a1.set_score(-1,5), std::invalid_argument);
}
TEST (SetMethods_After1, Set_ScoreWrongIndex5){
    EXPECT_THROW(a1.set_score(7,5), std::invalid_argument);
}

TEST (SetMethods_After1, Set_ScoreWrongValue0){
    EXPECT_THROW(a1.set_score(0,-1) ,std::invalid_argument);
}
TEST (SetMethods_After1, Set_ScoreWrongValue11){
    EXPECT_THROW(a1.set_score(0,14) ,std::invalid_argument);
}

TEST (AverageScore, After1){
    EXPECT_EQ(b1.AverageScore(), 5.5);
}

TEST (GetMethods_After2, Get_id){
    EXPECT_EQ(a2.get_id(), 1006);
}

TEST (GetMethods_After2, Get_number){
    EXPECT_EQ(a2.get_number(), 3);
}

TEST (GetMethods_After2, Get_name){
    EXPECT_EQ((std::string)a2.get_name(), "NameA");
}

TEST (GetMethods_After2, Get_course){
    EXPECT_EQ(a2.get_course(), 1);
}

TEST (GetMethods_After2, Get_group){
    EXPECT_EQ(a2.get_group(), 2);
}

TEST(GetMethods_After2, Get_Type){
    EXPECT_EQ(a2.getType(), 2);
}
TEST(GetMethods_After2, Get_Score1){
    EXPECT_EQ(b2.get_score(1,0), 4);
}
TEST(GetMethods_After2, Get_Score4){
    EXPECT_EQ(b2.get_score(1,3), 7);
}
TEST(GetMethods_After2, Get_Score5){
    EXPECT_EQ(b2.get_score(2,0), 4);
}
TEST(GetMethods_After2, Get_Score9){
    EXPECT_EQ(b2.get_score(2,4), 10);
}


TEST (ConstructorsAfter2, Copy){
    StudentAfter2 k1("NameCopy", 1, 11, 12,4,5,6,7,8,9,10,2,4);
    StudentAfter2 k(k1);
    EXPECT_EQ(k.get_id(), 1015);
    EXPECT_EQ(k.get_number(), 12);
    EXPECT_EQ((std::string)k.get_name(), "NameCopy");
    EXPECT_EQ(k.get_course(), 1);
    EXPECT_EQ(k.get_group(), 11);
    EXPECT_EQ(k.get_score(1,0),4);
    EXPECT_EQ(k.get_score(1,1),5);
    EXPECT_EQ(k.get_score(1,2),6);
    EXPECT_EQ(k.get_score(1,3),7);
    EXPECT_EQ(k.get_score(2,0),8);
    EXPECT_EQ(k.get_score(2,1),9);
    EXPECT_EQ(k.get_score(2,2),10);
    EXPECT_EQ(k.get_score(2,3),2);
    EXPECT_EQ(k.get_score(2,4),4);
}

TEST (ConstructorsAfter2, CopyStudent){
    StudentAfter1 k1("NameCopy", 1, 11, 12,4,5,6,7);
    StudentAfter2 k(k1);
    EXPECT_EQ(k.get_id(), 1017);
    EXPECT_EQ(k.get_number(), 12);
    EXPECT_EQ((std::string)k.get_name(), "NameCopy");
    EXPECT_EQ(k.get_course(), 1);
    EXPECT_EQ(k.get_group(), 11);
    EXPECT_EQ(k.get_score(1,0),4);
    EXPECT_EQ(k.get_score(1,1),5);
    EXPECT_EQ(k.get_score(1,2),6);
    EXPECT_EQ(k.get_score(1,3),7);
    EXPECT_EQ(k.get_score(2,0),-1);
    EXPECT_EQ(k.get_score(2,1),-1);
    EXPECT_EQ(k.get_score(2,2),-1);
    EXPECT_EQ(k.get_score(2,3),-1);
    EXPECT_EQ(k.get_score(2,4),-1);
}

TEST (SetMethods_After2, Set_name){
    a2.set_name("NameA2_New");
    EXPECT_EQ((std::string)a2.get_name(), "NameA2_New");
}

TEST (SetMethods_After2, Set_course){
    a2.set_course(4);
    EXPECT_EQ(a2.get_course(), 4);
}

TEST (SetMethods_After2, Set_courseWrong){
    EXPECT_THROW(a2.set_course(0), std::invalid_argument);
}

TEST (SetMethods_After2, Set_groupe){
    a2.set_group(17);
    EXPECT_EQ(a2.get_group(), 17);
}

TEST (SetMethods_After2, Set_groupWrong){
    EXPECT_THROW(a2.set_group(0), std::invalid_argument);
}

TEST (SetMethods_After2, Set_Score){
    a2.set_score(1,0,6);
    EXPECT_EQ(a2.get_score(1,0), 6);
}

TEST (SetMethods_After2, Set_ScoreWrongSem0){
    EXPECT_THROW(a2.set_score(0,1,5), std::invalid_argument);
}
TEST (SetMethods_After2, Set_ScoreWrongSem3){
    EXPECT_THROW(a2.set_score(4,0,5), std::invalid_argument);
}

TEST (SetMethods_After2, Set_ScoreWrongIndex0){
    EXPECT_THROW(a2.set_score(1,-1,5), std::invalid_argument);
}
TEST (SetMethods_After2, Set_ScoreWrongIndex5){
    EXPECT_THROW(a2.set_score(1,5,5), std::invalid_argument);
}
TEST (SetMethods_After2, Set_ScoreRightIndex){
    a2.set_score(2,5,5);
    EXPECT_EQ(a2.get_score(2,5), 5);
}
TEST (SetMethods_After2, Set_ScoreWrongIndex6){
    EXPECT_THROW(a2.set_score(2,6,5), std::invalid_argument);
}

TEST (SetMethods_After2, Set_ScoreWrongValue0){
    EXPECT_THROW(a2.set_score(1,0,-1) ,std::invalid_argument);
}
TEST (SetMethods_After2, Set_ScoreWrongValue11){
    EXPECT_THROW(a2.set_score(1,0,14) ,std::invalid_argument);
}

TEST (AverageScore, After2){
    EXPECT_EQ(b2.AverageScore(), 6);
}


TEST (ConstructorsStudent, WrongCourseLower1){
    EXPECT_THROW(Student s("NameS", -1, 11, 12), std::invalid_argument);
}
TEST (ConstructorsStudent, WrongCourseMore6){
    EXPECT_THROW(Student s("NameS", 7, 11, 12), std::invalid_argument);
}
TEST (ConstructorsStudent, WrongGroup){
    EXPECT_THROW(Student s("NameS", 1, 0, 12), std::invalid_argument);
}
TEST (ConstructorsStudent, WrongNumber){
    EXPECT_THROW(Student s("NameS", 1, 1, -12), std::invalid_argument);
}
TEST (ConstructorsAfter1, WrongCourseLower1){
    EXPECT_THROW(StudentAfter1 s1("NameS1", -1, 11, 12, 4,5,6,7), std::invalid_argument);
}
TEST (ConstructorsAfter1, WrongCourseMore6){
    EXPECT_THROW(StudentAfter1 s1("NameS1", 7, 11, 12,4,5,6,7), std::invalid_argument);
}
TEST (ConstructorsAfter1, WrongGroup){
    EXPECT_THROW(StudentAfter1 s1("NameS1", 1, 0, 12,4,5,6,7), std::invalid_argument);
}
TEST (ConstructorsAfter1, WrongNumber){
    EXPECT_THROW(StudentAfter1 s1("NameS1", 1, 1, -12,4,5,6,7), std::invalid_argument);
}
TEST (ConstructorsAfter1, WrongScore1){
    EXPECT_THROW(StudentAfter1 s1("NameS1", 1, 1, -12,-4,5,6,7), std::invalid_argument);
}
TEST (ConstructorsAfter1, WrongScore4){
    EXPECT_THROW(StudentAfter1 s1("NameS1", 1, 1, -12,4,5,6,-7), std::invalid_argument);
}


TEST (ConstructorsAfter2, WrongCourseLower1){
    EXPECT_THROW(StudentAfter2 s2("NameS2", -1, 11, 12, 4,5,6,7,4,5,6,7,10), std::invalid_argument);
}
TEST (ConstructorsAfter2, WrongCourseMore6){
    EXPECT_THROW(StudentAfter2 s2("NameS2", 7, 11, 12,4,5,6,7,4,5,6,7,10), std::invalid_argument);
}
TEST (ConstructorsAfter2, WrongGroup){
    EXPECT_THROW(StudentAfter2 s2("NameS2", 1, 0, 12,4,5,6,7,4,5,6,7,10), std::invalid_argument);
}
TEST (ConstructorsAfter2, WrongNumber){
    EXPECT_THROW(StudentAfter2 s2("NameS2", 1, 1, -12,4,5,6,7,4,5,6,7,10), std::invalid_argument);
}
TEST (ConstructorsAfter2, WrongScore1){
    EXPECT_THROW(StudentAfter2 s2("NameS2", 1, 1, -12,-4,5,6,7,4,5,6,7,10), std::invalid_argument);
}
TEST (ConstructorsAfter2, WrongScore9){
    EXPECT_THROW(StudentAfter2 s2("NameS2", 1, 1, -12,4,5,6,-7,4,5,6,7,-10), std::invalid_argument);
}
