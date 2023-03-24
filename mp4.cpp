#include<bits/stdc++.h>
#include<fstream>

using namespace std;

ofstream outFile; //have to declare as global variable to be used in the void function

int divSum(int n) //function to find sum of divisors
{
    if(n == 1)  //1 trips out the computer so this is to check for it manually
      return 1;

    // declare sum of divisors variable
    int sumOfDiv = 0;

    // find all divisors which divides into number
    for (int i = 2; i <= n; i++) //iterates from i=2 to n
    {
        // if 'i' is divisor of 'n' and checks if n and i are the same because proper divisors can not include the number itself
        if (n % i == 0 && n/i!=1)
        {
            sumOfDiv+=i; //adds the proper divisor to the total sum
        }
    }


    return (sumOfDiv+1); //have to manually add 1 because the for loop started from 2
}

int factors(int n) //function to find the number of proper divisors
{
    int i, sumFactors = 0; //declare variables

    for(i = 1; i <= n; i++) //iterates from 1 to n because you can not divide by 0
    {
        if(n % i == 0 && n/i !=1) //checks if n is divisible by i and does not include number itself because it is a proper divisor
        {
            ++sumFactors;
        }
    }
    return sumFactors; //returns total number of proper divisors
}

int smallNum(int n){ //function to find the smallest natural number with 6 proper divisors

    for(n; n<100; n++){ //starts from n and iterates through 100 because I did not want to make it slow

        if(factors(n) == 6){ //passes 'n' into the function factors to check if it has 6 proper divisors
                return(n); // returns the number that passes the conditions
                break; //add break here to make it stop after it finds the first number which is also the smallest
        }
    }
}

void printDivisors(int n) //function to print list of the proper divisors. I used 'void' because it was easier to use than 'int'
{                         // because the return messed up things
    for (int i=1; i<n; i++) //there is a more efficient solution but this is the simplest way to do this
    {
        if (n%i == 0 ) //checks if 'n' is divisible by i
        {
            outFile<<i <<" ";// prints it out on the output file
        }
    }
}


int main() //to print all the functions out
{

outFile.open("mp4output.txt");// open the text file to write
int n = 1; // declare n as 1 because 0 will trip out the computer

    for(n; n<smallNum(n); n++){ //iterates from n to the smallest natural number with 6 proper divisors which was found in the other function
        if(divSum(n) > n){ //checks if it is an abundant number because the sum of divisors has to be greater than the number itself
        outFile<<n<<" is an abundant number that is smaller than the smallest natural number that has exactly six proper divisors."<<endl; //print out everything
        outFile<<"The list of proper divisors for " << n << " is: ";
        printDivisors(n);//this is the void function so it looks a little different from the others. Remember the cout is in the function itself
        outFile<<"\n"; //create space
        outFile<<"The sum of the proper divisors is: "<<divSum(n)<<endl;
        outFile<<"The number of proper divisors is: "<<factors(n)<<endl;
        outFile<<"\n\n"<<endl;//creates double space between each list of info
        }
    }

    outFile << smallNum(n) << " is the smallest natural number with 6 proper divisors" <<endl; //prints out the number which was instructed in the directions
    outFile.close();// close the out put file
    cout<<"File was written successfully! Check for a file named mp4output.txt in computer"<<endl; // checks if the program ran successfully

    return 0;
}
