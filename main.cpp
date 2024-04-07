#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <ctime>
using namespace std;

class DATA {
public:
    string filename;
    string path;
    int date;
    int month;
    int year;
    int accessed;
    DATA* next;
};
DATA* head=nullptr;
DATA* tail=nullptr;
void deletefile(string path){
      remove(path.c_str());
      
}
bool FileEmpty(string& Path) {
    ifstream file(Path,ios::ate);
    return file.tellg() == 0;
}
bool comparedate(DATA a,DATA b){
       if(a.year!=b.year){
        return a.year<b.year;
       }
       if(a.month!=b.month){
        return a.month<b.month;
       }
       return a.date<b.date;
}
int getnoofmonthold(int createdyear,int createdmonth){
time_t currentTime = time(nullptr);
tm current_tm = *localtime(&currentTime);
int year = current_tm.tm_year + 1900; 
int month = current_tm.tm_mon + 1;
int yeardiff,monthdiff;
yeardiff=year-createdyear;
monthdiff=month-createdmonth;
return monthdiff + 12*yeardiff;
}
void clean(int M,int A){
    DATA* temp=head;
while(temp!=NULL){
    int m;
    m=getnoofmonthold(temp->year,temp->month);
    if(temp->accessed<A){
        deletefile(temp->path);
    }
    else if(FileEmpty(temp->path)){
        deletefile(temp->path);
    }
   
    else if(m>M){
        deletefile(temp->path);
    }
    else {
    DATA* temp2=temp->next;
    DATA* temp3=temp;
    while(temp2!=NULL){
        if(temp->filename==temp2->filename){
          if(comparedate(*temp,*temp2)){
             deletefile(temp->path);
          }
          else{
            deletefile(temp2->path);
            temp3->next=temp2->next;
          }

        }
         temp2=temp2->next;
         temp3=temp3->next;
    }
    }
    temp=temp->next;
}
}

int main() {
   
    string inputfile;
    cout<<"Enter the input file: "; 
    cin>>inputfile;
    
    
    ifstream ip(inputfile.c_str());
     
    if (!ip.is_open()) {
        cout << "Error: Unable to open input file: " << inputfile << endl;
        return 0;
    }
    string foldername;
    getline(ip,foldername);
    string line;
    while (getline(ip, line)) {
        DATA* a=new DATA;
        string date, month, year, access;
        stringstream word(line);
        getline(word,a->filename,',');
        getline(word, a->path, ',');
        getline(word, date, '/');
        a->date = stoi(date);
        getline(word, month, '/');
        a->month = stoi(month);
        getline(word, year, ',');
        a->year = stoi(year);
        getline(word, access);
        a->accessed = stoi(access);
        if(head==nullptr){
        head=a;
        tail=a;
          }
        else{
        tail->next=a;
        tail=a;
        tail->next=nullptr;
          }
      
    }
      DATA* temp=head;
       cout<<"This is data stored in input file: "<<endl;
      while(temp!=NULL) {
        cout <<"File Name: "<<temp->filename<<  ", Date: " << temp->date << "/" << temp->month << "/" << temp->year
             << ", Times Opened: " << temp->accessed << endl;
             temp=temp->next;
    }
 
    ip.close();
    int minaccess,monthold;
    cout<<"Enter Minimum no of month old files to be deleted: ";
    cin>>monthold;
    cout<<"Enter Minimum no of time accessed files to be deleted:";
    cin>>minaccess;
    clean(monthold,minaccess);
    cout<<"your folder: "<<foldername<<" is cleaned ";
    return 0;
}
