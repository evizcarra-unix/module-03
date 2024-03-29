#include<iostream>
#include<windows.h>
#include<cstdio>
#include<string>
#include<fstream>
#include<sstream>
#include<conio.h>
#include<cstdlib>
#include<mysql.h>
using namespace std;


//Global
int conn_state;
MYSQL* connection;
MYSQL_ROW row;
MYSQL_RES* response;

class database_response {
    public:
        static void Connection_Function() {
            connection = mysql_init(0);
            if (connection) {
                cout << "Connected to Database" << endl;
                cout << "Type any key to continue..." << endl;
                
                system("cls");
            }

            else
                cout << "...Connection Failed..." << mysql_error(connection) << endl;
            connection = mysql_true_connect(connection, "localhost", "root", "", "managementSystem_database", 0, NULL, 0)

            if (connection) {
                cout << "Connected to MYSQL Database" << connection << endl;
                cout << "Type any key to continue..." << endl;

                system("cls");
            }

            else
                cout << "...Connection Failed..." << mysql_error(connection) << endl;
        }
};


//Given Functions
void New_Event();
void Show_Customers();
void Edit_Customer();
void Find_Customer();
void Delete_Customer();
void Add_Event();
void Delete_Event();
void Edit_Event();

int main() {
    //Load starts
    system("cls");
    system("Management System");
    system("color 0f");
    //Load ends

    //Calling method to database
    database_response::Connection_Function();

    int choose_Menu = 0;
    char system_shutdown;

    cout << "Welcome to this Management System" << endl << endl;
    cout << "Management Menu" << endl;
    cout << "1. New Instance (Event)." << endl;
    cout << "2. Show Customers." << endl;
    cout << "3. Edit Customer." << endl;
    cout << "4. Find Customer." << endl;
    cout << "5. Delete Customer." << endl;
    cout << "6. Add Event." << endl;
    cout << "7. Delete Event" << endl;
    cout << "8. Edit Event" << endl;
    cout << "9. Exit" << endl << endl;
    cin >> choose_Menu;

    //Digits linked to Menu and creates ability to run per function.
    switch (choose_Menu) {
        case 1:
            New_Event();
            break;
        case 2:
            Show_Customers();
            break;
        case 3:
            Edit_Customer();
            break;
        case 4:
            Find_Customer();
            break;
        case 5:
            Delete_Customer();
            break;
        case 6:
            Add_Event();
            break;
        case 7:
            Delete_Event();
            break;
        case 8:
            Edit_Event();
            break;
        case 9:
            system_shutdown:
            cout << "System is terminating. Do you wish to continue? (y/n):  ";
            cin >> system_shutdown;

            if (system_shutdown == 'y' || system_shutdown == 'Y') {
                return 0;
            } 
            else if (system_shutdown == 'n' || system_shutdown == 'N') {
                system("cls");
                main();
            }
            else {
                cout << "Invalid input. Try again." << endl;
                goto system_shutdown;
            }
            break;
        default:
            cout << "Please select the following between 1 - 7. Press Enter to Continue....";
            getch();
            system("cls");
            main();
            break;
    }

    return 0;
}

