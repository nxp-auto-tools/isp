/pkg/.site/pkgs03/fs-adl-/3.12.4.sr2-gcc_4.7.3/x86_64-linux/bin/make-asm --cpp=/pkg/.site/pkgs03/gcc-/4.7.3/x86_64-linux/bin/g++ IPUS.adl --log-usage='no'    --asm --dis --arch-pfx='ppc' --asm-output='as-IPUS.cc' --dis-output='objdump-IPUS.cc'

/pkg/.site/pkgs03/gcc-/4.7.3/x86_64-linux/bin/g++  -DHAVE_CONFIG_H -D_GNU_SOURCE -I/pkg/.site/pkgs03/fs-adl-/3.12.4.sr2-gcc_4.7.3/x86_64-linux/include -I/pkg/.site/pkgs03/fs-adl-/3.12.4.sr2-gcc_4.7.3/x86_64-linux/share/binutils/opcodes -I/pkg/.site/pkgs03/fs-adl-/3.12.4.sr2-gcc_4.7.3/x86_64-linux/share/binutils/bfd -I/pkg/.site/pkgs03/fs-adl-/3.12.4.sr2-gcc_4.7.3/x86_64-linux/share/binutils/include -I/pkg/.site/pkgs03/fs-adl-/3.12.4.sr2-gcc_4.7.3/x86_64-linux/share/binutils/intl  -W -Wall -g -O2 --std=c++0x -fPIC  -c objdump-IPUS.cc -o objdump-IPUS.o

/pkg/.site/pkgs03/gcc-/4.7.3/x86_64-linux/bin/g++  -DHAVE_CONFIG_H -D_GNU_SOURCE -I/pkg/.site/pkgs03/fs-adl-/3.12.4.sr2-gcc_4.7.3/x86_64-linux/include -I/pkg/.site/pkgs03/fs-adl-/3.12.4.sr2-gcc_4.7.3/x86_64-linux/share/binutils/gas -I/pkg/.site/pkgs03/fs-adl-/3.12.4.sr2-gcc_4.7.3/x86_64-linux/share/binutils/gas/config -I/pkg/.site/pkgs03/fs-adl-/3.12.4.sr2-gcc_4.7.3/x86_64-linux/share/binutils -I/pkg/.site/pkgs03/fs-adl-/3.12.4.sr2-gcc_4.7.3/x86_64-linux/share/binutils/opcodes -I/pkg/.site/pkgs03/fs-adl-/3.12.4.sr2-gcc_4.7.3/x86_64-linux/share/binutils/bfd -I/pkg/.site/pkgs03/fs-adl-/3.12.4.sr2-gcc_4.7.3/x86_64-linux/share/binutils/include -I/pkg/.site/pkgs03/fs-adl-/3.12.4.sr2-gcc_4.7.3/x86_64-linux/share/binutils/intl  -W -Wall -g -O2 --std=c++0x -fPIC  -c as-IPUS.cc -o as-IPUS.o

/pkg/.site/pkgs03/gcc-/4.7.3/x86_64-linux/bin/g++ -static -W -Wall -g -O2 --std=c++0x  -fPIC   -o objdump-IPUS objdump-IPUS.o -L/pkg/.site/pkgs03/fs-adl-/3.12.4.sr2-gcc_4.7.3/x86_64-linux/lib -Wl,-R/pkg/.site/pkgs03/fs-adl-/3.12.4.sr2-gcc_4.7.3/x86_64-linux/lib -L/pkg/.site/pkgs03/fs-adl-/3.12.4.sr2-gcc_4.7.3/x86_64-linux/share/binutils/binutils -L/pkg/.site/pkgs03/fs-adl-/3.12.4.sr2-gcc_4.7.3/x86_64-linux/share/binutils/bfd -L/pkg/.site/pkgs03/fs-adl-/3.12.4.sr2-gcc_4.7.3/x86_64-linux/share/binutils/opcodes -L/pkg/.site/pkgs03/fs-adl-/3.12.4.sr2-gcc_4.7.3/x86_64-linux/share/binutils/libiberty -lobjdump -lbfd -lbfd -liberty  -lz -lopcodes

/pkg/.site/pkgs03/gcc-/4.7.3/x86_64-linux/bin/g++ -static -o as-IPUS -W -Wall -g -O2 --std=c++0x  -fPIC  as-IPUS.o -L/pkg/.site/pkgs03/fs-adl-/3.12.4.sr2-gcc_4.7.3/x86_64-linux/lib -Wl,-R/pkg/.site/pkgs03/fs-adl-/3.12.4.sr2-gcc_4.7.3/x86_64-linux/lib -L/pkg/.site/pkgs03/fs-adl-/3.12.4.sr2-gcc_4.7.3/x86_64-linux/share/binutils/gas -L/pkg/.site/pkgs03/fs-adl-/3.12.4.sr2-gcc_4.7.3/x86_64-linux/share/binutils/opcodes -L/pkg/.site/pkgs03/fs-adl-/3.12.4.sr2-gcc_4.7.3/x86_64-linux/share/binutils/bfd -L/pkg/.site/pkgs03/fs-adl-/3.12.4.sr2-gcc_4.7.3/x86_64-linux/share/binutils/intl -L/pkg/.site/pkgs03/fs-adl-/3.12.4.sr2-gcc_4.7.3/x86_64-linux/share/binutils/libiberty objdump-IPUS.o -lgas -lopcodes -lbfd -liberty  -lz -lgas-gas
