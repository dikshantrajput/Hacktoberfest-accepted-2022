//This project is based on booking flight tickets and  listing passangers information
//ONLY WORKS IN TURBO C++
#include<conio.h>
#include<iostream.h>
#include<fstream.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include<graphics.h>
#include<stdlib.h>
//THIS CLASS CONTAIN ALL THE FUNCTIONS RELATED TO TICKET

class TRAVEL
 {
     public:
       void INFORMATION(void);
       void RESERVATION(void);
       int RESERVED(int,int,int,int,int);
       int AVAIL(int,int,int,int);
       void DELETION(void);
       void LIST_OF_PASS(void);
       void PASS_INFO(void);
       void MAINMENU(void);
    private:
       int busno,seatno;
       char name[26],sex;
       int age,fair;
       int dd,mm,yy;
    };
    char *place[3]={"MUMBAI","KOLKATA","CHENNAI"};
    int price[3]={3000,3200,3400};
//THIS FUNCTION DISPLAY THE PASSENGER INFORMATION


void TRAVEL::PASS_INFO(void)
  {
     clrscr();
     int bno=0,found=0,sno,d,m,y;
     cout<<"\n Flight 1:Delhi to Mumbai.       <fare Rs.3000>";
     cout<<"\n Flight 2:Delhi to Kolkata.         <fare Rs.3200>";
     cout<<"\n Flight 3:Delhi to Chennai.        <fare Rs.3400>";
     do
       {
     cout<<"\n\n enter the fightno.(1/2/3)";
     cin>>bno;
       }while(bno<1||bno>3);
     cout<<"\n\n enter the date of the reserved ticket:";
     cin>>d;
     cout<<"\n\n enter the month:";
     cin>>m;
     cout<<"\n\n enter the year:";
     cin>>y;
     cout<<"\nenter the seat no.:";
     cin>>sno;
     if(sno>60||sno<1||!RESERVED(bno,d,m,y,sno))
       {
     cout<<"\n\n\nsorry!\7seat not reserved";
     getch();
     return;
       }
     fstream file;
     file.open("AIR.DAT",ios::in);
     while(file.read((char *)this,sizeof(TRAVEL)))
       {
     if((dd==d&&mm==m&&yy==y)&&bno==busno&&sno==seatno)
       {
	 found=1;
	 clrscr();
	 gotoxy(5,5);



	 cout<<"**********************************************************************";
	 gotoxy(28,7);
	 cout<<"cpptute.air travel agency";
	 gotoxy(10,9);
	 cout<<"FLIGHT NO."<<bno<<"\t\t\tDATE:"<<d<<"/"<<m<<"/"<<y;
	 gotoxy(10,10);
	 cout<<"SEAT NO.:"<<sno;
	 gotoxy(35,12);
	 cout<<"FROM:DELHI"<<"\tTo:"<<place[bno-1];
	 gotoxy(10,15);
	 cout<<"Passenger Name:"<<name;
	 gotoxy(10,16);
	 cout<<"Passenger Age:  "<<age<<"\t\tsex:"<<sex;
	 gotoxy(10,18);
	 cout<<"Total Fair   :" <<price[bno-1];
	 gotoxy(5,20);
	 cout<<"************************************************************************";
	 gotoxy(1,25);
	 cout<<"press any key to continue...";
	 getch();
	 break;
       }
       }
     file.close();
     if(!found)
       {
     cout<<"\n\n7passenger record not found";
     getch();
       }
  }
