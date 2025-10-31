#include <iostream>
#include <cstring>
using namespace std;

int main() {
    const int size = 15;
    char name1[size];
    char name2[size] = "C++owboy";

    // cout << "Howdy! I'm " << name2;
    // cout << "! What's your name? ";
    // cin >> name1;
    // cout << "Well, " << name1 << ", your name has ";
    // cout << strlen(name1) << " letters and is stored\n";
    // cout << "in an array of " << sizeof(name1) << " bytes.\n";
    // cout << "Your initial is " << name1[0] << ".\n";
    // name2[3] = '\0';
    // cout << "here are the first 3 letters of my name: ";
    // cout << name2 << endl;
    cin.get(name1, size);
    cin.get(name2, size);
    cout << "Here is your full name: " << name1 << " " << name2 << endl;
    return 0;
}
