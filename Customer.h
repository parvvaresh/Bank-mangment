#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;


class Customer
{
public:
    Customer();

    void set_information();

    int login(string, string);
    void change(string, int);
    void show();

    ~Customer();


private:
    string line;
    vector <string> List_Of_Users;
    string temp;
    string list;

    int place = 0;


    string last_name;
    string first_name;
    string id;
    string brithdate;
    string number_card;
    string username;
    string pass;
    string postion;

    int all;
    
};


Customer::Customer()
{
        ifstream mFile ("Customer.txt");  

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

int Customer::login(string P, string U)
{
    for (int i = 0; i < List_Of_Users.size(); i++)
    {
        list = List_Of_Users[i];
        size_t found1 = list.find("*PW");
        size_t found01 = list.find(")PW-");

        size_t found2 = list.find("*U");
        size_t found02 = list.find(")U-");
        if(list.substr(found1 + 4,found01- found1 - 4) == P && list.substr(found2 + 3,found02- found2 - 3) == U) 
        {
            place = i;

            set_information();
            return 1;

        }
        else{return 0;}
    }
       
}

void Customer::set_information()
{
        list = List_Of_Users[place];
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


        size_t found7 = list.find("*PO");
        size_t found07 = list.find(")PO-");
        postion =  list.substr(found7 + 4,found07- found7 - 4);

        size_t found8 = list.find("*NC");
        size_t found08 = list.find(")NC-");
        number_card =  list.substr(found8 + 4,found08- found8 - 4);


        string temp1;

        size_t found9 = list.find("*Aa");
        size_t found09 = list.find(")Aa-");
        temp1 =  list.substr(found9 + 4,found09- found9 - 4);

        all = stoi(temp1);    
}

void Customer::show()
{
    cout << "your information is : " << endl;
    cout << "first name : " << first_name << endl;
    cout << "last name : " << last_name << endl;
    cout << "id : " << id << endl;
    cout << "brithdate : " << brithdate << endl;
    cout << "username : " << username << endl;
    cout << "password : " << pass << endl;
    cout << "postion : " << postion << endl;
    cout << "number_card : " << number_card << endl;
    cout << "money : " << all << endl;
    cout << "------------------------*******************************--------------------------------" << endl;
}

void Customer::change(string test, int money)
{
    if(test == "+")
    {
        all += money;
        cout << "" << endl;
    }
    else if(test == "-")
    {
        if(all - money < 0){cout << " " << endl;}
        else if(all - money >= 0)
        {
            all -= money;
            cout << " " << endl;
        }
    }
    List_Of_Users[place] = "";
    List_Of_Users[place] += "*F(";
    List_Of_Users[place] += first_name;
    List_Of_Users[place] += ")F-";

    List_Of_Users[place] += "*L(";
    List_Of_Users[place] += last_name;
    List_Of_Users[place] += ")L-";


    List_Of_Users[place] += "*ID(";
    List_Of_Users[place] += id;
    List_Of_Users[place] += ")ID-";
   

    List_Of_Users[place] += "*B(";
    List_Of_Users[place] += brithdate;
    List_Of_Users[place] += ")B-";

    List_Of_Users[place] += "*U(";
    List_Of_Users[place] += username;
    List_Of_Users[place] += ")U-";


    List_Of_Users[place] += "*PW(";
    List_Of_Users[place] += pass;
    List_Of_Users[place] += ")PW-";


    List_Of_Users[place] += "*PO(";
    List_Of_Users[place] += postion;
    List_Of_Users[place] += ")PO-";

    List_Of_Users[place] += "*NC(";
    List_Of_Users[place] += number_card;
    List_Of_Users[place] += ")NC-";

    List_Of_Users[place] += "*Aa(";
    List_Of_Users[place] += std::to_string(all);
    List_Of_Users[place] += ")Aa-";
}
Customer::~Customer()
{
    ofstream myfile ("Customer.txt");  
    if(myfile.is_open())
    {
       
       for(int i = 0; i < List_Of_Users.size(); i++)
          myfile << List_Of_Users[i] << endl;

        myfile.close();
    }
}