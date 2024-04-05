#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include<cstdio>
#include<ctime>
using namespace std;
class DATA {
public:
    string foldername;
    string filename;
    string path;
    int date;
    int month;
    int year;
    int accessed;
};
bool comparedate(DATA a,DATA b){
       if(a.year!=b.year){
        return a.year<b.year;
       }
       if(a.month!=b.month){
        return a.month<b.month;
       }
       return a.date<b.date;
}
int getnoofmonthold(DATA a){
time_t currentTime = time(nullptr);
tm current_tm = *localtime(&currentTime);
int year = current_tm.tm_year + 1900; 
int month = current_tm.tm_mon + 1;
int yeardiff,monthdiff;
yeardiff=year-a.year;
monthdiff=month-a.month;
return a.month + 12*yeardiff;
}

void clean(vector<DATA>& data,int M,int A){
for(int i=1;i<data.size();i++){
    if(data[i].accessed<A){
        deletefile(data[i]);
        continue;
    }
    if(FileEmpty(data[i].path)){
        deletefile(data[i]);
        break;
    }
    int m;
    m=getnoofmonthold(data[i]);
    if(m>M){
        deletefile(data[i]);
    }
  for(int j=i+1;j<data.size();j++){
        if(data[i].filename==data[j].filename){
          if(comparedate(data[i],data[j])){
             deletefile(data[i]);
             break;
          }
          else{
            deletefile(data[j]);
            break;
          }

        }
    }
}
}
vector<DATA> input(string inputfile) {
    vector<DATA> data;
    ifstream ip(inputfile);
     
    if (!ip.is_open()) {
        cout << "Error: Unable to open file: " << inputfile << endl;
        return data;
    }
    DATA b;
    getline(ip,b.foldername);
    data.push_back(b);
    string line;
    while (getline(ip, line)) {
        DATA a;
        string date, month, year, access;
        stringstream word(line);
        getline(word,a.filename,',');
        getline(word, a.path, ',');
        getline(word, date, '/');
        a.date = stoi(date);
        getline(word, month, '/');
        a.month = stoi(month);
        getline(word, year, ',');
        a.year = stoi(year);
        getline(word, access);
        a.accessed = stoi(access);

        data.push_back(a);
    }
     ip.close();
    return data;
}
int main() {
    vector<DATA> data=input("file.txt");
    
    return 0;
}
