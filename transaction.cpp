// This program helps in creating an account, making transaction similar to the concept of bitcoin and blockchain
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class person {
    private:
        string name;
        int balance;
    public:
        person() { balance = 0; }
        void getName(string name2);
        string myName();
        int getBalance();
        void withdraw(int amount);
        void deposit(int amount);
        void convert(int amount);
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

static int counting = 0;
struct bitcoin {
    int transaction;
    bitcoin* prev;
    bitcoin* cur;
    string t1;
    string t2;
};

struct bitcoin* last = NULL;

bitcoin* createNode() {
    bitcoin* temp = (bitcoin*)malloc(sizeof(struct bitcoin));
    return temp;
}

void insertLast(bitcoin* last, int amount, int type, string name) {
    bitcoin* temp = createNode();
    temp->transaction = amount;
    if(type == 0) {
        temp->t1 = "bank";
        temp->t2 = name;
    }
    temp->prev = last;
    temp->cur = temp;
    last = temp;
}

void person::withdraw(int amount) {
    if(balance == 0) {
        cout<<"No balance !"<<endl;
    }
    else if(amount <= balance) {
        cout<<"Would you like to see your balance ?"<<endl;
        cout<<"Y/N ?"<<endl;
        char choice;
        cin>>choice;
        if(choice == 'Y') {
            cout<<"Mr."<<name<<" your balance is $$ "<<balance<<endl;
        }
        balance -= amount;
        cout<<"Would you like to see your current balance ?"<<endl;
        cout<<"Y/N ?"<<endl;
        cin>>choice;
        if(choice == 'Y') {
            cout<<"Mr."<<name<<" your balance is $$ "<<balance<<endl;
        }
    }
    else {
        cout<<"Balance is not enough to make transaction !"<<endl;
    }
    int type = 0;
    //type 0 for withdraw
    insertLast(last, amount, type, name);
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
                    a[i].withdraw(amount);
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
