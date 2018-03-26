##############################################################################
#
#  Copyright Freescale 2013, All rights reserved.
#  Copyright NXP 2017, All rights reserved.
# 
#  SPDX-License-Identifier: BSD-3-Clause
#
##############################################################################
#
#  CONTENT
#    
#
#  AUTHOR
#    Herrmann Stephan-R70157
#
#  DATE
#    $Date: 2013/09/15 10:50:49 $
#
#  LANGUAGE
#    make
#
#  ID
#    $Id: fsl_header.el,v 1.1 2006/09/15 10:50:49 norberts Exp $
#
##############################################################################

SRC = test0.asm


all: imem.elf

imem.elf: $(SRC)
	../as-IPUV $(SRC) -o imem.elf

run: imem.elf
	../IPUV -trace imem.elf -o trace.dat
#	../IPUV --heartbeat=1 imem.elf -o trace.dat

dbg: imem.elf
	xddd ../IPUV -trace imem.elf -o trace.dat

irun: imem.elf data.elf
	../IPUV -trace imem.elf -o trace.dat --cli

srun: imem.elf data.elf
	../IPUV -o trace.dat -mic=0 --cli < run.cli | grep -v "imulation halted at"

disp: srun
# 	../../tools/Mem2Hist.csh hist.mem
#	../../tools/Mem2PGM.csh out.mem 640 400 65535
#	convert out.pgm X:

data.elf: ../../data/data0_elf.img ../../data/data1_elf.img
	ld -Tdata 0x10000 -b elf32-little \
	../../data/data0_elf.img ../../data/data1_elf.img \
	--oformat elf32-little -o data.elf

clean:
	rm -f *.elf *.o *.dat out*.mem

st_ref:
	cp trace.dat out0.mem ref

check: imem.elf data.elf
	@../IPUV -o trace.dat -mic=0 --cli < run.cli > /dev/null
	@cmp out0.mem ref/out0.mem && echo "out0.mem is OK" || (echo "out0.mem not OK"; exit 1)
