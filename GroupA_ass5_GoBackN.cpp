#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

void trasmitframes(int totalframe,int windowsize,int &totalTrasmitted)
{
   int current=1;
   while(current<=totalframe)
   {
      int successfulAcks=0;
      for(int i=current;i<current+windowsize && i<=totalframe;i++)
      {
           cout<<"Sending Frame "<<i<<".."<<endl;
           totalTrasmitted++;
       }
       
       for(int i=current;i<current+windowsize && i<=totalframe;i++)
       {
           int sucess=rand()%2;
           if(sucess==0)
           {
              cout<<"Acknowledment for frame "<<i<<" received"<<endl;
              successfulAcks++;
           }
           else
           {
              cout<<"Timeout!! FRame "<<i<<" not received"<<endl;
              cout<<"Retransmitting window.."<<endl;
              break;
           }
       }
           current+=successfulAcks;
           cout<<endl;        
      }
   }
   int main()
   {
     int totalframe,windowsize, totalTrasmitted=0;
     srand(time(0)) ;
     
     cout<<"Enter the total number of frame:";
     cin>>totalframe;
     
     cout<<"Enter the window size:";
     cin>>windowsize;
     trasmitframes(totalframe,windowsize,totalTrasmitted);
     
       cout<<"Total number of frame sent:"<<totalTrasmitted<<endl;
       
       return 0;
   }
