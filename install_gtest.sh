# First download googletest-release-1.10.0 and then run following
sudo apt-get install cmake
cd deps
tar -zxvf googletest-release-1.10.0.tar.gz
cd googletest-release-1.10.0
mkdir build && cd build
cmake ..
sudo make install
