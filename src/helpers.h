#pragma once
#include "contacts_stru.h"
#include <vector>

void list_contacts(std::vector<contact_stru *> &arrContacts);
std::string get_firstname();
std::string get_lastname();
int get_age();

int get_contact_index(std::vector<contact_stru *> &arrContacts);
int get_field_id();
std::string get_new_field_value();
