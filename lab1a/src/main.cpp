#include <iostream>
#include "modes.h"

namespace test {
    int main_test(int argc, char* argv[]);
}

int main(int argc, char* argv[]) {

    test::main_test(argc,argv);

    bool check = true;

    while(check){
        cout << "Choose mode\n"
        << "1 - Interactive\n"
        << "2 - Demonstration\n"
        << "3 - benchmark\n"
        << "4 - exit\n";
        short action;
        cin >> action;
        switch (action){
            case 1: check = interactive();
                    break;
            case 2: check = demonstration();
                    break;
            case 3: check = benchmark();
                    break;
            case 4: check = false;
                    break;
            default: cout << "Choose correct number\n";
        }
    }
    return 0;
}
