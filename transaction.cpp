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
    // type 0 is for withdrawing money whereas type 1 is for depositing money !
    if(type == 0) {
        temp->t1 = "Bank";
        temp->t2 = name;
    }
    else if(type == 1) {
        temp->t1 = name;
        temp->t2 = "Bank";
    }
    temp->prev = last;
    temp->cur = temp;
    last = temp;
}

void traverse(bitcoin* tail) {
    if(tail != NULL) {
        traverse(tail->prev);
    }
    else
        return ;
    cout<<"All transactions recorded are :"<<endl;
    if(tail->t1 == "Bank") {
        cout<<tail->t2<<" withdraw $$ "<<tail->transaction<<" from "<<tail->t1<<endl;
    }
    else if(tail->t2 == "Bank") {
        cout<<tail->t1<<" deposited $$ "<<tail->transaction<<" to "<<tail->t2<<endl;
    }
}

void person::withdraw(int amount) {
    if(balance == 0) {
        cout<<"No balance !"<<endl;
        return ;
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
        return ;
    }
    int type = 0;
    //type 0 for withdraw
    insertLast(last, amount, type, name);
}

void person::deposit(int amount) {

    cout<<"Would you like to see your balance ?"<<endl;
    cout<<"Y/N ?"<<endl;
    char choice;
    cin>>choice;
    if(choice == 'Y' || choice == 'y') {
        cout<<"Mr."<<name<<" your balance is $$ "<<balance<<endl;
    }
    balance += amount;
    cout<<"Would you like to see your current balance ?"<<endl;
    cout<<"Y/N ?"<<endl;
    cin>>choice;
    if(choice == 'Y' || choice == 'y') {
        cout<<"Mr."<<name<<" your balance is $$ "<<balance<<endl;
    }

    int type = 1;
    //type 0 for withdraw
    insertLast(last, amount, type, name);
}

int main() {

    cout<<"Hello !"<<endl;
    cout<<"What would you like to do in this blockchain world ?"<<endl;
    cout<<"1. Create Account"<<endl<<"2. Withdraw Money"<<endl<<"3. Deposit Money"<<endl<<"4. Delete Account"<<endl;
    cout<<"5. Convert from bitcoin to inr"<<endl<<"6. Current Balanace "<<endl<<"7. Know all Transactions"<<endl;
    cout<<"8. Exit from the bitcoin world !"<<endl;
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
            case 2: if(i == 0) {
                        cout<<"You must first create an account"<<endl;
                        break;
                    }
                    cout<<"Enter Amount to withdraw !"<<endl;
                    cin>>amount;
                    a[i].withdraw(amount);
                    break;
            case 3: if(i == 0) {
                        cout<<"You must first create an account"<<endl;
                        break;
                    }
                    cout<<"Enter Amount to deposit !"<<endl;
                    cin>>amount;
                    a[i].deposit(amount);
                    break;
            case 7: traverse(last);
                    break;
            case 8: exit(0);
            default: return 0;
        }

        cout<<endl<<endl;
        cout<<"What would you like to do in this blockchain world ?"<<endl;
        cout<<"1. Create Account"<<endl<<"2. Withdraw Money"<<endl<<"3. Deposit Money"<<endl<<"4. Delete Account"<<endl;
        cout<<"5. Convert from bitcoin to inr"<<endl<<"6. Current Balanace "<<endl<<"7. Know all Transactions"<<endl;
        cout<<"8. Exit from the bitcoin world !"<<endl;
        cout<<"Warning :: only 10 accounts can be created at once !!"<<endl;
        cout<<endl;
    }
    return 0;
}