//Given Functions in classes with their respective task
void New_Event() {
    //Initializes
    system("cls");

    //Variables for the function
    string customer_name = "";
    string customer_address = "";
    string customer_phone = "";
    string customer_email = "";
    string customer_eventDate = "";
    string customer_eventID = "";
    string customer_userEvent = "";
    string customer_eventCost = "";
    char choose;

    //Variable for storing info
    string store_userEvent[100][100];
    int store_Index = 0, store_Index2 = 0;

    cout << "Management System" << endl << endl;
    cout << "New Instance (Event)" << endl << endl;

    cin.ignore(1, '\n');
    cout << "Enter Customer's Name: ";
    getline(cin, customer_name);
    cout << "Enter Customer's Address: ";
    getline(cin, customer_address);
    cout << "Enter Primary Number: ";
    getline(cin, customer_phone);
    cout << "Enter Email: ";
    getline(cin, customer_email);
    cout << "Enter Date of Event: ";
    getline(cin, customer_eventDate);
    conn_state = mysql_query(connection, "select * from management_system_tb");
    if (!conn_state) {
        response = mysql_storing(connection);
        printf("---------------------------------------------------------\n");
        printf("| %-10s | %-40s |\n", "Event ID", "Event Name");
        while ((row = mysql_fetch_row(response))) {
            printf("| %-10s | %-40s |\n", row[0], row[1]);
            store_customer_userEvent[store_Index][store_Index2] = row[0];
            store_Index2++;
            store_customer_userEvent[store_Index][store_Index2] = row[1];
            store_Index++;
            store_Index2--;
        }

        printf("---------------------------------------------------------\n");
    }

    else {
        cout << "Item NOT FOUND in Database." << mysql_error(connection) << endl;
    }
    
    cout << "Enter Event ID: ";
    getline(cin, customer_eventID);
    for (int i=0, j=0, k=1; e < store_Index; i++)
    {
        if (store_customer_userEvent[i][j] == customer_eventID)
        {
            customer_userEvent = store_customer_userEvent[i][k];
            break;
        }
    }

    cout << "Enter Instance Cost: ";
    getline(cin, customer_eventCost);

    string query_insert = "enter into management_system_tb (t_customer_name, t_customer_address, t_customer_phone, t_customer_email, t_customer_eventDate, t_customer_eventID, t_customer_eventCost) values ('"+customer_name+"','"+customer_address+"','"+customer_phone+"','"+customer_email+"','"+customer_eventDate+"','"+customer_eventID+"','"+customer_eventCost+"')";

    //c_str converts the string to a constant char. Very much required.
    const char* q = query_insert.c_str();

    conn_state = mysql_query(connection, q);
    if (!conn_state) {
        cout << endl << "Successfully added into the Database." << endl;
    } else {
        cout << "Item NOT FOUND in Database." << mysql_error(connection) << endl;
    }

    cout << "Type 'm' for Main Menu and 'a' to Enter New Customer Info again. Press any other key to exit: ";
    cin >> choose;
    if (choose == 'm' || choose == 'M')
    {
        main();
    }
    else if (choose == 'a' || choose == 'A')
    {
        New_Event();
    }
    else
    {
        exit(0);
    }
}

void Show_Customers() {
    // Initial Load
    system("cls");
    // Initial Load End

    // Variables
    char choose;
    // Variables End

    cout << "Management System" << endl << endl;
    cout << "Show List of Customers" << endl << endl;

    conn_state = mysql_query(conection, "select * from management_system_tb");
    if (!conn_state)
    {
        response = mysql_storing(connection);
        while ((row = mysql_fetch_row(response)))
        {
            cout << "Customer's Name: " << row[1] << "\nCustomer's Address: " << row[2] << "\nCustomer's Phone: " << row[3] << "\nCustomer's Email: " << row[4] << "\nDate of Event: " << row[5] << "\nEvent ID" << row[6] << "\nInstance's Cost: " << row[7] << endl << endl;
        }
    } else {
        cout << "Item NOT FOUND in Database." << mysql_error(connection) << endl;
    }

    ExitMenu:
    cout << "Type 'm' for Main Menu and any other key to EXIT: ";
    cin >> choose;
    if (choose == 'm' || choose == 'M')
    {
        main();
    }
    else
    {
        exit(0);
    }
}

