//
// Extra assembler support for RISC-V.
//
// This handles stuff like branch transformation and relocations.  Branch
// transformation is required when a branch's target is too far away- the branch
// is negated, then a jump is appended.  That way, the conditional branch avoids
// the jump if the condition doesn't hold, otherwise the jump is taken.
//
// Relaxation handles function calls.  The compiler emits assembler pseudo-ops
// like "call" and "tail".  These are expanded into instruction pairs- auipc and
// jalr.  If the function call is close enough, we can then convert those to
// single jal instructions in the linker.  This requires us to emit pairs of
// relocations- a relax relocation and then the usual high-address relocation.
//
// Most of this code comes from RISC-V binutils.

extern "C" {
#include "as.h"
#include "bfdver.h"
}

#include <assert.h>
#include <iostream>
#include <unordered_map>

#include "adl-asm-impl.h"
#include "adl-asm-info.h"

using namespace std;

static bool set_machine_code(int emc) {
  extern bfd_target powerpc_elf64_vec;
  extern bfd_target powerpc_elf64_le_vec;
  extern bfd_target powerpc_elf32_vec;
  extern bfd_target powerpc_elf32_le_vec;
  ((struct elf_backend_data*)(powerpc_elf64_vec.backend_data))->elf_machine_code = emc;
  ((struct elf_backend_data*)(powerpc_elf64_le_vec.backend_data))->elf_machine_code = emc;
  ((struct elf_backend_data*)(powerpc_elf32_vec.backend_data))->elf_machine_code = emc;
  ((struct elf_backend_data*)(powerpc_elf32_le_vec.backend_data))->elf_machine_code = emc;
  return true;
}

static bool inited = false;

void acb_after_parse_args()
{
	if (!inited) {
		inited = set_machine_code(40);
	}
}

int acb_parse_option(int c,const char *arg)
{
	if (arg != 0L && !strcmp(arg,"version")) {
		  /* This output is intended to follow the GNU standards document.  */
		  printf (_("GNU assembler %s version: %s\n"), BFD_VERSION_STRING, adl_asm_version.c_str());
		  printf (_("Copyright (C) 2014 Free Software Foundation, Inc.\n"));
		  printf (_("\
	This program is free software; you may redistribute it under the terms of\n\
	the GNU General Public License version 3 or later.\n\
	This program has absolutely no warranty.\n"));
		  printf (_("This assembler was configured for a target of `%s'.\n"),
				  "IPUS");
		  exit(0);
	}

	return 0;
}

