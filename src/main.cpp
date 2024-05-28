#include <iostream>
#include <string>

struct contact_stru {
  std::string first_name;
  std::string last_name;
  int age;
};

void ListCommands() {
  std::cout << "l -> Alle Kontakte auflisten" << std::endl;
  std::cout << "n -> Neuen Kontakt erstellen" << std::endl;
  std::cout << "d -> Kontakt löschen" << std::endl;
  std::cout << "e -> Kontakt bearbeiten" << std::endl;
  std::cout << "h -> Hilfe anzeigen" << std::endl;
  std::cout << "q -> Programm beenden" << std::endl;
}

void handle_list_command() { std::cout << "List betätigt" << std::endl; }
void handle_new_command() { std::cout << "New betätigt" << std::endl; }
void handle_delete_command() { std::cout << "Delete betätigt" << std::endl; }
void handle_edit_command() { std::cout << "Edit betätigt" << std::endl; }

int main() {

  std::cout << "Willkommen zum Kontaktplaner :)" << std::endl
            << "Folende Aktionen können durchgeführt werden:" << std::endl;
  ListCommands();

  bool bBeenden = false;
  char cInput = '\0';
  do {
    std::cin >> cInput;

    switch (cInput) {
    case 'l': {
      handle_list_command();
      break;
    }
    case 'n': {
      handle_new_command();
      break;
    }
    case 'd': {
      handle_delete_command();
      break;
    }
    case 'e': {
      handle_edit_command();
      break;
    }
    case 'h': {
      ListCommands();
      break;
    }
    case 'q': {
      bBeenden = true;
      break;
    }
    }
  } while (!bBeenden);

  std::cout << "Programm beendet..." << std::endl;

  return 0;
}
