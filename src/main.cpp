#include "handlers.h"
#include <iostream>
#include <string>
#include <vector>

void ListCommands() {
  std::cout << "l -> Alle Kontakte auflisten" << std::endl;
  std::cout << "n -> Neuen Kontakt erstellen" << std::endl;
  std::cout << "d -> Kontakt löschen" << std::endl;
  std::cout << "e -> Kontakt bearbeiten" << std::endl;
  std::cout << "h -> Hilfe anzeigen" << std::endl;
  std::cout << "q -> Programm beenden" << std::endl;
  std::cout << "s -> Kontakte speichern" << std::endl;
  std::cout << "i -> Kontakte importieren" << std::endl;
}

int main() {

  std::cout << "Willkommen zum Kontaktplaner :)" << std::endl
            << "Folende Aktionen können durchgeführt werden:" << std::endl;
  ListCommands();

  std::vector<contact_stru *> arrContacts;

  bool bBeenden = false;
  do {
    std::string strInput;
    std::getline(std::cin, strInput);

    switch (strInput.c_str()[0]) {
    case 'l': {
      handle_list_command(arrContacts);
      break;
    }
    case 'n': {
      handle_new_command(arrContacts);
      break;
    }
    case 'd': {
      handle_delete_command(arrContacts);
      break;
    }
    case 'e': {
      handle_edit_command(arrContacts);
      break;
    }
    case 'h': {
      ListCommands();
      break;
    }
    case 's': {
      handle_save_command(arrContacts);
      break;
    }
    case 'i': {
      handle_load_command(arrContacts);
      break;
    }
    case 'q': {
      bBeenden = true;
      break;
    }
    }
  } while (!bBeenden);

  // free memory
  for (auto &it : arrContacts) {
    delete it;
  }
  std::cout << "Programm beendet..." << std::endl;

  return 0;
}
