#include <iostream>
#include "main.h"

using namespace std;

class phone {
private:
    int homePhone = 0;
protected:
    int phoneNo=0;

    void cellWithHomeGetter(){
        cout<<"Home No is: "<<phoneNo<<endl;
        cout<<"==========================================="<<endl;
    }

public:
    phone() {
        homePhone=44444444;
        //cout << "ring" << endl;//2

    }

    phone(int no){
        cout<<"==========================================="<<endl;
        cout<<"Home and Cell No are same, No is: "<<no<<endl;
    }


    ~phone() {
        //cout << "hangup" << endl;  //5
        phoneNo=0;
        homePhone=0;
        cout<<"**********************"<<endl;
    }

    virtual void waitMsg(){
        cout<<"above is your ** home phone ** description"<<endl<<endl<<endl;
    }
   // virtual void waitMsg() const =0;
    void homegetter(){
        cout<<"==========================================="<<endl;
        cout<<"Plan 1----only homephone"<<endl;
        cout<<"temp phoneNo is:"<<homePhone<<endl;
        cout<<"==========================================="<<endl;

    }

};


class cellphone:phone{
private:
    int cellPhoneNo=0;
public:

    void waitMsg()const{
        cout<<"above is your ** Cellphone ** description"<<endl<<endl<<endl;
    }

    cellphone(){
        cellPhoneNo=55555555;


    }
    cellphone(int freehomeNo):phone(freehomeNo){ // advanced version cellphone(int freehomeNo):phone(freehomeNo)
        cellPhoneNo=freehomeNo;
        phoneNo=freehomeNo;  //from phone class

    }
    void cellphoneGetter(){
        cout<<"==========================================="<<endl;
        cout<<"Plan 2----cellphone only "<<endl;
        cout<<"temp no is: "<<cellPhoneNo<<endl;
        cout<<"==========================================="<<endl;
    }
    void cellPlusHomeGetter(){

        cout<<"Plan 3----homephone + cellphone"<<endl;
        cout<<"Cell  No is: "<<cellPhoneNo<<endl;
        cellWithHomeGetter();
    }

    friend void thankMsg(){
        cout<<"thank you for using xxx phone service!"<<endl;
    }
};

void thankMsg();


int main() {

    //cout<<"hello"<< endl;  //1
    phone P;
    P.homegetter();
    P.waitMsg();

    cellphone C;
    C.cellphoneGetter();
    C.waitMsg();

    cellphone c2(777777);
    c2.cellPlusHomeGetter();

    thankMsg();


//    std::cout << "Hello, World!" << std::endl;
    return 0;
}


//1. homePhone
//2. cellphone+homePhone
//3  cellphone