#include <iostream>

#define TRACE_FUNCTION_CALL(){                                      \
    std::cout << "Inside:  " << __PRETTY_FUNCTION__ << std::endl;   \
}

#define TRACED_LOCAL_SCOPE(name)                                    \
    for(auto flag = true;                                           \
        flag and std::cout << "Scope Begin (" << name << ") {\n";   \
        flag = false,                                               \
        std::cout << "} End Scope\n\n" << std::endl)

struct Base {
    Base() {
        TRACE_FUNCTION_CALL();
    }
    ~Base() {
        TRACE_FUNCTION_CALL();
    }
};

struct Derived : public Base {
    Derived() {
        TRACE_FUNCTION_CALL();
    }
    ~Derived() {
        TRACE_FUNCTION_CALL();
    }
};

struct BaseWrapper {
    const Base &b;
};

struct DerivedWrapper {
    const Derived &d;
    DerivedWrapper(): d{} {
        TRACE_FUNCTION_CALL();
    }
    ~DerivedWrapper() {
        TRACE_FUNCTION_CALL();
    }
};

namespace {

const Base &FunctionException3(const Base &b) {
    TRACE_FUNCTION_CALL();
    return b;
}

const Base &FunctionException1() {
    TRACE_FUNCTION_CALL();
    return Base{};
}

}//namespace

int main() {
    TRACED_LOCAL_SCOPE("a temporary") {
        Base{};
        TRACE_FUNCTION_CALL();
    }

    TRACED_LOCAL_SCOPE("const lvalue reference") {
        const auto &b = Base{};
        TRACE_FUNCTION_CALL();
    }

    TRACED_LOCAL_SCOPE("rvalue reference") {
        auto &&b = Base{};
        TRACE_FUNCTION_CALL();
    }

    TRACED_LOCAL_SCOPE("Derived") {
        const Base &b = Derived{};
        TRACE_FUNCTION_CALL();
    }

    TRACED_LOCAL_SCOPE("Exception 1") {
        const auto &b = FunctionException1();
        TRACE_FUNCTION_CALL();
    }

    TRACED_LOCAL_SCOPE("Exception 2") {
        DerivedWrapper dw;
        TRACE_FUNCTION_CALL();
    }

    TRACED_LOCAL_SCOPE("Exception 3") {
        const auto &b = FunctionException3({});
        TRACE_FUNCTION_CALL();
    }

    TRACED_LOCAL_SCOPE("Exception 4") {
        auto *w = new BaseWrapper{{}};
        TRACE_FUNCTION_CALL();
        delete w;
    }

    TRACED_LOCAL_SCOPE("Special Case") {
        BaseWrapper w{{}};
        TRACE_FUNCTION_CALL();
    }
}
