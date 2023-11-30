from pybind11.setup_helpers import Pybind11Extension, build_ext
from setuptools import setup

INC_DIRS = [
    '/opt/tiledb/include',
    '/Users/davisp/github/tiledb/py-tiledb/venv/lib/python3.11/site-packages/pybind11/include'
]
DEF_MACROS = []
LIB_DIRS = ['/opt/tiledb/lib']
LIBS = ['tiledb']
LFLAGS = ['-stdlib=libc++', '-Wl,-rpath,/opt/tiledb/lib']
CXXFLAGS = ['-std=c++17', '-Wno-deprecated-declarations']

ext_modules = [
    Pybind11Extension(
        "errortest",
        ["main.cc"],
        include_dirs=INC_DIRS,
        define_macros=DEF_MACROS,
        library_dirs=LIB_DIRS,
        libraries=LIBS,
        extra_link_args=LFLAGS,
        extra_compile_args=CXXFLAGS + ["-fvisibility=hidden"],
        language="c++",
    ),
]

setup(ext_modules=ext_modules, cmdclass={"build_ext": build_ext})
