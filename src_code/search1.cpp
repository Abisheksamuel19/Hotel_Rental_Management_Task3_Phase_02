#include "search1.h"
#include "guest_console.h"
guest_console guest;


int search1::room_type()
{  
    char c1;

    try
    {
        connection C("dbname = hotel_rentel_management_system user = postgres password = qwerty port = 5432");
        if (C.is_open())
        {
            string room_type;int t = 1;


            do
            {

                system("CLS");
                cout << setw(60) << "**********************************************" << endl;
                cout << setw(60) << "*               SEARCHING ROOMS              *" << endl;
                cout << setw(60) << "*            ACCORDING TO ROOM TYPE          *" << endl;
                cout << setw(60) << "**********************************************" << endl;
                cout << endl << endl;



                cout << "Room Types:  " << endl;
                cout << " => Delux       " << endl;
                cout << " => Family_suit " << endl;
                cout << " => AC          " << endl;
                cout << " => Non-AC      " << endl;
                cout << " => Standard    " << endl << endl;

                cout << "Enter The Type of Room For Searching : " << endl;

                cin >> room_type;

               
                std::string sql = " select Room_Number , floor_number, Room_rent,occupied_status from hotel_rooms_info where Room_type = (""'" + (room_type)+"'" + ")";

                
                work W(C);
                cout << endl << endl;
                cout << "Room type wise Room Details:" << endl << endl;


                cout << "=============================================================================" << endl;
                cout << "|S.No      |  ROOM_NUMBER  |   FLOOR_NUMBER  |   ROOM_RENT  |OCCUPIED STATUS|" << endl;
                cout << "=============================================================================" << endl;
                result R(W.exec(sql));

                for (result::const_iterator c = R.begin(); c != R.end(); ++c) {
                    cout << "|" << t << "\t   |\t" << c[0].as<int>() << "\t   |\t" << c[1].as<string>() << "\t     |" << " \t" << c[2].as<int>() << "\t    |" <<setw(8)<< c[3].as<string>() << "\t    |"<<endl;
                    t++;
                }
                cout << "-----------------------------------------------------------------------------" << endl;    
                W.commit();
                cout << "Do you want to you continue to Search again... press [y/n]";
                cin >> c1;
            } while (c1 == 'y');
        }
        else
        {
            cout << "Can't open database" << endl;

        }
    }
    catch (const std::exception& e) {
        cerr << e.what() << std::endl;

    }
    guest.guest_menu();
}
int search1::floor_num()
{
    char c1;

    try
    {
        connection C("dbname = hotel_rentel_management_system user = postgres password = qwerty port = 5432");
        if (C.is_open())
        {


            do
            {

                system("CLS");
                cout << setw(60) << "**********************************************" << endl;
                cout << setw(60) << "*               SEARCHING ROOMS              *" << endl;
                cout << setw(60) << "*           ACCORDING TO FLOOR NUMBER        *" << endl;
                cout << setw(60) << "**********************************************" << endl;
                cout << endl << endl;

                string floor_num;int t = 1;

                cout << "Enter The Floor Number To Search the Room: "; cin >> floor_num;


                std::string sql = " select Room_Number , Room_type, Room_rent,occupied_status from hotel_rooms_info where floor_number = (""'" + (floor_num)+"'" + ")";
                work W(C);
                cout << endl << endl;
                cout << "Room Details according to Floor Number:" << endl << endl;


                cout << "=============================================================================================" << endl;
                cout << "|S.No      |  ROOM_NUMBER  |         ROOM_TYPE          |      ROOM_RENT    |OCCUPIED STATUS|" << endl;
                cout << "=============================================================================================" << endl;
                result R(W.exec(sql));

                for (result::const_iterator c = R.begin(); c != R.end(); ++c) {
                    cout << "|" << t << "\t   |\t" << c[0].as<int>() << "\t   |\t" << setw(10) << setw(10) << c[1].as<string>() << setw(10) << "\t|" << " \t" << c[2].as<int>() << "\t    |" << setw(8) << c[3].as<string>() << "\t    |" << endl;

                    t++;
                }
                cout << "---------------------------------------------------------------------------------------------" << endl;

                W.commit();
                cout << "Do you want to you continue to Search again... press [y/n]";
                cin >> c1;
            } while (c1 == 'y');
        }
        else
        {
            cout << "Can't open database" << endl;

        }
    }
    catch (const std::exception& e) {
        cerr << e.what() << std::endl;

    }
    guest.guest_menu();
}
int search1::room_rent()
{
    char c1;

    try
    {
        connection C("dbname = hotel_rentel_management_system user = postgres password = qwerty port = 5432");
        if (C.is_open())
        {


            do
            {

                system("CLS");
                cout << setw(60) << "**********************************************" << endl;
                cout << setw(60) << "*               SEARCHING ROOMS              *" << endl;
                cout << setw(60) << "*           ACCORDING TO PRICE RANGE         *" << endl;
                cout << setw(60) << "**********************************************" << endl;
                cout << endl << endl;

                int room_rent, room_rent1, t = 1;

                cout << "Enter The Minimum Price of Room to Search :"; cin >> room_rent;
                cout << "Enter The Maximum Price of Room to Search :"; cin >> room_rent1;


                std::string sql = " select Room_Number , Room_type, floor_number,room_rent,occupied_status from hotel_rooms_info where room_rent >= (" + std::to_string(room_rent) + ") and room_rent <=(" + std::to_string(room_rent1) + ")";
                work W(C);
                cout << endl << endl;
                cout << "Room Details according to Price of a Room:" << endl << endl;


                cout << "=====================================================================================================" << endl;
                cout << "|S.No      |  ROOM_NUMBER  |       ROOM_TYPE      |     FLOOR_NUMBER |   ROOM_RENT  |OCCUPIED STATUS|" << endl;
                cout << "=====================================================================================================" << endl;
                result R(W.exec(sql));
                for (result::const_iterator c = R.begin(); c != R.end(); ++c) {
                    cout << "|" << t << "\t   |\t" << c[0].as<int>() << "\t   |\t" << setw(10) << c[1].as<string>() << "\t  |\t" << c[2].as<string>() << "\t     |" << " \t" << c[3].as<int>() << "\t    |" << setw(8) << c[4].as<string>() << "\t    |" << endl;
                    t++;
                }
                cout << "-----------------------------------------------------------------------------------------------------" << endl;

                W.commit();
                cout << endl << endl;
                cout << "Do you want to you continue to Search again... press [y/n]";
                cin >> c1;
            } while (c1 == 'y');
        }
        else
        {
            cout << "Can't open database" << endl;

        }
    }
    catch (const std::exception& e) {
        cerr << e.what() << std::endl;

    }

    guest.guest_menu();
}

