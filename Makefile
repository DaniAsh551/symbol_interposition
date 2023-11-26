# Compiler and compiler flags
CC := gcc
CFLAGS := -Wall -Werror -fPIC
RM := rm -f

# Directories
SYS_A_SRC := sys_a
SYS_B_SRC := sys_b

# Default target, builds all necessary components
all: sys_a_lib sys_b_lib sys_b_fakesmallmath_lib smallmathtest

# Target: Build libsmallmath for system_a
sys_a_lib: $(SYS_A_SRC)/libsmallmath/libsmallmath.so

# Target: Clean libsmallmath for system_a
clean_sys_a_lib:
	@$(RM) $(SYS_A_SRC)/libsmallmath/libsmallmath.so

# Recipe: Build libsmallmath for system_a
$(SYS_A_SRC)/libsmallmath/libsmallmath.so: $(SYS_A_SRC)/libsmallmath/libsmallmath.c
	$(CC) $(CFLAGS) -shared -o $@ $<

# Target: Build libsmallmath for system_b
sys_b_lib: $(SYS_B_SRC)/libsmallmath/libsmallmath.so

# Recipe: Build libsmallmath for system_b
$(SYS_B_SRC)/libsmallmath/libsmallmath.so: $(SYS_B_SRC)/libsmallmath/libsmallmath.c
	$(CC) $(CFLAGS) -shared -o $@ $<

# Target: Build libfakesmallmath for system_b
sys_b_fakesmallmath_lib: $(SYS_B_SRC)/libfakesmallmath/libfakesmallmath.so

# Recipe: Build libfakesmallmath for system_b
$(SYS_B_SRC)/libfakesmallmath/libfakesmallmath.so: $(SYS_B_SRC)/libfakesmallmath/libfakesmallmath.c $(SYS_B_SRC)/libsmallmath/libsmallmath.so
	$(CC) $(CFLAGS) -shared -o $@ $< -ldl

# Target: Build smallmathtest binary
smallmathtest: $(SYS_A_SRC)/smallmathtest.c $(SYS_A_SRC)/libsmallmath/libsmallmath.so
	$(CC) $(CFLAGS) -o $@ $< -L$(SYS_A_SRC)/libsmallmath -lsmallmath -Wl,-rpath,$(PWD)/$(SYS_A_SRC)/libsmallmath

# Target: Run smallmathtest
run:
	./smallmathtest

# Target: Run smallmathtest with faked library
run_fake:
	env LD_PRELOAD=$(SYS_B_SRC)/libfakesmallmath/libfakesmallmath.so LD_LIBRARY_PATH=$(SYS_B_SRC)/libsmallmath ./smallmathtest

# Target: Clean all generated files
clean: clean_sys_a_lib
	@$(RM) $(SYS_B_SRC)/libsmallmath/libsmallmath.so
	@$(RM) $(SYS_B_SRC)/libfakesmallmath/libfakesmallmath.so
	@$(RM) smallmathtest
