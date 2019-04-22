/*  SPRPTA Bus Ticket Reservation System
    C++ Software Development Project        */
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
