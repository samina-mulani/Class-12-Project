#include<graphics.h>
#include<time.h>
#include<conio.h>
#include<iostream>
#include <process.h>
#include <fstream>
#include <ctype.h>
#include <string.h>

using namespace std; 

class Heart;
class Eye;
class det;
void home();
void display_help();
void click_home(int a=0);
void click_report() ;
void bar(float a,int b);
void exit();
void add_records(int n);
void disp(int a);
void modify();
void del();
int chck(int);
void bar2(float,int);

struct details 
{ 
	char name[20]; 
	int age; 
	char gen[20]; 
	float height; 	
	float weight; 
	float bmi;
};

struct heart
{
	int test;
	int pulse;
	int chol;
	int sug;
};

class det
{
      details d;
      int pid;
      public:
             det()
             {
                  pid=0;
                  }
             int retp()
             {
                 return pid;
             }
             char* retn()
             {
                     return d.name;
             }
             int reta()
             {
                 return d.age;
             }
             char* retg()
             {
                   return d.gen;
             }
            float reth()
            {
                  return d.height;
            }
            float retw()
            {
                  return d.weight;
            }
            float retb()
            {
                  return d.bmi;
            }
            friend void add_records();
                 

             void phy_exam(int d=0);
             void report(Heart a, Eye b,int n=0);
             void report1(det a,Heart q, Eye b);
             void mod(det);
}obj;

class Heart
{
      heart h;      
      public:
             int flag1;
             void clearh()
             {
                  h.pulse=h.sug=h.chol=0;
             }
             Heart()
             {
                    flag1=0;h.pulse=h.sug=h.chol=0;
             }
             int retp()
             {
                 return h.pulse;
             }
             int rets()
             {
                 return h.sug;
             }
             int retch()
             {
                 return h.chol;
             }
             void heart_det(int i=0);
             friend void click_heart_eye(int i=0);
}obj_h;

class Eye
{
      int count;
      char ch1;
      public:
             int flag;
             void cleare()
             {
                  count=0;
             }
                  
             Eye()
             {
                  flag=-1;
                  ch1='A';
                  count=0;
             }
             int retc()
             {
                 return count;
             }
             void eye_test(int i=0);
             friend void click_heart_eye(int i);
}obj_e;

void choice();

     int main()
     {         
	      int gdriver=DETECT,gmode; 
	     int midx,midy; 
	     initgraph(&gdriver,&gmode,""); 
	     midx=getmaxx()/2; 
	     midy=getmaxy()/2;
	     
	     
       	 settextstyle(8,HORIZ_DIR,5);
	     outtextxy(10,10,"MEDICAL REPORT GENERATOR");
	     settextstyle(10,HORIZ_DIR,1);
	     outtextxy(20,400,"-Arpitha, Manasa, Samina");
	     circle(255,160,10);
	     circle(340,160,10);
	     circle(300,200,100);
	     arc(300,200,180+45,360-45,50);	
	     settextstyle(11,HORIZ_DIR,1);
	     fflush(stdin);
	     choice();
	     

	     return 0; 
      }        
             

//FUNCTION DEFINITIONS

int chck(int q)
{
     fstream file("ABC.dat");
      det a; Eye b; Heart c;
      int flag=0;
      while(!file.eof())
      {
                        file.read((char*)&a,sizeof(a));
                        file.read((char*)&b,sizeof(b));
                        file.read((char*)&c,sizeof(c));   
                        if(!file)
                        break;
                        if(q==a.retp())
                            {
                                                cout<<"Patient with ID "<<a.retp()<<" already exists\n";
                                                cout<<"Please re-enter patient ID : ";
                                                flag=1;
                                                break;
                            }
                    
                    if(flag!=0)
                    break;
      }
      file.close();
       return flag;
}



void del()
{ifstream fio("ABC.dat",ios::in);
 ofstream file("temp.dat",ios::out);
 int id;
 char found='f',confirm='n';
 cout<<"Enter Patient ID whose record has to be deleted : ";
 cin>>id;
 det a; Eye b; Heart c;
 while(!fio.eof())
 {fio.read((char*)&a,sizeof(a));
 fio.read((char*)&b,sizeof(b));
 fio.read((char*)&c,sizeof(c));
 if(!fio) break;
  if(a.retp()==id)
   {
    found='t';
    a.report(c,b,1);
    cout<<"Are you sure you want to delete this record?";
    cin>>confirm;
    if(confirm=='n')
    {
    file.write((char*)&a,sizeof(a));
    file.write((char*)&b,sizeof(b));
    file.write((char*)&c,sizeof(c));
    }
}
else
{
    file.write((char*)&a,sizeof(a));
    file.write((char*)&b,sizeof(b));
    file.write((char*)&c,sizeof(c));
}
}//end of while
if(found=='f')
cout<<"Record not found\n";
fio.close();
file.close();
remove("ABC.dat");
rename("temp.dat","ABC.dat");
if(found!='f')
cout<<"RECORD HAS BEEN DELETED\n";

}

