// Project Ohm. A tool to help you calculate different electrical calculations. 
//Author: CHGP


#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
//#define DEBUGG




class Resistor // RESISTORCLASS
{
  public:
    std::string resistance;
    int ID;
    double tolerance;
};

int findClosest(double arr[], int n, int target);
int getClosest(int val1, int val2, int target);
int resisColor(std::string resist, int tolerance);
void serialCalc();
void parallelCalc();
void logicalCalc();


int main(int argc, char const *argv[])
{

    //Declaring menu variables
    int menuCase;
    
    
    //Starting menu
    std::cout << "Hello and welcome to >NAMEHERE<. " << std::endl;
    std::cout << "What would you like to calculate today?" << std::endl;
    std::cout << "\n";
    std::cout << "1. Serial Resistor Calculations. " << std::endl;
    std::cout << "2. Parallel Resistor Calculations. " << std::endl;
    std::cout << "3. Logical Gate Calculations. " << std::endl;
    std::cin >> menuCase;

    //Switch case which takes you to different functions.
    switch (menuCase)
    {
        case 1:
            serialCalc();
            break;
        case 2:
            parallelCalc();
            break;
        case 3:
            std::cout << ">Not yet implented<" << std::endl;
            logicalCalc();
            break;
        default:
            break;
    }




}

