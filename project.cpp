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
         string typeOfSeat;
    public:
         seat()
        {
            defaultprice=0;
            seatnumber=0;
            typeOfSeat="";
        }
        seat(int defaultprice,int seatnumber,string typeOfSeat)
        {
            this->defaultprice=defaultprice;
            this->seatnumber=seatnumber;
            this->typeOfSeat=typeOfSeat;
        }
        void printSeat()
        {
            cout<<"defaultprice:"<<defaultprice<<endl;
            cout<<"seatnumber:"<<seatnumber<<endl;
            cout<<"typeOfSeat:"<<typeOfSeat<<endl;
        }
        void updatePrice()
        {
            if(typeOfSeat=="economy class")
            {
                defaultprice=defaultprice;
            }
            else if(typeOfSeat=="business class")
            {
                defaultprice+=1500;
            }
            else if(typeOfSeat=="first class")
            {
                defaultprice+=3000;
            }
        }
};

class airplane()
{
    public:
           int modelNumber;
           int capacity;
           route route;
           seat seat;
    public:
         airplane()
         {
            modelNumber=0;
            capacity=0;
         }
         airplane(modelNumber,capacity)
         {
            this->modelNumber=modelNumber;
            this->capacity=capacity;
         }
         
    

}
int main()
{
    route r("hubli","bangalore","hyderabad");
    r.printRoute();
    seat s(3500,4,"business class");
    s.updatePrice();
    s.printSeat();
    return 0;
}
