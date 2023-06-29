#include<iostream>
using namespace std;
class route
{
    public:
          string from;
          string to;
          string intermediate;
    public:
           route()
           {
            from="";
            to="";
            intermediate="";
           }
           route(string from,string to,string intermediate)
           {
            this->from=from;
            this->to=to;
            this->intermediate=intermediate;
           }
           void printRoute()
           {
            cout<<"from:"<<from<<endl;
            cout<<"to:"<<to<<endl;
            cout<<"intermediate:"<<intermediate<<endl;
           }

};

class seat
{
    public:
         int defaultprice;
         int seatnumber;
    public:
         seat()
        {
            defaultprice=0;
            seatnumber=0;
        }
        seat(int defaultprice,int seatnumber,string typeOfSeat)
        {
            this->defaultprice=defaultprice;
            this->seatnumber=seatnumber;
        }
        void printSeat()
        {
            cout<<"defaultprice:"<<defaultprice<<endl;
            cout<<"seatnumber:"<<seatnumber<<endl;

        }
        virtual void bookSeat()=0;
       
};
class economy:public seat{
public:
int seats[20][20];

economy():seat()
{
    for(int i=0;i<20;i++)
{
    for(int j=0;j<20;j++)
    {
        seats[i][j]=0;
    }
}
}
string bookseat()
{
    string position;
  for(int i=0;i<20;i++)
  {
    position+=i;

    for(int j=0;j<20;j++)
    {
        if(seats[i][j]==0)
        {
            seats[i][j]=1;
            position+=j;
            return position;
        }
    }
}
return "Not found";
}
};
class business:public seat{
public:
int seats[20][20];

int price;
business():seat()
{
    for(int i=0;i<20;i++)
{
    for(int j=0;j<20;j++)
    {
        seats[i][j]=0;
    }
} 
}
string bookseat()
{
    string position;
  for(int i=0;i<20;i++)
  {
    position+=i;

    for(int j=0;j<20;j++)
    {
        if(seats[i][j]==0)
        {
            seats[i][j]=1;
            position+=j;
            return position;
        }
    }
  }
return "Not found";
}
};
class firstClass:public seat{
public:
int seats[20][20];

firstClass():seat()
{
     for(int i=0;i<20;i++)
{
    for(int j=0;j<20;j++)
    {
        seats[i][j]=0;
    }
}
}
string bookseat()
{
    string position;
  for(int i=0;i<20;i++)
  {
    position+=i;

    for(int j=0;j<20;j++)
    {
        if(seats[i][j]==0)
        {
            seats[i][j]=1;
            position+=j;
            return position;
        }
    }
  }
return "Not found";
}
};
class airplane
{
    public:
           int modelNumber;
           int capacity;
           route* route;
           int typeOfSeat;
           economy* economySeats;
           business* businessSeats;
           firstClass* firstClassSeats;
    public:
         airplane()
         {
            modelNumber=0;
            capacity=0;
         }
         airplane(int modelNumber,int capacity)
         {
            this->modelNumber=modelNumber;
            this->capacity=capacity;
         }
         void selecteSeat()
         {
            string a;
            cout<<"Select Type of seat"<<endl;
            cout<<"1:Economy seat"<<endl;
            cout<<"2:Business seat"<<endl;
            cout<<"3:First class seat"<<endl;
            cout<<"4:skip"<<endl;
            cin>>typeOfSeat;
            if(typeOfSeat==1)
            {
                  a=economySeats->bookseat();
                  if(a=="Not found")
                  {
                    throw "All Seats Booked";
                  }
                  else
                  {

                  }
            }

         }
          void updatePrice()
        {
            if(typeOfSeat=="economy class")
            {
                
            }
            else if(typeOfSeat=="business class")
            {
                
            }
            else if(typeOfSeat=="first class")
            {
                
            }
        }

};
int main()
{
    route r("hubli","bangalore","hyderabad");
    r.printRoute();
    seat s(3500,4,"business class");
    s.updatePrice();
    s.printSeat();
    return 0;
}
