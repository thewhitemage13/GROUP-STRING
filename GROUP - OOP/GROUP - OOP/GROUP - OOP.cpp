using namespace std;
#include "Student.h"
#include "Date.h"
#include "Group.h"
#include "Fraction.h"

Group operator + (const Group& one, const Group two)
{

    Group result;
    result.SetGroupName(one.GetGroupName() + two.GetGroupName());
    result.SetNumberOfCourse(one.GetNumberOfCourse());
    result.SetSpecification(one.GetSpecification());

    for (int i = 0; i < one.GetCountOfStudent(); i++)
    {
        result.AddStudent(*one.classmates[i]);
    }
    for (int i = 0; i < two.GetCountOfStudent(); i++)
    {
        result.AddStudent(*two.classmates[i]);
    }

    return result;
}

int operator - (const Date& date_now, const Date& other_date)
{
    int thisDays = date_now.GetDay() + 31 * (date_now.GetMonth() - 1);
    int otherDays = other_date.GetDay() + 31 * (other_date.GetMonth() - 1);

    thisDays += (date_now.GetYear() % 4 == 0 && date_now.GetMonth() > 2);
    otherDays += (other_date.GetYear() % 4 == 0 && other_date.GetMonth() > 2);

    thisDays += (date_now.GetMonth() > 1);
    otherDays += (other_date.GetMonth() > 1);

    thisDays += date_now.GetMonth() / 2 + ((date_now.GetMonth() % 2 == 0 && date_now.GetMonth() > 7));
    otherDays += other_date.GetMonth() / 2 + ((other_date.GetMonth() % 2 == 0 && other_date.GetMonth() > 7));

    thisDays += 365 * (date_now.GetYear() - 1);
    otherDays += 365 * (other_date.GetYear() - 1);

    return thisDays - otherDays;
}
//Student
bool operator > (const Student& a, const Student& b)
{
    return a.GetAverageGrade() > b.GetAverageGrade();
}

bool operator < (const Student& a, const Student& b)
{
    return a.GetAverageGrade() < b.GetAverageGrade();
}

bool operator >= (const Student& a, const Student& b)
{
    return a.GetAverageGrade() > b.GetAverageGrade();
}

bool operator <= (const Student& a, const Student& b)
{
    return a.GetAverageGrade() <= b.GetAverageGrade();
}

bool operator == (const Student& a, const Student& b)
{
    return a.GetAverageGrade() == b.GetAverageGrade();
}

bool operator != (const Student& a, const Student& b)
{
    return a.GetAverageGrade() != b.GetAverageGrade();
}
//Group: 
bool operator > (const Group& a, const Group& b)
{
    return a.GetCountOfStudent() > b.GetCountOfStudent();
}

bool operator < (const Group& a, const Group& b)
{
    return a.GetCountOfStudent() < b.GetCountOfStudent();
}

bool operator >= (const Group& a, const Group& b)
{
    return a.GetCountOfStudent() >= b.GetCountOfStudent();
}

bool operator <= (const Group& a, const Group& b)
{
    return a.GetCountOfStudent() <= b.GetCountOfStudent();
}

bool operator == (const Group& a, const Group& b)
{
    return a.GetCountOfStudent() == b.GetCountOfStudent();
}

bool operator != (const Group& a, const Group& b)
{
    return a.GetCountOfStudent() != b.GetCountOfStudent();
}

istream& operator >> (const istream& i, Student& d)
{

        cout << "surname: ";
        string answear;
        cin >> answear;
        d.SetSurname(answear);

        cout << "name: ";
        cin >> answear;
        d.SetName(answear);

        cout << "middle name: ";
        cin >> answear;
        d.SetMiddlName(answear);

        cout << "adress: ";
        cin >> answear;
        d.SetAdress(answear);

        cout << "phonnumber: ";
        cin >> answear;
        d.SetPhone(answear);

        cout << "adress: ";
        cin >> answear;
        d.SetAdress(answear);

        return cin;
   
}

ostream& operator << (const ostream& i, Student& d)
{
    d.PrintStudent();
    d.PrintExam();
    d.PrintPractic();
    d.PrintHomeWork();
    return cout;
}

istream& operator >> (const istream& i, Group& g)
{

    cout << "Group Name: ";
    string answear;
    cin >> answear;
    g.SetGroupName(answear);

    cout << "Group Specification: ";
    cin >> answear;
    g.SetSpecification(answear);

    cout << "Course: ";
    unsigned short amswear2;
    cin >> amswear2;
    g.SetNumberOfCourse(amswear2);

    return cin;

}

ostream& operator << (const ostream& i, Group& d)
{
    d.Print();
    return cout;
}

istream& operator >> (const istream& i, Fraction& f)
{

    cout << "numerator: ";
    int answear;
    cin >> answear;
    f.SetNumerator(answear);

    cout << "denominator: ";
    cin >> answear;
    f.SetDenominator(answear);

    return cin;

}

ostream& operator << (const ostream& i, Fraction& f)
{
    f.Print();
    return cout;
}



int main()
{

    //1
    //Student s;
    //s.AddExam(2);
    //s.AddExam(12);
    //s.AverageGrade();

    //string a = (string)s;
    //cout << a;

    //2
    //Student s;
    //Student d;

    //Group g;
    //g += s;
    //g += d;

    //string str = (string)g;
    //cout << str;

    //3:
    Date today(1, 2, 2024);
    //today++; // 2 2 2024
    //++today; // 3 2 2024
    //--today; // 2 2 2024
    //today--; // 1 2 2024
    today += 5; // 6 2 2024
    today.PrintDate();

    //Date d(29, 2, 2024);
    //d++; // 1 3 2024
    //d.PrintDate();
}