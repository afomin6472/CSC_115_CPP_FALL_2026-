#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int main()
 {  
  
    // Variables
    string searchCourse;
   bool found;
 
    const int MAX_COURSES = 20;

    string courseIDs[MAX_COURSES];

    double grades[MAX_COURSES];

    int numberOfCourses = 0;
    int choice;

do
{
   
    // Menu 
    cout << "\nCourse Grades Menu\n";
    cout << "-----------------\n";
    cout << "1. Enter Number of Courses\n";
    cout << "2. Display a Specific Course and Grade\n";
    cout << "3. Display All Courses and Grades\n";
    cout << "4. Display Overall Average and Letter Grade\n";
    cout << "5. Exit\n";
    
    cout << "Enter your choice: ";
    cin >> choice;
    
    // Menu choices
    switch (choice)
{
    case 1:
        
        // Input section
        cout << "Enter number of courses: ";
    cin >> numberOfCourses;

    if (numberOfCourses < 1 || numberOfCourses > MAX_COURSES)
    {
        cout << "Invalid number of courses.\n";
        numberOfCourses = 0;
    }
    else
    {
        for (int i = 0; i < numberOfCourses; i++)
        {
            cout << "Course " << i + 1 << " ID: ";
            cin >> courseIDs[i];

            cout << "Grade: ";
            cin >> grades[i];
        }
    }
        break;

    case 2:
       
        // Search section
        cin >> searchCourse;

    found = false;

    for (int i = 0; i < numberOfCourses; i++)
    {
        if (courseIDs[i] == searchCourse)
        {
            cout << courseIDs[i] << ": "
                 << grades[i] << endl;

            found = true;
        }
    }

    if (!found)
    {
        cout << "Course not found.\n";
    }
        break;

    case 3:

    // Output section
    if (numberOfCourses == 0)
    {
        cout << "No courses entered yet.\n";
    }
    else
    {
        cout << "\nCourses and Grades\n";
        cout << "------------------\n";

        for (int i = 0; i < numberOfCourses; i++)
        {
            cout << courseIDs[i] << ": "
                 << grades[i] << endl;
        }
    }
        break;

    case 4:
        
        // Average calculation
        {
    if (numberOfCourses == 0)
    {
        cout << "No courses entered yet.\n";
    }
    else
    {
        double total = 0;
        double average;
        char letterGrade;

        for (int i = 0; i < numberOfCourses; i++)
        {
            total += grades[i];
        }

        average = total / numberOfCourses;

        if (average >= 90)
        {
            letterGrade = 'A';
        }
        else if (average >= 80)
        {
            letterGrade = 'B';
        }
        else if (average >= 70)
        {
            letterGrade = 'C';
        }
        else if (average >= 60)
        {
            letterGrade = 'D';
        }
        else
        {
            letterGrade = 'F';
        }

        cout << fixed << setprecision(2);
        cout << "Average Grade: " << average << endl;
        cout << "Letter Grade: " << letterGrade << endl;
    }
        break;
}
    case 5:
      
        // Exit  
        cout << "Goodbye !\n";
        break;

        // Invalid Output
        default:
        cout << "Invalid choice.\n";


    }


} while (choice != 5);










return 0;

}
