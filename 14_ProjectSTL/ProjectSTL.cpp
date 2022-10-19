#include <iostream>
#include "Phonebook.h"


int main()
{
    Phonebook book{};

    book.AddContact({ "Andrew", "Red","","","","","Ab",EGroup::Friends });
    book.AddContact({ "Lucia", "Greenas","","","","","Ab",EGroup::Family });
    book.AddContact({ "Sarah", "Brown","","","","","Glo",EGroup::Coworker });
    book.AddContact({ "Bob", "Ali","","","","","Za",EGroup::Acquaintance });
    book.AddContact({ "Lucia", "Zok","","","","","Ka",EGroup::Acquaintance });
    book.AddContact({ "Anjela", "Mani","","","","","Ka",EGroup::Acquaintance });
    book.AddContact({ "Leya", "Ki","","","","","La",EGroup::Acquaintance });
    book.AddContact({ "Alex", "Ha","","","","","La",EGroup::Friends });
    book.AddContact({ "Yarik", "Chi","","","","","La",EGroup::Friends });
    book.AddContact({ "Den", "Ro","","","","","La",EGroup::Friends });
    book.AddContact({ "Ru", "Kr","","","","","Ab",EGroup::Family });
    book.AddContact({ "Na", "Kr","","","","","Ab",EGroup::Family });
    book.AddContact({ "Ni", "Kr","","","","","Ac",EGroup::Family });
    book.AddContact({ "Ig", "Ka","","","","","Glo",EGroup::Coworker });
    book.AddContact({ "Yur", "Ne","","","","","Glo",EGroup::Coworker });
    book.DisplayAllContacts();

    book.SortContacts(EFilterType::FirstName, ESortOrder::AZ);
    std::cout << "After sorting :" << std::endl;
    book.DisplayAllContacts();

    std::cout << "Display Name and Phone :" << std::endl;
    book.DisplayAllContacts(EDisplayMode::FirstNamePhone);

    auto SelectedGroup = EGroupToString(EGroup::Family);
    std::cout << "Contacts by group : " << SelectedGroup << std::endl;
    auto book2 = book.GetContactsByTypeName(EFilterType::Group, SelectedGroup);
    book2.DisplayAllContacts(EDisplayMode::FullNameCompanyGroup);
    std::cout << "Num contacts with group " << SelectedGroup << " : " << book2.GetRecordsCount() << std::endl;

    std::string Name{ "DeN" };
    auto SearchedContact = book.GetContactByName(Name);
    SearchedContact.DisplayInfo(EDisplayMode::Full);

    Name = "Kr";
    SearchedContact = book.GetContactByName(Name, false);
    SearchedContact.DisplayInfo(EDisplayMode::Full);

    std::string SelectedCompanyName{"Glo"};
    std::cout << "Contacts by company " << SelectedCompanyName << ":" << std::endl;
    auto book3 = book.GetContactsByTypeName(EFilterType::Company, SelectedCompanyName);
    book3.DisplayAllContacts(EDisplayMode::FullNameCompanyGroup);
    std::cout << "Num contacts with company " << SelectedCompanyName << " : " << book3.GetRecordsCount() << std::endl;

    book.DisplayAllContacts();
    Name = "Den";
    book.RemoveContact(Name);
    std::cout << "After deletion :" << std::endl;
    book.DisplayAllContacts();
}
