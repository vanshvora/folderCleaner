#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include<cstdio>
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

int main() {
    vector<DATA> data=input("file.txt");
    
    return 0;
}
