#include <conio.h>

#include <cstdio>

#include <iostream>

#include <string.h>

#include <cstdlib>

using namespace std;

static int p = 0;

/*void empty()
{

      for(int i=0; i<8;i++)
      {

        for(int j=0;j<4;j++)

        {

          strcpy(bus[p].seat[i][j], "Empty");

         }

         }

       }*/


class hash
{
    private:
    static const int tablesize=20;
    struct passenger
    {
        string name;
        string kyc;
        string phno;
        string date;
        string Destination;
        passenger* next;
    };
    char busn[5];
    char seat[8][4][10];
    char driver[10];
    int arrival;
    int depart;
    char from[10];
    char to[10];
    string name;
    string phno;
    passenger* HashTable[tablesize];
    public:
    Hash() 
    
    
    
    
    {
       for(int i=0;i<tablesize;i++)
       {
           HashTable[i]=new passenger;
           HashTable[i]->name="empty";
           HashTable[i]->phno="empty";
           //HashTable[i]->date="empty";
          // HashTable[i]->Destination="empty";
           HashTable[i]->next=NULL;
       } 
    }
    int Hashing(string key)
     {
    char c[2];
    int index,i;
    for( i=0;key[i]!='\0';i++);
    c[0]=key[i/2];
    int num=atoi(c);
    index=num*num;
    index=index%tablesize;
    return index;

      }
    void PrintTable();
    void AddpassengerEntry();
    int NumberofItemsinIndex(int index);
    void PrintItemsInIndex(int index);
    void SearchRecord(string name);
    void RemoveEntry(string name);
    void SortFields();
    void bookticket();
    /*void empty()
    
    {

      for(int i=0; i<8;i++)
      {

        for(int j=0;j<4;j++)

        {

          strcpy(bus[p].seat[i][j], "Empty");

         }

         }

       }*/
    void empty();   
    void install();
    void allotment();
    void show();
    void avail();
    void position(int l);
    
}bus[10];

void vline(char ch)

{

  for (int i=80;i>0;i--)

  cout<<ch;

}

void hash::install()

{

  cout<<"Enter bus no: ";

  cin>>bus[p].busn;

  cout<<"\nEnter Driver's name: ";

  cin>>bus[p].driver;

  cout<<"\nArrival time: ";

  cin>>bus[p].arrival;

  cout<<"\nDeparture: ";

  cin>>bus[p].depart;

  cout<<"\nFrom: \t\t\t";

  cin>>bus[p].from;

  cout<<"\nTo: \t\t\t";

  cin>>bus[p].to;

 // bus[p].empty();

  p++;

}

void hash::allotment()

{

  int seat;

  char number[5];

  top:

  cout<<"Bus no: ";

  cin>>number;

  int n;

  for(n=0;n<=p;n++)

  {

    if(strcmp(bus[n].busn, number)==0)

    break;

  }

  while(n<=p)

  {

    cout<<"\nSeat Number: ";

    cin>>seat;

    if(seat>32)

    {

      cout<<"\nThere are only 32 seats available in this bus.";

    }

    else

    {

    if (strcmp(bus[n].seat[seat/4][(seat%4)-1], "Empty")==0)

      {

        cout<<"Enter passanger's name: ";

        cin>>bus[n].seat[seat/4][(seat%4)-1];
        
        //cout<<"enter passengers name:";
		cin>>bus[n].name;
        
        cout<<"enter the phone number:";
        cin>>phno;
        int index=Hashing(phno);
        if(HashTable[index]->name=="empty")
        {
            HashTable[index]->name=bus[n].name;
            HashTable[index]->phno=bus[n].phno;
       
        } 
        else
      {
       passenger* Ptr=HashTable[index];
       passenger* n = new passenger;
       n->name=name;
       n->phno=phno;
      // n->date=date;
      // n->Destination=Destination;
       
       n->next=NULL;
       while(Ptr->next !=NULL)
       {
           Ptr=Ptr->next;

       }
       Ptr->next=n;
      }
      break;

      }

    //else

      //cout<<"The seat no. is already reserved.\n";

     // }

    }

    if(n>p)

    {

      cout<<"Enter correct bus no.\n";

      goto top;

    }

  }
  //void empty()
    
   /* {

      for(int i=0; i<8;i++)
      {

        for(int j=0;j<4;j++)

        {

          strcpy(bus[p].seat[i][j], "Empty");

         }

         }

       }*/

}
void hash::show()