void det::mod(det o)
{
     pid=o.pid;
     strcpy(d.gen,o.d.gen);
     strcpy(d.name,o.d.name); 
}

void add_records(det a,Eye b,Heart c)
{
     fstream file;
 
     file.open("ABC.dat", ios::binary|ios::out|ios::app);
     file.write((char*)&a,sizeof(a));
     file.write((char*)&b,sizeof(b));
     file.write((char*)&c,sizeof(c));
      file.close();
    
}

void modify() 
{       int id,flag=0,f=0;
        char ch;
        cout<<"Enter ID of patient whose data is to be modified\n";
          cin>>id;
        
        det a; Eye b; Heart c;
         ifstream file("ABC.dat",ios::in|ios::binary);
         ofstream newf("temp.dat",ios::binary);
         while(!file.eof())
  {   
         flag=0;
        
         file.read((char*)&a,sizeof(a));
         file.read((char*)&b,sizeof(b));
         file.read((char*)&c,sizeof(c));   
         if(!file)
         break;
         if(a.retp()==id)
         {                       
                         a.report(c,b,1);
                         cout<<"Is this the record to be modified?\n";
                         cin>>ch; 
                         
                         if(ch=='y'||ch=='Y')
                         {
                                             system("cls");
                                             obj.mod(a);
                                             obj_e.cleare();
            	                             obj_h.clearh();
                                             flag=1;
                                             f=1;
                                             obj.phy_exam(1); 
	                                         home();                
            	                             click_home(1);
            	                              a.report1(obj,c,b);
           	                               newf.write((char*)&obj,sizeof(det));
                                           newf.write((char*)&obj_e,sizeof(Eye));
                                           newf.write((char*)&obj_h,sizeof(Heart));
                                             	
                                             cout<<"RECORD HAS SUCCESSFULLY BEEN MODIFIED\n\n";   
                                             system("pause");                                                                                     
                                             
                         }                                       
                                
         }
         if(flag==0)
         {
         newf.write((char*)&a,sizeof(a));
         newf.write((char*)&b,sizeof(b));
         newf.write((char*)&c,sizeof(c));
         }
         
   
    }     //end of while
    if(f==0)
    cout<<"NO RECORD FOUND\n";
     file.close();
        newf.close();
    remove("ABC.dat");
    rename("temp.dat","ABC.dat");     
}
     
