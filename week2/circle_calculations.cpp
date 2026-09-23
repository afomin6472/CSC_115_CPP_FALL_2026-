#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    const double PI = 3.14159265359;

    double radius;
    double angle;
    double area;
    double circumference;
    double arcLength;

    cout << "Enter the radius of circle: ";
    cin >> radius;

    cout << "Enter the central angle in degrees: ";
    cin >> angle;
    area = PI * radius * radius;
    circumference = 2 * PI * radius;
    arcLength = (angle / 360.0) * 2 * PI * radius;

    cout << fixed << setprecision(2);
    cout << "\nCircle Calculations\n";
    cout << "-------------------\n";
    cout << "Radius: " << radius << "\n";
    cout << "Angle: " << angle << " degrees\n";
    cout << "\nArea: " << area << "\n";
    cout << "Circumference: " << circumference << "\n";
    cout << "Arc Length: " << arcLength << "\n";

    return 0; 
}
