#include <iostream>
#include <string>
#include <vector>
#include<fstream>
#include <iomanip>

using namespace std;

class Employee
{
public:    
    Employee();

    int register1(string, string);

    void Request_leave();
    void Request_overtime();

    void show_customer(string);

    void delete_customer(string);

    void set_information();

    void create_customer(string, string, string, string , string , string , string , string , int);

    void show();

    ~Employee();
   
private:
    string line;
    vector <string> List_Of_Users;
    vector <string> List_Of_Users2;
    string list;
    string temp;
    string List2;

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
Employee::Employee()
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


        ifstream mFile1 ("Customer.txt");  

        if(mFile1.is_open()) 
        {
            while(mFile1.peek()!=EOF)
            {
                getline(mFile1, line);
                List_Of_Users2.push_back(line);
            }
            mFile1.close();
        } 
   
}
int Employee::register1(string P, string U)
{
     for (int i = 0; i < List_Of_Users.size(); i++)
    {
        list = List_Of_Users[i];
        size_t found1 = list.find("*PW");
        size_t found01 = list.find(")PW-");

        size_t found3 = list.find("*U");
        size_t found03 = list.find(")U-");


        if(list.substr(found1 + 4,found01- found1 - 4) == P && list.substr(found3 + 3,found03- found3 - 3) == U)
        {
            size_t found2 = list.find("*PQ");
            size_t found02 = list.find(")PQ-");
            if(list.substr(found2 + 4,found02- found1 - 4) == "E")
            {
                place  = i;
                temp = list;
                set_information();
                return 1;
            }
            else if(list.substr(found2 + 4,found02- found2 - 4) == "B")
            {
                place  = i;
                temp = list;
                set_information();
                return 2;
            }
            
        }
        else{return 0;}
    }

    

}
void Employee::Request_leave()
{
        if(Leave > 15)
        {
            throw "Hours exceeded the allowable limit :(";
        }
        else
        {
            Leave++;
            Rights -= 100;
            cout << "Your request has been successfully submitted :)" << endl;
        }
    
}

void Employee::Request_overtime()
{
        if(overtime > 12)
        {
            throw "Hours exceeded the allowable limit :(";
        }
        else
        {
            overtime++;
            Rights += 120;
            cout << "Your request has been successfully submitted :)" << endl;

        }
     
}

void Employee::set_information()
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
}

void Employee::show()
{
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
}


void Employee::show_customer(string id)
{
    int check = 0;
    for (int i = 0; i < List_Of_Users2.size(); i++)
    {
        string List22 = List_Of_Users2[i];

        List2 = List22;
        size_t found3 = List2.find("*ID");
        size_t found03 = List2.find(")ID-");

        if(List2.substr(found3 + 4,found03- found3 - 4) == id)
        {
                size_t found1 = List2.find("*F");
                size_t found01 = List2.find(")F-");
                cout << "first name : " <<  List2.substr(found1 + 3,found01- found1 - 3) << endl;
        
                size_t found2 = List2.find("*L");
                size_t found02 = List2.find(")L-");
                cout << "last name: " << List2.substr(found2 + 3,found02- found2 - 3) << endl;
        
                size_t found3 = List2.find("*ID");
                size_t found03 = List2.find(")ID-");
                cout << "ID : " <<  List2.substr(found3 + 4,found03- found3 - 4) << endl;

                size_t found4 = List2.find("*B");
                size_t found04 = List2.find(")B-");
                cout << "Brithdate : "  <<  List2.substr(found4 + 3,found04- found4 - 3) << endl;
        
                size_t found5 = List2.find("*U");
                size_t found05 = List2.find(")U-");
                cout << "username : " <<  List2.substr(found5 + 3,found05- found5 - 3) << endl;
        
                size_t found6 = List2.find("*PW");
                size_t found06 = List2.find(")PW-");
                cout << "password" <<  List2.substr(found6 + 4,found06- found6 - 4) << endl;


                size_t found7 = List2.find("*PO");
                size_t found07 = List2.find(")PO-");
                cout << "postion" <<  List2.substr(found7 + 4,found07- found7 - 4) << endl;

                size_t found8 = List2.find("*NC");
                size_t found08 = List2.find(")NC-");
                cout << "number card" <<  List2.substr(found8 + 4,found08- found8 - 4) << endl;


                

                size_t found9 = List2.find("*Aa");
                size_t found09 = List2.find(")Aa-");
                cout << "all of money" <<  List2.substr(found9 + 4,found09- found9 - 4) << endl;

                cout << "************************************************************************************" << endl;

                check++;

        }
    }
    if(check == 0){cout << "user not found" << endl;}
}

void Employee::delete_customer(string ID)
{
    int check = 0;
    for (int i = 0; i < List_Of_Users2.size(); i++)
    {
        List2 = List_Of_Users[i];
        size_t found3 = List2.find("*ID");
        size_t found03 = List2.find(")ID-");

        
        if(List2.substr(found3 + 4,found03- found3 - 4) == ID)
        {
                    
            List_Of_Users2.erase(List_Of_Users2.begin() + i);
            cout << " your performance was excellent " << endl;
            cout << "--> successfully removed user :)" << endl;

            check++;
                   
        }
    }

    if(check == 0){cout << "User not found :(" << endl;}
}

void Employee::create_customer(string fname, string lanme, string id2, string b, string nc, string username, string password, string postion1, int all)
{
    string temp;


    temp = "";
    temp += "*F(";
    temp += fname;
    temp += ")F-";

    temp += "*L(";
    temp += lanme;
    temp += ")L-";


    temp += "*ID(";
    temp += id2;
    temp += ")ID-";
   

    temp += "*B(";
    temp += b;
    temp += ")B-";

    temp += "*U(";
    temp += username;
    temp += ")U-";


    temp += "*PW(";
    temp += password;
    temp += ")PW-";


    temp += "*PO(";
    temp += postion1;
    temp+= ")PO-";

    temp += "*NC(";
    temp += nc;
    temp += ")NC-";

    temp += "*Aa(";
    temp += std::to_string(all);
    temp += ")Aa-";

    List_Of_Users2.push_back(temp);

    cout << "coustomer added to list :)" << endl;
}

Employee::~Employee()
{
    ofstream myfile ("Customer.txt");  
    if(myfile.is_open())
    {
       
       for(int i = 0; i < List_Of_Users2.size(); i++)
          myfile << List_Of_Users2[i] << endl;

        myfile.close();
    }

    ofstream myfile1 ("Employee.txt");  
    if(myfile1.is_open())
    {
       
       for(int i = 0; i < List_Of_Users.size(); i++)
          myfile1 << List_Of_Users[i] << endl;

        myfile.close();
    }
}