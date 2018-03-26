#Makefile

IPU_ROOTDIR ?= ..
IPUDIR ?= $(IPU_ROOTDIR)

CORE = IPUS

ADL_PREFIX ?= /usr/local

ADL2ISSPARAM = --log-usage=no
ADL2ASMPARAM = -D=ASM --verbose
ADL2DOCPARAM =

ifeq ($(DEBUG),y)
ADL2ISSPARAM += --no-optimize
ADL2ASMPARAM += --no-optimize
endif
ifeq ($(ISP2),y)
ADL2ISSPARAM += -D=ISP2
ADL2ASMPARAM += -D=ISP2
ADL2DOCPARAM += -D=ISP2
else
ISP2=n
endif
ifeq ($(STATIC),y)
ADL2ISSPARAM += --static
endif

IPUSTEST ?= test0
IPUTEST = $(IPUSTEST)

ADLFILES= \
	IPUS.adl IPUS_HostRegs.adl \
	IPUS_Scalar.adl IPUS_Matrix.adl IPUS_Mask.adl IPUS_Accelerators.adl \
	IPUS_Flow.adl IPUS_Done.adl IPUS_Defines.h IPUS_Registers.h \
	IPUS_StreamDMA.adl


help:
	@echo "Compileoptions"
	@echo "setenv ISP2         to enable ISP2 features is ("$(ISP2)")"
	@echo "setenv IPU_ROOTDIR  to select target directory for install"
	@echo "                    ("$(IPU_ROOTDIR)")"
	@echo
	@echo "make targets:"
	@echo "make doc            builds documentation"
	@echo "make model          builds simulator executable"
	@echo "make asm            builds tools"
	@echo "make cc             cc file for SystemC integration"
	@echo "make install        installs doc, tools, model, cc to $IPU_ROOTDIR"

all: model doc asm tools

static:
	/bin/csh static_asm.csh
	/bin/csh static_sim.csh

install: doc model $(IPUDIR)/lib/init.tcl $(CORE).cc
	mkdir -p $(IPUDIR)/doc $(IPUDIR)/bin $(IPUDIR)/lib
	cp -f $(CORE).html $(IPUDIR)/doc
	cp -f $(CORE) $(IPUDIR)/bin
	cp -f as-$(CORE) $(IPUDIR)/bin
	cp -f objdump-$(CORE) $(IPUDIR)/bin
	cp -f addr2line-$(CORE) $(IPUDIR)/bin
	cp -f $(CORE).ttc $(IPUDIR)/lib
	cp -f $(CORE).cc $(IPUDIR)/lib
	cp -f as-$(CORE).cc $(IPUDIR)/lib
	cp -f objdump-$(CORE).cc $(IPUDIR)/lib

$(IPUDIR)/lib/init.tcl:
	mkdir -p $(IPUDIR)/lib
	cp -f ../init.tcl $(IPUDIR)/lib/init.tcl

model: $(CORE)

$(CORE) : $(ADLFILES)
	@echo $(ADLFILES)
	adl2iss $(ADL2ISSPARAM) $(CORE).adl
	rm -f $(CORE).cc

cc: $(CORE)_sysc.cc

$(CORE)_sysc.cc : $(ADLFILES)
	make-iss $(CORE).adl --em --config=IPUS.ttc -D=SYSC $(ADL2ISSPARAM) --disassembler --output=$(CORE)_sysc.cc --jobs='0' --iss-namespace='IPUS_adl' --event-bus-send --warn-redefine

#make-iss --em $< --include $(IPU_ADL_BASE_DIR)/ipus.adl --output=$(ADLGENSRC)/$@ -D=SYSC --config=$(word 2,$^) --iss-namespace='IPUS_adl' --jobs='0' --verbose='0' --event-bus-send --warn-redefine --debug-mode

doc: $(CORE).html
$(CORE).html : $(ADLFILES) Makefile
	adl2doc --title "$(CORE)" --subtitle "Reference Manual" \
		$(ADL2DOCPARAM) \
		--ops-in-affect-tables \
		--no-core-level-hooks \
		-D=MAKEDOC \
		$(CORE).adl
#--no-helper-functions \

