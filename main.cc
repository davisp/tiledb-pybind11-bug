#include <iostream>
#include <memory>

#include <pybind11/pybind11.h>

namespace py = pybind11;

struct Test {
 Test(const std::string& val) : val_(val) {}
 std::string val_;
};

class ErrorTest {
 public:
  ErrorTest(const std::string& mesg)
      : test_(std::make_shared<Test>(mesg)) {
    std::cerr << "Constructor: " << (void*) this << std::endl;
    throw std::runtime_error("");
  }

  ~ErrorTest() {
    std::cerr << "Destructor: " << (void*) this << std::endl;
  }

  std::string repr() {
    return test_->val_;
  }

 private:
  std::shared_ptr<Test> test_;
};

void init_group(py::module &m) {

}

PYBIND11_MODULE(errortest, m) {
  m.doc() = "Test exceptions from contructors";

  py::class_<ErrorTest>(m, "ErrorTest")
    .def(py::init<const std::string &>())
    .def("__repr__", &ErrorTest::repr);
}
