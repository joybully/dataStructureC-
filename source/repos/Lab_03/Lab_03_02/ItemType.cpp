// ItemType.cpp is the implementation file for data for the real 
//  estate manipulation program.
#include "ItemType.h"
void HouseType::GetFromFile(std::ifstream& file)
{
    lastName.GetStringFile(true, NOT_NEW, file);
    firstName.GetStringFile(true, NOT_NEW, file);
    address.GetStringFile(true, NOT_NEW, file);
    file >> price >> squareFeet >> bedRooms>>bathRooms;
}

void HouseType::WriteToFile(std::ofstream& file)
{
    using std::endl;
    lastName.PrintToFile(false, file);
    firstName.PrintToFile(true, file);
    address.PrintToFile(true, file);
    file << endl << price << endl;
    file << squareFeet << endl;
    file << bedRooms << endl;
    file << bathRooms << endl;
}

void HouseType::GetFromUser()
{
    using namespace std;
    cout << "Enter last name; press return." << endl;
    lastName.GetString(true, NOT_NEW);
    cout << "Enter first name; press return." << endl;
    firstName.GetString(true, NOT_NEW);
    cout << "Enter address; press return." << endl;
    address.GetString(true, NOT_NEW);
    cout << "Enter price, square feet, number of bedrooms, number of bathrooms;"
        << " press return." << endl;
    cin >> price >> squareFeet >> bedRooms>>bathRooms;
}

void HouseType::PrintHouseToScreen()
{
    using namespace std;
    firstName.PrintToScreen(false);
    cout << " ";
    lastName.PrintToScreen(false);
    address.PrintToScreen(true);
    cout << endl << "Price: " << price << endl;
    cout << "Square Feet: " << squareFeet << endl;
    cout << "Bedrooms: " << bedRooms << endl;
    cout << "Bathrooms: " << bathRooms << endl;
}

void HouseType::GetNameFromUser()
{
    using namespace std;
    cout << "Enter last name;  press return." << endl;
    lastName.GetString(true, NOT_NEW);
    cout << "Enter first name;  press return." << endl;
    firstName.GetString(true, NOT_NEW);
}

void HouseType::PrintNameToScreen()
{
    using namespace std;
    firstName.PrintToScreen(false);
    cout << " ";
    lastName.PrintToScreen(false);
    cout << endl;
}

RelationType HouseType::ComparedTo(HouseType house)
{
    if (*this==house)
        return EQUAL;
    else if (*this < house)
        return LESS;
    else
        return GREATER;
}

//void HouseType::operator=(const HouseType& otherHouse)
//{   
//    lastName = otherHouse.lastName;
//    firstName = otherHouse.firstName;
//    address = otherHouse.address;
//    price = otherHouse.price;
//    squareFeet = otherHouse.squareFeet;
//    bedRooms = otherHouse.bedRooms;
//    bathRooms = otherHouse.bathRooms;
//}

bool HouseType::operator==(HouseType otherHouse) const
{
    if (lastName == otherHouse.lastName && firstName == otherHouse.firstName)
        return true;
    else
        return false;
}

bool HouseType::operator<(HouseType otherHouse) const
{
    if (lastName < otherHouse.lastName)
        return true;
    else if (otherHouse.lastName < lastName)
        return false;
    else if (firstName < otherHouse.firstName)
        return true;
    else if (otherHouse.firstName < firstName)
        return false;
    else return false;
}