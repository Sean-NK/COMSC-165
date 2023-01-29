//
//  main.cpp
//  Hyun_Namkoong_165_assign5
//
//  Created by Hyun Namkoong on 3/12/22.
//

#include <iostream>
using namespace std;
const int COLS = 5;
//Function Prototypes
int getTotal(int array[][COLS], int rows);
int getRowTotal(int array[][COLS], int rowToTotal);
double getAverage(int array[][COLS], int rows);
int getColumnTotal(int array[][COLS], int colToTotal, int rows);
int getHighestInRow(int array[][COLS], int rowToSearch);
int getLowestInRow(int array[][COLS], int rowToSearch);
int main()
{
  const int ROWS = 4;
  
  int testArray[ROWS][COLS] =
   { { 1,   2,  3,  4,  5 },
   {   6,   7,  8,  9, 10 },
   {  11,  12, 13, 14, 15 },
   {  16,  17, 18, 19, 20 } };
   
     

    
  cout << "The total of the array elements is " << getTotal(testArray, ROWS) << endl;;

//  cout << "The average value of an element is " << getAverage(testArray, ROWS) << endl;
//
//  cout << "The total of row 0 is " << getRowTotal(testArray, 0) << endl;
//
//  cout << "The total of col 2 is " << getColumnTotal(testArray, 2, ROWS) << endl;
//
//  cout << "The highest value in row 2 is " << getHighestInRow(testArray, 2) << endl;
//
//  cout << "The lowest value in row 2 is " << getLowestInRow(testArray, 2) << endl;

    //system("PAUSE");
  return 0;
}
// Implement the six (6) functions here

int getTotal(int array[][COLS], int rows)
{
    int sum=0;
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<COLS;j++)
        {
            sum+=array[i][j];
        }
     }
    return sum;
}

//double getAverage(int array[][COLS], int rows)
//{
//    int sum=0;
//    double average=3.0;
//    for(int i=0;i<rows;i++)
//    {
//        for(int j=0;j<COLS;j++)
//        {
//            sum+=array[i][j];
//        }
//     }
//    average=sum/21.0;
//    return average;
//}
//
//int getRowTotal(int array[][COLS], int rowToTotal)
//{
//    int sum=0;
//    for(int i=0;i<COLS;i++)
//    {
//        sum+=array[rowToTotal][i];
//    }
//    return sum;
//}
//
//int getColumnTotal(int array[][COLS], int colToTotal, int rows)
//{
//    int sum=0;
//    for(int i=0;i<COLS;i++)
//    {
//        sum+=array[i][colToTotal];
//    }
//    return sum;
//}
//
//int getHighestInRow(int array[][COLS], int rowToSearch)
//{
//    int high=0;
//    for(int i=0; i<COLS;i++)
//    {
//        if(high<array[rowToSearch][i])
//        {
//            high=array[rowToSearch][i];
//        }
//    }
//    return high;
//}
//
//int getLowestInRow(int array[][COLS], int colToSearch)
//{
//    int low=0;
//    for(int i=0; i<COLS;i++)
//    {
//        if(low>array[i][colToSearch])
//        {
//            low=array[i][colToSearch];
//        }
//    }
//    return low;
//}
////error 뜰떄는 세분화해서 cout을 찍어보면 어디서 오류가 났는지 알 수 있음
