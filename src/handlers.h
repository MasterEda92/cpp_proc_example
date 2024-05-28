#pragma once

#include "contacts_stru.h"
#include <vector>

void handle_list_command(std::vector<contact_stru *> &arrContacts);
void handle_new_command(std::vector<contact_stru *> &arrContacts);
void handle_delete_command(std::vector<contact_stru *> &arrContacts);
void handle_edit_command(std::vector<contact_stru *> &arrContacts);
void handle_save_command(std::vector<contact_stru *> &arrContacts);
void handle_load_command(std::vector<contact_stru *> &arrContacts);
