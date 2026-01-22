// You can use this file to call your functions for basic testing.
// You don't need to make changes in this file.


#include "code.h"


int main()
{
 /*   //printImage test
    image img = {
        {10,  20,  30,  40,  50,  60,  70,  80,  90,  100},
        {10,  20,  30,  40,  50,  60,  70,  80,  90,  100},
        {10,  20,  30,  40,  50,  60,  70,  80,  90,  100},
        {10,  20,  30,  40,  50,  60,  70,  80,  90,  100},
        {10,  20,  30,  40,  50,  60,  70,  80,  90,  100}
    };

    printImage(img);

     expected: 
    "10\t20\t30\t40\t50\t60\t70\t80\t90\t100\t\n"
    "10\t20\t30\t40\t50\t60\t70\t80\t90\t100\t\n"
    "10\t20\t30\t40\t50\t60\t70\t80\t90\t100\t\n"
    "10\t20\t30\t40\t50\t60\t70\t80\t90\t100\t\n"
    "10\t20\t30\t40\t50\t60\t70\t80\t90\t100\t\n"
    */

// minMaxNormalization test
vector<vector<int>> image{
    {100, 200, 300, 400, 500},
    {50, 150, 250, 350, 450},
    {175, 275, 375, 475, 575},
    {0, 100, 200, 300, 400},
    {50, 150, 250, 350, 450}
    };
    
    minMaxNormalization(image);
    
    return 0;
}