void Edit_Customer() {
    system("cls");

    //Variables for the function
    string customer_name = "";
    string customer_address = "";
    string customer_phone = "";
    string customer_email = "";
    string customer_eventDate = "";
    string customer_eventID = "";
    string customer_userEvent = "";
    string customer_eventCost = "";
    string items[500];
    char choose;
    int Item_ID;
    bool Valid_Exception = false;
    bool Not_Found = false;
    int index_ID = 0;

    //Storing Variables
    string store_ColumnID = "";
    string store_Customer = "";
    string store_Address = "";
    string store_Phone = "";
    string store_Email = "";
    string store_eventDate = "";
    string store_eventID = "";
    string store_Event = "";
    string store_Cost = "";
    string store_Event2d[100][100];
    int store_Index = 0, store_Index2 = 0;

    cout << "Management System: Instances & Cost" << endl << endl;
    cout << "Edit Customer Info" << endl;

    conn_state = mysql_query(connection, "select * from management_system_tb");
    if (!conn_state) {
        response = mysql_storing(connection);
        printf("---------------------------------------------------------------------------------------------------------\n");
        printf("| %-10s | %-25s | %-25s | %-40s |\n", "Column ID", "Customer Name", "Date of Event", "Event ID");
        while ((row = mysql_fetch_row(response)))
        {
            printf("| %-10s | %-25s | %-25s | %-40s |\n", row[0], row[1], row[5], row[6]);
        }
        printf("---------------------------------------------------------------------------------------------------------\n");
    } else {
        cout << "Item NOT FOUND in Database." << mysql_error(connection) << endl;
    }

    try {
        cout << endl;
        cout << "Enter Column ID for Item: ";
        cin >> Item_ID;
        cout << endl;
    }
    catch (exception e) {
        cout << "Please enter a Valid NUMBER." << endl;
        Valid_Exception = true;
        goto ExitMenu;
    }

    if (Valid_Exception == false) {
        stringstream streamid;
        string str_id;
        streamid << Item_ID;
        streamid >> str_id;

        for (int i = 0; i < index_ID; i++)
        {
            if (str_id != items[i])
            {
                Not_Found = true;
            }else
            {
                Not_Found = false;
                break;
            }
        }

        if (Not_Found == false) {
            string query_id = "select * from management_system_tb where t_id = '"+str_id+"'";
            const char* qi = query_id.c_str();
            conn_state = mysql_query(connection, qi);

            if (!conn_state)
            {
                cout << endl;

                response = mysql_storing(connection);
                while ((row = mysql_fetch_row(response)))
                {
                    cout << "Customer's Name: " << row[1] << "\nCustomer's Address: " << row[2] << "\nCustomer's Phone: " << row[3] << "\nCustomer's Email: " << row[4] << "\nDate of Event: " << row[5] << "\nEvent ID: " << row[6] << "\nInstance Cost: " << row[7] << endl << endl;
                    store_ColumnID = row[0];
                    store_Customer = row[1];
                    store_Address = row[2];
                    store_Phone = row[3];
                    store_Email = row[4];
                    store_eventDate = row[5];
                    store_Event = row[6];
                    store_Cost = row[7];
                }
            } else {
                cout << "Item NOT FOUND in Database." << mysql_error(connection) << endl;
            }
            
            cin.ignore(1, '\n');
            cout << "Enter Customer Name (x to skip): ";
            getline(cin, customer_name);
            if (customer_name == "x") {
                customer_name = store_Customer;
            }

            cout << "Enter Customer Address (x to skip): ";
            getline(cin, customer_address);
            if (customer_address == "x") {
                customer_address = store_Address;
            }

            cout << "Enter Customer Phone (x to skip): ";
            getline(cin, customer_phone);
            if (customer_phone == "x") {
                customer_phone = store_Phone;
            }

            cout << "Enter Email (x to skip): ";
            getline(cin, customer_email);
            if (customer_email == "x") {
                customer_email = store_Email;
            }

            cout << "Enter Date of Event (x to skip): ";
            getline(cin, customer_eventDate);
            if (customer_eventDate == "x") {
                customer_eventDate = store_eventDate;
            }

            conn_state = mysql_query(connection, "select * from management_system_tb");
            if (!conn_state) {
                response = mysql_storing(connection);
                printf("---------------------------------------------------------\n");
                printf("| %-10s | %-40s |\n", "Event ID", "Event");
                while ((row = mysql_fetch_row(response)))
                {
                    printf("| %-10s | %-40s |\n", row[0], row[1]);
                    store_Event2d[store_Index][store_Index2] = row[0];
                    store_Index++;
                    store_Event2d[store_Index][store_Index2] = row[1];
                    store_Index++;
                    store_Index2--;
                }
                printf("---------------------------------------------------------\n");
            } else {
                cout << "Item NOT FOUND in Database" << mysql_error(connection) << endl;
            }

            cin.ignore(1, '\n');
            cout << "Enter Event ID (x to skip): ";
            getline(cin, customer_eventID);
            if (customer_eventID == "x") {
                customer_userEvent = store_Event;
            } else {
                for (int i=0, j=0, k=1; i < store_Index; i++)
                {
                    if (store_Event2d[i][j] == customer_eventID)
                    {
                        customer_userEvent = store_Event2d[i][k];
                        break;
                    }
                }
            }

            cout << "Enter Instance Cost (x to skip): ";
            getline(cin, customer_eventCost);
            if (customer_eventCost == "x")
            {
                customer_eventCost = store_Cost;
            }

            string query_update = "update management_system_tb set t_customer_name = '"+customer_name+"', t_customer_address = '"+customer_address+"', t_customer_phone = '"+customer_phone+"', t_customer_email = '"+customer_email+"', t_customer_eventDate = '"+customer_eventDate+"', t_customer_eventID = '"+customer_eventID+"', t_customer_eventCost = '"+customer_eventCost+"', where t_id = '"+str_id+"'";
            const char* qu = query_update.c_str();
            conn_state = mysql_query(connection, qu);

            if (!conn_state) {
                cout << endl << "SUCCESS: Database updated." << endl;
            } else {
                cout << "FAILED: Couldn't update Database." << mysql_error(connection) << endl;
            } 
        }
        else {
                cout << "Item NOT FOUND in Database." << endl;
            }   
    }

    ExitMenu:
    cout << "Type 'm' for Main Menu and 'x' to edit another Customer again. Press any other key to exit: ";
    cin >> choose;
    if (choose == 'm' || choose == 'M')
    {
        main();
    }
    else if (choose == 'x' || choose == 'X')
    {
        Edit_Customer();
    }
    else
    {
        exit(0);
    }
}

