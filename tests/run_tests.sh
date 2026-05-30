#!/usr/bin/env bash
# ************************************************************************************************ #
#                                                                                                  #
#   Libft test runner                                                                              #
#                                                                                                  #
#   Usage from the tests folder:                                                                   #
#                                                                                                  #
#       chmod +x run_tests.sh                                                                      #
#       ./run_tests.sh                                                                             #
#                                                                                                  #
#   This script:                                                                                   #
#   - runs make fclean, make, and make bonus in ../libft                                           #
#   - compiles tests.c against ../libft/libft.a                                                    #
#   - runs the test binary                                                                         #
#   - runs Valgrind if available                                                                   #
#   - runs make fclean again to leave ../libft clean                                               #
#                                                                                                  #
# ************************************************************************************************ #

set -u

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ROOT_DIR="$(cd "$SCRIPT_DIR/.." && pwd)"
LIBFT_DIR="$ROOT_DIR/libft"
TEST_SRC="$SCRIPT_DIR/tests.c"
BUILD_DIR="$SCRIPT_DIR/.build"
TEST_BIN="$BUILD_DIR/tests"

GREEN="\033[32m"
RED="\033[31m"
YELLOW="\033[33m"
RESET="\033[0m"

STATUS=0

print_step()
{
	printf "${YELLOW}\n== %s ==${RESET}\n" "$1"
}

fail()
{
	printf "${RED}Error:${RESET} %s\n" "$1"
	STATUS=1
}

cleanup()
{
	print_step "Cleaning generated files"
	if [ -d "$LIBFT_DIR" ] && [ -f "$LIBFT_DIR/Makefile" ]; then
		make -C "$LIBFT_DIR" fclean
	fi
	rm -rf "$BUILD_DIR"
}

trap cleanup EXIT

print_step "Checking project layout"

if [ ! -d "$LIBFT_DIR" ]; then
	fail "libft directory not found: $LIBFT_DIR"
	exit "$STATUS"
fi

if [ ! -f "$LIBFT_DIR/Makefile" ]; then
	fail "Makefile not found inside: $LIBFT_DIR"
	exit "$STATUS"
fi

if [ ! -f "$LIBFT_DIR/libft.h" ]; then
	fail "libft.h not found inside: $LIBFT_DIR"
	exit "$STATUS"
fi

if [ ! -f "$TEST_SRC" ]; then
	fail "tests.c not found: $TEST_SRC"
	exit "$STATUS"
fi

print_step "Building Libft mandatory"

if ! make -C "$LIBFT_DIR" fclean; then
	fail "make fclean failed"
	exit "$STATUS"
fi

if ! make -C "$LIBFT_DIR"; then
	fail "make failed"
	exit "$STATUS"
fi

print_step "Building Libft bonus"

if ! make -C "$LIBFT_DIR" bonus; then
	fail "make bonus failed"
	exit "$STATUS"
fi

print_step "Compiling test binary"

mkdir -p "$BUILD_DIR"

if ! cc -Wall -Wextra -Werror -I"$LIBFT_DIR" "$TEST_SRC" \
	"$LIBFT_DIR/libft.a" -o "$TEST_BIN"; then
	fail "tests.c compilation failed"
	exit "$STATUS"
fi

print_step "Running unit tests"

if ! "$TEST_BIN"; then
	fail "unit tests failed"
	exit "$STATUS"
fi

print_step "Running Valgrind"

if command -v valgrind >/dev/null 2>&1; then
	if ! valgrind --leak-check=full --show-leak-kinds=all \
		--track-origins=yes --error-exitcode=42 "$TEST_BIN"; then
		fail "Valgrind found leaks, invalid reads/writes, or other memory errors"
		exit "$STATUS"
	fi
else
	printf "${YELLOW}Warning:${RESET} Valgrind is not installed. Skipping memory check.\n"
fi

print_step "Result"

printf "${GREEN}All Libft tests completed successfully.${RESET}\n"
exit "$STATUS"
