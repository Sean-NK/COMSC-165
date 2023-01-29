#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;
    const int NUM_OF_MONTHS = 3;
const int NUM_OF_DAYS = 30;
void make_array(int array[3][3], char* ptr_1);

int main()
{
char weather[NUM_OF_MONTHS][NUM_OF_DAYS];
    ifstream ifs("RainOrShine.txt");
    
    int i = 0;
       int j = 0;
       int n = 0;
       while (ifs)
       {
          char c;
          string str;
          getline(ifs, str);
          c = str[0];

          if (n != 90)
          {
             weather[i][j] = c;

             if (j == 29)
             {
                i += 1;
                j = 0;
             }
             else
                j += 1;
          }
          n += 1;
       }

char* ptr = &weather[0][0];
    int array[3][3]{};
    make_array(array,ptr);

        cout << "\t" << "Summer Weather Report" << endl;
        cout << endl;
        cout << "Month" << "\t" << "Rainy" << "  " << "Cloudy" << "  " << "Sunny" << endl;
        cout << endl;
        cout << "────────────────────────────" << endl;
        cout << "June" << "\t" << **array << "\t" <<  *(*(array)+1) << "\t" << *(*(array)+2)<< endl;
        cout << "July" << "\t" <<  *(*(array+1)) << "\t" << *(*(array+1)+1) << "\t" << *(*(array+1)+2) << endl;
        cout << "August" << "\t" << *(*(array+2)) <<  "\t" << *(*(array+2)+1)<< "\t" <<  *(*(array+2)+2) << endl;
        cout << endl;
        cout << "────────────────────────────" << endl;
        cout << "Totals" << "\t" << **array+*(*(array+1))+*(*(array+2)) << "\t" << *(*(array)+1)+*(*(array+1)+1)+*(*(array+2)+1) << "\t" << *(*(array)+2)+*(*(array+1)+2)+*(*(array+2)+2) << endl;
        cout << endl;

    if(**array > **(array+1) && **array > **(array+2))
       {
           cout << "June had the most rainy day." << endl;
       }
    else if(**(array+1) > **array && **(array+1) > **(array+2))
       {
           cout << "July had the most rainy day." << endl;
       }
    else if(**(array+2) > **array && **(array+2) > **(array+1))
       {
           cout << "August had the most rainy day." << endl;
       }

    
 
return 0;
}

void make_array(int array[3][3],  char* ptr_1)
{

    for(int i = 0; i<NUM_OF_MONTHS; i++)
    {
        for(int j=0;j<NUM_OF_DAYS;j++)
        {
            if(*(ptr_1+(30*i+j))=='R')
            {
                *(*(array+i))+=1;
            }
            if(*(ptr_1+(30*i+j))=='C')
            {
                *(*(array+i)+1)+=1;
            }
            if(*(ptr_1+(30*i+j))=='S')
            {
                *(*(array+i)+2)+=1;
            }
        }
    }
}
