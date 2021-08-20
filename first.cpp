#include<iostream>
#include<windows.h>
#include<cstring>
#include<conio.h>
#include"class.h"
#include<fstream>

using namespace std ;
class librarian
{
    public:
     void welcome();
     void view_booklist();
     void search_book();
     void modify_details();
     void issue_book();
     void change_password();
     void student();
     void admin();

};



void librarian::welcome()
{
    
    int choice;
    
    
        
        int i;
        system("COLOR 4F");
        for(i=0;i<5;i++)
        {

                printf("\n\n\n\n           ..............................welcome..............................................\n");
                Sleep(500);
                system("cls");
                Sleep(500);
        } 
            system("cls");
            system("COLOR 60");
            cout<<"\n\n\n *******************************************  MAIN MENU  ***************************************************\n";
            cout<<"\n\n ENTER  1  FOR STUDENT  LOGIN \n\n";
            cout<<" ENTER  2  FOR  ADMIN  STAFF  LOGIN  \n\n " ;
            cout<<"ENTER  3  TO Exit  \n " ;

             cin>>choice ;
             if(choice==1)
            {
              student();
            }  
             else if(choice==2)
             {
                  admin();
             }
             else if(choice==3)
             {
                 exit(0);
             }
    
};

void librarian::student()
{
    int choice ;
    system("cls");
    system("COLOR 70");

    cout<<"*******************************************    STUDENT SECTION   ***************************************************\n\n";
    cout<<" PRESS   1  TO  VIEW  THE  BOOKLIST \n\n ";
    cout<<" PRESS   2  TO  SEARCH  THE  BOOK \n\n ";
    cout<<" PRESS   3  TO   GO   TO THE   MAIN  MENU  \n\n ";
    cout<<" PRESS   4  TO  EXIT  FROM  THE  SOFTWARE   \n\n ";
     
     cin>>choice;

    /* if(choice==1)
     {
         view_booklist();
     }
     else if(choice==2)
     {
         search_book();
     }
     else if(choice==3)
     {
         welcome();
     }
     else 
     {
         exit(0);
     }*/
}

void librarian::admin()
{
    int choice,i,c=220;
    string origin,pass;
    char ch ;
    system("cls");
    system("COLOR 70");


    cout<<"\n\n\n******************************************************   ADMIN  SECTION   *******************************************\n\n" ;

    cout<<"ENTER  THE  PASSWORD  ::::\n\n";
    

   i=0;
   while(1)
   {
      
      ch=getch();
      if(ch=='\r')
      {
         pass[i]='\0';
          break ;
      }
      pass[i]= ch ;
      printf("*");
      i++;
   }  
   //cout<<pass<<endl ;
   i=0;
    ifstream inf ;
    inf.open("password.dat");
   if(!inf)
   {
       cout<<"password file not open\n";
   }
    else
    {   
            while(getline(inf,origin));

    }   
       

   inf.close();
   //cout<<origin ;
   if(origin==pass)
   {
       system("cls");

       system("COLOR 57");

     cout<<" \n\n\nPRESS  1  to   VIEW  THE  BOOKLIST  \n\n";
     cout<<" PRESS  2  TO   SEARCH   A   BOOK  \n\n";
     cout<<" PRESS  3  TO   MODIFY  THE   DETAILS   OF  A   BOOK  \n\n";
     cout<<" PRESS  4  TO  ISSUE  A  BOOK \n\n";
     cout<<" PRESS  5  TO  CHANGE  THE  PASSWORD  \n\n";
     cout<<" PRESS  6  TO  GO  TO  THE  MAIN  MENU \n\n ";
     cout<<"PRESS  7  TO  EXIT  FROM  THE  SOFTWARE  \n\n";

     cin>>choice ;
     if(choice==1)
     {
        view_booklist();
     }
     /*else if(choice==2)
     {
        search_book();
     }*/
     else if(choice==3)
     {
        modify_details();
     }
     /*else if(choice==4)
     {
        issue_book();
     }
     else if(choice==5)
     {
        change_password();
     }
     else if(choice==6)
     {
        welcome();
     }
     else{
        exit(0);
     }*/

   }
   else 
   {
       cout<<"password  "<<pass ;
       cout<<"my password "<<origin;
       getch();
       system("cls");
       system("COLOR 17");
       i=0;
       for(i=0;i<5;i++)
       {

         cout<<"  ENTERED   PASSWORD  IS  INCOREECT  ";
         Sleep(500);
         system("cls");
         Sleep(500);
       } 
   }
}

void librarian :: view_booklist()
{
    system("cls");
    system("COLOR 70");
    cout<<"\n  S.NO.                      BOOK-NAME                            AUTHOR-NAME                          SUBJECT    \n";
    for(int i=0;i<120;i++)
    {
        cout<<"-";
    }
    fstream inf ;
    inf.open("booklist.dat" ,ios::in);
    if(!inf)
    {
        cout<<endl<<" error  occured  in opening the booklist file  ";
        exit(0);
    }
    while(!inf.eof())
    {
        inf.read((char*)&book,sizeof(book));
        
        //cout<<"loop";
        cout<< book.serial_num<<"                             "<<book.bookname<<"                                "<<book.author<<"                               "<<book.subject<<endl;   
    }

    inf.close();
    
}
void librarian::modify_details()
{
    int i ;

    system("cls");
    system("COLOR 30");

    fstream file ;

    

    cout<<"  \n\n press 1 to modify and 0 to exit from modification mode "<<endl;
    cin>>i;

    cout<<"\n\n enter  the  serial  number :"<<endl ;
    cin>>book.serial_num;


    cout<<"\n\n  enter the book name  : "<<endl ;
    cin>>book.bookname ;


    cout<<"\n\n  enter the  author name :"<<endl ;
    cin>>book.author ;


    cout<<"\n\n enter the  subject of the book :"<<endl ;
    cin>>book.subject;


    file.open("booklist.dat",ios::app);


    file.write((char*)&book,sizeof(book));
   

}



int main()
{
    librarian lib;
    lib.welcome();
    return 0;
}