void disp(int id) 
{
     int flag=0;
     ifstream file("ABC.dat",ios::in|ios::binary);
  det a;Eye b; Heart c;
  while(!file.eof())
  {file.read((char*)&a,sizeof(a));
  file.read((char*)&b,sizeof(b));
    file.read((char*)&c,sizeof(c));
    if(!file)break;
   if(a.retp()==id)
   {
          a.report(c,b); 
          flag=1;        
   }
   
    }     
    if(flag==0)
    cout<<"NO RECORD FOUND\n"; 
 file.close(); 
}

     
void choice()
{
     int ch,id;
     char c,t;
     
     do{
     here:
          system("cls");
          fflush(stdin);  
        //  system("COLOR 0B");
          cout<<"          -----------------------------------------------       \n";        
          cout<<"          |                    MENU                      |\n";            
          cout<<"          |                   ------                     |\n";
          cout<<"          |     1. Display database                      |\n";              
          cout<<"          |     2. Enter new record                      |\n";               
          cout<<"          |     3. Delete record                         |\n";         
          cout<<"          |     4. Modification                          |\n";
          cout<<"          |     5. Exit                                  |\n";
          cout<<"          |                                              |\n";
          cout<<"          ------------------------------------------------       \n";  
           cout<<endl<<endl;
          cout<<"ENTER CHOICE : ";             cin>>ch; 
          cout<<"Press 0 to return to Menu now. Press any other key to continue.\n"; 
          cin>>t;
          if(t=='0')
          goto here;
          system("cls");
          switch(ch)
          {
                case 1: cout<<"Enter patient ID : ";
                cin>>id;
                disp(id);
                break;
                case 2:  obj_e.cleare();
                obj_h.clearh();             
                obj.phy_exam(); 
	            home();                
	            click_home(); 
                add_records(obj,obj_e,obj_h);	
                cout<<"RECORD HAS SUCCESSFULLY BEEN ENTERED\n\n";            
                break;
                case 3: del();
                break;
                case 4:modify();
                break;
                case 5: exit();
                break;
                default: cout<<"INVALID CHOICE\n";
         }
         cout<<"CONTINUE? ";
         cin>>c;
         }while(c=='y'||c=='Y');
}   
     
  void click_heart_eye(int i) 
{ 
	int x1,y1;
	outtextxy(600,0,"EXIT"); 
	outtextxy(550,0,"HOME"); 
	outtextxy(270,420,"REPORT"); 
	outtextxy(500,0,"HELP"); 
	while(1) 
	{ 
			delay(1000);			
			x1=mousex();						
			y1=mousey();		
			if(x1>=600&&x1<=1630) 
			{ 
				if(y1>=0&&y1<=10) 
				{ 
					exit(); 
					break; 
				} 
			} 
				else if(x1>=550&&x1<=590) 
				{ 
					if(y1>=0&&y1<=10) 
					{ 
						home();
						click_home(); 
						break; 
					} 
				} 
				else if(x1>=500&&x1<=535) 
				{ 
					if(y1>=0&&y1<=10) 
					{ 
						display_help();
						break; 
					} 
				} 
				else if(x1>=270&&x1<=320) 
				{ 
					if(y1>=420&&y1<=430) 
					{ if(i==0)
					{
						obj.report(obj_h,obj_e);      
						break; }
						else 
						break;
					} 
				} 
			clearmouseclick(WM_LBUTTONDOWN); 		
	} 
}    
void det::phy_exam(int f) 
{ 
 
     int count=0,r;
	cout<<"Enter Details \n\n";
	if(f==0)
	{
  	cout<<"Patient ID : ";
	do
	{
	cin>>pid;
	r=chck(pid);
    }while(r!=0);
	
	cout<<endl;
	cout<<"Name: "; 
	cin>>d.name; 
	cout<<endl; 
   }
	do{
    if(count!=0)
    cout<<"Sorry, INVALID VALUE, renter the age(yrs):";
    else            
	cout<<"Age(in yrs) :"; 
	cin>>d.age; 
	count++;
    }while(d.age<=0);
	cout<<endl; 
    if(f==0)
    {
	cout<<"Gender :"; 
	cin>>d.gen; 
	cout<<endl; 
	count=0;
   }
   count=0;
    do{
    if(count!=0)
    cout<<"Sorry, INVALID VALUE, renter the height(m):";
    else            
	cout<<"Height (in m) :"; 
	cin>>d.height; 
	count++;
}while(d.height<=0||d.height>3);
	cout<<endl; 
	count=0;
	do{
    if(count!=0)
    cout<<"Sorry, INVALID VALUE, renter the weight(kg):";
    else            
	cout<<"Weight (in kg) :"; 
	cin>>d.weight; 
	count++;
}while(d.weight<=0);
	cout<<endl;
	d.bmi=d.weight/(d.height*d.height);

} 
             
void Heart::heart_det(int i) 
{ 
	system("cls"); 
	cleardevice();
	flag1=1;
	h.pulse=h.sug=h.chol=0;
	cout<<"Enter Details \n"; 
	cout<<"Pulse (bpm) (Normal Range:60-100) : "; 
	cin>>h.pulse; 
	cout<<endl; 
	cout<<"Cholestrol (in mg/dL) (Normal Range: < 200) : "; 
	cin>>h.chol; 
	cout<<endl; 
	cout<<"Normal Fasting Blood Sugar (in mg/dL)(Normal Range: < 100):"; 
	cin>>h.sug; 
	cout<<endl; 
	click_heart_eye(i);
}        


