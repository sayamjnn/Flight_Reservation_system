#include<iostream>
#include <vector>
#include <sstream>
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
           int ID;
           int capacity;
           route* route;
           int typeOfSeat;
           economy* economySeats;
           business* businessSeats;
           firstClass* firstClassSeats;
    public:
         airplane()
         {
            ID=0;
            capacity=0;
         }
         airplane(int modelNumber,int capacity)
         {
            this->ID=modelNumber;
            this->capacity=capacity;
         }
         string selecteSeat()
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
                        return a;
                  }
            }

         }
          

};

class passenger{
    public:
    string name;
    int age;
    char sex;
    int mobileNM;
    int seatNumber;

    passenger( string name,int age,char sex)
    {
        this->name=name;
        this->age=age;
        this->sex=sex;

    }

    void printPassenger()
    {

    }

    void addMobileNUmber()
    {
        if(this->age>=18)
        {
            cout<<"Enter your mobile number"<<endl;
            cin>>this->mobileNM;
        }else{
            throw "NOT needed!!";
        }
    }



};

class Packages{
    public:
    string packageName;
     string services;
     int price;


Packages(   string packageName,string services,int price){
    this->packageName=packageName;
    this->price=price;
    this->services=services;
}

void printPAckage()
{

}



};

class Flight{
    public:
    string departureTime;
    string ArrivalTime;
    int duration;
    string FlightNumber;
    int defaultPrice;
    airplane *Planes;
    Packages *packages;

    Flight(string departureTime, string ArrivalTime, string FlightNumber,int defaultPrice)
    {
        this->defaultPrice=defaultPrice;
        this->ArrivalTime=ArrivalTime;
        this->departureTime=departureTime;
        this->FlightNumber=FlightNumber;
        this->duration=calculateDuration();
    }


    int calculateDuration() {

        string arHr=ArrivalTime.substr(0,2);
        int arrivalHour=stoi(arHr);

        string arMi=ArrivalTime.substr(3);
        int arrivalMinute=stoi(arMi);

        string drHr=departureTime.substr(3);
         int departureHour=stoi(drHr);

        string drMi=departureTime.substr(3);
        int departureMinute=stoi(drMi);
    int durationHour = departureHour - arrivalHour;
    int durationMinute = departureMinute - arrivalMinute;

    // Handling negative minutes
    if (durationMinute < 0) {
        durationMinute += 60;
        durationHour--;
    }

    return (durationHour * 60) + durationMinute;
}

void addPackages()
{
    
    int size = sizeof(packages) / sizeof(packages[0]);
      for (int i = 0; i < size; i++)
      {
        packages[i].printPAckage();
        cout<<endl;
      }
      cout<<"Enter the package you want you can select multiple packages"<<endl;
    string input;
    vector<int> values;
    cout << "Enter values (press Enter to finish): ";

    // Read input until the user presses Enter
    while (getline(std::cin, input) && !input.empty()) {
        // Convert the input string to an integer
        int value;
        istringstream iss(input);
        if (iss >> value) {
            // Store the integer value
            values.push_back(value);
        } else {
           cout << "Invalid input. Please enter an integer value." << std::endl;
        }
    }

    for(int value : values){
         
    }
}

void printFlight()
{

}
};
int main()
{
 
    return 0;
}
