#include<iostream>
#include<fstream>
#include<iomanip>
#include<windows.h>

using namespace std;
void menu();

class ManageMenu
{
protected:
    string userName; //hide admin name

public:

    //virtual void menu(){}

    ManageMenu()
    {
        system("color 0A"); //change terminal color
        cout << "\n\n\n\n\n\n\n\n\n\t  Enter Your Name to Continue as an Admin: ";
        cin >> userName;
        system("CLS");
        menu(); //call to main function to load after executing the constructr
    }

    ~ManageMenu(){} //de
};

class Customers
{
    public:
        string name,gender,address;
        int age,mobilenumber;
        static int cusID;
        char all[999];

        void getDetails()
        {   
            ofstream out("old-customers.txt", ios::app);
            {
                cout<< "Enter Customer ID";
                cin>> cusID;
                cout<< "Enter Name";
                cin>> name;
                cout<< "Enter Age";
                cin>> age;
                cout<< "Enter Mobile Number";
                cin>> mobilenumber;
                cout<< "Enter gender";
                cin>> gender;
                cout<< "Enter Address";
                cin>> address;
            }

            out << "\n Customer ID "<<cusID <<"\n Name" <<name << "\nAge" <<age<<"\nGender"<<gender << "\nMobile Number:" <<mobilenumber << "\nAddress:" <<address<<endl;
            out.close();

            cout <<"\nSAVED \n NOTE: We saved your details record for future  purpose\n"<<endl;
            
        }

        void showDetails()
        {
            ifstream in("old-customers.txt");
            {
                if(!in)
                {
                    cout<<"File Error!"<<endl;
                }
                while(!(in.eof()))
                {
                    in.getline(all, 999);
                    cout<< all <<endl;
                }
                in.close();
            }
        }
};

int Customers::cusID;

class Cabs
{
    public:
        int cabChoice;
        int kilometers;
        float cabCost;
        static float lastcabCost;

        void cabDetails()
        {
            cout<< "We collaborated with fastest,safest, and smartest cab service around the country" << endl;
            cout<<"...................ABC Cabs...................\n"<<endl;
            cout<<"1. Rent a Standard Cab - Rs.15 for 1KM"<<endl;
            cout<<"2. Rent a luxury Cab - Rs.25 per 1KM" << endl;

            cout<<"\n To calculate the cost for your journey: "<<endl;
            cout<<"\n Enter which kind of cab you need:";
            cin >> cabChoice;
            cout<<"\n Enter kilometers you have to travel";
            cin >> kilometers;

            int hireCab;
            if(cabChoice == 1)
            {
                cabCost = kilometers * 15;
                cout<< "\n Your tour cost " << cabCost << " rupees for a standard Cab"<<endl;
                cout << "Press 1 to hire this cab: or ";
                cout<< "Press 2 to selec another cab"<<endl;
                cin >> hireCab;

                system("cls"); /* clears the Screen */;

                if(hireCab == 1){
                    lastcabCost = cabCost;
                    cout<< "\n you have succesfully hired a standard cab" << endl;
                    cout << "Goto Menu and take the receipt" << endl;

                }
                else if(hireCab == 2)
                {
                    cabDetails();

                }
                else{
                    cout << "Invalid Input! Redirecting to Previous Menu\n Please wait \n"<<endl;
                    Sleep(99);
                    system("cls");
                    cabDetails();

                }
            }
            else if(cabChoice == 2)
            {
                cabCost = kilometers * 25;
                cout<< "\n Your tour cost " << cabCost << " rupees for a luxury Cab"<<endl;
                cout << "Press 1 to hire this cab: or ";
                cout<< "Press 2 to select another cab"<<endl;
                cin >> hireCab;

                system("cls"); /* clears the Screen */;

                if(hireCab == 1){
                    lastcabCost = cabCost;
                    cout<< "\n you have succesfully hired a luxury cab" << endl;
                    cout << "Goto Menu and take the receipt" << endl;

                }
                else if(hireCab == 2)
                {
                    cabDetails();

                }
                else{
                    cout << "Invalid Input! Redirecting to Previous Menu\n Please wait \n"<<endl;
                    Sleep(99);
                    system("cls");
                    cabDetails();

                }
            }
            else{
                    cout << "Invalid Input! Redirecting to Previous Menu\n Please wait \n"<<endl;
                    Sleep(9999);
                    system("cls");
                    menu();

                }

        cout << "\n Press 1 to Redirect Main mennu: ";
        cin >> hireCab;
        system("cls");
        if(hireCab == 1)
        {
            menu();
        }
        else{
            menu();
        }


        }

};