void Eye::eye_test(int j) 
{ 
	system("cls");
	cleardevice();
	srand(time(0)); 
	int r,add,s; 
	flag=0;
    count=0;
	int x=200,y=200; 
	char a[2],ch; 
	for(int i=0;i<10;i++) 
	{ 
           char ch1='A';
		add=(rand()%25)+0; 
	    ch1+=add; 
		a[0]=(char)ch1; 
		a[1]='\0'; 
		r=(rand()%15)+1; 
		setcolor(r); 
		s=(rand()%10)+1;
		settextstyle(BOLD_FONT,HORIZ_DIR,s); 
		outtextxy(x,y,a); 
		delay(500); 
		cout<<"ENTER THE LETTER YOU SEE :"; 
		cin>>ch; 
		if(ch==a[0]||(ch-32)==a[0]) 
		count++; 
		cleardevice(); 
	} 
	cout<<"\n Your score is:"<<count; 
	settextstyle(11,HORIZ_DIR,1);
	setcolor(15);
	click_heart_eye(j);
} 


void display_help() 
{ 
	cleardevice(); 
	setcolor(15); 
	settextstyle(BOLD_FONT,HORIZ_DIR,1); 
	outtextxy(0,0,"NAVIGATION:"); 
	outtextxy(0,60,"1.In the home page click the \"EYE\" or \"HEART\" button "); 
	outtextxy(0,90,"  to go to the respective screens");
	
	outtextxy(0,120,"2.Click on the \"CREATE REPORT \" option to generate report"); 
	outtextxy(0,150,"3.Click on the \"EXIT\" button to exit at anytime"); 
	delay(7000);
	settextstyle(11,HORIZ_DIR,1);
	home();
	click_home();
} 

void exit()
{
	cleardevice();
	system("cls");
	settextstyle(1,HORIZ_DIR,4);
	outtextxy(100,100,"THANK YOU");
	delay(5000);
	exit(0);
}




void det::report(Heart q,Eye m,int n)
{
	system("cls"); 
	cleardevice();
	cout<<"REPORT\n\n";
    cout<<"Patient ID : "<<pid<<endl;
	cout<<endl;
	cout<<"Name: "; 
	cout<<retn();
	cout<<endl; cout<<endl;
	cout<<"Age: "; 
	cout<<reta(); 
	cout<<endl; cout<<endl;
	cout<<"Gender: "; 
	cout<<retg(); 
	cout<<endl; cout<<endl;
if(n==0)
{
	cout<<"Height (in m): "; 
	cout<<reth(); 
	cout<<endl; cout<<endl;
	cout<<"Weight (in kg): ";
	cout<<retw();
	cout<<endl;cout<<endl;
	cout<<"BMI: ";
	cout<<retb();
	cout<<endl;cout<<endl;
	
	if (q.flag1!=0)
	{
		cout<<"Pulse (bpm): "; 
		cout<<q.retp(); 
		cout<<endl; cout<<endl;
		cout<<"Cholestrol (mg/dL): "; 
		if(q.retch()!=0)
		cout<<q.retch();
        cout<<endl;
        if(q.retch()<200&&q.retch()!=0)
        cout<<"NORMAL cholestrol\n\n";
        else if(q.retch()!=0)
        cout<<"Cholestrol level is HIGH\n\n";
        else if(q.retch()==0)
        { cout<<"NOT AVAILABLE\n"<<endl;}
		cout<<"Normal Fasting Blood Sugar (in mg/dL):"; 
		if(q.rets()!=0)
		cout<<q.rets();
        cout<<endl; 
		if(q.rets()<=100&&q.rets()!=0) cout<<"Sugar Level is NORMAL\n\n";
		else if(q.rets()>100&&q.rets()<125&&q.rets()!=0)
		cout<<"Prediabetes stage\n\n";
		else if(q.rets()>=125&&q.rets()!=0)
		cout<<"Diabetes stage\n\n";
		else if(q.rets()==0)
		{ cout<<"NOT AVAILABLE\n"<<endl;}
	
		
	}
	if (m.flag!=-1)
	cout<<"Eye test score: "<<m.retc()<<endl;cout<<endl;


    bar(d.bmi, q.retp());
    clearmouseclick(WM_LBUTTONDOWN);
	click_report();
}
}


