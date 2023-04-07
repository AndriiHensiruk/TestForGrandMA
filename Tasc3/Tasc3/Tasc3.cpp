#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    ifstream fin("Treasure_1_Small.in");

    if (fin.is_open()) {

        ifstream fin;
        fin.open("Treasure_1_Small.in");
        char ch;
        while (fin.get(ch))
            cout << ch;
        fin.close();
        system("pause");
    }
    else {
        cout << "File not found" << endl;
        system("pause");
    }

    return 0;
}