class Booking
{
    public:
        int choiceHotel;
        int packChoice1;
        
        int gotoMenu;
        static float hotelCost;

        void hotels()
        {
            string hotelNo[] = {"Avengers", "Choice" , "ElephantBay"};
            for(int a=0; a< 3; a++){
                cout << (a+1) <<". Hotel" << hotelNo[a] <<endl;
            }
            cout << "\n Currently we Collaoboratd with above Hotels" << endl;

            cout << "Press any key to back or \n Enter number of Hotel you wish to book: ";
            cin >> choiceHotel;

            system("cls");

            if(choiceHotel == 1){
            cout << "-------WELCOME TO HOTEL AVENDRA-------\n" << endl;

            cout << "The Garden, food and beverage. Enjoy all you can drink, Stay cool and get chilled in the summer sun." << endl;

            cout << "Packages offered by Avendra:\n" << endl;

            cout << "1. Standard Pack" << endl;
            cout << "\tAll basic facilities you need just for: Rs.5000.00" << endl;
            cout << "2. Premium Pack" << endl;
            cout << "\tEnjoy Premium: Rs.10000.00" << endl;
            cout << "3. Luxury Pack" << endl;
            cout << "\tLive a Luxury at Avendra: Rs.15000.00" << endl;


            cout << "\nPress another key to back or\nEnter Package number you want to book: ";
            cin >> packChoice1;

            if (packChoice1 == 1){
                hotelCost = 5000.00;
                cout << "\nYou have successfully booked Standard Pack at Avendra" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else if (packChoice1 == 2){
                hotelCost = 10000.00;
                cout << "\nYou have successfully booked Premium Pack at Avendra" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else if (packChoice1 == 3){
                hotelCost = 15000.00;
                cout << "\nYou have successfully booked Luxury Pack at Avendra" << endl;
                cout << "Goto Menu to take the receipt" << endl;
            }
            else{
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                Sleep(1100);
                system("CLS");
                hotels();

            }

            cout << "\nPress 1 to Redirect Main Menu: ";
            cin >> gotoMenu;
            system("CLS");
            if(gotoMenu == 1){
                menu();
            }
            else{
                menu();
            }
        }
        else if(choiceHotel == 2){
            cout << "-------WELCOME TO HOTEL CHOICEYOU-------\n" << endl;

            cout << "Swimming Pool | Free WiFi | Family Rooms \n Fitness Center | Restaurant & Bar" << endl;

            cout << "Packages Offered by ChoiceYou:\n" << endl;

            cout << "1. Family Pack" << endl;
            cout << "\t Rs.15000.00 for a day" << endl;
            cout << "2. Couple Pack" << endl;
            cout << "\t Rs.10000.00 for a day" << endl;
            cout << "3. Single Pack" << endl;
            cout << "\t 5000.00 for a day" << endl;

            cout << "\nPress another key to back or\nEnter Package number you want to book: ";
            cin >> packChoice1;

            if (packChoice1 == 1){
                hotelCost = 15000.00;
                cout << "You have successfully booked Family Pack at ChoiceYou" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else if (packChoice1 == 2){
                hotelCost = 10000.00;
                cout << "You have successfully booked Couple Pack at ChoiceYou" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else if (packChoice1 == 3){
                hotelCost = 5000.00;
                cout << "You have successfully booked Single Pack at ChoiceYou" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else{
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                Sleep(1100);
                system("CLS");
                hotels();
            }

            cout << "\nPress 1 to Redirect Main Menu: ";
            cin >> gotoMenu;
            system("CLS");
            if(gotoMenu == 1){
                menu();
            }
            else{
                menu();
            }
        }
        else if(choiceHotel == 3){
            cout << "-------WELCOME TO HOTEL ELEPHANTBAY-------\n" << endl;
            cout << "Set in tropical gardens on the banks of the Maha Oya river While Seeing Elephants" << endl;
            cout << "Amazing offer in this summer: Rs.5000.00 for a one day!!!" << endl;

            cout << "\nPress another key to back or\nPress 1 to book this special package: ";
            cin >> packChoice1;

            if (packChoice1 == 1){
                hotelCost = 5000.00;
                cout << "You have successfully booked ElephantBay Special Pack" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else{
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                Sleep(1100);
                system("CLS");
                hotels();
            }
            cout << "\nPress 1 to Redirect Main Menu: ";
            cin >> gotoMenu;
            system("CLS");
            if(gotoMenu == 1){
                menu();
            }
            else{
                menu();
            }
        }
        else{
            cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
            Sleep(1100);
            system("CLS");
            menu();
        }
        }
};

float Cabs:: lastcabCost;
float Booking::hotelCost;
class Charges : public Booking,Cabs, Customers

{
    public:
        void printBill()
        {
            ofstream outf("receipt.txt");
            {
            outf << "--------ABC Travel Agency--------" << endl;
            outf << "-------------Receipt-------------" << endl;
            outf << "_________________________________" << endl;

            outf << "Customer ID: " << Customers::cusID << endl << endl;
            outf << "Description\t\t Total" << endl;
            outf << "Hotel cost:\t\t " << fixed << setprecision(2) << Booking::hotelCost << endl;
            outf << "Travel (cab) cost:\t " << fixed << setprecision(2) << Cabs::lastcabCost << endl;

            outf << "_________________________________" << endl;
            outf << "Total Charge:\t\t " << fixed << setprecision(2) << Booking::hotelCost+Cabs::lastcabCost << endl;
            outf << "_________________________________" << endl;
            outf << "------------THANK YOU------------" << endl;
        }
        outf.close();


            
        }

        void  showBill()
        {
            ifstream inf("receipt.txt");
            {
                if(!inf)
                {
                    cout << "file opening error:"<<endl;
                }
                while(!(inf.eof()))
                {
                    inf.getline(all,999);
                    cout << all<< endl;
                }
            }
            inf.close();
        }

};

void menu()
{
    int mainChoice;
    int inChoice;
    int gotoMenu;
    cout << "\t\t      * ABC Travels *\n" << endl;
    cout << "-------------------------Main Menu--------------------------" << endl;

    cout << "\t _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ " << endl;
    cout << "\t|\t\t\t\t\t|" << endl;
    //cout << "\t|\tAgency System Management -> 0" << endl;
    cout << "\t|\tCustomer Management -> 1\t|" << endl;
    cout << "\t|\tCabs Management     -> 2\t|" << endl;
    cout << "\t|\tBookings Management -> 3\t|" << endl;
    cout << "\t|\tCharges & Bill      -> 4\t|" << endl;
    cout << "\t|\tExit                -> 5\t|" << endl;
    cout << "\t|\t\t\t\t\t|" << endl;
    cout << "\t|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|" << endl;

    cout << "\nEnter Choice: ";
    cin >> mainChoice;

    system("CLS");

    Customers a2; //creating objects
    Cabs a3;
    Booking a4;
    Charges a5;

    if(mainChoice == 1){
        cout << "------Customers------\n" << endl;
        cout << "1. Enter New Customer"<< endl;
        cout << "2. See Old Customers"<< endl;

        cout << "\nEnter choice: ";
        cin >> inChoice;

        system("CLS");
        if(inChoice == 1){
            a2.getDetails();
        }
        else if(inChoice == 2){
            a2.showDetails();
        }
        else{
            cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
            Sleep(1100);
            system("CLS");
            menu();
        }
        cout << "Press 1 to Redirect Main Menu: ";
        cin >> gotoMenu;
        system("CLS");
        if(gotoMenu == 1){
            menu();
        }
        else{
            menu();
        }
    }



    else if(mainChoice == 2){
        a3.cabDetails();
    }
    else if(mainChoice == 3){
        cout << "--> Book a Luxury Hotel using the System <--\n" << endl;
        a4.hotels();
    }
    else if(mainChoice == 4){
        cout << "-->Get your receipt<--\n" << endl;
        a5.printBill();
        cout << "Your receipt is already printed you can get it from file path\n" << endl;
        cout << "to display the your receipt in the screen, Enter 1: or Enter another key to back main menu: ";
        cin >> gotoMenu;
        if(gotoMenu == 1){
            system("CLS");
            a5.showBill();
            cout << "Press 1 to Redirect Main Menu: ";
            cin >> gotoMenu;
            system("CLS");
            if(gotoMenu == 1){
                menu();
            }
            else{
                menu();
            }
        }
        else{
            system("CLS");
            menu();
        }
    }
    else if(mainChoice == 5){
        cout << "\n\n\t--GOOD-BYE!--" << endl;
        Sleep(1100);
        system("CLS");
        ManageMenu();
    }
    else{
        cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
        Sleep(1100);
        system("CLS");
        menu();
    }
}

int main()
{   

    ManageMenu startObj;
    return 0;
}
