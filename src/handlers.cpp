#include "handlers.h"
#include "helpers.h"
#include <fstream>
#include <iostream>
#include <string>

void handle_list_command(std::vector<contact_stru *> &arrContacts) {
  list_contacts(arrContacts);
}

void handle_new_command(std::vector<contact_stru *> &arrContacts) {
  contact_stru *new_contact = new contact_stru;
  memset(new_contact, '\0', sizeof(contact_stru));

  new_contact->first_name = get_firstname();
  new_contact->last_name = get_lastname();
  new_contact->age = get_age();

  arrContacts.push_back(new_contact);
  std::cout << "Der Kontakt wurde neu angelegt." << std::endl;
}

void handle_delete_command(std::vector<contact_stru *> &arrContacts) {
  std::cout << "Geben Sie die Nummer des Kontakts ein, der gelöscht werden "
               "soll. (-1 für Abbrechen)"
            << std::endl;

  list_contacts(arrContacts);

  int nNrToDelete = get_contact_index(arrContacts);
  if (nNrToDelete < 1)
    return;

  delete arrContacts.at(nNrToDelete - 1);
  arrContacts.erase(arrContacts.begin() + (nNrToDelete - 1));
  std::cout << "Der Kontakt mit der Nummer " << nNrToDelete
            << " wurde gelöscht." << std::endl;
}

void handle_edit_command(std::vector<contact_stru *> &arrContacts) {
  std::cout << "Geben Sie die Nummer des Kontakts ein, der geändert werden "
               "soll. (-1 für Abbrechen)"
            << std::endl;

  list_contacts(arrContacts);

  int nNrToEdit = get_contact_index(arrContacts);
  if (nNrToEdit < 1)
    return;

  int nFeldId = get_field_id();
  if (nFeldId < 1) {
    return;
  }

  std::string strNewValue = get_new_field_value();

  switch (nFeldId) {
  case 1: {
    arrContacts.at(nNrToEdit - 1)->first_name = strNewValue;
    break;
  }
  case 2: {
    arrContacts.at(nNrToEdit - 1)->last_name = strNewValue;
    break;
  }
  case 3: {
    arrContacts.at(nNrToEdit - 1)->age = atoi(strNewValue.c_str());
    break;
  }
  }
  std::cout << "Der Kontakt mit der Nummer " << nNrToEdit << " wurde geändert."
            << std::endl;
}

void handle_save_command(std::vector<contact_stru *> &arrContacts) {
  std::string strFileName;
  std::cout << "Bitte geben Sie die Datei (mit Pfad) an in der die Kontakte "
               "gespeichert werden:"
            << std::endl;
  std::getline(std::cin, strFileName);

  std::ofstream contacts_file(strFileName);
  if (contacts_file.is_open()) {
    for (auto &it : arrContacts) {
      contacts_file << get_csv_string_from_contact(it) << std::endl;
    }
    contacts_file.close();
  }
  std::cout << "Kontakte wurde in die Datei " << strFileName << " geschrieben."
            << std::endl;
}

void handle_load_command(std::vector<contact_stru *> &arrContacts) {
  std::string strFileName;
  std::cout << "Bitte geben Sie die Datei (mit Pfad) an aus der die Kontakte "
               "geladen werden sollen:"
            << std::endl;
  std::getline(std::cin, strFileName);

  std::string line;
  std::ifstream contacts_file(strFileName);
  if (contacts_file.is_open()) {
    while (getline(contacts_file, line)) {
      arrContacts.push_back(get_contact_from_csv_string(line));
    }
    contacts_file.close();
  }
  std::cout << "Kontakte wurde aus der Datei " << strFileName << " geladen."
            << std::endl;
}
