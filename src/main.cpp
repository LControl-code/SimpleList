#include "include/list.h"
#include "include/database.h"
using namespace std;
int main(int arg_count, char *args[]){
        List simpleList;
        Database data;
        if(arg_count > 1) {
                simpleList.name = string(args[1]);
                simpleList.mainList = data.read();
                cin.get();

                simpleList.find_userlist();
                cin.get();
                
                simpleList.print_menu();
                // data.write(simpleList.list);
                // data.read();
        }  else {
                cout << "Username not supplied... exiting the program." << endl;
        }
        return 0;
}