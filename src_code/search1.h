#pragma once
#include<iostream>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<iomanip>
#include <pqxx/pqxx> 

//hotel_rentel_management_system

using namespace std;
using namespace pqxx;

class search1
{
public:
    int  room_search();
    int room_type();
    int floor_num();
    int room_rent();
    int vacancy();
    void date();
};