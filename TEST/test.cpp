#include <iostream>
using namespace std;

int
main (int argc, char *argv[])
{
    int input = 0;
    while (1) {
        cin >> input;
        if (42 == input)
            return 0;
        cout << input << endl;
    }
}