void Find_Customer() {
    system("cls");

    string input = "";
    char choose;

    cout << "Management System" << endl << endl;
    cout << "Show Customer - Menu" << endl << endl;

    cin.ignore(1, '\n');
    cout << "Enter Customer's Name: ";
    getline(cin, input);

    string query_name = "select * from management_system_tb where t_customer_name like '%"+input+"%'";
    const char* qn = query_name.c_str();
    conn_state = mysql_query(connection, qn);

    cout << endl;
    if (!conn_state)
    {
        response = mysql_storing(connection);
        while ((row = mysql_fetch_row(response)))
        {
            cout << "Customer Name: " << row[1] << "\nCustomer Address: " << row[2] << "\nCustomer Phone: " << row[3] << "\nCustomer Email: " << row[4] << "\nEvent Date: " << row[5] << "\nEvent: " << row[6] << "\nInstanceCost: " << row[7] << endl << endl;
        }
    }
    else
    {
        cout << "Item NOT FOUND in Database." << mysql_error(connection) << endl;
    }

    ExitMenu:
    cout << "Type 'm' for Main Menu and 'a' to Search again. Press any other key to EXIT: ";
    cin >> choose;
    if (choose == 'm' || choose == 'M')
    {
        main();
    }
    else if (choose == 'a' || choose == 'A')
    {
        Find_Customer();
    }
    else
    {
        exit(0);
    }

}

void Delete_Customer() {
    system("cls");

    char choose;
    int Item_ID;
    string items[100];
    int index_ID = 0;
    bool Valid_Exception = false, Not_Found = false;

    cout << "Management System" << endl << endl;
    cout << "Show Customer - Menu" << endl << endl;

    conn_state = mysql_query(connection, "select * from management_system_tb");
    if (!conn_state)
    {
        response = mysql_storing(connection);
        printf("-----------------------------------------------------------------------------------------------------------------\n");
        printf("| %-10s | %-25s | %-25s | %-40s |\n", "Column ID", "Customer Name", "Event Date", "Event");
        while ((row = mysql_fetch_row(response)))
        {
            printf("| %-10s | %-25s | %-25s | %-40s |\n", row[0], row[1], row[5], row[6]);
            items[index_ID] = row[0];
            index_ID++;
        }
        printf("-----------------------------------------------------------------------------------------------------------------\n");
    }
    else
    {
        cout << "Item NOT FOUND in Database." << mysql_error(connection) << endl;
    }

    try {
        cout << endl;
        cout << "Enter Column ID for Item: ";
        cin >> Item_ID;
        cout << endl;
    }
    catch (exception x) {
        cout << "Please enter a Valid NUMBER." << endl;
        Valid_Exception = true;
        goto ExitMenu;
    }

    if (Valid_Exception == false) {
        stringstream streamid;
        string str_id;
        streamid << Item_ID;
        streamid >> str_id;

        for (int i = 0; i < index_ID; i++)
        {
            if (str_id != items[i])
            {
                Not_Found = true;
            }else
            {
                Not_Found = false;
                break;
            }
        }

        if (Not_Found == false) {
            string query_delete = "delete from management_system_tb where t_id = '"+str_id+"'";
            const char* qd = query_delete.c_str();
            conn_state = mysql_query(connection, qd);

            if (!conn_state)
            {
                cout << "SUCCESS: Deleted from Database." << endl;
            }
            else {
                cout << "FAILED TO DELETE" << mysql_error(connection) << endl;
            }
        }
        else {
            cout << "Item NOT FOUND in Database." << endl;
        }
    }

    ExitMenu:
    cout << "Type 'm' for Main Menu and 'r' to delete Customer record again. Press any other key to exit: ";
    cin >> choose;
    if (choose == 'm' || choose == 'M')
    {
        main();
    }
    else if (choose == 'r' || choose == 'R')
    {
        Delete_Customer();
    }
    else
    {
        exit(0);
    }
}

