#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include<cstdio>
using namespace std;

class DATA {
public:
    string path;
    int date;
    int month;
    int year;
    int accessed;
};
void deletefile(DATA a){
      remove(a.path.c_str());
}
vector<DATA> input(string inputfile){
     vector<DATA> data;
    ifstream ip(inputfile);

   

    string line;
    while (getline(ip, line)) {
        DATA a;
        string date,month,year,access;
        stringstream word(line);

        getline(word, a.path, ',');
        getline(word, date, '/');
        a.date = stoi(date);
        getline(word,month, '/');
        a.month = stoi(month);
        getline(word,year, ',');
        a.year = stoi(year);
        getline(word,access);
        a.accessed = stoi(access);
        data.push_back(a);
    }
cout<<"hi";
    for (int i=0;i<data.size();i++) {
        cout<<"in";
        cout << "Path: " << data[i].path << ", Date: " << data[i].date << ", Month: " << data[i].month << ", Year: " << data[i].year
             << ", Times Opened: " << data[i].accessed << endl;
    }
cout<<"by";

    ip.close();
    return data;
}
int main() {
    vector<DATA> data=input("file.txt");
    
    return 0;
}
