#include <iostream>

#include <pybind11/pybind11.h>

namespace py = pybind11;

class MyContext {
 public:
  MyContext() : msg_("Can I be a mongoose dog?") {
    std::cerr << "Context Constructor: " << (void*) this << std::endl;
  }

  ~MyContext() {
    std::cerr << "Context Destructor: " << (void*) this << std::endl;
  }

 std::string get() const {
  return msg_;
 }

 private:
  std::string msg_;
};

class MyGroup {
 public:
  MyGroup(const MyContext& ctx, const std::string& uri) : ctx_(ctx), uri_(uri) {
    std::cerr << "Group Constructor: " << (void*) this << std::endl;
    std::cerr << "Group Context: " << (void*) &ctx_ << std::endl;
    throw std::runtime_error("Look! A squirrel!");
  }

  ~MyGroup() {
    std::cerr << "Group Destructor: " << (void*) this << std::endl;
  }

  std::string dump(bool) {
    return ctx_.get();
  }

 private:
  const MyContext& ctx_;
  std::string uri_;
};

void init_context(py::module &m) {
  py::class_<MyContext>(m, "Context")
      .def(py::init());
}

std::string do_dump(MyGroup& group, bool recursive) {
  std::cerr << "DUMPING GROUP: " << (void*) &group << std::endl;
  auto ret = group.dump(recursive);
  std::cerr << "FINISHED DUMPING GROUP: " << (void*) &group << std::endl;
  return ret;
}

void init_group(py::module &m) {
  py::class_<MyGroup>(m, "Group")
      .def(
          py::init<const MyContext &, const std::string &>(),
          py::keep_alive<1, 2>())
      .def("_dump", do_dump);
}

PYBIND11_MODULE(errortest, m) {
    m.doc() = "Test exceptions from contructors";
    init_context(m);
    init_group(m);
}