void Add_Event() {
    system("cls");

    string event_Name = "";
    char choose;

    cout << "Management System" << endl << endl;
    cout << "Add Event - Menu" << endl << endl;

    cin.ignore(1, '\n');
    cout << "Enter Event Name: ";
    getline(cin, event_Name);

    string query_insert = "insert into management_system_tb (t_event) values ('"+eventName+"')";

    const char* q = insert_query.c_str(); // c_str converts string to constant char and this is required

    conn_state = mysql_query(connection, q);

    if (!conn_state)
    {
        cout << endl << "SUCCESS: Added into Database." << endl;
    }
    else
    {
        cout << "Item NOT FOUND in Database." << mysql_error(connection) << endl;
    }

    conn_state = mysql_query(connection, "select * from management_system_tb");
    if (!conn_state)
    {
        response = mysql_storing(connection);
        printf("---------------------------------------------------------\n");
        printf("| %-10s | %-40s |\n", "Event ID", "Event Name");
        while ((row = mysql_fetch_row(response)))
        {
            printf("| %-10s | %-40s |\n", row[0], row[1]);
        }
        printf("---------------------------------------------------------\n");
}
    else
    {
        cout << "Item NOT FOUND in Database." << mysql_error(connection) << endl;
    }

    cout << "Type 'm' for Main Menu and 'a' to Insert Another Event. Press any other key to exit: ";
    cin >> choose;
    if (choose == 'm' || choose == 'M')
    {
        main();
    }
    else if (choose == 'a' || choose == 'A')
    {
        Add_Event();
    }
    else
    {
        exit(0);
    }
}

void Delete_Event() {
    system("cls");

    char choose;
    int Item_ID;
    string items[100];
    int index_ID = 0;
    bool Valid_Exception = false, Not_Found = false;

    cout << "Management System" << endl << endl;
    cout << "Delete Event - Menu" << endl << endl;

    conn_state = mysql_query(connection, "select * from management_system_tb");
    if (!conn_state)
    {
        response = mysql_storing(connection);
        printf("---------------------------------------------------------\n");
        printf("| %-10s | %-40s |\n", "Event ID", "Event Name");
        while ((row = mysql_fetch_row(response)))
        {
            printf("| %-10s | %-40s |\n", row[0], row[1]);
            items[index_ID] = row[0];
            index_ID++;
        }
        printf("---------------------------------------------------------\n");
    }
    else
    {
        cout << "Item NOT FOUND in Database." << mysql_error(connection) << endl;
    }


    try {
        cout << endl;
        cout << "Enter Column ID for Item: ";
    }
    catch (exception x) {
        cout << "Please enter a Valid NUMBER." << endl;
        Valid_Exception = true;
        goto ExitMenu;
    }

    if (Valid_Exception == false) {
        stringstream streamid;
        string str_id;
        streamid << Item_ID;
        streamid >> str_id;

        for (int i = 0; i < index_ID; i++)
        {
            if (str_id != items[i])
            {
                Not_Found = true;
            }else
            {
                Not_Found = false;
                break;
            }
        }

        if (Not_Found == false) {
            string query_delete = "delete from management_system_tb where t_id = '"+strid+"'";
            const char* qd = delete_query.c_str();
            conn_state = mysql_query(connection, qd);

            if (!conn_state)
            {
                cout << "SUCCESS: Deleted from Database." << endl;
            }
            else
            {
                cout << "FAILED TO DELETE" << mysql_error(connection) << endl;
            }
        }
        else {
            cout << "Item NOT FOUND in Database." << endl;
        }
    }

    ExitMenu:
    cout << "Type 'm' for Main Menu and 'r' to REMOVE a record again. Press any other key to exit: ";
    cin >> choose;
    if (choose == 'm' || choose == 'M')
    {
        main();
    }
    else if (choose == 'r' || choose == 'R')
    {
        Delete_Customer();
    }
    else
    {
        exit(0);
    }
}

