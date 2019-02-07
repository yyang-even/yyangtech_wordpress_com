#include <iostream>

#define TRACE_FUNCTION_CALL(){                                      \
    std::cout << "Inside:  " << __PRETTY_FUNCTION__ << std::endl;  \
}

#define TRACED_LOCAL_SCOPE()                        \
    for(auto flag = true;                           \
        flag and std::cout << "Scope Begin {\n";    \
        flag = false,                               \
        std::cout << "} End Scope\n\n" << std::endl)

struct Base {
    Base() {
        TRACE_FUNCTION_CALL();
    }
    ~Base() {
        TRACE_FUNCTION_CALL();
    }
};

namespace {

void FunctionBase(const Base &) {
    TRACE_FUNCTION_CALL();
}

void FunctionVoid(void) {
    TRACE_FUNCTION_CALL();
}

}//namespace

int main() {
    TRACED_LOCAL_SCOPE() {
        FunctionBase({});
        TRACE_FUNCTION_CALL();
    }

    TRACED_LOCAL_SCOPE() {
        Base{};
        FunctionVoid();
        TRACE_FUNCTION_CALL();
    }

    TRACED_LOCAL_SCOPE() {
        const auto &b = Base{};
        FunctionVoid();
        TRACE_FUNCTION_CALL();
    }

    TRACED_LOCAL_SCOPE() {
        auto &&b = Base{};
        FunctionVoid();
        TRACE_FUNCTION_CALL();
    }
}
