#include <iostream>  //add libraries
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>


using namespace std; //call standard library

ifstream inFile;     //declare variable for reading file
ofstream outFile;    //declare variable for writing file
string str;          //declare variables for storing and calculations
string str1;
string str2;
string str3;
float number;
float number2;
float surcharge = 0.0031;



int main()
{
    inFile.open("C:/Users/bigfi/Downloads/machineprob.txt");  //open text file

    if(inFile.fail()){  //check for any errors
        cout<< "Could not find file" <<endl;
    }
    else{


          getline(inFile,str);          //extract information from text file and store in variables

          getline(inFile, str1);


          getline(inFile, str2);

            number= stof(str2);         //converting from string to float

          getline(inFile, str3);

            number2= stof(str3);


        inFile.close();  //close file
    }

    float totalValue = number * 74.5 * number2;         //calculating the total value of shipment
    outFile.open("machineprob2output2.txt");            //open file for writing

    if(outFile.fail()){  //check for errors
        cout<< "Could not write file" <<endl;
    }
    else{

        outFile<<"KERBAA & M COAL TRAIN REPORT – Satyadev Moolagani"<< endl << endl;              //writing on file

        outFile<<"Railroad name: "<<setw(30)<<str<<endl;
        outFile<<"Destination:   "<<setw(30)<<str1<<endl<<endl;
        outFile<<"Number of ore cars:          "<<fixed<<setw(10)<< setfill('_')<<setprecision(2)<<number<<endl<<endl;
        outFile<<"Total weight of coal:        "<<fixed<<setw(10)<<setprecision(2)<<number * 74.5<<endl<<endl;
        outFile<<"Current Cost per short ton: $"<<fixed<<setw(10)<<setprecision(2)<<number2<<endl<<endl; //write on file with "fixed", "setw" , setprecision, and setfill to format lines vertically
        outFile<<"Total Value of Shipment:    $"<<fixed<<setw(10)<<setprecision(2)<<totalValue<<endl<<endl;
        outFile<<"Current Surcharge:           "<<fixed<<setw(10)<<setprecision(2)<<surcharge *100 <<"%"<<endl<<endl;
        outFile<<"Total Surcharge(Est):       $"<<fixed<<setw(10)<<setprecision(2)<<surcharge * totalValue<<endl<<endl;




        outFile.close();  //close writing file
    }

    cout<<"Report was written successfully, check for file named machineprob2output2.txt"<<endl;  //check to see if everything is written successfully

    return 0;
}
