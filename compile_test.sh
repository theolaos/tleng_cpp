!/bin/bash

cd build && cmake .. && make && cd ..

cp /build/tleng3.cpython-312-x86_64-linux-gnu.so ~/Documents/tleng_cpp

cd test_py && python test.py

rm tleng3.cpython-312-x86_64-linux-gnu.so