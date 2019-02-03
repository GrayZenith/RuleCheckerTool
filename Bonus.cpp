#include<fstream>    //header files required
#include<iostream>
#include<string>

using namespace std;

void CheckFor1() //method checkfor 1 to count occ. of 1
{   
    char c1;     
    int count =0;
    std::ifstream ifile;
    ifile.open("BadCode.java");  // to open the file
    while(!ifile.eof())  // run the loop till the end of the file
    { 
        ifile.get(c1); //reading each character one by one
        if(c1 == '1')  //comparision
        count++;
    }
    ifile.close(); //to close file
    if (count<=1)
       cout<<"1 occurs"<<c1<<"times:"<<"The rule is followed";  //and dislpay if rule has been followed
    else 
       cout<<"1 occurs"<<c1<<"times:"<<"The rule is not followed";   
}

void CheckFor2()   //method checkfor 1 to count occ. of 2
{   
    char c2;    
    int count =0;
    std::ifstream ifile;
    ifile.open("BadCode.java");
    while(!ifile.eof())
    { 
        ifile.get(c2);
        if(c2 == '2')
        count++;
    }
    ifile.close();
    if (count<=1)
       cout<<"2 occurs"<<c2<<"times:"<<"The rule is followed"; //and dislpay if rule has been followed
    else 
       cout<<"2 occurs"<<c2<<"times:"<<"The rule is not followed";   
}

void CheckForOther()  //method checkfor 1 to count occ. of 0,3,4,5,6,7,8,9
{   
    char c;
    int check =0;
    std::ifstream ifile;
    ifile.open("BadCode.java");
    while(!ifile.eof())
    { 
        ifile.get(c);
        if((c == '0')||(c =='3')||(c=='4')||(c =='5')||(c =='6')||(c =='7')||(c=='8')||(c =='9'))
        check++;
        break;
    }
    ifile.close();
    if (check == 0)
       cout<<"A forbidden number did not occurr :The rule is followed";  //and dislpay if rule has been followed
    else 
       cout<<"A forbidden number occurred :TThe rule is not followed";   
}
void CheckForDoubleFloat() //method to check explicit conversion to double or float
{   
    string word;
    int check =0;
    std::ifstream ifile;
    ifile.open("BadCode.java");
    while(!ifile.eof())
    { 
        ifile>>word;
        if((word.compare("float") == 0)||(word.compare("double") == 0));        
        check++;
        break;
    }
    ifile.close();
    if (check == 0)
       cout<<"No occurance of double or float did not occurred :The rule is followed"; //and dislpay if rule has been followed
    else 
       cout<<"There is occurance of doubl or float :TThe rule is not followed";
}

void CheckLineLen(){   //function to check length of eack line 
    std::string cline1;
    int count =0;
    std::ifstream ifile;
    ifile.open("BadCode.java");
    while(!ifile.eof())
    { 
        std::getline(ifile,cline1);
        if(cline1.length()>80)
        count++;
        break;
    }
    ifile.close();
    if (count<=1)
       cout<<"There in no line with more that 80 char :The rule is followed";  //and dislpay if rule has been followed
    else 
       cout<<"There is line with more than 80 char:The rule is not followed";  
}
void Check300lines(){   //function to check that the code contains no more than 300 lines
    string cline2;
    int count = 0;
    std::ifstream ifile;
    ifile.open("BadCode.java");
    while(!ifile.eof()){
        std::getline(ifile,cline2);
        count++;
    }
    ifile.close();
    if (count<=300)
       cout<<"There are not more than 300 lines of code :The rule is followed";  //and dislpay if rule has been followed
    else 
       cout<<"There are more than 300 lines of code :The rule is not followed"; 
}

int main(){ // main function to ask the user which rules they want to check 
    int ch;
    cout<<" \nThe following rules can be checked for assignment 2 in this tool:\n";
    cout<<"\n1)The digit 1 may only occur once in your .java file ";
    cout<<"\n2)The digit 2 may only occur once in your .java file";
    cout<<"\n3)The digits 0, 3, 4, 5, 6, 7, 8, 9 may not occur in your .java file";
    cout<<"\n4)No values of type float or double may be used, even implicitly";
    cout<<"\n5)No line of code shall be longer than 80 characters";
    cout<<"\n6)Your code should not be longer than 300 lines of code";
    cout<<"\n7)To check all rules";
    cout<<"\n Please enter the number of the rule you wish to check :";
    cin>>ch;

    std::ifstream ifile;
    ifile.open("BadCode.java");
    if(ifile.is_open()) {

        switch(ch){    //switch case for the user input
                
        case 1 : CheckFor1();
                 break;
        case 2 : CheckFor2();
                 break;
        case 3 : CheckForOther();
                 break;
        case 4 :CheckForDoubleFloat(); 
                 break;
        case 5 :CheckLineLen(); 
                 break;
        case 6 :Check300lines();
                 break;
        case 7 :CheckFor1();       // case to check all rules at once
                 CheckFor2();
                 CheckForOther();
                 CheckForDoubleFloat();
                 CheckLineLen();
                 Check300lines();
                 break;
        default : cout<<"Wrong Input";  // default case for error
                 break;
        }
    }
        else std::cout<<"There was an error when I attempted to open the file"; //Display error message if "BadCode.java" is not found
        return 0;
}

