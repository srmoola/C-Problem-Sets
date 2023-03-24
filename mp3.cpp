#include <iostream>  //add libraries
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>


using namespace std;


ifstream inputFile;     //declare variable for reading file
ofstream outFile;    //declare variable for writing file
int callTime, callDuration;
string totalTimePrint;
char callType;
int minutes;
int totalTime = 200;
float cost = 0.00;

int main()
{
    inputFile.open("C:/Users/bigfi/Downloads/mp3.txt");  //open text file
    outFile.open("machineprob3output.txt");            //open file for writing


    if(inputFile.fail()){  //check for any errors
        cout<< "Could not find file" <<endl;
    }
    else{

    outFile<< "Time: " <<setw(15) << "Duration: " <<setw(18)<< "Type of Call: "<<setw(25)<< "Minutes used so far: " <<setw(25)<< "Total Cost for Month: "<<setw(15)<<"Total Cost: " <<endl;

    while (inputFile >> callTime >> callDuration>> callType)
    {


        if(callTime <= 1800 && callTime>600){

                totalTime -= callDuration;
                //totalTime = 200 - totalTime;
                totalTimePrint = to_string(200-totalTime);

            if(totalTime <=0){

            if(callDuration != 15){

                if(callType = 'A'){
                    cost += 0.29 * callDuration;
                }
                else if(callType = 'L'){
                    cost += 0.69 *callDuration;
                }
            }
            else{

                cost += 0.29 * 5;
            }


            }
        }
        else{

            totalTimePrint = "Free";
        }







        outFile<<setw(5) << left <<setprecision(4) <<callTime
               <<setw(1) << left << " "
               <<setw(10) << right <<callDuration
               <<setw(1) << left << " "
               <<setw(15)<< right<<callType
               <<setw(1) << left << " "
               <<setw(20)<< right<<totalTimePrint
               <<setw(1) << left << " "
               <<setw(20)<< right<< setprecision(4) << "$ " <<cost
               <<setw(1) << left << " "
               <<setw(20)<< right << "$ "<<cost + 39.99<<endl;








    }
    outFile.close();  //close writing file

    }
    inputFile.close();

    cout<< "File Written Successfully, check for file named machineprob3output"<<endl;

     return 0;
    }
