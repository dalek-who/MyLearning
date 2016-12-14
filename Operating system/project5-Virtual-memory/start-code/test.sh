echo "test start"
echo "testing 1"
cd 1
make clean && make > /dev/null
bochs -q
cd ..
echo "testing 2"
cd 2
make clean && make > /dev/null
bochs -q
cd ..
echo "testing 3"
cd 3
make clean && make > /dev/null
bochs -q
cd ..
echo "test done"