{

  int n;

  char number[5];

  cout<<"Enter bus no: ";

  cin>>number;

  for(n=0;n<=p;n++)

  {

    if(strcmp(bus[n].busn, number)==0)

    break;

  }

while(n<=p)

{

  vline('*');

  cout<<"Bus no: \t"<<bus[n].busn

  <<"\nDriver: \t"<<bus[n].driver<<"\t\tArrival time: \t"

  <<bus[n].arrival<<"\tDeparture time:"<<bus[n].depart

  <<"\nFrom: \t\t"<<bus[n].from<<"\t\tTo: \t\t"<<

  bus[n].to<<"\n";

  vline('*');

  bus[0].position(n);

  int a=1;

  for (int i=0; i<8; i++)

  {

    for(int j=0;j<4;j++)

    {

      a++;

      if(strcmp(bus[n].seat[i][j],"Empty")!=0)

      cout<<"\nThe seat no "<<(a-1)<<" is reserved for "<<bus[n].seat[i][j]<<".";

    }

  }

  break;

  }

  if(n>p)

    cout<<"Enter correct bus no: ";

}

void hash::position(int l)

{

  int s=0;p=0;

  for (int i =0; i<8;i++)

  {

    cout<<"\n";

    for (int j = 0;j<4; j++)

    {

      s++;

      if(strcmp(bus[l].seat[i][j], "Empty")==0)

        {

          cout.width(5);

          cout.fill(' ');

          cout<<s<<".";

          cout.width(10);

          cout.fill(' ');

          cout<<bus[l].seat[i][j];

          p++;

        }

        else

        {

        cout.width(5);

        cout.fill(' ');

        cout<<s<<".";

        cout.width(10);

        cout.fill(' ');

        cout<<bus[l].seat[i][j];

        }

      }

    }

  cout<<"\n\nThere are "<<p<<" seats empty in Bus No: "<<bus[l].busn;

  }

void hash::avail()

{


  for(int n=0;n<p;n++)

  {

    vline('*');

    cout<<"Bus no: \t"<<bus[n].busn<<"\nDriver: \t"<<bus[n].driver

    <<"\t\tArrival time: \t"<<bus[n].arrival<<"\tDeparture Time: \t"

    <<bus[n].depart<<"\nFrom: \t\t"<<bus[n].from<<"\t\tTo: \t\t\t"

    <<bus[n].to<<"\n";

    vline('*');

    vline('_');

  }

}
void hash::PrintTable()
{
    int number;
   vline('*');
    cout<<"\nINDEX\t\tNAME\t\tK.Y.C\t\tPHNO\t\tDATE OF JOURNEY\t\tDESTINATION"<<endl;
    for(int i=0;i<tablesize;i++)
    {
        number=NumberofItemsinIndex(i);
      
        cout<<i<<"\t\t"<<HashTable[i]->name<<"\t"<<HashTable[i]->phno<<"\t"<<endl;
    }
    vline('*');
}
int hash::NumberofItemsinIndex(int index)
{
    int count=0;
    if(HashTable[index]->name=="empty")
    {
        return count;
    }
    else
    {
        count++;
        passenger* Ptr=HashTable[index];
        while(Ptr->next!=NULL)
        {
            count++;
            Ptr=Ptr->next;
        }
    }
    return count;
    
}


int main()

{

system("cls");

int w;

while(1)

{

    //system("cls");

  cout<<"\n\n\n\n\n";

  cout<<"\t\t\t1.install\n\t\t\t"

  <<"2.Reservation\n\t\t\t"

  <<"3.Show\n\t\t\t"

  <<"4.Buses Available. \n\t\t\t"
  <<"5.print the details.\n\t\t\t"
  <<"6.Exit";
  cout<<"\n\t\t\tEnter your choice:-> ";

  cin>>w;

  switch(w)

  {

    case 1:  bus[p].install();

      break;

    case 2:  bus[p].allotment();

      break;

    case 3:  bus[0].show();

      break;

    case 4:  bus[0].avail();

      break;
      
    case 5:  bus[0].PrintTable();
	  
	  break;  

    case 6:  exit(0);

  }

}

return 0;

}