//Function to calculate serial resistor
void serialCalc(){

        //Declaring ugly long E24 serie
    double e24[168] = {1.0, 1.1, 1.3, 1.5, 1.6, 1.8, 2.0, 2.2, 2.4, 2.7,
                       3.0, 3.3, 3.6, 3.9, 4.3, 4.7, 5.1, 5.6, 6.2, 6.8, 7.5, 8.2, 9.1,
                       10, 11, 12, 13, 15, 16, 18, 20, 22, 24, 27, 30, 33, 36, 39, 43, 47,
                       51, 56, 62, 68, 75, 82, 91, 100, 110, 120, 130, 150, 160, 180, 200,
                       220, 240, 270, 300, 330, 360, 390, 430, 470, 510, 560, 620, 680, 750,
                       820, 910, 1.1 * pow(10, 3), 1.2 * pow(10, 3), 1.3 * pow(10, 3), 1.5 * pow(10, 3),
                       1.5 * pow(10, 3), 1.6 * pow(10, 3), 1.8 * pow(10, 3), 2.0 * pow(10, 3),
                       2.2 * pow(10, 3), 2.2 * pow(10, 3), 2.4 * pow(10, 3), 2.7 * pow(10, 3),
                       3.0 * pow(10, 3), 3.3 * pow(10, 3), 3.6 * pow(10, 3), 3.9 * pow(10, 3),
                       4.3 * pow(10, 3), 4.7 * pow(10, 3), 5.1 * pow(10, 3), 5.6 * pow(10, 3),
                       6.2 * pow(10, 3), 6.8 * pow(10, 3), 7.5 * pow(10, 3), 8.2 * pow(10, 3),
                       9.1 * pow(10, 3), 10 * pow(10, 3), 11 * pow(10, 3), 12 * pow(10, 3), 13 * pow(10, 3),
                       15 * pow(10, 3), 16 * pow(10, 3), 18 * pow(10, 3), 20 * pow(10, 3), 22 * pow(10, 3),
                       24 * pow(10, 3), 27 * pow(10, 3), 30 * pow(10, 3), 33 * pow(10, 3),
                       36 * pow(10, 3), 39 * pow(10, 3), 43 * pow(10, 3), 47 * pow(10, 3), 51 * pow(10, 3),
                       56 * pow(10, 3), 62 * pow(10, 3), 68 * pow(10, 3), 75 * pow(10, 3), 82 * pow(10, 3),
                       91 * pow(10, 3), 100 * pow(10, 3), 110 * pow(10, 3), 120 * pow(10, 3), 130 * pow(10, 3),
                       150 * pow(10, 3), 160 * pow(10, 3), 180 * pow(10, 3), 200 * pow(10, 3),
                       220 * pow(10, 3), 240 * pow(10, 3), 270 * pow(10, 3), 300 * pow(10, 3),
                       330 * pow(10, 3), 360 * pow(10, 3), 390 * pow(10, 3), 430 * pow(10, 3), 470 * pow(10, 3),
                       510 * pow(10, 3), 560 * pow(10, 3), 620 * pow(10, 3), 680 * pow(10, 3),
                       750 * pow(10, 3), 820 * pow(10, 3), 910 * pow(10, 3), 1.0 * pow(10, 6),
                       1.1 * pow(10, 6), 1.2 * pow(10, 6), 1.3 * pow(10, 6), 1.5 * pow(10, 6),
                       1.6 * pow(10, 6), 1.8 * pow(10, 6), 2.0 * pow(10, 6), 2.2 * pow(10, 6),
                       2.4 * pow(10, 6), 2.7 * pow(10, 6), 3.0 * pow(10, 6), 3.3 * pow(10, 6),
                       3.6 * pow(10, 6), 3.9 * pow(10, 6), 4.3 * pow(10, 6), 4.7 * pow(10, 6),
                       5.1 * pow(10, 6), 5.6 * pow(10, 6), 6.2 * pow(10, 6), 6.8 * pow(10, 6),
                       7.5 * pow(10, 6), 8.2 * pow(10, 6), 9.1 * pow(10, 6)};
   
     
     
     //Get info from user. 
    int howMany;
    std::vector<Resistor> RV; // Vector of Resistor class RV
    std::string Res;          // RESISTANCE FROM USERS
    int ResitorCounter = 1;
    int n = sizeof(e24) / sizeof(e24[0]);
    long double rMin = 0;
    long double rMax = 0;
    long double minVal = 0;
    long double maxVal = 0;
    double tolerance;

    std::cout << "How many resistors do you want to use in your calculations?" << std::endl;
    std::cin >> howMany;

    // GET DATA
    for (int i = 0; i < howMany; i++)
    {

        Resistor R;
        std::cout << "Enter resistance of resistor no. " << ResitorCounter << std::endl;
        std::cin >> Res; // Resistance
        std::cout << "Enter tolerance of resistor no. " << ResitorCounter << " Only use full numbers. Dont use procent sign. " << std::endl;
        std::cin >> tolerance; // Takes tolerance
        resisColor(Res, tolerance);
        tolerance = tolerance / pow(10, 2); // Splits given procent into 0.00 format, easier to calc with 
        R.tolerance = tolerance;
        R.resistance = Res;
        R.ID = ResitorCounter;
        ResitorCounter++;

        RV.push_back(R);
    }

    int vectorCounter = 0;
    std::cout << "Your Resistors:" << std::endl;
    //PRINT DATA
    for (int i = 0; i < howMany; i++)
    {
        
        std::cout << "Resistor " << RV[vectorCounter].ID << ": " << RV[vectorCounter].resistance << " Ohm" << std::endl;
        std::cout << std::endl;
        vectorCounter++;
    } 
    

    double sum;
    char prefix;
    int castSum;

    // LOOP TO SUM UPP THE DATA AND PRINT WITH THE RIGHT PREFIX
        for (int i = 0; i < howMany; i++)
        {
            std::string tempSum = RV[i].resistance;
            long double tempTol = RV[i].tolerance;
            prefix = tempSum.back();
            prefix = toupper(prefix);
            castSum = stoi(tempSum); // The final data, this one we use to calculate Rtot

            if (prefix == 'K' || prefix == 'M' || prefix == 'G')
            {
                // CALCULATIONS BASED ON PREFIX
                switch (prefix)
                {
                case 'K':
                    castSum = castSum * pow(10, 3);

                    break;

                case 'M':
                    castSum = castSum * pow(10, 6);

                    break;

                case 'G':
                    castSum = castSum * pow(10, 9);

                    break;
                }
            }
            rMin = castSum * (1-tempTol);
            rMax = castSum * (1+tempTol);
            // Rtot
            sum += castSum;
            minVal += rMin;
            maxVal += rMax;

        }
        double Rtot = (double)sum;
        

        if (Rtot > 999999999)
        {
            minVal = minVal / pow (10, 9);
            maxVal = maxVal / pow (10, 9);
            Rtot = Rtot / pow(10, 9);
            resisColor(Res, tolerance);
            std::cout << std::setprecision(10) << "Total resistance = " << Rtot << "G Ohm" << std::endl;
            std::cout << std::setprecision(10) << "Tolerance interval: [" << minVal << " , " << maxVal << "]" << std::endl;
            std::cout << "Recommended Resistor from the E24 series: " << findClosest(e24, n, Rtot) << "G Ohm" << std::endl;
        }
        else if (Rtot > 999999)
        {
            minVal = minVal / pow (10, 6);
            maxVal = maxVal / pow (10, 6);
            Rtot = Rtot / pow(10, 6);
            resisColor(Res, tolerance);
            std::cout << std::setprecision(7) << "Total resistance = " << Rtot << "M Ohm" << std::endl;
            std::cout << std::setprecision(7) << "Tolerance interval: [" << minVal << " , " << maxVal << "]" << std::endl;
            std::cout << "Recommended Resistor from the E24 series: " << findClosest(e24, n, Rtot) << "M Ohm" << std::endl;
        }
        else if (Rtot > 999)
        {
            minVal = minVal / pow (10, 3);
            maxVal = maxVal / pow (10, 3);
            Rtot = Rtot / pow(10, 3);
            resisColor(Res, tolerance);
            std::cout << std::setprecision(4) << "Total resistance = " << Rtot << "K Ohm" << std::endl;
            std::cout << std::setprecision(4) << "Tolerance interval: [" << minVal << " , " << maxVal << "]" << std::endl;
            std::cout << "Recommended Resistor from the E24 series: " << findClosest(e24, n, Rtot) << "K Ohm" << std::endl;
        }
        else if (Rtot < 999)
        {
            resisColor(Res, tolerance);
            std::cout << "Total resistance = " << Rtot << " Ohm" << std::endl;
            std::cout << "Tolerance interval: [" << minVal << " , " << maxVal << "]" << std::endl;
            std::cout << "Recommended Resistor from the E24 series: " << findClosest(e24, n, Rtot) << " Ohm" << std::endl;
        }


}



