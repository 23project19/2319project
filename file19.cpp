       
#include <iostream>
#include <fstream>
#include <cstdio>
#include <conio.h>
#include <cstdlib>
#include <stdio.h>
using namespace std;
int count01 ;
// class Passenger
class Passenger
 {
                string    str_City, str_ContactNumber, str_UserName, str_Password, str_name ;
            protected:
                string   str_NIC ;
            public:
                Passenger(){}
                Passenger(string name, string NIC, string City, string ContactNumber, string Username, string Password) ;
                void Login();
                void SearchFile_and_Update() ;
                void Deletes() ;
		                ~Passenger() ;
};
// class Seats
class Seats{
        protected:
            int i_SeatNo ;
        public:
            void CheckSeatAvailabilty() ;
};
// class Reservations
class Reservations : public Passenger,public Seats{
protected :
        string str_Arrival_St, str_Dep_St ;
        int  i_No_Tickets, i_Charge ;
        double i_total ;
    public:
                Reservations();
                // to make a reservation
                Reservations(string NIC, string DeptSt, string ArrivalSt, int NoTickets );
                void SearchFile_and_Update();
                // ModifyReservation Function
                void Deletes();
                // cancel reservation function
                void Show(string, string, string, int, int, int);
                double  CalculateFee(double, int) ;
                ~Reservations();
};
                ~Passenger() ;
};
// class Seats
class Seats{
        protected:
            int i_SeatNo ;
        public:
            void CheckSeatAvailabilty() ;
};
// class Reservations
class Reservations : public Passenger,public Seats{
protected :
        string str_Arrival_St, str_Dep_St ;
        int  i_No_Tickets, i_Charge ;
        double i_total ;
    public:
                Reservations();
                // to make a reservation
                Reservations(string NIC, string DeptSt, string ArrivalSt, int NoTickets );
                void SearchFile_and_Update();
                // ModifyReservation Function
                void Deletes();
                // cancel reservation function
                void Show(string, string, string, int, int, int);
                double  CalculateFee(double, int) ;
                ~Reservations();
};
// class TimeTables
class TimeTables : public Reservations{
    public:
                void Show()const ;
                ~TimeTables ();
};
// class Payments
class Payments: public Reservations{
    public :
                void Show()const ;
                ~Payments();
};
// payments - show
inline void Payments :: Show()const{
                    fstream payments ;
                    payments.open("Payments.txt",ios :: in)  ;
                    string line ;
                    cout << "\n\n-----------------Payment Scheme------------------\n\n" ;
                    while(!payments.eof()){
                            getline(payments,line);
                            cout << line << "\n" ;
                    }
}
// timetables - Show
inline void TimeTables :: Show()const{
                    string line2 ;
                    ifstream timetable("Timetables.txt") ;
                    cout << "\n\n----------------TimeTable-------------------------\n\n" ;
                    while(!timetable.eof()){
                            getline(timetable,line2) ;
                            cout << line2 << "\n\n" ;
                    }
}
// Reservations constructor
inline Reservations :: Reservations(string NIC, string DeptSt, string ArrivalSt, int NoTickets ){
                        Reservations  r2 ;
			                        str_NIC = NIC ;
                        str_Dep_St = DeptSt ;
                        str_Arrival_St = ArrivalSt ;
                        i_No_Tickets = NoTickets ;
                        ifstream PaymentsRead ;
                        PaymentsRead.open("Payments.txt") ;
                        double  ch ;
                        string s1,s2 ;
                        while(PaymentsRead >> s1 >> s2 >> ch){
                                if((str_Dep_St == s1) & (str_Arrival_St == s2)){
                                    i_total = CalculateFee(ch, i_No_Tickets);
                                }
                        }
                        char confirmation ;
                            cout << "\n\nConfirm the Reservation(Y/N): \n\n" ;
                            cin >> confirmation ;
                            confirmation = tolower(confirmation);
                        if(confirmation == 'y'){
                                fstream Reservations ;
                                fstream Seats ;
                                string line ;
                                Reservations.open("Reservations.txt", ios::app | ios:: out | ios::ate);
                                Seats.open("Seat.txt", ios :: app | ios :: out | ios :: ate | ios :: in);
                                Seats <<  str_NIC << "\t" << i_No_Tickets <<"\n" ;
                                Reservations << str_NIC <<"\t"<< str_Dep_St <<"\t"<< str_Arrival_St <<"\t"<< i_No_Tickets
                                            << "\t" << i_total <<"\n";
			                                Reservations.close();
                        }
                        else{
                                cout << "\n\nConfirmation denied and exiting from the program \n" ;
                                exit(0) ;
                        }
                                r2.Show(str_NIC, str_Dep_St, str_Arrival_St, i_No_Tickets, ch, i_total  ) ;
}
// modify Reservation function
inline void Reservations :: SearchFile_and_Update(){
                                Reservations  r1 ;
                                double ch;
                                char confirmation ;
				// modify Reservation function

inline void Reservations :: SearchFile_and_Update(){


                                Reservations  r1 ;
                                double ch;
                                char confirmation ;
                                int   s7;


                                    ifstream reservationsIn ; //SEARCH
                                    ifstream  seatsIn; //search

                                    fstream  reservationsOut ;
                                    fstream seatsOut ;

                                    cout << "\n\nConfirm the You wants to modify reservation(Y/N): \n\n" ;
                                    cin >> confirmation ;
                                    confirmation = tolower(confirmation) ;
                                    system("CLS");

                        if(confirmation == 'y'){


                                    TimeTables T1 ;
                                    Payments P1 ;
                                    T1.Show();
                                    P1.Show() ;

                                    cout << "\n\n-------------------------------------------------\n\n" ;

                                    cout <<"\n\nEnter new your NIC :\n\n" ;
                                    cin >> str_NIC ;

                                     cout << "\n\n-------------------------------------------------\n\n" ;

                                    cout << "\n\n New Depature station\n\n " ;
                                    cin >> str_Dep_St ;

                                    cout << "\n\n New Arrival station\n\n " ;
                                    cin >> str_Arrival_St ;


                                    cout << "\n\nNew  No. of Tickets\n\n " ;
                                    cin >> i_No_Tickets ;


                                    fstream PaymentsRead ;
                                    PaymentsRead.open("Payments.txt", ios :: in) ;


