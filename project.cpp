#include<iostream>
#include <vector>
#include <sstream>
#include<ctime>
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
         void printPlane()
         {
            cout<<"AIRPLANE ID:"<<this->ID<<endl;
            cout<<"AIRPLANE CAPACITY:"<<this->capacity<<endl;
            cout<<"TYPE OF SEAT:"<<this->typeOfSeat<<endl;
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
     cout<<"PASSENGER NAME:"<<this->name<<endl;
     cout<<"PASSENGER SEX:"<<this->sex<<endl;
     cout<<"PASSENGER AGE:"<<this->age<<endl;
     if(this->age>=18)
     {
        cout<<"PASSENGER MOBILE NUMBER:"<<this->mobileNM<<endl;
     }
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

    Packages( string packageName,string services,int price){
     this->packageName=packageName;
     this->price=price;
     this->services=services;
}

void printPackage()
{
   cout<<"PACKAGE NAME:"<<this->packageName<<endl;
   cout<<"PACKAGE SERVICES:"<<this->services<<endl;
   cout<<"PACKAGE PRICE:"<<this->price<<endl;
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
        packages[i].printPackage();
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
       defaultPrice+= packages[value].price;
    }
}

void printFlight()
{
 cout<<"DEPARTURE TIME:"<<this->departureTime<<endl;
 cout<<"ARRIVAL TIME:"<<this->ArrivalTime<<endl;
 cout<<"FLIGHT NUMBER:"<<this->FlightNumber<<endl;
 cout<<"DEFAULT PRICE:"<<this->defaultPrice<<endl;
}
};



class Addones
{

    public:
    string name;
    string service;
    int price;

    Addones(string name,string service,int price)
    {
        this->name=name;
        this->service=service;
        this->price=price;

    }

    void printAddOnes()
    {
       cout<<"ADDONES NAME:"<<this->name<<endl;
       cout<<"ADDONES SERVICE:"<<this->service<<endl;
       cout<<"ADDONES PRICE:"<<this->price<<endl;
    }
};


class FlightSelection
{
    public:
    string from;
    string to;
    string date;
    int NumberOfPassengers;
    passenger *Passenger;
    Addones *arrAddons;
    Flight *flights;


    FlightSelection( string from, string to,string date,int NumberOfPassengers){
        this->date=date;
        this->from=from;
        this->NumberOfPassengers=NumberOfPassengers;
        this->to=to;
    }
    void printflightselection()
    {
        cout<<"SOURCE"<<this->from<<endl;
        cout<<"DESTINATION"<<this->to<<endl;
        cout<<"DATE"<<this->date<<endl;
        cout<<"NUMBER OF PASSENGERS"<<this->NumberOfPassengers<<endl;
    }
};

class Payment
{
    public:
    int id;
    int amount;
    int status;
    string date;
    Payment(){}
    Payment(int id,int amount,int status,string date)
    {
        this->id=id;
        this->amount=amount;
        this->status=status;
        this->date=date;
    }
    void printPaymentDetails()
    {
      cout<<"PAYMENT ID:"<<this->id<<endl;
      cout<<"PAYMENT AMOUNT:"<<this->amount<<endl;
      if(this->status==1)
        cout<<"PAYMENT STATUS:SUCCESSFUL"<<endl;
        else
        cout<<"PAYMENT STATUS:UNSUCCESSFUL"<<endl;
       cout<<"PAYMENT DATE:"<<this->date<<endl;
    }
    int returnStatus()
    {
        if(status==1)
        return 1;
        return 0;
    }
};
class UPI
{
    public:
   int pin;

   UPI(int p)
   {
     this->pin=p;
   }
   
 void validatepin(int amount)
 {
    int validpin;
    cout<<"Enter the pin"<<endl;
    cin>>validpin;
      time_t currentTime =  time(nullptr);
      string dateString =  ctime(&currentTime);
    if(validpin==pin){
       Payment *payment = new Payment(rand(),amount,1,dateString);
    }else{
        Payment *payment = new Payment(rand(),amount,0,dateString);
         cout<<"Payment failed"<<endl;
    }
 }
};
class card
{
    public:
    string bankName;
    int cardNo;
    string typeOfCard;
    string validity;
    int otp;
    card(int otp)
    {
        string bank,card,valid;
        int cno;
        cout<<"Enter the card details bankname,cardNo,typeOfCard,validity(mm//yy)"<<endl;
        cin>>bank>>cno>>card>>valid;
        this->bankName=bank;
        this->cardNo=cno;
        this->typeOfCard=card;
        this->validity=valid;
        this->otp=otp;

    }
    int pay(int amount)
    {
        int itp1;
        cout<<"Enter the otp"<<endl;
        cin>>itp1;
         time_t currentTime =  time(nullptr);
      string dateString =  ctime(&currentTime);
         if(itp1==otp){
        Payment *payment = new Payment(rand(),amount,1,dateString);
    } else{
        Payment *payment = new Payment(rand(),amount,0,dateString);
        cout<<"Payment failed"<<endl;
    }
    }
};

class paymentOptions
{
public:
  int amount;
  string modeOfpayment;
  UPI *upi;
  card *DebitCard;

 
  paymentOptions(int amount)
  {
    this->amount=amount;
    cout<<"Enter the mode of payment"<<endl;
    cin>>this->modeOfpayment;
  }

  void selectPaymentOptions()
  {
      if(modeOfpayment=="UPI")
      {
           upi=new UPI(123456789);
           upi->validatepin(amount);
      }else{
         DebitCard=new card(123);
         DebitCard->pay(amount);

      }
  }

  void printDetails()
  {
     cout<<"AMOUNT:"<<this->amount<<endl;
     cout<<"MODE OF PAYMENT:"<<this->modeOfpayment<<endl;
  } 
};

class AirlineBooking
{
    public:
    int bookingId;
    paymentOptions *payment;
    FlightSelection *SelectFlight;

    AirlineBooking()
    {
        this->bookingId=rand();
    }

    void printBooking()
    {
       cout<<"BOOKING ID:"<<this->bookingId<<endl;
       payment->printDetails();
       SelectFlight->printflightselection();
    }
};

class JourneyDetails
{
    public:
    AirlineBooking *Book;
    
    void printJourneyDetails()
    {
      Book->printBooking();
    }

};