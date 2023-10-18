#include<iostream>
#include<string>
#include<vector>
using std::string;
using std::vector;

class Person{
protected:
    string name;
    int age;
public:
    string getName(){
        return this->name;
    }

    void setName(string value)
    {
        this->name = value;
    }

    int getAge(){
        return this->age;
    }

    void setAge(int value)
    {
        this->age = value;
    }

    Person()
    {
        std::cout << "\nAn instance has been derived from Person." << std::endl;
    }

    Person(string name, int age)
    :Person()
    {
        std::cout << "\nAn instance with parameters has been derived from Person." << std::endl;
        this->name = name;
        this->age = age;
    }

    virtual string toString()
    {
        return this->name + " - " + std::to_string(this->age) + " years";
    }
};

class Student: public Person
{
protected:
    int IDno;
public:
    Student()
    {
        std::cout<< "Has been derived Student Class" <<std::endl;
    }
    Student(string name, int age, int IDno)
    : Person(name, age)
    {
        std::cout << "\nAn instance with paramaters has been derived from Student." << std::endl;
        this->IDno = IDno;
    }

    int getStudentId()
    {
        return IDno;
    }

    void setStudentId(int IdNumber)
    {
        this->IDno = IdNumber;
    }

    string toString() override
    {
        return this->name + " - " + std::to_string(this->age) +  " years"+ " - " + "IDno: "+std::to_string(this->IDno);
    }
};

class Teacher: public Person
{
protected:
    vector<string> teachingSubjects;

public:
    Teacher()
    {
        std::cout << "\nAn instance has been derived from Teacher." << std::endl;
    }
    Teacher(string name, int age, const vector<string>& teachingSubjects)
    : Person(name, age)
    {
        std::cout << "\nAn instance with paramaters has been derived from Teacher." << std::endl;
        this->teachingSubjects = teachingSubjects;
    }

    vector<string> getTeachingSubjects()
    {
        return teachingSubjects;
    }

    void setTeachingSubjects(const vector<string>& teachingSubjects){
        this->teachingSubjects = teachingSubjects;
    }

    string toString() override
    {
        string teacherInfo = this->name + " - " + std::to_string(this->age) + " years" + " - [";
        for (const string& subject : this->teachingSubjects)
        {
           teacherInfo += subject + ", ";
        }
        if (!this->teachingSubjects.empty())
        {
            teacherInfo = teacherInfo.substr(0, teacherInfo.length() - 2);
        }
        
        teacherInfo+= "]";

        return teacherInfo;
    }

};

int main()
{
    /* Base Class */
    Person personOne = Person("Ali", 24);
    std::cout << personOne.toString() <<std::endl; 

    // Student class
    Student student1 = Student("Hamza", 20, 2454);
    std::cout << student1.toString() <<std::endl; 

    // Teacher Class
    Teacher teacher1 = Teacher("Khalid", 50, {"Maths", "English"});
    // vector<string> subjects = teacher1.getTeachingSubjects();
    std::cout << teacher1.toString() <<std::endl; 

    // Teacher Class
    Teacher teacher2 = Teacher();
    teacher2.setName("Faahiye");
    teacher2.setAge(54);
    teacher2.setTeachingSubjects({"Chemistry", "Science", "Social Studies"});
    
    std::cout << teacher2.toString() <<std::endl; 

    return 0;
}
