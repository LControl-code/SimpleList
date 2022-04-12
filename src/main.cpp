#include "include/list.h"
#include "include/database.h"
using namespace std;
int main(int arg_count, char *args[]){
        List simpleList;
        Database data;
        if(arg_count > 1) {
                simpleList.name = string(args[1]); // ulozenie prveho argumentu ako meno
                simpleList.mainList = data.read(); // test - vypisanie zo suboru veci co najde
                cin.get(); // cakanie na vstup
                simpleList.find_userlist(); // vyhlada podla mena z toho listu, dalej to ulozi a bude vypisovat len to v programe
                cin.get();
                
                simpleList.print_menu(); // obycajny program vypisovania
                // data.write(simpleList.mainLlist);
        }  else {
                cout << "Username not supplied... exiting the program." << endl;
        }
        return 0;
}