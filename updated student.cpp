#include<iostream>
#include<fstream>
#include<process.h>
#include<iomanip>
#include<windows.h>
using namespace std;

// the class that stores data

class student
{
    int rollno;
    int batch;
    int sem;
    char name[50];
    char faculty[20];
    float eng_marks, math_marks, sci_marks, nep_marks, cs_marks;
    char grade;
   
    float per;
	public:
        void getdata();
        void showdata();
        void calculate();
        int retrollno();
}; //class ends here

void student::calculate()
{
    per=(eng_marks+math_marks+sci_marks+nep_marks+cs_marks)/5.0;
    
    if(per>=60.0)
		grade='A';
    else if(per>=50.0 )
		grade='B';
    else if(per>=32.0 )
		grade='C';
    else
		grade='F';
}

void student::getdata()
{
    cout<<"\nEnter student's roll number    : ";
    cin>>rollno;
    
    cout<<"\nEnter student's name           : ";
    cin.ignore();
    cin.getline(name,50);
    
    cout<<"\nEnter faculty                  : ";
    cin>>faculty;
    
    cout<<"\nEnter batch                    : ";
    cin>>batch;
    
    cout<<"\nEnter semester                 : ";
    cin>>sem;
    
    cout<<"\nEnter marks obtained in all 5 subjects   : ";
	cout<<"\nEnter marks in English out of 80         : ";
    cin>>eng_marks;
    if(per>=60.0 && per<=80.0)
		grade='A';
    else if(per>=50.0 )
		grade='B';
    else if(per>=32.0 )
		grade='C';
    else
		grade='F'; 
		
	cout<<"\nEnter marks in Math out of 100           : ";
    cin>>math_marks;
    
	cout<<"\nEnter marks in Science out of 75         : ";
    cin>>sci_marks; 
	if(per>=60.0 && per<=75.0)
		grade='A';
    else if(per>=50.0 )
		grade='B';
    else if(per>=32.0 )
		grade='C';
    else
		grade='F'; 
    
	cout<<"\nEnter marks in Nepali out of 80          : ";
    cin>>nep_marks;
     if(per>=60.0 && per<=80.0)
		grade='A';
    else if(per>=50.0 )
		grade='B';
    else if(per>=32.0 )
		grade='C';
    else
		grade='F'; 
		
	cout<<"\nEnter marks in Computer Science out of 50: ";
    cin>>cs_marks;
	if(per>=40.0 && per<=50.0)
		grade='A';
    else if(per>=35.0 )
		grade='B';
    else if(per>=20.0 )
		grade='C';
    else
		grade='F';
    
}
void student::showdata()
{
   cout<<"\n   Roll No.    Faculty     Batch     Semester     Percentage      Grade     Marks Obtained        "<<endl;
}

int  student::retrollno(){
	return rollno;
}

//function declaration
void create_student();
void display_student(int);//display particular record
void display_all();      //display all records
void delete_student(int);//delete particular record
void change_student(int);//edit particular record
  
//MAIN
int main()
{
    char ch;
    cout<<setprecision(4); 
    do
    {
        char ch;
        int num;
        float highest_marks(float[]);
        float lowest_marks(float[]);
        float marks[10]={0};
        system("cls");
        cout<<endl<<endl;
        system("Color 0A");
        
        cout<<"\t\t\t\t\t________________________________________"<<endl;
        cout<<"\t\t\t\t\t*** STUDENT REPORT MANAGEMENT SYSTEM ***"<<endl;
        cout<<"\t\t\t\t\t________________________________________"<<endl;
        cout<<"\n\n\n\tMENU";
        cout<<"\n\n\t1.Create student record        ";
        cout<<"\n\n\t2.Search student record        ";
        cout<<"\n\n\t3.Display all students records ";
        cout<<"\n\n\t4.Delete student record        ";
        cout<<"\n\n\t5.Modify student record        ";
        cout<<"\n\n\t6.Exit";
        cout<<"\n\n\t\t\t\t\tWhat is your Choice (1/2/3/4/5/6):";
        cin>>ch;
        system("cls");
      
        switch(ch)
        {
         	case '1':
		        create_student();
		        break;
		        
	        case '2':
	            cout<<"\n\n\tEnter the roll number:";
		        cin>>num;
		        display_student(num);
		        break;
	        
			case '3':
	         	display_all();
	        	break;
	        
			case'4':
	            cout<<"\n\n\tEnter the roll number:";
		        cin>>num;
		        delete_student(num);
		        break;
	        
			case'5':
	            cout<<"\n\n\tEnter the roll number:";
		        cin>>num;
		        change_student(num);
	        	break;
	        
			case'6':
	            cout<<"Please exit, Thank you!";
	        	exit(0); 
        }
    }while(ch!='6');
    return 0;
}

