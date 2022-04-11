#include "include/list.h"

void List::print_menu() {
        system("clear");
        int choice;

        cout << "************************\n";
        cout << " 1 - Print list.\n";
        cout << " 2 - Add to list.\n";
        cout << " 3 - Delete from list.\n";
        cout << " 4 - Quit.\n";
        cout << "Enter your choice and press return:  ";

        cin >> choice;
        switch (choice)
        {
        case 1:
                print_list();
                break;
        case 2:
                add_item();
                break;
        case 3:
                delete_item();
                break;
        case 4:
                return;
        default:
                cout << "Sorry choice not implemented yet.\n";
                break;
        }
}

void List::add_item() {
        system("clear");
        cout << "**** Add item ***\n";
        cout << "Type in an item and press enter:  ";

        string item;
        cin.ignore();
        getline(cin, item); 
        

        list.push_back(item);
        cout << "Successfully added an item to the list.\n";
        cin.clear();
        system("clear");

        print_menu();

}

void List::delete_item() {
        system("clear");
        cout << "**** Delete item ***\n";
        cout << "Select an item index number to delete:\n";
        
        if(list.size()) {
                for (int i = 0; i < (int)list.size(); i++) {
                        cout << i+1 << ":  "<< list[i] << "\n";
                }
        } else {
                cout << "There are no items to delete.\n";
        }
        
        
        int choice_num;
        cin >> choice_num;
        list.erase(list.begin()+choice_num-1);

        print_menu();
}

void List::print_list() {
        system("clear");
        cout << "*** Printing list ***\n";
        
        if(list.size()) {
                for (int list_index = 0; list_index < (int)list.size(); list_index++) {
                        cout <<" * "<< list[list_index] << "\n";
                }
        } else {
                cout << "There are no items to print.\n";
        }

        cout << "M - Menu\n";
        char choice;
        cin >> choice;

        system("clear");

        if(choice == 'M' || choice == 'm') {
                print_menu();
        } else {
                cout << "Invalid argument. Quiting...\n";
        }
}

void List::find_userlist() {
        bool user_Found = false;

        system("clear");
        cout << "*** Welcome " << name << " ***\n";

        for(int user_index = 0; user_index < (int)mainList.size(); user_index++){
                cout << mainList[user_index][0] << '\n';
                if(mainList[user_index][0] == name){
                        cout << "User has been found: " << mainList[user_index][0] << '\n';
                        list = mainList[user_index];
                        user_Found = true;
                        break;
                }
        }
}