#include<iostream.h>
#include<fstream.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<process.h>
#include<dos.h>
#include<stdlib.h>
char uname[5],Pass[6],ch,lo,df[4];
void MAIN();

int i,odd,cnum,pin[3],tid,present=0;
fstream fu;
fstream fin;
char f_destination[4][15]={"CHENNAI","BANGLORE","KOLKATA",};
char t_destination[4][15]={"GOA","HYDERABAD","MUMBAI",};
int TIME[5]={13,8,3,5,9};
int chk=0,q,t;
int check_date(int d,int m,int y)
{
int s=5;
if((y%4==0)||(y%400==0))
{
if(m==2)
if(d>0&&d<30)
s=1;
if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
if (d>0&&d<32)
s=1;
if(m==4||m==6||m==9||m==11)
if (d>0&&d<31)
s=1;
}
else
{
if(m==2)
if(d>0&&d<29)
s=1;
if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
if(d>0&&d<32)
s= 1;
if(m==4||m==6||m==9||m==11)
if(d>0&&d<31)
s= 1;
}
return s;
}
class booking
{
char from[15],to[15],uid[5];
int seat,yr,date,month,time,cost,id;
public:int func;
booking()
{
seat=100;
yr=2016;
month=5;
}
void create();
int cos();
int retid();
void disp();
char *retus()
{
return uid;
}
};
booking temp;
void booking::disp()
{
cout<<endl;
cout<<"    FROM:";puts(from); cout<<"       TO:";puts(to);cout<<endl;
cout<<"Booking id:"<<id;
cout<<"Number of seats:"<<seat<<endl;
cout<<"Date :"<<date<<"  Month:"<<month<<"  Year:"<<yr<<endl;
cout<<"Time Of Journey :"<<time<<endl;
cout<<"Cost :"<<cost<<endl;
cout<<"------------------------------------------------------------------------------"<<endl;
}
int booking::cos()
{
return cost;
}
int booking::retid()
{
return id;
}

void booking::create()
{
e:cout<<"     FROM: ";
gets(from);
for(q=2;q>=0;q--)
{
if (strcmpi(from,f_destination[q])==0)
{
chk++;break;
}
}
if(chk==0)
{
cout<<"    NOT VALID...ENTER AGAIN";goto e;
}
t:ch=0;
cout<<"     TO ";gets(to);
for(q=2;q>=0;q--)
{
if(strcmpi(to,t_destination[q])==0)
{
chk++;break;
}
}
if(chk==0)
{
cout<<"                              NOT VALID...ENTER AGAIN";
goto t;
}

xc:cout<<"     NUMBER OF SEATS(not more than 20): ";
cin>>seat;
if (!((seat>1)&&(seat<=20)))
goto xc;
cost=(seat*150);
randomize();
id=random(100)+8; cout<<"your booking id is:"<<id<<"\n";
strcpy(uid,uname);
ag:cout<<"     DATE: ";
cin>>date;
cout<<"     MONTH(enter only number): ";
cin>>month;
ji:cout<<"     YEAR: ";
cin>>yr;
if(!(yr>2015))
goto ji;
func=check_date(date,month,yr);
if(func!=1)
{
cout<<"               NOT VALID DATE...TYPE AGAIN..";
goto ag;
}
tim:chk=0;
cout<<"     ENTER TIME  :";cin>>time;
for(t=0;t<6;t++)
{
if (time==TIME[t])
{
chk++; break;
}
}
if(chk==0)
{
cout<<"           NOT VALID ENTER AGAIN...";
delay(300);
goto tim;
}
}

class regs
{
char p[6],n[15],a[5],ad[50],d;int j;long h;
public:void getdat();
char  *us()
{
return a;
}
char  *pass()
{
return p;
}
};
void regs:: getdat()
{
bu: char ch;
delay(50);
cout<<"     Name :";
gets(n);
s:cout<<"     Age(Abv 18 below 60) : ";
cin>>j;
if (!(j>18&&j<60))
goto s;
cout<<"     User name (5 characters max) : ";
gets(a);
cout<<"     Password (6 letters only) : ";
gets(p);
cout<<"     Phone num : ";
cin>>h;
cout<<"     Gender(m/f) : ";
cin>>d;
cout<<"     Address : ";
gets(ad);
cout<<"            Type YES to confirm you are human ";
gets(df);
if (strcmp(df,"YES")!=0)
{
cout<<"Error..not human..try again"<<endl;
goto bu;
}
}
regs ti;

void checking_user()
{
i=0;
fu.open("use.dat",ios::in|ios::binary);
while(!fu.eof())
{
fu.read((char*)&ti,sizeof(regs));
if((strcmp(ti.us(),uname)==0)&&(strcmp(ti.pass(),Pass)==0))
{
present=1;
break;
}
else
i++;
}
}

