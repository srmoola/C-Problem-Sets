#include <iostream>
#include <stdlib.h.>
#include <iomanip>


using namespace std;

float length;
float width;
float HouseL;
float HouseW;
float speed;



int main()
{
    string answer;


    do{


    cout<< setfill('*') << setw(10) <<"Enter the length of the lawn: ";
    cin>>length;

    cout<< "Enter the width of the lawn: ";
    cin>>width;

    cout<< "Enter the length of the house: ";
    cin>>HouseL;

    cout<< "Enter the width of the house: ";
    cin>>HouseW;

    cout<< "Enter your walking speed: ";
    cin>>speed;

    system("CLS");

    cout<< "The lawn's dimensions are " << length << " by " << width << " feet" << endl;
    cout<< "The House's dimensions are " << HouseL << " by " << HouseW << " feet" << endl;
    cout<< "Walking Speed: " << speed << endl;

    cout<<endl;

    cout<< "Type (yes) to if information is correct or type (no) to re-enter information: ";
    cin>> answer;

    system("CLS");

    }while(answer == "no" || answer == "No");

    float lawnArea = length * width;
    float houseArea = HouseL * HouseW;
    float mowArea = lawnArea - houseArea;
    float mowTime = mowArea/198;
    float mowRate = mowArea/mowTime;


    cout<< " Area to mow: " << mowArea << " square feet" <<endl;
    cout<< " Rate at which you mow: " << mowRate<< " square feet per minute" <<endl;
    cout<< " Time that it will take you to finish mowing: " << mowTime << " minutes" <<endl;


    return 0;
}
