#include <iostream>
#include <fstream>
using namespace std;

const int DESC_SIZE = 31;
const int DATE_SIZE = 11;

struct Inventory
{
   char desc[DESC_SIZE];
   int qty;
   double wholeSale;
   double retail;
   char date[DATE_SIZE];
   Inventory* next = nullptr;
                             
};

void addRecord(fstream &);
void viewRecord(fstream &);
void changeRecord(fstream &);
Inventory buildList(fstream &,Inventory* head);
void prindList(Inventory* head);

int main()
{
    Inventory* head = new Inventory;
    Inventory* rtn = new Inventory;
    head->qty = NULL;
    head->wholeSale = NULL;
    head->retail = NULL;
    head->next = NULL;

    
    Inventory inv;
    cout << inv.next;

   fstream inventoryFile;
   
   int choice;

   do
   {
      cout << "\n1. Add a new record\n";
      cout << "2. View an existing record\n";
      cout << "3. Change an existing record\n";
      cout << "4. Exit\n\n";
      cout << "Enter your choice (1-4): ";
      cin >> choice;
      
      while (choice < 1 || choice > 4)
      {
         cout << "ERROR. Enter 1, 2, 3, or 4: ";
         cin >> choice;
      }

      switch (choice)
      {
         case 1:
            addRecord(inventoryFile);
            break;
          case 2:
              viewRecord(inventoryFile);
              break;
          case 3:
              changeRecord(inventoryFile);
              break;
     }
       
   } while (choice != 4);

    *rtn = buildList(inventoryFile,head);
    
    cout << rtn -> next ->next ->retail << endl;
 
    
    if(choice == 4)
    {
        prindList(rtn);
    }
 //  system("PAUSE");
   return 0;
}

void addRecord(fstream &invFile)
{
   Inventory record;

   invFile.open("invtry.dat", ios::out | ios::app | ios::binary);

   if (invFile.fail())
   {
      cout << "Error opening file.\n";
      exit(EXIT_FAILURE);
   }
    
   cin.get();
    
   cout << "\nEnter the following inventory data:\n";
   
   cout << "Description: ";

   cin.getline(record.desc, DESC_SIZE);
   
   cout << "Quantity: ";
   cin >> record.qty;
    
   while (record.qty < 0)
   {
      cout << "Enter a positive value, please: ";
      cin >> record.qty;
   }
    
   cout << "Wholesale cost: ";
   cin >> record.wholeSale;
   while (record.wholeSale < 0)
   {
      cout << "Enter a positive value, please: ";
      cin >> record.wholeSale;
   }
   
   cout << "Retail price: ";
   cin >> record.retail;
   while (record.retail < 0)
   {
      cout << "Enter a positive value, please: ";
      cin >> record.retail;
   }
   
   cout << "Date added to inventory: ";
   cin >> record.date;
  
   invFile.write(reinterpret_cast<char *>(&record), sizeof(record));
   
   if (invFile.fail())
      cout << "Error writing record to file.\n";
   else
      cout << "record written to file.\n\n";

   invFile.close();
}

void viewRecord(fstream& invFile)
{
    Inventory record;
    int num = 0;
    
    invFile.open("invtry.dat", ios::in | ios::binary);
    
    if (invFile.fail())
    {
       cout << "Error opening file.\n";
       exit(EXIT_FAILURE);
    }
    
    cout << endl << "Enter the record number of the item: ";
    cin >> num;
    
    invFile.seekg(80*num, ios::beg);
    
    invFile.read(reinterpret_cast<char*>(&record), sizeof(record));
    
    cout << "Description: " << record.desc << endl;
    cout << "Quantity: " << record.qty << endl;
    cout << "Wholesale cost: " << record.wholeSale << endl;
    cout << "Retail price: " << record.retail << endl;
    cout << "Date added to inventory: " << record.date << endl;
    
    invFile.close();
}

void changeRecord(fstream& invFile)
{
    Inventory record;
    int num = 0;
    
    invFile.open("invtry.dat", ios::in | ios::out | ios::binary);
    
    if (invFile.fail())
    {
       cout << "Error opening file.\n";
       exit(EXIT_FAILURE);
    }
    
    cout << "Enter the record number of item: ";
    cin >> num;
    
    invFile.seekg(80*num, ios::beg);
    
    invFile.read(reinterpret_cast<char*>(&record), sizeof(record));
    
    cout << "Description: " << record.desc << endl;
    cout << "Quantity: " << record.qty << endl;
    cout << "Wholesale cost: " << record.wholeSale << endl;
    cout << "Retail price: " << record.retail << endl;
    cout << "Date added to inventory: " << record.date << endl;
    cout << endl;
    
    cin.get();
     
    cout << "\nEnter the following inventory data:\n";
    
    cout << "Description: ";

    cin.getline(record.desc, DESC_SIZE);
    
    cout << "Quantity: ";
    cin >> record.qty;
    while (record.qty < 0)
    {
       cout << "Enter a positive value, please: ";
       cin >> record.qty;
    }

    cout << "Wholesale cost: ";
    cin >> record.wholeSale;
    while (record.wholeSale < 0)
    {
       cout << "Enter a positive value, please: ";
       cin >> record.wholeSale;
    }
    
    cout << "Retail price: ";
    cin >> record.retail;
    while (record.retail < 0)
    {
       cout << "Enter a positive value, please: ";
       cin >> record.retail;
    }
    
    cout << "Date added to inventory: ";
    cin >> record.date;
    
    invFile.seekg(80*num, ios::beg);
    invFile.write(reinterpret_cast<char *>(&record), sizeof(record));
    
    invFile.close();
}

Inventory buildList(fstream &invFile, Inventory* head)
{
    Inventory record;
    Inventory* a = new Inventory;
    a = head;
    invFile.open("invtry.dat", ios::in | ios::binary);
    
    if (invFile.fail())
    {
       cout << "Error opening file.\n";
       exit(EXIT_FAILURE);
    }
        
    
    
    for(int i=0;i<3;i++)
    {
        Inventory* new_node = new Inventory;
        new_node -> retail = NULL;
        new_node -> qty = NULL;
        new_node -> wholeSale = NULL;
        new_node ->next = NULL;
        invFile.seekg(80*i, ios::beg);
        invFile.read(reinterpret_cast<char*>(&record), sizeof(record));
    
        new_node = &record;
        cout << "ㅃ" << new_node->qty << endl;
        
        cout << head << endl;
        head = new_node;
      if(head -> next == NULL)
      {
          
          cout << " a1" << endl;
          cout << head << endl;
          cout << endl;
      }
      else
      {
          while(head-> next != nullptr)
          {
              head = head ->next;
              cout << "1121" << endl;
          }
      }
        head->next = new_node;
    }
    
    
    invFile.close();

    return *head;
}

void prindList(Inventory* head)
{
//    head = head -> next;
    cout << "@" << head->desc << endl;
    int num = 0;
//    while(head != nullptr)
//    {
//        cout << "Record #" << num << ":" << endl;
//        cout << "Description: " << head -> desc << endl;
//        cout << "Quantity: " << head -> qty << endl;
//        cout << "Wholesale cost: " << head -> wholeSale << endl;
//        cout << "Retail price: " << head -> retail << endl;
//        cout << "Data added to inventory: " << head -> date << endl;
//
//        head = head -> next;
//        num++;
//    }
}
