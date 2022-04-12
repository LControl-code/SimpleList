#include "include/database.h"
// vpisovanie z mainListu najprv meno a az potom list
void Database::write(vector<vector<string>> mainList) {
        ofstream db;
        db.open("db/list.sl");

        if(db.is_open()) {
               for (int user_index = 0; user_index < (int)mainList[user_index].size(); user_index++) {
                       for(int list_index = 0; list_index < (int)mainList[user_index] [list_index].size(); list_index++){
                               db << mainList[user_index] [list_index] << '\n';
                       }
                }
        } else {
                cerr << "Cannot open file for writing.\n";
        }

        db.close();
}

// citanie zo suboru
vector<vector<string>> Database::read() {
        string line;
        ifstream db;
        vector<string> userlist;
        db.open("db/list.sl");
        
        if(db.is_open()) {
                while(getline(db, line, '\n')) { // zapisuje co najde do temp var line, ktora je pouzita do vectoru
                        if(line.front() == '#') {
                                cout << "Found a Hashtag: " << line << '\n';
                                line.erase(line.begin());
                                userlist.push_back(line);

                        } else if(line.front() == '%') { // % zaznamenava konec listu uzivatela
                                cout << "Found a Percentage:  " << line << '\n';
                                mainList.push_back(userlist); // zapisanie do hlavneho 2D vectora
                                userlist.clear(); // vycistenie na buduce pouzitie
                        } else {
                                cout << "Found an Item: " << line << '\n';
                                userlist.push_back(line);
                        }
                }
        } else {
                cerr << "Couldn't open file for reading.\n";
        }
        db.close();

        return mainList;
}