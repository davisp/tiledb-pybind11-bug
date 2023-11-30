#include <pybind11/pybind11.h>

#include <tiledb/tiledb>
#include <tiledb/tiledb_experimental>

using namespace tiledb;
namespace py = pybind11;

void init_enums(py::module& m) {
  py::enum_<tiledb_query_type_t>(m, "QueryType")
    .value("READ", TILEDB_READ)
    .value("WRITE", TILEDB_WRITE)
    .value("DELETE", TILEDB_DELETE)
    .value("MODIFY_EXCLUSIVE", TILEDB_MODIFY_EXCLUSIVE);
}

void init_context(py::module &m) {
  py::class_<Context>(m, "Context")
      .def(py::init());
}

std::string do_dump(Group& group, bool recursive) {
  std::cerr << "DUMPING GROUP: " << (void*) &group << std::endl;
  auto ret = group.dump(recursive);
  std::cerr << "FINISHED DUMPING GROUP: " << (void*) &group << std::endl;
  return ret;
}

void init_group(py::module &m) {
  py::class_<Group>(m, "Group")
      .def(
          py::init<const Context &, const std::string &, tiledb_query_type_t>(),
          py::keep_alive<1, 2>())
      .def(py::init<const Context &, const std::string &, tiledb_query_type_t,
                    const Config &>(),
           py::keep_alive<1, 2>())
      .def("_dump", do_dump);

}

PYBIND11_MODULE(errortest, m) {
    m.doc() = "Test exceptions from contructors";
    init_context(m);
    init_group(m);
}
