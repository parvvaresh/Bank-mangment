#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <ctime>


#include "Customer.h"
#include "Employee.h"
#include "Boss.h"
#include "Time.h"
using namespace std;

int main(void)
{
    class time1 t;
    cout << "hello to international bank" << endl;
    cout << "are you ' Customer' or 'Employee'?" << endl;
    cout << "for finished Enter 'Exit'" << endl;
    string user = "";
    cin >> user;
    while(user !=  "Exit")
    {
       if(user == "Customer")
            {
                class Customer c;
                string pw , u;
                cout << "for register in your account entered pass word" << endl;
                cin >> pw;
                cin >> u;
                if(c.login(pw, u) == 1)
                {
                    time_t l = time(NULL);
                    char* timee = ctime(&l);
                    t.login(timee, u, "Customer", "successfully");


                    cout << "what do you do?" << endl;
                    cout << "---Withdraw or deposit money----> for this type money" << endl;
                    cout << "---see details-----> for this type see" << endl;
                    cin >> user;
                    if(user == "see")
                    {
                        time_t x = time(NULL);
                        char* timee = ctime(&x);
                        t.see_informational(timee, u, u, "Customer", "Customer");
                        c.show();
                    }
                    else if(user == "money")
                    {
                        cout << "If you want to increase the credibility of your account, enter +" << endl;
                        cout << "If you want to reduce the credit of your account  enter - " << endl;
                        cin >> user;
                        if(user == "+")
                        {
                            cout << "Enter the amount of money you want to deposit : ";
                            int money = 0;
                            cin >> money;
                            c.change("+", money);


                            time_t f = time(NULL);
                            char* timee = ctime(&f);
                            t.money(timee, u, "add money" , money);
                        }
                        else if(user == "-")
                        {
                            cout << "Enter the amount of money you want to withdraw from your account : ";
                            int money = 0;
                            cin >> money;
                            c.change("-", money);


                            time_t f = time(NULL);
                            char* timee = ctime(&f);
                            t.money(timee, u, "maines money" , money);
                        }
                    }
                }
            } 
            else if (user == "Employee")
            {
                class Employee e;
                string pw , u;
                cout << "for register in your account entered pass word" << endl;
                cin >> pw;
                cin >> u;
                if(e.register1(pw,u) == 1)
                {
                    time_t l1 = time(NULL);
                    char* timee = ctime(&l1);
                    t.login(timee, u, "Employee", "successfully");                  
                    cout << "hello employee:))))))))))))" << endl;
                    cout << "what do you do ?" << endl;
                    cout << "-------------Request leave" << endl;
                    cout << "-------------Request overtime" << endl;
                    cout << "-------------show customer" << endl;
                    cout << "-------------delete customer" << endl;
                    cout << "-------------create customer" << endl;
                    cout << "-------------show your information" << endl;
                    cout << "------------------------------------------------------------" << endl;
                    string U;
                    getline(cin, U);
                    if(U == "Request leave")
                    {
                        e.Request_leave();

                        time_t z = time(NULL);
                        char* timee = ctime(&z);
                        t.request1(timee, u, "Leave", "Employee");
                    }
                    else if(U == "Request overtime")
                    {
                        e.Request_overtime();
                        time_t z = time(NULL);
                        char* timee = ctime(&z);
                        t.request1(timee, u, "overtime", "EMployee");
                    }


                    else if(U == "show customer")
                    {
                        cout << "Please enter the customer national number : " ;
                        string temp;
                        cin >> temp;
                        e.show_customer(temp);

                        time_t x = time(NULL);
                        char* timee = ctime(&x);
                        t.see_informational(timee, u, temp, "Employee", "Customer");
                    }

                    else if(U == "delete customer")
                    {
                    
                        cout << "Please enter the customer national number : " ;
                        string temp;
                        cin >> temp;
                        e.delete_customer(temp);


                        time_t q = time(NULL);
                        char* timee = ctime(&q);
                        t.delete1(timee, u, temp, "Employee", "Customer");
                    }                       
                
                    else if(U == "create customer")
                    {
                        string fname, lname, id, b, nc, username, pass, postion;

                        int all;

                        cout << "Please enter a frist name : " ;
                        cin >> fname;

                        cout << "Please enter a last name : ";
                        cin >> lname;

                        cout << "Please enter a id : ";
                        cin >> id;

                        cout << "Please enter a brithdate : ";
                        cin >> b;

                        cout << "Please enter a number card : ";
                        cin >> nc;

                        cout << "Please enter a username : ";
                        cin >> username;

                        cout << "Please enter a password : ";
                        cin >> pass;
                        

                        cout << "Please enter a postion : ";
                        cin >> postion;

                        cout << "Please enter a all : ";
                        cin >> all;

                        e.create_customer(fname, lname, id, b, nc, username, pass, postion, all);

                        time_t b1 = time(NULL);
                        char* timee = ctime(&b1);

                        t.add(timee, u, username, "Employee" , "customer");

                    }
                    else if(U == "show your information")
                    {
                        e.show();
                        time_t x = time(NULL);
                        char* timee = ctime(&x);
                        t.see_informational(timee, u, u, "Employee", "Employee");
                    }

                }
                else if(e.register1(pw, u) == 2)
                {

                    time_t l2 = time(NULL);
                    char* timee = ctime(&l2);
                    t.login(timee, u, "Boss", "successfully");  
                    class Boss b;
                    cout << "hello boss" << endl;
                    cout << "what do you do ?" << endl;
                    cout << "-------------Request leave" << endl;
                    cout << "-------------Request overtime" << endl;
                    cout << "-------------show customer" << endl;
                    cout << "-------------delete customer" << endl;
                    cout << "-------------create customer" << endl;
                    cout << "-------------show your information" << endl;
                    cout << "-------------add employe" << endl;
                    cout << "-------------delete employee" << endl;
                    cout << "-------------show information of employee" << endl;
                    cout << "------------------------------------------------------------" << endl;
                    string U;
                    getline(cin, U);
                    if(U == "Request leave")
                    {
                        e.Request_leave();
                        time_t z = time(NULL);
                        char* timee = ctime(&z);
                        t.request1(timee, u, "Leave", "Boss");
                    }
                    else if(U == "Request overtime")
                    {
                        e.Request_overtime();

                        time_t z = time(NULL);
                        char* timee = ctime(&z);
                        t.request1(timee, u, "overtime", "Boss");
                        
                    }

                    else if(U == "show customer")
                    {
                        cout << "Please enter the customer national number : " ;
                        string temp;
                        cin >> temp;
                        e.show_customer(temp);

                        time_t x = time(NULL);
                        char* timee = ctime(&x);
                        t.see_informational(timee, u, temp, "Boss", "Customer");
                    }

                    else if(U == "delete customer")
                    {
                    
                        cout << "Please enter the customer national number : " ;
                        string temp;
                        cin >> temp;
                        e.delete_customer(temp);

                        time_t q = time(NULL);
                        char* timee = ctime(&q);

                        t.delete1(timee, u, temp, "Boss", "Customer");
                    }                       
                
                    else if(U == "create customer")
                    {
                        string fname, lname, id, b, nc, username, pass, postion;

                        int all;

                        cout << "Please enter a frist name : " ;
                        cin >> fname;

                        cout << "Please enter a last name : ";
                        cin >> lname;

                        cout << "Please enter a id : ";
                        cin >> id;

                        cout << "Please enter a brithdate : ";
                        cin >> b;

                        cout << "Please enter a number card : ";
                        cin >> nc;

                        cout << "Please enter a username : ";
                        cin >> username;

                        cout << "Please enter a password : ";
                        cin >> pass;
                        

                        cout << "Please enter a postion : ";
                        cin >> postion;

                        cout << "Please enter a all : ";
                        cin >> all;

                        e.create_customer(fname, lname, id, b, nc, username, pass, postion, all);


                        
                        time_t b1 = time(NULL);
                        char* timee = ctime(&b1);

                        t.add(timee, u, username, "Boss" , "customer");

                    }
                    else if(U == "show your information")
                    {
                        e.show();

                        time_t x = time(NULL);
                        char* timee = ctime(&x);
                        t.see_informational(timee, u, u, "Employee", "Customer");
                    }
                    else if(U == "add employe")
                    {
                        string fname, lname, id, b, username, pass, postion, nc;

                        int R,O,L;

                        cout << "Please enter a frist name : " ;
                        cin >> fname;

                        cout << "Please enter a last name : ";
                        cin >> lname;

                        cout << "Please enter a id : ";
                        cin >> id;

                        cout << "Please enter a brithdate : ";
                        cin >> b;

                

                        cout << "Please enter a username : ";
                        cin >> username;

                        cout << "Please enter a password : ";
                        cin >> pass;
                        

                        cout << "Please enter a postion : ";
                        cin >> postion;

                        cout << "Please enter a all : ";
                        cin >> R;


                        cout << "Please enter a overtime : ";
                        cin >> O;

                        cout << "Please enter a leave time : ";
                        cin >> L;


                        //b.add_employee(lname, fname, id, b, username, pass, postion, R,O,L);

                        
                        time_t b1 = time(NULL);
                        char* timee = ctime(&b1);

                        t.add(timee, u, username, "Boss" , "Emplyee");


                    }
                    else if(U == "delete employee")
                    {
                        cout << "Please enter the id : " ;
                        string temp;
                        cin >> temp;
                        b.delete_employee(temp);


                        time_t q = time(NULL);
                        char* timee = ctime(&q);
                        t.delete1(timee, u, temp, "Boss", "Employee");

                    }
                    else if(U == "show information of employee")
                    {
                        cout << "Please enter the id : " ;
                        string temp;
                        cin >> temp;
                        b.show_employee(temp);


                        time_t x = time(NULL);
                        char* timee = ctime(&x);
                        t.see_informational(timee, u, temp, "Boss", "Employee");

                    }

                }
            

            }

      

            cin >> user;
    }
    
}   


