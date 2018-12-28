set(OPENLDAP_LIBRARIES
    ldap
    lber
)

add_executable(test_global_option test_global_option.cpp)
target_link_libraries(test_global_option
    ${OPENLDAP_LIBRARIES}
)

add_executable(test_handle_option test_handle_option.cpp)
target_link_libraries(test_handle_option
    ${OPENLDAP_LIBRARIES}
)
