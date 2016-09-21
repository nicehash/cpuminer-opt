make clean

rm -f config.status

# icon
windres res/icon.rc icon.o

CFLAGS="-O3 -mavx -maes -Wall" CXXFLAGS="$CFLAGS -std=gnu++11 -flto -fpermissive" ./configure --with-curl

make -j8

strip -p --strip-debug --strip-unneeded cpuminer.exe

mv cpuminer.exe cpuminer_opt_AVX_AES.exe

