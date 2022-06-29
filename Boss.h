#include <iostream>
#include <string>
#include <vector>
#include<fstream>
#include <iomanip>


using namespace std;


class Boss
{
public:
    Boss();
    void show_employee(string);
    void delete_employee(string);
    void add_employee(string, string, string, string, string, string, string, int , int , int);
    


    ~Boss();
private:
    string line;
    vector <string> List_Of_Users;
    vector <string> List_Of_Users2;
    string list;
    string temp;
    string List2;
    string List;

    int place = 0;


    string last_name;
    string first_name;
    string id;
    string brithdate;
    string postion;
    string pass;
    string username;
    int Rights = 0;
    int overtime = 0;
    int Leave = 0;
    
};
Boss::Boss()
{
    ifstream mFile ("Employee.txt");  

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
void Boss::delete_employee(string ID)
{
    int check = 0;
    for (int i = 0; i < List_Of_Users.size(); i++)
    {
        List = List_Of_Users[i];
        size_t found3 = List2.find("*ID");
        size_t found03 = List2.find(")ID-");

        
        if(List2.substr(found3 + 4,found03- found3 - 4) == ID)
        {
                    
            List_Of_Users.erase(List_Of_Users2.begin() + i);
            cout << " your performance was excellent " << endl;
            cout << "--> successfully removed user :)" << endl;

            check++;
                   
        }
    }

    if(check == 0){cout << "User not found :(" << endl;}
}

void Boss::show_employee(string ID)
{
    
    int check = 0;
    for (int i = 0; i < List_Of_Users.size(); i++)
    {
        string List22 = List_Of_Users[i];

        list = List22;
        size_t found3 = list.find("*ID");
        size_t found03 = list.find(")ID-");
        if(list.substr(found3 + 4,found03- found3 - 4) == ID)
        {

            size_t found1 = list.find("*F");
            size_t found01 = list.find(")F-");
            first_name = list.substr(found1 + 3,found01- found1 - 3);
        
            size_t found2 = list.find("*L");
            size_t found02 = list.find(")L-");
            last_name = list.substr(found2 + 3,found02- found2 - 3);
        
            size_t found3 = list.find("*ID");
            size_t found03 = list.find(")ID-");
            id =  list.substr(found3 + 4,found03- found3 - 4);

            size_t found4 = list.find("*B");
            size_t found04 = list.find(")B-");
            brithdate = list.substr(found4 + 3,found04- found4 - 3);
        
            size_t found5 = list.find("*U");
            size_t found05 = list.find(")U-");
            username =  list.substr(found5 + 3,found05- found5 - 3);
        
            size_t found6 = list.find("*PW");
            size_t found06 = list.find(")PW-");
            pass =  list.substr(found6 + 4,found06- found6 - 4);


            string temp1;

        
            size_t found7 = list.find("*M");
            size_t found07 = list.find(")M-");
            temp1 =  list.substr(found7 + 3,found07- found7 - 3);

            Rights = stoi(temp1);

            size_t found8 = list.find("*O");
            size_t found08 = list.find(")O-");
            temp1 =  list.substr(found8 + 3,found08- found8 - 3);

            overtime = stoi(temp1);

            size_t found9 = list.find("*A");
            size_t found09 = list.find(")A");
            temp1 =  list.substr(found9 + 3,found09- found9 - 3);

            Leave = stoi(temp1);


            size_t found10 = list.find("*PQ");
            size_t found001 = list.find(")PQ-");
            postion =  list.substr(found10 + 4,found001- found10 - 4);











            cout << "your information is  : " << endl;
            cout << "first name : " << first_name << endl;
            cout << "last name : " << last_name << endl;
            cout << "ID : " << id << endl;
            cout << "Brithdate : " << endl;
            cout << "username : " << endl;
            cout << "password : " << pass << endl;
            cout << "postion : " << postion << endl;
            cout << "overtime : " << overtime << endl;
            cout << "leave : " << Leave << endl;
            cout << "your money : " << Rights << endl;       

            check++;     

        }
	}

    if(check == 0){cout << "user not found :)" << endl;}




}
void Boss::add_employee(string lname, string fname, string ii, string b, string user, string pass1, string pos, int R1 , int O, int L)
{
    string temp = "";


    temp += "*F(";
    temp += fname;
    temp += ")F-";

    temp += "*L(";
    temp += lname;
    temp += ")L-";


    temp += "*ID(";
    temp += ii;
    temp += ")ID-";
   

    temp += "*B(";
    temp += b;
    temp += ")B-";

    temp += "*U(";
    temp += user;
    temp += ")U-";


    temp += "*PW(";
    temp += pass1;
    temp += ")PW-";


    temp += "*M(";
    temp += std::to_string(R1);
    temp += ")M-";

    temp += "*O(";
    temp += std::to_string(O);
    temp += ")O-";

    temp += "*A(";
    temp += std::to_string(L);
    temp += ")A-";

    temp += "*PQ(";
    temp += pos;
    temp += ")PQ-";

    List_Of_Users.push_back(temp);


    cout << "employee add was successfully :)" << endl;

}

Boss::~Boss()
{
    ofstream myfile ("Employee.txt");  
    if(myfile.is_open())
    {
       
       for(int i = 0; i < List_Of_Users.size(); i++)
          myfile << List_Of_Users[i] << endl;

        myfile.close();
    }
}