void reg()
{
clrscr();
d:
regs w;
int g;
cout<<endl<<endl<<endl<<endl<<endl<<endl;
cout<<"             REGISTRATION FOR SBY TRAVELS"<<endl;
w.getdat();
fu.open("use.dat",ios::binary|ios::app);
fu.write((char*)&w,sizeof(w));
fu.close();
cout<<"        SUCCESSFULLY REGISTERED......";
delay(350);
MAIN();
}

void next_page();
void login()
{
try: clrscr();
cout<<endl<<endl<<endl<<endl<<endl<<endl;
cout<<"             LOGIN TO SBY TRAVELS     "<<endl;
cout<<"     ENTER USER NAME :";gets(uname);
cout<<"     ENTER PASSWORD :";gets(Pass);
checking_user();
if(present!=1)
{
cout<<"    ERROR...TRY AGAIN"; delay(450);goto try;
}
else
{
cout<<"                 LOGIN SUCCESS...";next_page();
}
}

void next_page()
{
clrscr();
cout<<endl<<endl<<endl<<endl<<endl<<endl;
cout<<"     1.BOOK NEW TICKET"<<endl;
cout<<"     2.CANCEL TICKET"<<endl;
cout<<"     3.BOOKED TICKETS"<<endl;
cout<<"     4.MAIN MENU"<<endl;
cout<<"        WHAT YOU WANT TO DO..? ";
cin>>ch;
switch(ch)
{
case '1':
int w;
booking test;
clrscr();
cout<<endl;
cout<<endl;
cout<<"FROM.."<<endl;
for(w=2;w>=0;w--)
puts(f_destination[w]);
cout<<"TO.."<<endl;
for(w=2;w>=0;w--)
puts(t_destination[w]);
cout<<"TIME.."<<endl;
for(w=4;w>=0;w--)
cout<<TIME[w]<<endl;
test.create();
cout<<"     COST:"<<test.cos();
cout<<endl;
cout<<"   CONFIRM YOU WANT BOOK(Y/N) : ";
cin>>lo;
switch(lo)
{
case 'Y':
case 'y':
clrscr();
cout<<endl<<endl<<endl<<endl<<endl<<endl;
cout<<"             PAYMENT"<<endl;
cout<<"     CARD NUMBER: ";
cin>>cnum;
cout<<"     PIN:";
for(i=3;i>=0;++i)
{
ch=getch();
if(ch==13)
break;
cout<<'*';
pin[i]=ch;
}
clrscr();
cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
cout<<"            YOUR BOOKING ID .."<<test.retid();
fin.open("rese.dat",ios::binary|ios::app);
fin.write((char*)&test,sizeof(test));
fin.close();
next_page();
break;
default:cout<<"<<<<<<<<<<<<<<SEE YOU AGAIN>>>>>>>>>>";
next_page();
}
break;

case '2':
clrscr();
cout<<endl;
cout<<endl;
cout<<endl;
cout<<endl;
cout<<endl;
cout<<endl;
cout<<"             CANCEL TICKET";
cout<<"     ENTER YOUR TICKET ID :";
cin>>tid;
fin.open("rese.dat",ios::binary|ios::beg|ios::in);
fstream Temp;
Temp.open("temps.dat",ios::binary|ios::beg|ios::out);
while(!fin.eof())
{
fin.read((char*)&temp,sizeof(temp));
if(fin.eof())break;
if(temp.retid()!=tid)
Temp.write((char*)&temp,sizeof(temp));
}
fin.close();
Temp.close();
remove("rese.dat");
rename("temps.dat","rese.dat");
cout<<endl;
cout<<"             SUCCESSFULLY CANCELLED";
delay(450);
next_page();
break;
case '3':
clrscr();
cout<<endl;
cout<<endl;
cout<<endl;
cout<<endl;
cout<<endl;
cout<<endl;
fin.open("rese.dat",ios::binary|ios::in);
cout<<"             BOOKED TICKETS";
fin.seekg(0,ios::beg);
while(!fin.eof())
{
fin.read((char*)&temp,sizeof(temp));
if(fin.eof())
break;
if(strcmp(temp.retus(),uname)==0)
temp.disp();
getch() ;
}
fin.close() ;
next_page();
break;
case '4':MAIN();
break;
default:cout<<endl;
cout<<endl;
cout<<"      WRONG CHOICE ENTER AGAIN";
next_page();
}
}

void MAIN()
{
int ip;
clrscr();
cout<<endl<<endl<<endl<<endl<<endl<<endl;
cout<<"             1.REGISTER"<<endl;
cout<<"             2.LOGIN"<<endl;
cout<<"             3.EXIT"<<endl;
cout<<"     YOUR CHOICE :";
cin>>ip;
switch(ip)
{
case 1:reg();break;
case 2:login();break;
default:exit(0);
}
}

void main()
{
MAIN();
getchar();}

