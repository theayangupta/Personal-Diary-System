#include <graphics.h>
#include <iomanip>          //for setw(); 
#include <stdio.h>
#include <stdlib.h>
#include <iostream>         //basic c++ header file
#include <conio.h>          //for using _getch()
#include <string.h>         //for using string functions
#include <fstream>          //for file handling operations

using namespace std;

gotoxy(int x, int y)
{
  cout<<setw(x);  //horizontal

  for(;y>0;y--)   //vertical
    cout<<endl;
 }

class records
{
private:

char rec_no[25];           //record number of a record
char name[25];         //name of person/event to meet
char date[25];          //date of meeting
char time[25];          //time of meeting
char place[25];       //place of meeting
char priority[25];      //priority of meeting

public:

void input()
{
	system("color B3");
    char filename[20];             //name of file used for storing records
    ofstream fio1,fio2;           //for writing to file

    fio1.open("records.txt",ios::app);           //ios:app means appending at the end of a file if it exits,otherwise a new file is created

    //in records.txt, records of all the dates will be stored

    cout<<"Enter the date of entry"<<endl;
    cin>>filename;
    cout<<endl;

    fio2.open(filename,ios::app);                //ios:app means appending at the end of a file if it exits,otherwise a new file is created
    cin.ignore();

    cout<<"Enter the record number"<<endl;
    cin.getline(rec_no,25);
    //for solving input problem due to getline() function

    cout<<"\nWhom do you have to meet?"<<endl;
    cin.getline(name,25);            //for reading the spaces in the name

    cout<<"\nWhen you have to meet?"<<endl;
    cin.getline(date,25);


    cout<<"\nAt what time you have to meet?"<<endl;
    cin.getline(time,25);


    cout<<"\nEnter the place to visit"<<endl;
    cin.getline(place,25);


    cout<<"\nSpecify the priority"<<endl;
    cin.getline(priority,25);

    fio1<<rec_no<<'|'<<name<<'|'<<date<<'|'<<time<<'|'<<place<<'|'<<priority<<'\n';

    fio2<<rec_no<<'|'<<name<<'|'<<date<<'|'<<time<<'|'<<place<<'|'<<priority<<'\n';
   
    fio1.close();               //closing the file
    fio2.close();            //closing the file
    
    cout<<endl;
    cout<<"Record added successfully"<<endl;
    char p;
    cout<<endl;
    
    cout<<"Do you want to add another record:[Y/N]"<<endl<<endl;
    cin>>p;

    if(p=='Y')
    {
    system("CLS");                //clearing the screen
    input();
    }
}

void view_all()              //for viewing all records
{
	system("color E8");
    ifstream fin;
    fin.open("records.txt",ios::in);               //for reading the file
    char ch;
    if(!fin)                     //if file doesn't open
    cout<<"No Records Exist"<<endl;

    else                  //read the whole content of file
    {
    while(!fin.eof())                       //till the end of file is reached
    {
    fin.getline(rec_no,25,'|');
    fin.getline(name,25,'|');
    fin.getline(date,25,'|');
    fin.getline(time,25,'|');
    fin.getline(place,25,'|');
    fin.getline(priority,25);

    cout<<rec_no<<endl;
    cout<<name<<endl;
    cout<<date<<endl;
    cout<<time<<endl;
    cout<<place<<endl;
    cout<<priority<<endl<<endl;
    }
    fin.close();
    }
}

void view_specific()                    //for viewing records of a specific date
{
	system("CLS");
	system("color 6E");
    char filename[20];
    ifstream fin;
    cout<<"Enter the date of entry"<<endl;
    cin>>filename;
    cout<<endl;

    fin.open(filename,ios::in);

    if(!fin)                    //if the file doesn't open
    cout<<"No Records!!"<<endl;

    else                     //read the whole content of file
    {
    while(!fin.eof())                  //till the end of file is reached
    {
    fin.getline(rec_no,25,'|');
    fin.getline(name,25,'|');
    fin.getline(date,25,'|');
    fin.getline(time,25,'|');
    fin.getline(place,25,'|');
    fin.getline(priority,25);

    cout<<rec_no<<endl;
    cout<<name<<endl;
    cout<<date<<endl;
    cout<<time<<endl;
    cout<<place<<endl;
    cout<<priority<<endl<<endl;
    }
    
    fin.close();
    }
}

void delete_record()       //for deleting a record
{
	system("color F9");
	char filename[20];              //for taking input the name of file
  
    char a[25];           //record to be deleted

    fstream f1;
    fstream temp;

    system("CLS");            //clearing the screen

        cout<<"Enter the date of entry whose records are to be deleted"<<endl;
        cin>>filename;

        f1.open(filename,ios::in);
        temp.open("temp.txt",ios::out);
        cin.ignore();

        cout<<"\nEnter the record number to be deleted: ";

        cin.getline(a,25);

        while(!f1.eof())               //till the end of file is reached
        {
            f1.getline(rec_no,25,'|');
            f1.getline(name,25,'|');
            f1.getline(date,25,'|');
            f1.getline(time,25,'|');
            f1.getline(place,25,'|');
            f1.getline(priority,25);

            if(strcmp(rec_no,a)==0)
            {
                continue;
            }

            else
            {
               temp<<rec_no<<'|'<<name<<'|'<<date<<'|'<<time<<'|'<<place<<'|'<<priority<<'\n';
            }
        }

        temp.close();
        f1.close();

        f1.open(filename,ios::out);
        temp.open("temp.txt",ios::in);

        while(!temp.eof())            //till the end of file is reached
        {
            temp.getline(rec_no,25,'|');
            temp.getline(name,25,'|');
            temp.getline(date,25,'|');
            temp.getline(time,25,'|');
            temp.getline(place,25,'|');
            temp.getline(priority,25);
            f1<<rec_no<<'|'<<name<<'|'<<date<<'|'<<time<<'|'<<place<<'|'<<priority<<'\n'<<endl;
        }

        temp.close();
        f1.close();
        remove("temp.txt");

        f1.open("records.txt",ios::in);
        temp.open("temp.txt",ios::out);
        cin.ignore();

        while(!f1.eof())
        {
            f1.getline(rec_no,25,'|');
            f1.getline(name,25,'|');
            f1.getline(date,25,'|');
            f1.getline(time,25,'|');
            f1.getline(place,25,'|');
            f1.getline(priority,25);

        if(strcmp(rec_no,a)==0)
        {
            continue;
        }

        else
        {
           temp<<rec_no<<'|'<<name<<'|'<<date<<'|'<<time<<'|'<<place<<'|'<<priority<<'\n';
        }

        }
        temp.close();
        f1.close();

        f1.open("records.txt",ios::out);
        temp.open("temp.txt",ios::in);

        while(!temp.eof())
        {
            temp.getline(rec_no,25,'|');
            temp.getline(name,25,'|');
            temp.getline(date,25,'|');
            temp.getline(time,25,'|');
            temp.getline(place,25,'|');
            temp.getline(priority,25);
            f1<<rec_no<<'|'<<name<<'|'<<date<<'|'<<time<<'|'<<place<<'|'<<priority<<'\n'<<endl;
        }

        temp.close();
        f1.close();

        remove("temp.txt");

        cout<<"\nRecord deleted successfully!!!"<<endl<<endl;

        system("PAUSE");                 //pausing the program until user presses a key
        system("CLS");             //clearing the screen

}
};