//write student details to file
void create_student()
{
    student std;
    ofstream oFile;
    oFile.open("student.dat",ios::binary | ios::app);
    std.getdata();
	std.calculate();
   
    oFile.write((char*)&std,sizeof(std));
   
    oFile.close();

	cout<<"\n\nStudent record Has Been Created ";

    cin.ignore();
    cin.get();
}

// read file records
void display_all()
{
    student std;
    ifstream inFile;
    inFile.open("student.dat",ios::binary);
    
    if(inFile.fail())
    {
        cout<<"File not found !! Press any Key to exit";
        cin.ignore();
        cin.get();
        return;
    }
    
    cout<<"\n\n\n\t\tDISPLAYING ALL RECORDS\n\n";
    cout<<"\n ********************  Result Sheet  ****************"<<endl;
      

       cout<<"\n   Roll No.    Faculty     Batch     Semester     Percentage      Grade     Marks Obtained        "<<endl;
    
    
    inFile.close();
    cin.ignore();
    cin.get();
}

//read specific record based on roll number
void display_student(int n)
{
    student std;
    ifstream iFile;
    float sum=0,marks;
        int i;
        cout<<"Enter marks obtained in all 5 subjects:";
        for(i=0;i<5;i++)
        {
    	    cin>>marks;
    	    sum=sum+marks;
	    }
    iFile.open("student.dat",ios::binary);
    if(iFile.fail())
    {
        cout<<"File not found... Press any Key to exit";
        cin.ignore();
        cin.get();
        return;
    }
    
    bool flag=false;
    
	while(iFile.read((char*)&std,sizeof(std))!=0)
    {
        if(std.retrollno()==n)
        {
            std.showdata();
            flag=true;
        }
    }
    iFile.close();
    if(flag==false)
    	cout<<"\n\nrecord does not exist";
    cin.ignore();
    cin.get();
}

// modify record for specified roll number
void change_student(int n)
{
    bool found=false;
    student std;
    fstream f1;
    f1.open("student.dat",ios::binary|ios::in|ios::out);
    if(f1.fail())
    {
        cout<<"File not found. Press any Key to exit...";
        cin.ignore();
        cin.get();
        return;
    }
    
     while(!f1.eof() && found==false)
    {
        f1.read((char*)&std,sizeof(std));
        if(std.retrollno()==n)
        {
            std.showdata();
            cout<<"\n\Enter new student details:"<<endl;
            std.getdata();
			f1.write((char*)&std,sizeof(std));
			cout<<"\n\n\t Record Updated";
			found=true;
        }
    }
    
    f1.close();
    if(found==false)
    cout<<"\n\n Record Not Found ";
    cin.ignore();
    cin.get();
}

//delete record with particular roll number
void delete_student(int n)
{
    student std;
    ifstream iFile;
    iFile.open("student.dat",ios::binary);
    
	if(iFile.fail())
    {
        cout<<"File not found... Press any Key to exit...";
        cin.ignore();
        cin.get();
        return;
    }
    
    ofstream oFile;
    oFile.open("Temp.dat",ios::out);
    iFile.seekg(0,ios::beg);
    
	while(iFile.read((char*)&std,sizeof(std))!=0)
        if(std.retrollno()!=n)
            oFile.write((char*)&std, sizeof(std));

    oFile.close();
    iFile.close();
    remove("student.dat");
    rename("Temp.dat","student.dat");
    cout<<"\n\n\tRecord Deleted ..";
    cin.ignore();
    cin.get();
}
