#include <iostream>
#include <string>
#include <cstring>

using namespace std;

// int main(){
//     int carrots;
//     cout << "How many carrots do you have?" << endl;
//     cin >> carrots;
//     cout << "I have " << carrots << " carrots." << endl;
//     carrots = carrots + 2;
//     cout << "Now, you have " << carrots << " carrots!" << endl;
//     return 0;

// }

// ---------------------------------P31 Q7
// int main(){
//     int hour, minutes;
//     cout << "Enter the number of hours: ";
//     cin >> hour;
//     cout << "Enter the number of minutes: ";
//     cin >> minutes;
//     cout << "Time: " << hour << ":" << minutes;
// }

// -------------------------------- P31 Q6
// double lightYearsToUnits(double years){
//     return 63240 * years;
// }

// int main(){
//     double years;
//     cout << "Enter the number of light years: ";
//     cin >> years;
//     cout << years << " light years = " << lightYearsToUnits(years) << " astronomical units." << endl;

// }

// --------------------------------- P31 Q5
/*
double CelsiusToFahrenheit(int);

int main(){
    double CelValue;
    cout << "Please enter a Celsius value: ";
    cin >> CelValue;
    cout << CelValue << " degrees Celsius is " << CelsiusToFahrenheit(CelValue) << " degrees Fahrenheit." << endl;
}

double CelsiusToFahrenheit(int x){
    return 1.8 *  x + 32.0;
}
    */
int main(){
    char ch;
    int count = 0;
    cout << "Enter a character: " << endl;

    cin >> ch;
    while(ch != '#'){
        cout << ch;
        ++count;
        cin >> ch;
    }
    cout << "Total characters entered (excluding #): " << count << endl;
    return 0;
}