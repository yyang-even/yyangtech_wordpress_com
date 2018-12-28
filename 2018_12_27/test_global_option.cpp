#include "defines.h"

int main(int argc, char **argv) {
    // DEBUG_LEVEL only works with Global.
    //ber_set_option(nullptr, LBER_OPT_DEBUG_LEVEL, &DEBUG_LEVEL);
    ldap_set_option(nullptr, LDAP_OPT_DEBUG_LEVEL, &DEBUG_LEVEL);

    LdapConnection ldap = {URI};
    ldap.Search(BASE, SCOPE);
}