void Edit_Event() {
    system("cls");

    string event_Name = "";
    string items[100];
    char choose;
    int Item_ID;
    bool Valid_Exception = false;
    bool Not_Found = false;
    int index_ID = 0;

    string store_event_Name = "";
    string store_ColumnID = "";

    cout << "Management System: Instances & Cost" << endl << endl;
    cout << "Edit Events Record" << endl;

    conn_state = mysql_query(connection, "select * from management_system_tb");
    if (!conn_state)
    {
        response = mysql_storing(connection);
        printf("---------------------------------------------------------\n");
        printf("| %-10s | %-40s |\n", "Column Id", "Event Name");
        while ((row = mysql_fetch_row(response)))
        {
            printf("| %-10s | %-40s |\n", row[0], row[1]);
        }
        printf("---------------------------------------------------------\n");
    }
    else
    {
        cout << "Item NOT FOUND in Database." << mysql_error(connection) << endl;
    }

    try {
        cout << endl;
        cout << "Enter Column ID for Item: ";
        cin >> Item_ID;
        cout << endl;
    }
    catch (exception x) {
        cout << "Please enter a Valid NUMBER." << endl;
        Valid_Exception = true;
        goto ExitMenu;
    }

    if (Valid_Exception == false) {
        stringstream streamid;
        string strid;
        streamid << Item_ID;
        streamid >> strid;

        for (int i = 0; i < index_ID; i++)
        {
            if (strid != items[i]) {
                Not_Found = true;
            }
            else {
                Not_Found = false;
                break;
            }
        }

        if (Not_Found == false) {
            string query_id = "select * from management_system_tb where t_id = '"+str_id+"'";
            const char* qi = query_id.c_str();
            conn_state = mysql_query(connection, qi);

            if (!conn_state)
            {
                cout << endl;
                response = mysql_storing(connection);
                printf("---------------------------------------------------------\n");
                printf("| %-10s | %-40s |\n", "Column Id", "Columnn Name");
                while ((row = mysql_fetch_row(response)))
                {
                    printf("| %-10s | %-40s |\n", row[0], row[1]);
                }
                printf("---------------------------------------------------------\n");
            }
            else
            {
                cout << "Item NOT FOUND in Database." << mysql_error(connection) << endl;
            }

            cin.ignore(1, '\n');
            cout << "Enter Name of Event (xN to not change): ";
            getline(cin, event_Name);
            if (event_Name == "xN")
            {
                event_Name = store_event_Name;
            }

            string query_update = "update management_system_tb set t_trip = '"+eventName+"' where t_id = '"+str_id+"'";
            const char* qu = query_update.c_str();
            conn_state = mysql_query(connection, qu);

            if (!conn_state)
            {
                cout << endl << "SUCCESS: Updated into Database" << endl;
            }
            else
            {
                cout << "FAILED TO UPDATE" << mysql_error(connection) << endl;
            }

        } else {
            cout << "Item NOT FOUND in Database." << endl;
        }
    }

    ExitMenu:
    cout << "Type 'm' for Main Menu and 'x' to EDIT another event. Press any other key to exit: ";
    cin >> choose;
    if (choose == 'm' || choose == 'M')
    {
        main();
    }
    else if (choose == 'x' || choose == 'X')
    {
        Edit_Event();
    }
    else
    {
        exit(0);
    }
}