void det::report1(det a,Heart q,Eye m)//NEED TO FINISH
{
	system("cls"); 
	cleardevice();
	cout<<"REPORT COMPARISON:\n\n";

	cout<<"PREVIOUS REPORT\n\n";

    cout<<"Patient ID : "<<pid<<endl;
	cout<<endl;
	cout<<"Name: "; 
	cout<<retn();
	cout<<endl; cout<<endl;
	cout<<"Gender: "; 
	cout<<retg(); 
	cout<<endl; cout<<endl;
		cout<<"Age: "; 
	cout<<reta();
	cout<<endl; cout<<endl;
	cout<<"Height (in m): "; 
	cout<<reth();
	cout<<endl; cout<<endl;
	cout<<"Weight (in kg): ";
	cout<<retw();
	cout<<endl;cout<<endl;
	cout<<"BMI: ";
	cout<<retb();
	cout<<endl;cout<<endl;	
	if (q.flag1!=0)
	{
		cout<<"Pulse (bpm): "; 
		cout<<q.retp(); 
		cout<<endl; cout<<endl;
		cout<<"Cholestrol (mg/dL): "; 
		if(q.retch()!=0)
		cout<<q.retch();
        cout<<endl;
        if(q.retch()<200&&q.retch()!=0)
        cout<<"NORMAL cholestrol\n\n";
        else if(q.retch()!=0)
        cout<<"Cholestrol level is HIGH\n\n";
        else if(q.retch()==0)
        { cout<<"NOT AVAILABLE\n"<<endl;}
		cout<<"Normal Fasting Blood Sugar (in mg/dL):"; 
		if(q.rets()!=0)
		cout<<q.rets();
        cout<<endl; 
		if(q.rets()<=100&&q.rets()!=0) cout<<"Sugar Level is NORMAL\n\n";
		else if(q.rets()>100&&q.rets()<125&&q.rets()!=0)
		cout<<"Prediabetes stage\n\n";
		else if(q.rets()>=125&&q.rets()!=0)
		cout<<"Diabetes stage\n\n";
		else if(q.rets()==0)
		{ cout<<"NOT AVAILABLE\n"<<endl;}
	
		
	}
	if (m.flag!=-1)
	cout<<"Eye test score: "<<m.retc()<<endl;cout<<endl;
    

	cout<<endl<<"MODIFIED REPORT\n\n";

	cout<<"Age: "; 
	cout<<a.reta();
	cout<<endl; cout<<endl;
	cout<<"Height (in m): "; 
	cout<<a.reth();
	cout<<endl; cout<<endl;
	cout<<"Weight (in kg): ";
	cout<<a.retw();
	cout<<endl;cout<<endl;
	cout<<"BMI: ";
	cout<<a.retb();
	cout<<endl;cout<<endl;	
	if (obj_h.flag1!=0)
	{
		cout<<"Pulse (bpm): "; 
		cout<<obj_h.retp(); 
		cout<<endl; cout<<endl;
		cout<<"Cholestrol (mg/dL): "; 
		if(obj_h.retch()!=0)
		cout<<obj_h.retch();
        cout<<endl;
        if(obj_h.retch()<200&&obj_h.retch()!=0)
        cout<<"NORMAL cholestrol\n\n";
        else if(obj_h.retch()!=0)
        cout<<"Cholestrol level is HIGH\n\n";
        else if(obj_h.retch()==0)
        { cout<<"NOT AVAILABLE\n"<<endl;}
		cout<<"Normal Fasting Blood Sugar (in mg/dL):"; 
		if(obj_h.rets()!=0)
		cout<<obj_h.rets();
        cout<<endl; 
		if(obj_h.rets()<=100&&obj_h.rets()!=0) cout<<"Sugar Level is NORMAL\n\n";
		else if(obj_h.rets()>100&&obj_h.rets()<125&&obj_h.rets()!=0)
		cout<<"Prediabetes stage\n\n";
		else if(obj_h.rets()>=125&&obj_h.rets()!=0)
		cout<<"Diabetes stage\n\n";
		else if(obj_h.rets()==0)
		{ cout<<"NOT AVAILABLE\n"<<endl;}
	
		
	}
	if (obj_e.flag!=-1)
	cout<<"Eye test score: "<<obj_e.retc()<<endl;cout<<endl;


    bar(a.d.bmi, obj_h.retp());
    bar2(d.bmi,q.retp());
	click_report();
}

void home()
{
	cleardevice();
	system("cls");
	setcolor(15); 
	setfillstyle(1,15); 
	circle(80,160,6); 
	setcolor(15); 
	setfillstyle(1,4); 
	circle(80,160,3); 
//	readimagefile("D:\Dev-Cpp\samina\Eye.jpg",100,170,210,270);
//	readimagefile("D:\Dev-Cpp\samina\heart.gif",400,170,520,270); 
	outtextxy(100,150,"EYE");
	outtextxy(400,150,"HEART");
	setcolor(15); 
	setfillstyle(1,15); 
	circle(380,160,6); 
	setcolor(15); 
	setfillstyle(1,4); 
	circle(380,160,3); 
}

