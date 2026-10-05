#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int main()
{
    string courseIDs[5];
    double grades[5];
    double total = 0;

    for (int i = 0; i < 5; i++)
    {
    cout << "Enter course ID: ";
     cin >> courseIDs[i];

        cout << "Enter grade: ";
    cin >> grades[i];

    total = total + grades[i];
}
    double average = total / 5;
    char letterGrade;

    if (average >= 90)
    {
 letterGrade = 'A' ;   
    }
else if (average >= 80)
{
    letterGrade = 'B' ;

}
     else if (average >= 70)
  {
        letterGrade = 'C' ;
  }
        else if (average >= 60)
    {
            letterGrade = 'D' ;   
    }
               else
     {
                      letterGrade = 'F' ;
     }

     cout << fixed << setprecision(2);
cout << "\nCourse Grades" << endl;
cout << "-------------" << endl;

for (int i = 0; i < 5; i++)
{
    cout << courseIDs[i] << ": " << grades[i] << endl;
}

cout << "Average Grade: " << average << endl;

cout << "Letter Grade: " << letterGrade << endl;



    return 0;
}
