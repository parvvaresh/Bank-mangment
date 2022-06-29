#include <iostream>
#include <string>
#include <vector>
#include<fstream>

using namespace std;
class time1
{
public:    
    time1();
    void login(string, string, string, string);
    void see_informational(string, string, string, string, string);
    void request1(string, string, string, string);
    void money(string, string, string, int);

    void delete1(string, string, string, string, string);

    void add(string, string, string, string, string);


    ~time1();
private:
    vector <string>List_Of_Users;
    string line;
    string temp;
};

time1::time1()
{
    ifstream mFile ("report.txt");  

    if(mFile.is_open()) 
    {
        while(mFile.peek()!=EOF)
        {
          getline(mFile, line);
          List_Of_Users.push_back(line);
        }
        mFile.close();
    }
}
void time1::login(string time2, string id, string pos, string A)
{
    temp = "";
    temp += pos;
    temp += "with identification number : ";
    temp += id;
    temp += "in the time : ";
    temp += time2;
    temp += "login in system : ";
    temp += A;
}

void time1::see_informational(string time2 , string id1, string id2, string pos1, string pos2)
{
    temp = "";
    temp += pos1;
    temp += "with identification number : ";
    temp += id1;
    temp += "in the time : ";
    temp += time2;
    temp += "see information who  : ";
    temp += pos2;
    temp += "with identification number : ";
    temp += id2; 
}

void time1::request1(string time2, string id, string re, string pos)
{
    temp = "";
    temp += pos;
    temp += "with identification number : ";
    temp += id;
    temp += "in the time : ";
    temp += time2;
    temp += "requsted  : ";
    temp += re;
   
}
void time1::money(string time2, string id, string re, int m)
{
    temp = "";
    temp += "with identification number : ";
    temp += id;
    temp += "in the time : ";
    temp += time2;
    temp += "requsted  money : ";
    temp += re;
    temp += std::to_string(m);
}

void time1::delete1(string time2, string id1, string id2, string pos1, string pos2)
{
    temp = "";
    temp += pos1;
    temp += "with identification number : ";
    temp += id1;
    temp += "in the time : ";
    temp += time2;
    temp += "delete  : ";
    temp += pos2;
    temp += "with identification number : ";
    temp += id2;
}
void time1::add(string time2, string id1, string id2, string pos1, string pos2)
{
    temp = "";
    temp += pos1;
    temp += "with identification number : ";
    temp += id1;
    temp += "in the time : ";
    temp += time2;
    temp += "added   : ";
    temp += pos2;
    temp += "with identification number : ";
    temp += id2;    
}
time1::~time1()
{
    ofstream myfile ("report.txt");  
    if(myfile.is_open())
    {
       
       for(int i = 0; i < List_Of_Users.size(); i++)
          myfile << List_Of_Users[i] << endl;

        myfile.close();
    }
}