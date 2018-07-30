// This program helps in creating an account, making transaction similar to the concept of bitcoin and blockchain
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class person {
    private:
        string name;
        int balance;
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
        int transaction;
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
    cout<<"5. Convert from bitcoin to inr"<<endl<<"6. Current Balanace "<<endl;
    cout<<"Warning :: only 10 accounts can be created at once !!"<<endl;
    cout<<endl;
    int choice, i = 0, amount;
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
            case 2: cout<<"Enter Amount to withdraw !"<<endl;
                    cin>>amount;

            default: return 0;
        }

        cout<<endl<<endl;
        cout<<"What would you like to do in this blockchain world ?"<<endl;
        cout<<"1. Create Account"<<endl<<"2. Withdraw Money"<<endl<<"3. Deposit Money"<<endl<<"4. Delete Account"<<endl;
        cout<<"5. Convert from bitcoin to inr"<<endl<<"6. Current Balance "<<endl;
        cout<<"Warning :: only 10 accounts can be created at once !!"<<endl;
        cout<<endl;
    }
    return 0;
}