void click_home(int i) 
{ 
	int x1,y1;
	outtextxy(600,0,"EXIT"); 
	outtextxy(500,0,"HELP"); 
	int answer; 
	while(1) 
	{ 
		delay(1000);	 
		x1=mousex();			
		y1=mousey();			
			if(x1>=600&&x1<=630) 
			{ 
				if(y1>=0&&y1<=10) 
				{ 
				
					exit();
					break; 
				} 
			} 
			if(x1>=500&&x1<=535) 
			{ 
				if(y1>=0&&y1<=10) 
				{ 
					display_help();
					break; 
				} 
			} 
			if(x1>=74&&x1<=86) 
			{ 
				if(y1>=154&&y1<=166) 
				{ 
					obj_e.eye_test(i);
					break; 
				} 
			} 
			if(x1>=374&&x1<=386) 
			{ 
				if(y1>=154&&y1<=166) 
				{                       
					obj_h.heart_det(i);
					break; 
				} 
			} 
		clearmouseclick(WM_LBUTTONDOWN); 	
	} 
} 



void click_report() 
{ 
	int x1,y1;
	outtextxy(600,0,"EXIT"); 
	outtextxy(550,0,"MENU");
	while(1) 
	{ 
		delay(1000); 		
		x1=mousex();						
		y1=mousey();
		if(x1>=600&&x1<=630) 
		{ 
			if(y1>=0&&y1<=10) 
			{             
				exit(); 
				break; 
			} 
		}
       else if(x1>=550&&x1<=580)
        {
             if(y1>=0&&y1<=10)
             {
                              system("cls");
	                          cleardevice(); 
                              break;  
             }
        }
                               
		clearmouseclick(WM_LBUTTONDOWN); 
	}  
} 

void bar(float a,int b) 
{ 
	cleardevice(); 
	settextstyle(1,HORIZ_DIR,4); 
	outtextxy(120,10,"BMI"); 
	settextstyle(1,VERT_DIR,3); 
	outtextxy(50,400,"BMI (in kg per m^2)"); 
	settextstyle(11,HORIZ_DIR,1); 
	outtextxy(70,400-25*10-10,"25"); 
	outtextxy(70,400-18*10-10,"18"); 
	char ar[10]; 
	sprintf(ar,"%4.1f",a); 
	setcolor(4);
	outtextxy(70,400-a*10-10,ar); 
	setcolor(15);
	setfillstyle(1,2); 
	bar(100,400-25*10,250,400-18*10); //BMI	
	bar(300,400-100*2,550,400-60*2); //PULSE	
	setlinestyle(0,1,1);	
	line(100,50,100,400); 
	line(100,400,250,400); 
	line(100,400-25*10,250,400-25*10); 
	line(100,400-18*10,250,400-18*10); 
	
	line(300,50,300,400); 
	line(300,400,550,400); 
	line(300,400-100*2,550,400-100*2); 
	line(300,400-60*2,550,400-60*2); 	
	
//	setlinestyle(0,1,1);
    setcolor(4); 
	line(100,400-a*10,250,400-a*10); 	
	setcolor(15);
	settextstyle(1,HORIZ_DIR,4);
	outtextxy(320,10,"PULSE"); 
	settextstyle(11,HORIZ_DIR,1); 
	outtextxy(270,400-60*2-10,"60"); 
	outtextxy(270,400-100*2-10,"100"); 
	char arr[10]; 
	sprintf(arr,"%5d",b); 
	setcolor(4);
	outtextxy(270,400-b*2-10,arr); 
	setcolor(4);	
	
	//setlinestyle(0,1,1); 
	line(300,400-b*2,550,400-b*2); 
	setcolor(15);
} 

void bar2(float i,int j)
{ 
	settextstyle(11,HORIZ_DIR,1); 
	char ar[10]; 
	sprintf(ar,"%4.1f",i); 
	setcolor(9);
	outtextxy(70,400-i*10-10,ar); 	
	setlinestyle(0,1,1); 
	line(100,400-i*10,250,400-i*10); 	


	settextstyle(11,HORIZ_DIR,1); 
	char arr[10]; 
	sprintf(arr,"%5d",j); 
	setcolor(9);
	outtextxy(270,400-j*2-10,arr); 		
	setlinestyle(1,1,2); 
	line(300,400-j*2,550,400-j*2); 	
    outtextxy(100,430,"This colour indicates previous report.");
    setcolor(4);
    	outtextxy(100,450,"This colour indicates modified report.");
setcolor(15);
}
