#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
class Account
{
    char customer_name[20],act_type;
    int act_num;
    public:
        int a=0,b=0;
        void input(int an,char cn[20],char at)
        {
            this->act_num=an;
            strcpy(this->customer_name,cn);
            this->act_type=at;
        }
        void show()
        {
            cout<<"Account Number: -"<<this->act_num<<endl;
            cout<<"Account Name: -"<<this->customer_name<<endl;
            cout<<"Account Type S for Saving and C for Current: -"<<this->act_type<<endl;
        }
        int search(int an)
        {
            int t;
            if(this->act_num==an)
            {
                t=1;
            }
            else
            {
                t=0;
            }
            return(t);
        }
};
class cur_act:public Account
{
    int Balance;
    public:
        void input1(int bal)
        {
            this->Balance=bal;
        }
/*        int depos(int Bal)
        {
            this->Balance+=deposit;   
        }
  */      void show1()
        {
            cout<<"Balance in Account: -"<<this->Balance<<endl;
        }
        void penalty(){
            if(this->Balance>=5000)
            {
                    cout<<"There is no penalty imposed"<<endl;
            }
            else
            {
                cout<<"Balnce is less than 5000 Rupees hence Service Charge will be imposed\n";
                this->Balance-=500;
            }
        }
        void withdr(int with){
            if(this->Balance>=with)     this->Balance-=with;
            else    cout<<"Not enough balance in your account\n";
        }
};
class sav_act:public Account
{
    int Balance;
    public:
        void input1(int bal)
        {
            this->Balance=bal;
        }
        void show1()
        {
            cout<<"Balance in Account: -"<<this->Balance<<endl;
        }
        void depositBalance(int deposit){
            this->Balance+=deposit;
        }
        void withdr(int with){
            if(this->Balance>=with)     this->Balance-=with;
            else    cout<<"Not enough balance in your account\n";
        }
        void penalty(){
            if(this->Balance>=5000)
            {
                    cout<<"There is no penalty imposed"<<endl;
            }
            else
            {
                cout<<"Balnce is less than 5000 Rupees hence Service Charge will be imposed\n";
                this->Balance-=500;
            }
        }
};
int main()
{
    char ch,ch1;
    int opt,an,i=0,j=0;
    char at,cn[20];
    int Bal;
    int deposit,with;
    sav_act saving_act[10];
    cur_act current_act[10];
    cout<<"********************* Welcome! *********************\n";
    while(1)
    {
        cout<<"Enter Account Name:";
        fflush(stdin);
        gets(cn);
        cout<<"Enter Account Number:";
        cin>>an;
        cout<<"Enter Account Type(Account Type S for Saving and C for Current):";
        fflush(stdin);
        cin>>at;
        cout<<"Enter Amount for balance:";
        cin>>Bal;
        if(at =='s' || at =='S')    
        {
            saving_act[i].input(an,cn,at);
            saving_act[i].input1(Bal);
            i++;
        }
        else
        {
            current_act[j].input(an,cn,at);
            current_act[j].input1(Bal);
            j++;
        }
        cout<<endl<<"Insert more records Y for yes";
        fflush(stdin);
        cin>>ch1;
        if(ch1=='n')
            break;
    }


    do{
        cout<<endl<<"1.Accept deposit from customer and update Balance";
        cout<<endl<<"2.Display the Balance";
        cout<<endl<<"3.Permit withdrawl and update the Balance";
        cout<<endl<<"4.Check for minimum Balance and penalty";
        cout<<endl<<"5.Exit this option menu";
        cout<<endl<<"Enter Your option";
        cin>>opt;
        switch(opt)
        {
            case 1:
                cout<<"Enter Account Number:";
                cin>>an;
                cout<<"Enter Account Type(Account Type S for Saving and C for Current):";
                fflush(stdin);
                cin>>at;
                cout<<"Enter Amount to deposit:";
                cin>>deposit;
                int k;
                if(at =='s' || at =='S')    
                {
                    for(k=0;k<i;k++)
                    {
                        if(saving_act[k].search(an)==1)
                        {
                            saving_act[k].depositBalance(deposit);
                            cout<<"Deposit Success...!";
                            break;
                        }
                    }
                    if(k==i)
                    {
                        cout<<"Deposit not Success because account not found...!";
                    }
                }
                else if(at =='c' || at =='C')
                {
                    cout<<"Can't deposit money in the Current account only in Saving account!";
                }
                else{
                    cout<<"Wrong input";
                }
                break;
            case 2:
                for(int k=0;k<i;k++)
                {
                    saving_act[k].show();
                    saving_act[k].show1();
                }
                for(int k=0;k<j;k++)
                {
                    current_act[k].show();
                    current_act[k].show1();
                }
                break;
            case 3:
                cout<<"Enter amount to withdraw:- ";
                cin>>with;
                if(at =='s' || at =='S'){
                    for(int k=0;k<i;k++)
                    {
                        saving_act[k].withdr(with);
                        saving_act[k].show1();
                    }
                }
                else{
                    for(int k=0;k<j;k++)
                    {
                        current_act[k].withdr(with);
                        current_act[k].show1();
                    }
                }
                break;
            case 4:
                if(at =='s' || at =='S'){
                    for(int k=0;k<i;k++)
                    {
                        saving_act[k].penalty();
                        saving_act[k].show1();
                    }
                }
                else{
                    for(int k=0;k<j;k++)
                    {
                        current_act[k].penalty();
                        current_act[k].show1();
                    }
                }
                break;   
            case 5:
                break;                                                             
            default:
                cout<<"Wrong Input";
        }

        cout<<endl<<"Continue with more options Y for yes";
        fflush(stdin);
        cin>>ch;
    }while(ch=='y'||ch=='Y');
    cout<<"********************* Thank You! *********************\n";
    return 0;
}
