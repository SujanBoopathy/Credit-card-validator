#include<iostream>
#include<stdio.h>
#include<string>

using namespace std;

bool isNumberString(string s){
    for(int i=s.length()-1;i>=0;i--){
        if(s[i]>'9' || s[i]<'0')
           return false;
    }
    return true;
}


class credit_card_validator{
   int doubleEvenSum=0,i,dbl,ch;
   string ccNumber;
   public:
     void get_ccNumber();
     void check_ccNumber();
};

void credit_card_validator::get_ccNumber(){
   cout<<"\nCredit Card Validation using Luhn Algorithm , press exit to quit \n\n"<<endl;
   cout<<"\nEnter your credit card Number :"<<endl;
   cin>>ccNumber;
}


void credit_card_validator::check_ccNumber(){
    
    while(1){
        this->get_ccNumber();
        if(!isNumberString(ccNumber)){
            cout<<"\nBad input value "<<endl;
            continue;
        }
        for(i=ccNumber.length()-1;i>=0;i-=2){
            doubleEvenSum+=(ccNumber[i] - 48);
        }
        for(i=ccNumber.length()-2;i>=0;i=-2){
            dbl=(ccNumber[i] - 48)*2;
            if(dbl>9 || dbl<0){
                dbl=(dbl/10)+(dbl%10);
            }
            doubleEvenSum+=dbl;
        }
        
        cout<<"\n\nThe given credit card number is ";
        cout<<(doubleEvenSum%10 == 0 ?"Valid" : "Invalid")<<endl;
        
        cout<<"Do you want to continue (1|0) :";
        cin>>ch;
        if(ch != 1){
            break;
        }
    }
}

int main(){
   credit_card_validator ccv;
   ccv.check_ccNumber();
   return 0;
}