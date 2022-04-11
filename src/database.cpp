#include "include/database.h"

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

vector<vector<string>> Database::read() {
        string line;
        ifstream db;
        vector<string> userlist;
        db.open("db/list.sl");
        
        if(db.is_open()) {
                while(getline(db, line, '\n')) {
                        if(line.front() == '#') {
                                cout << "Found a Hashtag: " << line << '\n';
                                line.erase(line.begin());
                                userlist.push_back(line);

                        } else if(line.front() == '%') {
                                cout << "Found a Percentage:  " << line << '\n';
                                mainList.push_back(userlist);
                                userlist.clear();
                        } else {
                                cout << "Found an Item: " << line << '\n';
                        }
                }
        } else {
                cerr << "Couldn't open file for reading.\n";
        }
        db.close();

        return mainList;
}