//This function gives the list of all the passenger
void TRAVEL::LIST_OF_PASS(void)
  {
     clrscr();
     int bno=0,found=0,row=8;
     char ch;
     cout<<"\n Flight 1:Delhi to Mumbai. <ticket Rs.3000>";
     cout<<"\n Flight 2:Delhi to Kolkata.   <ticket Rs.3200>";
     cout<<"\n Flight 3:Delhi to Chennai.  <ticket Rs.3400>";
     do
       {
     cout<<"\n\nenter the flight no.(1/2/3)";
     cin>>bno;
       }while(bno<1||bno>3);
     do
       {
     cout<<"\n Do you want date wise report(y/n)";
     cin>>ch;
       }while(toupper(ch)!='N'&& toupper(ch)!='Y');
     int d=0,m=0,y=0;
     if(toupper(ch)=='Y')
       {
     cout<<"\n\n Enter  date:";
     cin>>d;
     cout<<"\n\n Enter month:";
     cin>>m;
     cout<<"\n\n Enter year:";
     cin>>y;
       }
     clrscr();
     gotoxy(25,1);
     cout<<"LIST OF THE PASSENGERS ";
     gotoxy(24,2);
     cout<<"\n***********************************************************************"<<endl;
     gotoxy(1,3);
     cout<<" FLIGHT NO.:"<<bno<<"\t\t\t\t\tfrom: DELHI TO:"<<place[bno-1];
     gotoxy(2,5);
     cout<<"SEAT NO.   PASSENGER NAME               SEX    AGE    DATE ";
     gotoxy(2,6);
     cout<<"**************************************************************************"<<endl;
     fstream file;
     file.open("AIR.DAT",ios::in);
     while(file.read((char*)this,sizeof(TRAVEL)))
       {
     if(busno==bno)
     {
      if((toupper(ch)=='N')||((toupper(ch)=='Y')&&(dd==d&&mm==m&&yy==y)))
      {
       found=1;
       gotoxy(5,row);
       cout<<seatno;
       gotoxy(14,row);
       cout<<name;
       gotoxy(43,row);
       cout<<sex;
       gotoxy(50,row);
       cout<<age;
       gotoxy(61,row);
       cout<<dd<<"/"<<mm<<"/"<<yy;
       row++;
       if(row==25)
	 {
	   getch();
	   for(int i=8;i<=24;i++)
	   {
	 gotoxy(1,i);
	 clreol();
	   }
	 row=8;
      }
     }
       }
     }
     file.close();
     if(!found)
       {
     cout<<"\n\n\n\n\n\7No reservation for the flight no. "<<bno;
     getch();
     return;
       }
     cout<<"\n\nPress any key to continue..............";
     getch();
  }

int TRAVEL::AVAIL(int bno,int d,int m,int y)
  {
     fstream file;
     file.open("AIR.DAT",ios::in);
     int avail=0,count=0;
     while(file.read((char*)this,sizeof(TRAVEL)))
       {
     if(dd==d&&mm==m&&yy==y&&bno==busno)
     count++;
       }
     if(count<60)
     avail=1;
     file.close();
     return avail;
  }

int TRAVEL::RESERVED(int bno,int d,int m,int y,int sno)
  {
     fstream file;
     file.open("AIR.DAT",ios::in);
     int reserved=0;
     while(file.read((char*)this,sizeof(TRAVEL)))
       {
     if(dd==d&&mm==m&&yy==y&&bno==busno&&sno==seatno)
       {
	 reserved=1;
	 break;
       }
       }
     file.close();
     return reserved;
  }


       /* FUNCTION TO RESERVE TICKET */

