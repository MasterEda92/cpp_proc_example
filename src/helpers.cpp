#include "helpers.h"
#include "contacts_stru.h"
#include <iostream>
#include <sstream>
#include <string>

void list_contacts(std::vector<contact_stru *> &arrContacts) {
  int nNr = 1;
  for (auto &it : arrContacts) {
    std::cout << "Nr. " << nNr << "; ";
    std::cout << "Vorname: " << it->first_name << "; ";
    std::cout << "Nachname: " << it->last_name << "; ";
    std::cout << "Alter: " << it->age << "; ";
    std::cout << "Telefonnummer: " << it->phone_nr << std::endl;
    ++nNr;
  }
  if (arrContacts.size() == 0)
    std::cout << "Die Kontaktliste ist momentan leer." << std::endl;
}

std::string get_firstname() {
  std::cout << "Bitte geben Sie den Vornamen ein:";
  std::string first_name;
  std::getline(std::cin, first_name);
  return first_name;
}

std::string get_lastname() {
  std::cout << "Bitte geben Sie den Nachnamen ein:";
  std::string last_name;
  std::getline(std::cin, last_name);
  return last_name;
}

int get_age() {
  std::cout << "Bitte geben Sie das Alter ein:";
  std::string strAge;
  std::getline(std::cin, strAge);
  int nAge = std::stoi(strAge);
  return nAge;
}

std::string get_phonenr() {
  std::cout << "Bitte geben Sie die Telefonnummer ein:";
  std::string phone_nr;
  std::getline(std::cin, phone_nr);
  return phone_nr;
}

int get_contact_index(std::vector<contact_stru *> &arrContacts) {
  int nNrToDelete = -1;

  do {
    std::string strInput;
    std::getline(std::cin, strInput);
    nNrToDelete = std::stoi(strInput);

    if (nNrToDelete < 0) {
      return -1;
    }
    if (nNrToDelete > arrContacts.size())
      std::cout << "Die eingegebene Nummer ist zu groß, bitte geben Sie eine "
                   "korrekte Nummer ein."
                << std::endl;
  } while (nNrToDelete > arrContacts.size());

  return nNrToDelete;
}

int get_field_id() {
  std::cout << "Geben Sie die Nummer des Feldes ein, dass geändert werden soll:"
            << std::endl;

  std::cout << "1 - Vorname" << std::endl;
  std::cout << "2 - Nachname" << std::endl;
  std::cout << "3 - Alter" << std::endl;
  std::cout << "4 - Telefonnummer" << std::endl;

  int nFeldId = -1;
  do {
    std::string strInput;
    std::getline(std::cin, strInput);
    nFeldId = std::stoi(strInput);
    if (nFeldId < 1)
      return -1;

    if (nFeldId > 4)
      std::cout << "Das eingegebene Feld ist ungültig. Bitte geben Sie eine "
                   "korrekte Nummer ein."
                << std::endl;
  } while (nFeldId < 1 && nFeldId > 4);

  return nFeldId;
}

std::string get_new_field_value() {
  std::cout << "Geben Sie den neuen Wert für das Feld ein:" << std::endl;
  std::string strNewValue = "";
  std::getline(std::cin, strNewValue);

  return strNewValue;
}

contact_stru *get_contact_from_csv_string(std::string strCsv) {
  std::istringstream ss(strCsv);
  std::string token;

  std::string first_name, last_name, age, phone_nr;
  int nCounter = 0;
  while (std::getline(ss, token, ';')) {
    switch (nCounter) {
    case 0:
      first_name = token;
      break;
    case 1:
      last_name = token;
      break;
    case 2:
      age = token;
      break;
    case 3:
      phone_nr = token;
      break;
    default:
      break;
    }
    ++nCounter;
  }
  contact_stru *pContact = new contact_stru;
  pContact->first_name = first_name;
  pContact->last_name = last_name;
  pContact->age = std::stoi(age);
  pContact->phone_nr = phone_nr;

  return pContact;
}

std::string get_csv_string_from_contact(contact_stru *pContact) {
  std::ostringstream oss;
  oss << pContact->first_name << ";" << pContact->last_name << ";"
      << pContact->age << ";" << pContact->phone_nr;

  return oss.str();
}
