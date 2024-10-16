#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;
class Fina
{
    int balance,pin,piin,amt,mini;
    string name,name2,line;
    char ans;
    public:
    fstream fout,fin;
    Fina()
    {
        fout.open("C:\\Krish More\\Krish Programs\\Transaction History",ios::out);
        fin.open("C:\\Krish More\\Krish Programs\\Transaction History",ios::in);
        pin = 12345;
        balance = 0;
        cout<<"Enter your name: ";
        cin>>name;
        fout<<"User name: "<<name<<endl;
        do
        {
            cout<<"Enter password: ";
            cin>>piin;
            cout<<endl;
            if(piin != pin)
            cout<<"Incorrect Passsword.Enter again\n";
        }while(piin!=pin);
        cout<<"Enter balance: ";
        cin>>balance;
        fout<<"Balance Entered: "<<balance;
        cout<<"Set your minmum range: ";
        cin>>mini;
        fout<<endl<<"Range: "<<mini<<endl;
    }
    void deposit();
    void withd();
    void check();
    void Transhis();
    void Transfer();
};
void Fina :: deposit()
{
    cout<<"Enter amount: ";
    cin>>amt;
    balance += amt;
    cout<<endl<<"Current Balance: "<<balance;
    fout<<"You Deposit "<<amt<<"Rs"<<endl;
}
void Fina :: withd()
{
    cout<<"Enter amount: ";
    cin>>amt;
    if(balance <= mini)
    {
        cout<<"You are on the range do you really want to withdrawl money(Yes-y/No-n): ";
        cin>>ans;
    }
    if(ans=='y' || balance > mini)
    {
        balance -= amt;
        cout<<endl<<"Current Balance: "<<balance;
        fout<<"You Withdrwal "<<amt<<"Rs"<<endl;
    }
}
void Fina :: check()
{
    cout<<endl<<"Current Balance: "<<balance;
    fout<<"You check balance\n";
}
void Fina :: Transfer()
{
    cout<<"Enter person's name: ";
    cin>>name2;
    cout<<"Enter amount: ";
    cin>>amt;
    if(balance <= mini)
    {
        cout<<"You are on the range do you really want to transfer money(Yes-y/No-n): ";
        cin>>ans;
    }
    if(ans=='y' || balance > mini)
    {
        balance -= amt;
        cout<<endl<<"Current Balance: "<<balance<<endl;
        fout<<"You Transfered "<<amt<<"Rs to "<<name2<<endl;
        cout<<amt<<"Rs Transfered to "<<name2<<endl;
    }
}
void Fina :: Transhis()
{
    string name3;
    cout<<endl;
    while(!fin.eof())
    {
        fin>>name3;
        if(name3 == name)
        continue;
        while(getline(fin,line))
        {
            cout<<line<<endl;
        }
        break;
    }
}
int main()
{
    int answ;
    Fina f;
    do
    {
        cout<<"\n-----------------------------------------------------------------------------------------------------------\n";
        cout<<"1. Check\n2. Deposit\n3. Withdrwal\n4. Transfer money\n5. Transaction History\n6. Exit\nEnter your choice: ";
        cin>>answ;
        switch(answ)
        {
            case 1: f.check();break;
            case 2: f.deposit();break;
            case 3: f.withd();break;
            case 4: f.Transfer();break;
            case 5: f.Transhis();break;
            getch();
            case 6: break;
        }
    }while(answ != 6);
    cout<<"Thank You!";
    getch();
    return 0;
}