ASM_HLP_OBJS = IPUS_support.o
CXXFLAGS = -I $(ADL_PREFIX)/share/binutils/gas -I $(ADL_PREFIX)/share/binutils/include -I $(ADL_PREFIX)/share/binutils/bfd -I $(ADL_PREFIX)/share/binutils/gas/config -I $(ADL_PREFIX)/share/binutils --std=c++0x -ggdb -g3 -Wall -Wno-deprecated -Wno-unused-label -Wno-unused-but-set-variable -Wno-unused-local-typedefs -D_REENTRANT -DGC_LINUX_THREADS

asm: as-$(CORE)
as-$(CORE) : $(ADLFILES) $(ASM_HLP_OBJS)
	adl2asm $(ADL2ASMPARAM) $(CORE).adl --no-log-usage --no-a2l --no-ld --as-libs=$(ASM_HLP_OBJS)
#	adl2asm $(ADL2ASMPARAM) --static-link $(CORE).adl
	cd $(IPUTEST); make clean

$(ASM_HLP_OBJS): %.o: %.c
	$(CXX) $(CXXFLAGS) -c -o $@ $<

tools:
	cd ../tools; make all

clean: testclean traceclean
	rm -f $(CORE) $(CORE).cc  $(CORE)_sysc.cc *.o $(CORE).html $(CORE).rst
	rm -f as-$(CORE).cc as-$(CORE) objdump-$(CORE).cc objdump-$(CORE) \
		addr2line-$(CORE)

testclean:
	@for a in $$(find . -type d -name "test*" -print); do \
		echo "cleaning folder $$a"; \
		$(MAKE) -C $$a clean; \
	done;

traceclean:
	rm -f trace.dat test*/trace.dat

fw: asm
	cd $(IPUTEST); make

run: model asm tools
	cd $(IPUTEST); make run

dbg: model asm tools
	cd $(IPUTEST); make dbg

irun: model asm tools
	cd $(IPUTEST); make irun

srun: model asm tools
	cd $(IPUTEST); make srun

check: model asm tools
#	cd $(IPUTEST); make check
#	$(MAKE) -C testsuite check
	@echo "*******************"
	@echo Starting simulations
	@echo "*******************\n\n"
	@failed=0; \
	failtest=""; \
	for a in $$(find . -type d -name "test*" -print); do \
		if [ -d $$a ]; then \
			echo "processing folder $$a"; \
			fail=0; \
			$(MAKE) -C $$a check || \
				fail=1; \
			if test $$fail -eq 1 ; then \
				failed=`echo "$$failed + 1" | bc`; \
				failtest=$$failtest" "$$a ; \
			fi; \
		fi; \
	done; \
	echo; echo; echo ++++++++++++++; \
	echo Faild tests: $$failed : $$failtest; \
	echo ++++++++++++++
	@echo "Done!"

cmp: model asm tools
	@cd $(IPUTEST); make check || echo "Faild ++++++++++"

disp: model asm tools
	cd $(IPUTEST); make disp

ref:
	@for a in $$(find . -type d -name "test*" -print); do \
		echo "archiving reference in folder $$a"; \
		$(MAKE) -C $$a st_ref; \
	done;
#	cd $(IPUTEST); make st_ref

trace:
	less $(IPUTEST)/trace.dat

bkup: clean doc
	cd ..; tar cjvf $(CORE)_bkup.tbz --exclude data --exclude restore ipus.adl

diff_v:
	xemacs IPUS.adl           ../ipuv.adl/IPUV.adl
	xemacs IPUS_Done.adl      ../ipuv.adl/IPUV_Done.adl
	xemacs IPUS_HostRegs.adl  ../ipuv.adl/IPUV_HostRegs.adl
	xemacs IPUS_StreamDMA.adl ../ipuv.adl/IPUV_StreamDMA.adl
	xemacs IPUS_Scalar.adl    ../ipuv.adl/IPUV_Scalar.adl
	xemacs IPUS_Defines.h     ../ipuv.adl/IPUV_Defines.h
	xemacs IPUS_Flow.adl      ../ipuv.adl/IPUV_Flow.adl
#	xemacs IPUS_MRegisters.h  ../ipuv.adl/IPUV_VRegisters.h
	xemacs IPUS_Registers.h   ../ipuv.adl/IPUV_Registers.h
	xemacs IPUS_Matrix.adl    ../ipuv.adl/IPUV_Vector.adl
