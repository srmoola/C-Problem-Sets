#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <cctype>
#include <fstream>

using namespace std;

float accntBalance;

int deposit;
int cumulative;
int customer1;
int customer2;
int customer3;
int customer4;
float customer1balance;
float customer2balance;
float customer3balance;
float customer4balance;
float addBonusAmmount;

ofstream outFile; //have to declare as global variable to be used in the void function

int readAccountNo(){

    while(true){
    int accntNum;
    cout<<"Please Enter Your Account Number: ";
    cin>>accntNum;

    if(accntNum > 10000 || accntNum < 0){
        cout<<"Error, incorrect number, account number has to be between 0 and 10000"<<endl;
        continue;
    }
    else{
        return accntNum ;
        break;
    }
    }
}

int readAccountBalance(){

    while(true){

    cout<<"Please Enter Your Opening Balance Amount: ";
    cin>>accntBalance;

    if(accntBalance > 200000 || accntBalance < 1){
        cout<<"Opening balance has to be between 1$ and $200000, Please enter again"<<endl;
        continue;
    }
    else{
        return accntBalance;
        break;
    }
    }
}

float addReturnBonus(float accntBalance){
    if(accntBalance >= 1 && accntBalance <= 100){
        addBonusAmmount = accntBalance * 0.02;
        return addBonusAmmount;
    }
    else if(accntBalance >=101 && accntBalance <=500){
        addBonusAmmount = accntBalance * 0.03;
        return addBonusAmmount;
    }
    else if(accntBalance >=501 && accntBalance <=1000){
        addBonusAmmount = accntBalance * 0.04;
        return addBonusAmmount;
    }
    else if(accntBalance>1000){
        addBonusAmmount = accntBalance * 0.05;
        return addBonusAmmount;
    }
}

int calculateDeposit(){
    while(true){
    system("ClS");
    cout<<"Balance amount for Account number "<<customer1<<": $"<< customer1balance<<endl;
    cout<<"Balance amount for Account number "<<customer2<<": $"<< customer2balance<<endl;
    cout<<"Balance amount for Account number "<<customer3<<": $"<< customer3balance<<endl;
    cout<<"Balance amount for Account number "<<customer4<<": $"<< customer4balance<<endl;
    cout<<endl;
    cout<<"How much do you want to deposit?: ";
    cin>>deposit;
    if(deposit < 0){
        cout<<"Can only deposit, please enter positive number"<<endl;
        continue;
    }

    while(true){
        int option3;
        cout<<"Which account number do you want to deposit to?: ";
        cin>>option3;
        if(option3 == customer1){
            customer1balance += deposit;
            break;
        }
        else if(option3 == customer2){
            customer2balance += deposit;
            break;
        }
        else if(option3 == customer3){
            customer3balance += deposit;
            break;
        }
        else if(option3 == customer4){
            customer4balance += deposit;
            break;
        }else{
            cout<<"No account found, please enter again"<<endl;
            continue;
        }
    }


    break;
    }
}

int printAllInfo(int customer1, int customer2, int customer3, int customer4, int customer1balance, int customer2balance, int customer3balance, int customer4balance){
    outFile<<"Balance amount for Account number "<<customer1<<": $"<< customer1balance<<endl;
    outFile<<"Balance amount for Account number "<<customer2<<": $"<< customer2balance<<endl;
    outFile<<"Balance amount for Account number "<<customer3<<": $"<< customer3balance<<endl;
    outFile<<"Balance amount for Account number "<<customer4<<": $"<< customer4balance<<endl;

}

int main()
{

    cout<<"For customer 1: "<<endl;
    customer1 = readAccountNo();
    customer1balance = readAccountBalance() + addReturnBonus(accntBalance);
    cout<<"For customer 2: "<<endl;
    customer2 = readAccountNo() ;
    customer2balance = readAccountBalance() + addReturnBonus(accntBalance);
    cout<<"For customer 3: "<<endl;
    customer3 = readAccountNo();
    customer3balance = readAccountBalance() + addReturnBonus(accntBalance);
    cout<<"For customer 4: "<<endl;
    customer4 = readAccountNo();
    customer4balance = readAccountBalance() + addReturnBonus(accntBalance);

    while(true){
    system("CLS");
    string option;

    cout<<"A - Deposit"<<endl;
    cout<<"B - View Accounts"<<endl;
    cout<<"C - Exit the Program"<<endl;
    cout<<"What do you want to do?: ";
    cin>>option;

    if(option == "A"){
        calculateDeposit();
    }
    else if(option == "B"){
        while(true){
        outFile.open("mp5output.txt");
        system("CLS");
        string option2;
        printAllInfo(customer1, customer2, customer3, customer4, customer1balance, customer2balance, customer3balance, customer4balance);

        cout<<"File Written Successfully"<<endl;
        outFile.close();// close the out put file
        cout<<endl;
        cout<<"Press any letter to go back: ";
        cin>>option2;

        if(option2 == "B"){
            break;
        }
        else{
            break;
        }

        }
        continue;
    }
    else if(option == "C"){
        system("CLS");
        cout<<"Thanks for using my bank! See you later!"<<endl;
        Sleep(5000);
        return 0;
    }
    else{
        system("CLS");
        cout<<"Oops! No option was selected please type again"<<endl;
        Sleep(3500);

    }


    }

    return 0;
}