void parallelCalc(){

    double e24[168] = {1.0, 1.1, 1.3, 1.5, 1.6, 1.8, 2.0, 2.2, 2.4, 2.7,
                       3.0, 3.3, 3.6, 3.9, 4.3, 4.7, 5.1, 5.6, 6.2, 6.8, 7.5, 8.2, 9.1,
                       10, 11, 12, 13, 15, 16, 18, 20, 22, 24, 27, 30, 33, 36, 39, 43, 47,
                       51, 56, 62, 68, 75, 82, 91, 100, 110, 120, 130, 150, 160, 180, 200,
                       220, 240, 270, 300, 330, 360, 390, 430, 470, 510, 560, 620, 680, 750,
                       820, 910, 1.1 * pow(10, 3), 1.2 * pow(10, 3), 1.3 * pow(10, 3), 1.5 * pow(10, 3),
                       1.5 * pow(10, 3), 1.6 * pow(10, 3), 1.8 * pow(10, 3), 2.0 * pow(10, 3),
                       2.2 * pow(10, 3), 2.2 * pow(10, 3), 2.4 * pow(10, 3), 2.7 * pow(10, 3),
                       3.0 * pow(10, 3), 3.3 * pow(10, 3), 3.6 * pow(10, 3), 3.9 * pow(10, 3),
                       4.3 * pow(10, 3), 4.7 * pow(10, 3), 5.1 * pow(10, 3), 5.6 * pow(10, 3),
                       6.2 * pow(10, 3), 6.8 * pow(10, 3), 7.5 * pow(10, 3), 8.2 * pow(10, 3),
                       9.1 * pow(10, 3), 10 * pow(10, 3), 11 * pow(10, 3), 12 * pow(10, 3), 13 * pow(10, 3),
                       15 * pow(10, 3), 16 * pow(10, 3), 18 * pow(10, 3), 20 * pow(10, 3), 22 * pow(10, 3),
                       24 * pow(10, 3), 27 * pow(10, 3), 30 * pow(10, 3), 33 * pow(10, 3),
                       36 * pow(10, 3), 39 * pow(10, 3), 43 * pow(10, 3), 47 * pow(10, 3), 51 * pow(10, 3),
                       56 * pow(10, 3), 62 * pow(10, 3), 68 * pow(10, 3), 75 * pow(10, 3), 82 * pow(10, 3),
                       91 * pow(10, 3), 100 * pow(10, 3), 110 * pow(10, 3), 120 * pow(10, 3), 130 * pow(10, 3),
                       150 * pow(10, 3), 160 * pow(10, 3), 180 * pow(10, 3), 200 * pow(10, 3),
                       220 * pow(10, 3), 240 * pow(10, 3), 270 * pow(10, 3), 300 * pow(10, 3),
                       330 * pow(10, 3), 360 * pow(10, 3), 390 * pow(10, 3), 430 * pow(10, 3), 470 * pow(10, 3),
                       510 * pow(10, 3), 560 * pow(10, 3), 620 * pow(10, 3), 680 * pow(10, 3),
                       750 * pow(10, 3), 820 * pow(10, 3), 910 * pow(10, 3), 1.0 * pow(10, 6),
                       1.1 * pow(10, 6), 1.2 * pow(10, 6), 1.3 * pow(10, 6), 1.5 * pow(10, 6),
                       1.6 * pow(10, 6), 1.8 * pow(10, 6), 2.0 * pow(10, 6), 2.2 * pow(10, 6),
                       2.4 * pow(10, 6), 2.7 * pow(10, 6), 3.0 * pow(10, 6), 3.3 * pow(10, 6),
                       3.6 * pow(10, 6), 3.9 * pow(10, 6), 4.3 * pow(10, 6), 4.7 * pow(10, 6),
                       5.1 * pow(10, 6), 5.6 * pow(10, 6), 6.2 * pow(10, 6), 6.8 * pow(10, 6),
                       7.5 * pow(10, 6), 8.2 * pow(10, 6), 9.1 * pow(10, 6)};



    //GET SERIAL Rtot
    int howMany;
    std::vector<Resistor> RV; // Vector of Resistor class RV
    std::string Res;          // RESISTANCE FROM USERS
    int ResitorCounter = 1;
    int n = sizeof(e24) / sizeof(e24[0]);
    long double rMin = 0;
    long double rMax = 0;
    long double minVal = 0;
    long double maxVal = 0;
    double tolerance;

    std::cout << "How many resistors do you want to use in your calculations?" << std::endl;
    std::cin >> howMany;

    // GET DATA
    for (int i = 0; i < howMany; i++)
    {

        Resistor R;
        std::cout << "Enter resistance of resistor " << ResitorCounter << std::endl;
        std::cin >> Res; // Resistance
        std::cout << "Enter tolerance of resistor no. " << ResitorCounter << " Only use full numbers. Dont use procent sign. " << std::endl;
        std::cin >> tolerance; // Takes tolerance
        tolerance = tolerance / pow(10, 2); // Splits given procent into 0.00 format, easier to calc with
        R.tolerance = tolerance;
        R.resistance = Res;
        R.ID = ResitorCounter;
        ResitorCounter++;

        RV.push_back(R);
    }

    int vectorCounter = 0;
    std::cout << "Your Resistors:" << std::endl;
    //PRINT DATA
    for (int i = 0; i < howMany; i++)
    {

        std::cout << "Resistor " << RV[vectorCounter].ID << ": " << RV[vectorCounter].resistance << " Ohm" << std::endl;
        std::cout << std::endl;
        vectorCounter++;
    }

    double sum;
    char prefix;
    int castSum;


        // LOOP TO SUM UPP THE DATA AND PRINT WITH THE RIGHT PREFIX
        for (int i = 0; i < howMany; i++)
        {
            std::string tempSum = RV[i].resistance;
            long double tempTol = RV[i].tolerance;
            prefix = tempSum.back();
            prefix = toupper(prefix);
            castSum = stoi(tempSum); // The final data, this one we use to calculate Rtot
            double toduble;
            toduble = (double)castSum;
            if (prefix == 'K' || prefix == 'M' || prefix == 'G')
            {
                // CALCULATIONS BASED ON PREFIX
                switch (prefix)
                {
                case 'K':
                    toduble = toduble * pow(10, 3);
                    toduble = 1 / toduble;

                    break;

                case 'M':
                    toduble = toduble * pow(10, 6);
                    toduble = 1 / toduble;

                    break;

                case 'G':
                    toduble = toduble * pow(10, 9);
                    toduble = 1 / toduble;

                    break;
                }
            }
            else
            {
                toduble = 1 / toduble;
            }
            //Takes 0.0x of 1 
            rMin = castSum * (1-tempTol);
            rMax = castSum * (1+tempTol);

            // Rtot
            sum += toduble;
            
            //here i halvera  with 1/x 
            double rMinHalf;
            double rMaxHalf;
            rMinHalf = 1/rMin;
            rMaxHalf = 1/rMax;

            //Adds value after every varv 
            minVal += 1/rMinHalf;
            maxVal += 1/rMaxHalf;

        }
        double Rtot = (double)sum;
        Rtot = 1 / Rtot;
        

        if (Rtot > 999999999)
        {
            minVal = minVal / pow (10, 9);
            maxVal = maxVal / pow (10, 9);
            Rtot = Rtot / pow(10, 9);
            std::cout << std::setprecision(10) << "Rtot = " << Rtot << "G Ohm" << std::endl;
            std::cout << std::setprecision(10) << "Tolerance interval: [" << minVal << " , " << maxVal << "]" << std::endl;
            std::cout << "Recomended Resistor from the E24 series: " << findClosest(e24, n, Rtot) << "G Ohm" << std::endl;
        }
        else if (Rtot > 999999)
        {
            minVal = minVal / pow (10, 6);
            maxVal = maxVal / pow (10, 6);
            Rtot = Rtot / pow(10, 6);
            std::cout << std::setprecision(7) << "Rtot = " << Rtot << "M Ohm" << std::endl;
            std::cout << std::setprecision(7) << "Tolerance interval: [" << minVal << " , " << maxVal << "]" << std::endl;
            std::cout << "Recomended Resistor from the E24 series: " << findClosest(e24, n, Rtot) << "M Ohm" << std::endl;
        }
        else if (Rtot > 999)
        {
            minVal = minVal / pow (10, 3);
            maxVal = maxVal / pow (10, 3);
            Rtot = Rtot / pow(10, 3);
            std::cout << std::setprecision(3) << "Rtot = " << Rtot << "K Ohm" << std::endl;
            std::cout << std::setprecision(3) << "Tolerance interval: [" << minVal << " , " << maxVal << "]" << std::endl;
            std::cout << "Recomended Resistor from the E24 series: " << findClosest(e24, n, Rtot) << "K Ohm" << std::endl;
        }
        else if (Rtot < 999)
        {
            std::cout << "Rtot = " << Rtot << " Ohm " << std::endl;
            std::cout << "Tolerance interval: [" << minVal << " , " << maxVal << "]" << std::endl;
            std::cout << "Recomended Resistor from the E24 series: " << findClosest(e24, n, Rtot) << " Ohm" << std::endl;
        }
    }




