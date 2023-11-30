To Build TileDB
===

$ cd ~/wherever
$ git clone https://github.com/TileDB-Inc/TileDB tiledb
$ cd tiledb
$ mkdir build
$ cd build
$ ../bootstrap --enable=ccache,serialization --prefix=/opt/tiledb
$ make -j$(nproc) && make -C tiledb -j$(nproc) install

To Reproduce
===

./run.sh
