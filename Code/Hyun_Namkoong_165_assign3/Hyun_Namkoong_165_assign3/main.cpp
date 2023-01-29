//
//  main.cpp
//  Hyun_Namkoong_165_assign3
//
//  Created by Hyun Namkoong on 3/3/22.
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <numeric>
using namespace std;

void getJudgeData(double& n);
double findHighest(double a, double b, double c, double d, double e);
double findLowest(double a, double b, double c, double d, double e);
void calcScore(double a, double b, double c, double d, double e);

int main()
{
   double score1;
   double score2;
   double score3;
   double score4;
   double score5;

   getJudgeData(score1);
   getJudgeData(score2);
   getJudgeData(score3);
   getJudgeData(score4);
   getJudgeData(score5);

   
   calcScore(score1, score2, score3, score4, score5);
   
    cout << endl;
   // system("PAUSE");
   return 0;
}


void getJudgeData(double& n)
{
   do
   {
      cout << "Enter a judge's score: ";
      cin >> n;
      if (n < 0 || n>10.0)
         cout << "The score must be between 0.0 and 10.0" << endl;

   } while (n < 0 || n>10.0);
}

double findHighest(double a, double b, double c, double d, double e)
{
   vector<double> v = { a,b,c,d,e };

   double max = *max_element(v.begin(), v.end());

   return max;
}

double findLowest(double a, double b, double c, double d, double e)
{
   vector<double> v = { a,b,c,d,e };

   double min = *min_element(v.begin(), v.end());

   return min;
}


void calcScore(double a, double b, double c, double d, double e)
{

   double max = findHighest(a, b, c, d, e);
   double min = findLowest(a, b, c, d, e);

   vector<double> v = {a,b,c,d,e};
   
   double sum = v[0] + v[1] + v[2] + v[3] + v[4];
   double sum_2 = sum - max - min;

   double avg = sum_2 / 3;
   cout << "After dropping the lowest and highest scores, the average score was " << avg;

}
