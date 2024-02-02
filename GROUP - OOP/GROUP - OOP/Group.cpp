#include "Group.h"

    Group::Group()
    {
        SetGroupName("P26");
        SetNumberOfCourse(2);
        SetSpecification("Software Development");
    }

    Group::Group(const Group& original)
    {
        this->countstudent = original.countstudent;
        this->classmates = new Student * [original.countstudent];

        for (int i = 0; i < countstudent; i++)
        {
            this->classmates[i] = new Student(*original.classmates[i]);
        }

        this->group_name = original.group_name;
        this->specification = original.specification;
        this->number_of_course = original.number_of_course;
       
    }

    void Group::Print() const
    {
        cout << group_name << "\n";
        for (int i = 0; i < countstudent; i++)
        {
            classmates[i]->PrintStudent();
            classmates[i]->PrintExam();
            classmates[i]->PrintHomeWork();
            classmates[i]->PrintPractic();
            classmates[i]->AverageGrade();
        }
    }

    void Group::AddStudent(const Student& new_student)
    {
        Student** temp = new Student * [countstudent + 1];
        for (int i = 0; i < countstudent; i++)
        {
            temp[i] = classmates[i];
        }
        temp[countstudent] = new Student(new_student);
        countstudent++;
        delete[]classmates;
        classmates = temp;
    }

    void Group::WeanStudent(unsigned short index)
    {
        Student** temp = new Student * [countstudent - 1];
        for (int i = 0, j = 0; i < countstudent; i++)
        {
            if (i != index)
            {
                temp[j++] = classmates[i];
            }
        }
        delete classmates[index];
        delete[] classmates;
        countstudent--;
        classmates = temp;
    }
    void Group::Expel()
    {
        if (countstudent == 0) {
            cout << "The group is empty.\n\n";
            return;
        }
        int minGradeIndex = 0;
        for (int i = 1; i < countstudent; i++)
        {
            if (classmates[i]->GetAverageGrade() < classmates[minGradeIndex]->GetAverageGrade())
            {
                minGradeIndex = i;
            }
        }
        Student** temp = new Student * [countstudent - 1];
        for (int i = 0, j = 0; i < countstudent; i++)
        {
            if (i != minGradeIndex) {
                temp[j++] = classmates[i];
            }
        }
        delete classmates[minGradeIndex];
        delete[] classmates;
        countstudent--;
        classmates = temp;
        cout << "The student with the lowest grade point average is dropped from the group.\n\n";
    }

    void Group::SetCountOfStudent(int countstudent)
    {
        this->countstudent = countstudent;
    }

    int Group::GetCountOfStudent() const
    {
        return countstudent;
    }

    void Group::SetGroupName(string group_name)
    {
        this->group_name = group_name;
    }

    string Group::GetGroupName() const
    {
        return group_name;
    }

    void Group::SetSpecification(string specification)
    {
        this->specification = specification;
    }

    string Group::GetSpecification() const
    {
        return specification;
    }

    void Group::SetNumberOfCourse(int number_of_course)
    {
        this->number_of_course = number_of_course;
    }

    int Group::GetNumberOfCourse() const
    {
        return number_of_course;
    }

    Group::~Group()
    {
        for (int i = 0; i < countstudent; i++)
        {
            delete classmates[i];
        }
        delete[] classmates;
    }

