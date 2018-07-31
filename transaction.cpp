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
        string myName();
        int getBalance();
};

void person::getName(string name2) {
    name = name2;
    cout<<"Account Created !"<<endl<<"Welcome "<<name2<<" !"<<endl;
}

string person::myName() {
    return name;
}

int person::getBalance() {
    return balance;
}

static counting = 0;

class bitcoin {
    private:
        string a;
        string b;
        int transaction;
        bitcoin* prev;
        bitcoin* cur;
    public:
        bitcoin();
        void withdraw(person p1, int amount);
        void deposit(person p1);
        void convert(person p1);
};

void bitcoin::bitcoin() {

    if(counting == 0) {
        prev = NULL;
        // cur points to its own location ...
    }

}

void bitcoin::withdraw(person p1, int amount) {

    if(p1.getBalance() == 0) {
        cout<<"No balance"<<endl;
        return ;
    }
    else if(p1.getBalance() >= amount) {
        char choice;
        cout<<"Do you want to know the current balance ?"<<endl;
        cout<<"Y/N ?"<<endl;
        cin>>choice;
        if(choice == 'Y') {
            cout<<"Your balance is "<<p1.getBalance()<<"Mr. "<<p1.myName()<<endl;
        }
    }
    else {
        cout<<"Not enough balance !"<<endl;
        cout<<"Transaction failed !"<<endl;
    }
}

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
                    bitcoin b1;
                    b1.withdraw(a[i], amount);
                    break;
            default: return 0;
        }

        cout<<endl<<endl;
        cout<<"What would you like to do in this blockchain world ?"<<endl;
        cout<<"1. Create Account"<<endl<<"2. Withdraw Money"<<endl<<"3. Deposit Money"<<endl<<"4. Delete Account"<<endl;
        cout<<"5. Convert from Bitcoin to INR"<<endl<<"6. Current Balance "<<endl;
        cout<<"Warning :: only 10 accounts can be created at once !!"<<endl;
        cout<<endl;
    }
    return 0;
}