//function to calculate best matching color on resistor (4 band code)
int resisColor(std::string resist, int tolerance){
    std::cout << "Resistance: " << resist << " Tolerance:" << tolerance << std::endl;
    
    //Split up resist and put into different variables
    std::string firstDig = resist.substr(0, 1);
    std::string secDig = resist.substr(1, 1);
    std::string multiDig = resist.substr(2, -1);
    
    //array with all colors
    std::string colorArr [] = { "black", "brown", "red", "orange", "yellow", "green", "blue", "purple", "grey", "white" };

    
    

    //debug
    std::cout << "firstDig " << firstDig << std::endl;
    std::cout << "secDig " << secDig << std::endl;
    std::cout << "multiDig" << multiDig << std::endl;




    //If statmentSSS for first digit
    
    
    
    



    return 0;
}


//function to find the closest matching resistor
int findClosest(double arr[], int n, int target){
    // Corner cases
    if (target <= arr[0])
        return arr[0];
    if (target >= arr[n - 1])
        return arr[n - 1];

    // Doing binary search
    int i = 0, j = n, mid = 0;
    while (i < j)
    {
        mid = (i + j) / 2;

        if (arr[mid] == target)
            return arr[mid];

        /* If target is less than array element, 
            then search in left */
        if (target < arr[mid])
        {

            // If target is greater than previous
            // to mid, return closest of two
            if (mid > 0 && target > arr[mid - 1])
                return getClosest(arr[mid - 1],
                                  arr[mid], target);

            /* Repeat for left half */
            j = mid;
        }

        // If target is greater than mid
        else
        {
            if (mid < n - 1 && target < arr[mid + 1])
                return getClosest(arr[mid],
                                  arr[mid + 1], target);
            // update i
            i = mid + 1;
        }
    }

    // Only single element left after search
    return arr[mid];
}

// Method to compare which one is the more close.
// We find the closest by taking the difference
// between the target and both values. It assumes
// that val2 is greater than val1 and target lies
// between these two.

int getClosest(int val1, int val2, int target)
{
    if (target - val1 >= val2 - target)
        return val2;
    else
        return val1;
}
    

//Function to calculate logical gates
void logicalCalc(){

}