// This program helps in creating an account, making transaction similar to the concept of bitcoin and blockchain
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class person {
    private:
        string name;
    public:
        person() {}

        void getName(string name2);
};

void person::getName(string name2) {
    name = name2;
    cout<<"Account Created !"<<endl<<"Welcome "<<name2<<" !"<<endl;
}

class bitcoin {
    private:
        int balance;
        bitcoin* prev;
        bitcoin* cur;
    public:
        void withdraw(person p1);
        void deposit(person p1);
        void convert(person p1);
};

int main() {

    cout<<"Hello !"<<endl;
    cout<<"What would you like to do in this blockchain world ?"<<endl;
    cout<<"1. Create Account"<<endl<<"2. Withdraw Money"<<endl<<"3. Deposit Money"<<endl<<"4. Delete Account"<<endl;
    cout<<"5. Convert from bitcoin to inr"<<endl<<endl;
    cout<<"Warning :: only 10 accounts can be created at once !!"<<endl;

    int choice, i = 0;
    person a[10];
    string name;
    while(1) {
        cin>>choice;

        switch(choice) {

            case 1: cout<<"Enter account name"<<endl;
                    cin>>name;
                    a[i].getName(name);
                    i++;
                    break;
            case 2: cout<<"";
            default: return 0;
        }
    }
    return 0;
}
