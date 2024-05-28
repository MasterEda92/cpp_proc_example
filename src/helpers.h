#pragma once
#include "contacts_stru.h"
#include <vector>

void list_contacts(std::vector<contact_stru *> &arrContacts);
std::string get_firstname();
std::string get_lastname();
int get_age();
std::string get_phonenr();

int get_contact_index(std::vector<contact_stru *> &arrContacts);
int get_field_id();
std::string get_new_field_value();

contact_stru *get_contact_from_csv_string(std::string strCsv);
std::string get_csv_string_from_contact(contact_stru *pContact);
