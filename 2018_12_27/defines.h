#pragma once

#include "ldap_connection.h"

const std::string URI = "ldap://";
const std::string BASE = "dc=yyangtech,dc=wordpress,dc=com";
const auto SCOPE = LDAP_SCOPE_BASE;
const auto DEBUG_LEVEL = -1;
