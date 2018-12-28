#include "defines.h"

int main(int argc, char **argv) {
    LdapConnection ldap = {URI};

    //ldap.BerSetOption(LBER_OPT_DEBUG_LEVEL, &DEBUG_LEVEL);
    ldap.LdapSetOption(LDAP_OPT_DEBUG_LEVEL, &DEBUG_LEVEL);

    ldap.Search(BASE, SCOPE);
}
