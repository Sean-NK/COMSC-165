//
//  main.cpp
//  Hyun_Namkoong_165_assign11
//
//  Created by Hyun Namkoong on 5/1/22.
//

#include <iostream>
#include <iomanip>
using namespace std;

struct Drink
{
    string name;
    double cost;
    int num;

};

void showMenu(Drink arr[5]);
double getMoney(Drink d);
void getRest(Drink d, double& money);

int main()
{
    Drink d1{"Cola",0.75,20};
    Drink d2{"Root Beer",0.75,20};
    Drink d3{"Lemon-Lime",0.75,20};
    Drink d4{"Grape Soda",0.80,20};
    Drink d5{"Cream Soda",0.80,20};
    Drink arr[5]={d1, d2, d3, d4, d5};
    double total=0;
    int n=0;
    while(n==0)
    {
        showMenu(arr);

        int num;
        cout << "Choose one: ";
        cin >> num;
        if(arr[num-1].num==0)
        {
            cout << endl << "Select another number." << endl;
        }
        else
        {
         if(num!=6)
         {
             double money=0;
             money = getMoney(arr[num-1]);

             getRest(arr[num-1], money);
             total=total+arr[num-1].cost;
         }
         else
         {
             cout << "Total earnings: $" << total << endl;
             break;
         }
        }
    }
    
    return 0;
}

void showMenu(Drink arr[5])
{
    cout << endl;
    cout << fixed;
    cout.precision(2);
    cout << "1) " << setw(20) << left << arr[0].name << arr[0].cost << endl;
    cout << "2) " << setw(20) << left << arr[1].name << arr[1].cost << endl;
    cout << "3) " << setw(20) << left << arr[2].name << arr[2].cost << endl;
    cout << "4) " << setw(20) << left << arr[3].name << arr[3].cost << endl;
    cout << "5) " << setw(20) << left << arr[4].name << arr[4].cost << endl;
    cout << "6) Leave the drink machine" << endl<< endl;
   
}

double getMoney(Drink d)
{
    int i=0;
    double money=0;

    cout << "Enter an amount of money: ";
    while(i==0)
    {
        cin >> money;
        if(money>=d.cost&&money<=1.0)
        {
            i=1;
            cout << endl << "Enjoy your beverage!" << endl << endl;
        }
        else
        {
            cout << "Enter at least 0.75 and not more than 1 dollar." << endl;
        }
    }
    return money;
}

void getRest(Drink d, double& money)
{
    double rest;
    rest = money - d.cost;

        cout << "Change calculated: "<< rest << endl;
    if(rest!=0)
    {
        cout << "Your change, " << rest << " has just dropped into the Change Dispenser." << endl;
        cout << endl;
    }
 
      d.num-=1;
      cout << "There are " << d.num << " drinks of that type left." << endl;
}