int start()
{
    int n=0;
    records r;

while(n!=5)        //choice menu
    {
    	system("color 2A");
    cout <<"\t\t\t\t\t\t    WELCOME TO YOUR DIARY"<<endl<<endl;
    cout <<"1. View all the records" << endl;
    cout <<"2. Add a record" << endl;
    cout <<"3. Delete an Existing Record" << endl;
    cout <<"4. View records for a specific day"<<endl;
    cout <<"5. Exit" <<endl;

    cout<<endl;
    cout<<"Enter your choice:";
    cin>>n;
    cout<<endl;

    switch(n)
    {
    case 1:

        system("CLS");          //for clearing the screen
        r.view_all();

        cout<<endl<<endl;
        system("PAUSE");         //pausing the program until user presses a key
        break;

    case 2:

        system("CLS");          //for clearing the screen
        r.input();
        system("PAUSE");          //pausing the program until user presses a key
        break;

    case 3:

        r.delete_record();
        break;

    case 4:

        r.view_specific();
        system("PAUSE");      //pausing the program until user presses a key
        break;

    case 5:

        cout<<"Logged out successfully"<<endl;
        system("PAUSE");      //pausing the program until user presses a key
        break; 

    default:

        cout<<"Enter valid input"<<endl;
        system("PAUSE");        //pausing the program until user presses a key

    }
    system("CLS");        //for clearing the screen
    }

return 0;
}

	char name[20];         /* username */
	string password="";       /* password */
	
int main(){
	
	int gd=DETECT , gm;
    initgraph(&gd,&gm,"C:\\TC\\BGI"); 
    setbkcolor(10);                /* function to define the color */
	setfillstyle(SOLID_FILL,10);    /* function to fill color inside a shape*/
	setlinestyle(0,0,3);
	     line(80,30,580,30);         /* function to draw a line */
	     line(80,430,580,430);
	     line(80,30,80,430);
	     line(580,30,580,430);
    floodfill(251,53,WHITE);
  
    settextstyle(1,0,4);
	outtextxy(190,70,"MY DIARY");          /* function to print the text */
	settextstyle(1,0,1); 
	outtextxy(160,110,"Give Name and Password");
	
	setbkcolor(3);
	setfillstyle(SOLID_FILL,3);
		line(150, 150 , 510 , 150); 
		line(150, 210 , 510 , 210);
		line(150, 150 , 150 , 210);
		line(510, 150 , 510 , 210);
    floodfill(160,159,WHITE);
    
   	setfillstyle(SOLID_FILL,3);
		line(150, 250 , 510 , 250);
		line(150, 310 , 510 , 310);
		line(150, 250 , 150 , 310); 
		line(510, 250 , 510 , 310);
	floodfill(160,259,WHITE);
	
	setlinestyle(0,0,1);
	settextstyle(7,0,2);     /* function to specify the styling of text */
	setbkcolor(10);
	setlinestyle(0,0,3);        /* function to specify the styles of line */
	line(385,350,570,350);
		outtextxy(390,325,"PROJECT BY:");
		outtextxy(405,355,"Ayan Gupta");
		outtextxy(405,380,"Ayush Gupta");
		outtextxy(405,405,"Jagriti");
		 
	setbkcolor(3);	
    settextstyle(1,0,2);
	outtextxy(170,170,"Name : ");
	cin >> name;
	outtextxy(300,170,name);
	outtextxy(170,270,"Password : ");
	
        int i=0;
        char ch;
        ch=_getch();
    while(ch != 13){        /* input password */
        password.push_back(ch);
        outtextxy((350+i),270,"*"); 
        ch = _getch();
        i=i+15;
    }
		setbkcolor(BLACK);
		settextstyle(1,0,2);
		
    if(strcmp(name,"abc")==0 && password.compare("321")==0){
  	    outtext("Access Granted");
		system("CLS");
    	start();
    }
    else{
   	    outtext("Incorrect credentials");
    }
    getch();
    return 0;
}