void TRAVEL::RESERVATION(void)
  {

     clrscr();
     int bno,sno,pfair,page;
     char ch,pname[26],psex;
     cout<<"\n Flight 1:Delhi to Mumbai. <fare Rs.3000>";
     cout<<"\n Flight 2:Delhi to Kolkata.   <fare Rs.3200>";
     cout<<"\n Flight 3:Delhi to Chennai.  <fare Rs.3400>";
     do
       {
     cout<<"\n\nenter the flight no.(1/2/3)";
     cin>>bno;
       }while(bno<1||bno>3);
     int d,m,y;
     cout<<"\n\n Enter the date for reservation :";
     cin>>d;
     cout<<"\n\n Enter month:";
     cin>>m;
     cout<<"\n\n Enter year:";
     cin>>y;
     if(!AVAIL(bno,d,m,y))
       {
     cout<<"\n\n\nsorry!\7seat not available";
     getch();
     return;
       }
     cout<<"\nEnter the seat no.:";
     cin>>sno;
     if(sno>60||sno<1||RESERVED(bno,d,m,y,sno))
       {
     cout<<"\n\n\nsorry!\7seat already reserved";
     getch();
     return;
       }
     cout<<"\n Enter name of passenger:";
     gets(pname);
     do
       {
     cout<<"Enter sex of passenger(M/F):";
     cin>>psex;
       }while(toupper(psex)!='M'&&toupper(psex)!='F');
     cout<<"enter age:";
     cin>>page;
     if(page<=5)
       {
     cout<<"\7\n No ticket is required upto the age of 5";
     getch();
     return;
    }
     clrscr();
     gotoxy(5,5);
     cout<<"**********************************************************************"<<endl;
     gotoxy(28,7);
     cout<<"cpptute.air travel agency";
     gotoxy(10,9);
     cout<<"FLIGHT NO."<<bno<<"\t\t\tDATE:"<<d<<"/"<<m<<"/"<<y;
     gotoxy(10,10);
     cout<<"SEAT NO.:"<<sno;
     gotoxy(35,12);
     cout<<"FROM:DELHI"<<"\tTo:"<<place[bno-1];
     gotoxy(10,15);
     cout<<"Passenger Name:"<<pname;
     gotoxy(10,16);
     cout<<"Passenger Age:  "<<page<<"\t\tsex:"<<psex;
     gotoxy(10,18);
     cout<<"Total Amount   :" <<price[bno-1];
     gotoxy(5,20);
     cout<<"**********************************************************************";
     cout<<"\n\n\n";
     do
       {
     cout<<"Do you want to save ticket(y/n)";
     cin>>ch;
       }while(toupper(ch)!='N'&& toupper(ch)!='Y');
     if(toupper(ch)=='N')
     return;
     fstream file;
     file.open("AIR.DAT",ios::app);
     busno=bno;
     seatno=sno;
     strcpy(name,pname);
     sex=psex;
     age=page;
     fair=pfair;
     dd=d;
     mm=m;
     yy=y;
     file.write((char*)this,sizeof(TRAVEL));
     file.close();
  }


      /*FUNCTION TO DELETE RECORD OF THE PASSENGER */

void TRAVEL::DELETION(void)
  {
     clrscr();
     int bno=0,found=0,sno,d,m,y;
     char ch;
     cout<<"\n Flight 1:Delhi to Mumbai.       <Ticket Rs.3000>";
     cout<<"\n Flight 2:Delhi to Kolkata.         <Ticket Rs.3200>";
     cout<<"\n Flight 3:Delhi to Chennai.        <Ticket Rs.3400>";
     do
       {
     cout<<"\n\n enter the flightno.(1/2/3)";
     cin>>bno;
       }while(bno<1||bno>3);
     cout<<"\n\n enter the date of the reserved ticket:";
     cin>>d;
     cout<<"\n\n enter the month:";
     cin>>m;
     cout<<"\n\n enter the year:";
     cin>>y;
     cout<<"\nenter the seat no.:";
     cin>>sno;
     if(sno>60||sno<1||!RESERVED(bno,d,m,y,sno))
       {
     cout<<"\n\n\nsorry!\7seat not reserved";
     getch();
     return;
       }
     fstream file,temp;
     file.open("AIR.DAT",ios::in);
     temp.open("TEMP.DAT",ios::out);
     while(file.read((char*)this,sizeof(TRAVEL)))
       {
     if(dd==d&&mm==m&&yy==y&&bno==busno&&sno==seatno)
     {
       found=1;
       clrscr();
       gotoxy(5,5);
       cout<<"************************************************************************";
       gotoxy(28,7);
       cout<<"cpptute.air travel agency";
       gotoxy(10,9);
       cout<<"FLIGHT NO."<<bno<<"\t\t\tDATE:"<<d<<"/"<<m<<"/"<<y;
       gotoxy(10,10);
       cout<<"SEAT NO.:"<<sno;
       gotoxy(35,12);
       cout<<"FROM:DELHI"<<"\tTo:"<<place[bno-1];
       gotoxy(10,15);
       cout<<"Passenger Name:"<<name;
       gotoxy(10,16);
       cout<<"Passenger Age:  "<<age<<"\t\tsex:"<<sex;
       gotoxy(10,18);
       cout<<"Total PRICE :" <<price[bno-1];
       gotoxy(5,20);
       cout<<"*********************************************************************";
       do
	 {
	   gotoxy(1,25);
	   clreol();
	   cout<<"Do you want to delete(y/n)";
	   cin>>ch;
	 }while(toupper(ch)!='N'&& toupper(ch)!='Y');
       if(toupper(ch)=='N')
       temp.write((char *)this,sizeof(TRAVEL));
       }
     else
     temp.write((char *)this,sizeof(TRAVEL));
     }
     file.close();
     temp.close();
     if(!found)
       {
     cout<<"\n\n\7Passenger record not found";
     getch();
     return;
       }
     if(toupper(ch)=='N')
     return;
     file.open("AIR.DAT",ios::out);
     temp.open("TEMP.DAT",ios::in);
     while(temp.write((char*)this,sizeof(TRAVEL)));
     file.write((char*)this,sizeof(TRAVEL));
     file.close();
     temp.close();
  }