int search1::vacancy()
{
    char c1;
    try
    {
        connection C("dbname = hotel_rentel_management_system user = postgres password = qwerty port = 5432");
        if (C.is_open())
        {
            int t = 1;


            do
            {

                system("CLS");
                cout << setw(60) << "**********************************************" << endl;
                cout << setw(60) << "*             SEARCHING VACANT ROOMS         *" << endl;
                cout << setw(60) << "**********************************************" << endl;
                cout << endl << endl;



                std::string sql = " select Room_Number,room_type,Floor_Number,Room_rent from hotel_rooms_info where occupied_status = 'No'";
                work W(C);
                cout << endl << endl;



                cout << "=====================================================================================" << endl;
                cout << "|S.No      |  ROOM_NUMBER  |       ROOM_TYPE      |     FLOOR_NUMBER |   ROOM_RENT  |" << endl;
                cout << "=====================================================================================" << endl;
                result R(W.exec(sql));
                for (result::const_iterator c = R.begin(); c != R.end(); ++c) {
                    cout << "|" << t << "\t   |\t" << c[0].as<int>() << "\t   |\t" << setw(10) << c[1].as<string>() << "\t  |\t" << c[2].as<string>() << "\t     |" << " \t" << c[3].as<int>() << "\t    |" << endl;
                    t++;
                }
                cout << "-------------------------------------------------------------------------------------" << endl;

                W.commit();
                cout << "Do you want to you continue to Search again... press [y/n]";
                cin >> c1;
            } while (c1 == 'y');
        }
        else
        {
            cout << "Can't open database" << endl;

        }
    }
    catch (const std::exception& e) {
        cerr << e.what() << std::endl;

    }     guest.guest_menu();


}