void TRAVEL::INFORMATION(void)
  {
     clrscr();
     gotoxy(20,8);
     cout<<"INTRODUCTION OF cpptute.Air travel agency";
     gotoxy(4,10);
     cout<<"In this agency there are three flights whose destinitions are:";
     gotoxy(15,12);
     cout<<"FLIGHT 1.DELHI TO MUMBAI.    <TICKET RS 3000>";
     gotoxy(15,13);
     cout<<"FLIGHT 2.DELHI TO KOLKATA.      <TICKET RS 3200>";
     gotoxy(15,14);
     cout<<"FLIGHT 3.DELHI TO CHENNAI.     <TICKET RS 3400>";
     gotoxy(4,16);
     cout<<"you can reserve ticket of any date and later on cancel the same also.";
     gotoxy(28,23);
     cout<<"press any key to continue.......";
     getch();
  }
/*   MAIN FUNCTION WHICH DISPLAY MAIN MENU & CALL ALL OTHER FUNCTIONS */

void MAINMENU(void)
  {
     TRAVEL travel;
     char ch;
     while(1)
       {
     for (int i=0; i<8;i++)
       {
	 for (int j=0; j<20; j++)
	 textcolor(i);
	 textbackground(i+9);
       }
     clrscr();
     cout<<"********************************************************************************\n";
     cout<<"                              c";
     cout<<"p";
     cout<<"p";
     cout<<"A";
     cout<<"I";
     cout<<"R";
     cout<<"T";
     cout<<"R";
     cout<<"A";
     cout<<"V";
     cout<<"E";
     cout<<"L";
     cout<<" A";
     cout<<"G";
     cout<<"E";
     cout<<"N";
     cout<<"C";
     cout<<"Y";
     cout<<"(";
     cout<<"P";
     cout<<"V";
     cout<<"T";
     cout<<".";
     cout<<"L";
     cout<<"T";
     cout<<"D";
     cout<<")"<<endl;
     cout<<"********************************************************************************";
     gotoxy(22,22);
     cout<<"*    By: Aditya Tiwari  Class:12th 'A'   *";
     gotoxy(30,10);
     cout<<"cpptute.Airindia.com";
     gotoxy(29,13);
     cout<<"1::INTRODUCTION";
     gotoxy(29,14);
     cout<<"2::BOOK TICKET";
     gotoxy(29,15);
     cout<<"3::DELETE RECORD";
     gotoxy(29,16);
     cout<<"4::PASSENGER LIST";
     gotoxy(29,17);
     cout<<"5::PASSENGER INFORMATION";
     gotoxy(29,18);
     cout<<"6::QUIT";
     gotoxy(29,20);
     cout<<"Enter your choice::";
     ch=getche();
     if(ch==27||ch=='6')
	 {
	   clrscr();
	   cout<<"	                 THANK YOU PLEASE VISIT US AGAIN";
	   break;
	 }
     else
     if(ch=='1')
     travel.INFORMATION();
     else
     if(ch=='2')
     travel.RESERVATION();
     else
     if(ch=='3')
     travel.DELETION();
     else
     if(ch=='4')
     travel.LIST_OF_PASS();
     else
     if(ch=='5')
     travel.PASS_INFO();
       }
  }

       //MAIN function to call all the functions
void main()
  {



     MAINMENU();
     getch();
  }

