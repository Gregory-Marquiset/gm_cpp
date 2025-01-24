#!/bin/bash

all_tests_passed=true

# ---------------------- Tests Makefile ----------------------
echo -e "\033[1;33mRunning Makefile commands...\033[0m"
echo -e "\033[1;33mRunning Makefile commands...\033[0m" > debug.txt

# Test make
echo -e "\033[1;36mRunning make...\033[0m"
echo -e "\033[1;36mRunning make...\033[0m" >> debug.txt
make > .make.txt 2>&1
if [ $? -ne 0 ]; then
    cat .make.txt >> debug.txt
    echo -e "\033[1;31mInvalide\033[0m"
    echo -e "\033[1;31mInvalide\n\033[0m" >> debug.txt
    all_tests_passed=false
else
    echo -e "\033[1;32mValide\033[0m"
    echo -e "\033[1;32mValide\033[0m" >> debug.txt
fi

# Test make clean
echo -e "\033[1;36mRunning make clean...\033[0m"
echo -e "\033[1;36mRunning make clean...\033[0m" >> debug.txt
make clean > .make.txt 2>&1
if [ $? -ne 0 ]; then
    cat .make.txt >> debug.txt
    echo -e "\033[1;31mInvalide\033[0m"
    echo -e "\033[1;31mInvalide\n\033[0m" >> debug.txt
    all_tests_passed=false
else
    echo -e "\033[1;32mValide\033[0m"
    echo -e "\033[1;32mValide\033[0m" >> debug.txt
fi

# Test make re
echo -e "\033[1;36mRunning make re...\033[0m"
echo -e "\033[1;36mRunning make re...\033[0m" >> debug.txt
make re > .make.txt 2>&1
if [ $? -ne 0 ]; then
    cat .make.txt >> debug.txt
    echo -e "\033[1;31mInvalide\033[0m"
    echo -e "\033[1;31mInvalide\n\033[0m" >> debug.txt
    all_tests_passed=false
else
    echo -e "\033[1;32mValide\033[0m"
    echo -e "\033[1;32mValide\033[0m" >> debug.txt
fi

# ---------------------- Tests exercice ----------------------
echo -e "\033[1;33m\nRunning tests for ex00...\033[0m" >> debug.txt
echo -e "\033[1;33m\nRunning tests for ex00...\033[0m"

# Test 1
echo -e "\033[1;36mTest 1:\033[0m" >> debug.txt
echo -e "\033[1;36mTest 1:\033[0m"
./megaphone "shhhhh... I think the students are asleep..." > .output.txt 2>&1
echo -n "SHHHHH... I THINK THE STUDENTS ARE ASLEEP...
" > .expected.txt 2>&1
if diff -q .output.txt .expected.txt >> /dev/null 2>&1; then
    echo -e "\033[1;32mValide\033[0m"
    echo -e "\033[1;32mValide\033[0m" >> debug.txt
else
    echo -e "\033[1;33mOutput megaphone:\033[0m" >> debug.txt
    cat .output.txt >> debug.txt
    echo -e "\033[1;33mOutput expected:\033[0m" >> debug.txt
    cat .expected.txt >> debug.txt
    echo -e "\033[1;31mInvalide\033[0m"
    echo -e "\033[1;31mInvalide\n\033[0m" >> debug.txt
    all_tests_passed=false
fi

# Test 2
echo -e "\033[1;36mTest 2:\033[0m" >> debug.txt
echo -e "\033[1;36mTest 2:\033[0m"
./megaphone Damnit " ! " "Sorry students, I thought this thing was off." > .output.txt 2>&1
echo -n "DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.
" > .expected.txt 2>&1
if diff -q .output.txt .expected.txt >> /dev/null 2>&1; then
    echo -e "\033[1;32mValide\033[0m"
    echo -e "\033[1;32mValide\033[0m" >> debug.txt
else
    echo -e "\033[1;33mOutput megaphone:\033[0m" >> debug.txt
    cat .output.txt >> debug.txt
    echo -e "\033[1;33mOutput expected:\033[0m" >> debug.txt
    cat .expected.txt >> debug.txt
    echo -e "\033[1;31mInvalide\033[0m"
    echo -e "\033[1;31mInvalide\n\033[0m" >> debug.txt
    all_tests_passed=false
fi

# Test 3
echo -e "\033[1;36mTest 3:\033[0m" >> debug.txt
echo -e "\033[1;36mTest 3:\033[0m"
./megaphone "" > .output.txt 2>&1
echo -n "* LOUD AND UNBEARABLE FEEDBACK NOISE *
" > .expected.txt 2>&1
if diff -q .output.txt .expected.txt >> /dev/null 2>&1; then
    echo -e "\033[1;32mValide\033[0m"
    echo -e "\033[1;32mValide\033[0m" >> debug.txt
else
    echo -e "\033[1;33mOutput megaphone:\033[0m" >> debug.txt
    cat .output.txt >> debug.txt
    echo -e "\033[1;33mOutput expected:\033[0m" >> debug.txt
    cat .expected.txt >> debug.txt
    echo -e "\033[1;31mInvalide\033[0m"
    echo -e "\033[1;31mInvalide\n\033[0m" >> debug.txt
    all_tests_passed=false
fi

# Test 4
echo -e "\033[1;36mTest 4:\033[0m" >> debug.txt
echo -e "\033[1;36mTest 4:\033[0m"
./megaphone "" "" "" > .output.txt 2>&1
echo -n "* LOUD AND UNBEARABLE FEEDBACK NOISE *
" > .expected.txt 2>&1
if diff -q .output.txt .expected.txt >> /dev/null 2>&1; then
    echo -e "\033[1;32mValide\033[0m"
    echo -e "\033[1;32mValide\033[0m" >> debug.txt
else
    echo -e "\033[1;33mOutput megaphone:\033[0m" >> debug.txt
    cat .output.txt >> debug.txt
    echo -e "\033[1;33mOutput expected:\033[0m" >> debug.txt
    cat .expected.txt >> debug.txt
    echo -e "\033[1;31mInvalide\033[0m"
    echo -e "\033[1;31mInvalide\n\033[0m" >> debug.txt
    all_tests_passed=false
fi

# Test 5
echo -e "\033[1;36mTest 5:\033[0m" >> debug.txt
echo -e "\033[1;36mTest 5:\033[0m"
./megaphone > .output.txt 2>&1
echo -n "* LOUD AND UNBEARABLE FEEDBACK NOISE *
" > .expected.txt 2>&1
if diff -q .output.txt .expected.txt >> /dev/null 2>&1; then
    echo -e "\033[1;32mValide\033[0m"
    echo -e "\033[1;32mValide\033[0m" >> debug.txt
else
    echo -e "\033[1;33mOutput megaphone:\033[0m" >> debug.txt
    cat .output.txt >> debug.txt
    echo -e "\033[1;33mOutput expected:\033[0m" >> debug.txt
    cat .expected.txt >> debug.txt
    echo -e "\033[1;31mInvalide\033[0m"
    echo -e "\033[1;31mInvalide\n\033[0m" >> debug.txt
    all_tests_passed=false
fi

# ---------------------- Tests valgrind ----------------------
echo -e "\033[1;33m\nRunning valgrind for ex00...\033[0m"
echo -e "\033[1;33m\nRunning valgrind for ex00...\033[0m" >> debug.txt

# Valgrind Test 1
echo -e "\033[1;36mValgrind Test 1:\033[0m" >> debug.txt
echo -e "\033[1;36mValgrind Test 1:\033[0m"
valgrind --leak-check=full ./megaphone "shhhhh... I think the students are asleep..." > .valgrind.txt 2>&1
if grep -q "ERROR SUMMARY: 0 errors" .valgrind.txt; then
    echo -e "\033[1;32mValide\033[0m" >> debug.txt
    echo -e "\033[1;32mValide\033[0m"
else
    cat .valgrind.txt >> debug.txt
    echo -e "\033[1;31mInvalide\033[0m"
    echo -e "\033[1;31mInvalide\n\033[0m" >> debug.txt
    all_tests_passed=false
fi

# Valgrind Test 2
echo -e "\033[1;36mValgrind Test 2:\033[0m" >> debug.txt
echo -e "\033[1;36mValgrind Test 2:\033[0m"
valgrind --leak-check=full ./megaphone Damnit " ! " "Sorry students, I thought this thing was off." > .valgrind.txt 2>&1
if grep -q "ERROR SUMMARY: 0 errors" .valgrind.txt; then
    echo -e "\033[1;32mValide\033[0m" >> debug.txt
    echo -e "\033[1;32mValide\033[0m"
else
    cat .valgrind.txt >> debug.txt
    echo -e "\033[1;31mInvalide\033[0m"
    echo -e "\033[1;31mInvalide\n\033[0m" >> debug.txt
    all_tests_passed=false
fi

# Valgrind Test 3
echo -e "\033[1;36mValgrind Test 3:\033[0m" >> debug.txt
echo -e "\033[1;36mValgrind Test 3:\033[0m"
valgrind --leak-check=full ./megaphone "" > .valgrind.txt 2>&1
if grep -q "ERROR SUMMARY: 0 errors" .valgrind.txt; then
    echo -e "\033[1;32mValide\033[0m" >> debug.txt
    echo -e "\033[1;32mValide\033[0m"
else
    cat .valgrind.txt >> debug.txt
    echo -e "\033[1;31mInvalide\033[0m"
    echo -e "\033[1;31mInvalide\n\033[0m" >> debug.txt
    all_tests_passed=false
fi

# Valgrind Test 4
echo -e "\033[1;36mValgrind Test 4:\033[0m" >> debug.txt
echo -e "\033[1;36mValgrind Test 4:\033[0m"
valgrind --leak-check=full ./megaphone "" "" "" > .valgrind.txt 2>&1
if grep -q "ERROR SUMMARY: 0 errors" .valgrind.txt; then
    echo -e "\033[1;32mValide\033[0m" >> debug.txt
    echo -e "\033[1;32mValide\033[0m"
else
    cat .valgrind.txt >> debug.txt
    echo -e "\033[1;31mInvalide\033[0m"
    echo -e "\033[1;31mInvalide\n\033[0m" >> debug.txt
    all_tests_passed=false
fi

# Valgrind Test 5
echo -e "\033[1;36mValgrind Test 5:\033[0m" >> debug.txt
echo -e "\033[1;36mValgrind Test 5:\033[0m"
valgrind --leak-check=full ./megaphone > .valgrind.txt 2>&1
if grep -q "ERROR SUMMARY: 0 errors" .valgrind.txt; then
    echo -e "\033[1;32mValide\033[0m" >> debug.txt
    echo -e "\033[1;32mValide\033[0m"
else
    cat .valgrind.txt >> debug.txt
    echo -e "\033[1;31mInvalide\033[0m"
    echo -e "\033[1;31mInvalide\033[0m" >> debug.txt
    all_tests_passed=false
fi

# ---------------------- Fin et netoyage ----------------------
echo -e "\033[1;33m\nRunning Makefile commands...\033[0m"
echo -e "\033[1;33m\nRunning Makefile commands...\033[0m" >> debug.txt
echo -e "\033[1;36mRunning make fclean...\033[0m"
echo -e "\033[1;36mRunning make fclean...\033[0m" >> debug.txt
make fclean > .make.txt 2>&1
if [ $? -ne 0 ]; then
    cat .make.txt >> debug.txt
    echo -e "\033[1;31mInvalide\033[0m"
    echo -e "\033[1;31mInvalide\033[0m" >> debug.txt
    all_tests_passed=false
else
    echo -e "\033[1;32mValide\033[0m"
    echo -e "\033[1;32mValide\033[0m" >> debug.txt
fi

rm -f .make.txt .output.txt .expected.txt .valgrind.txt

if $all_tests_passed; then
    rm -f debug.txt
    echo -e "\033[1;32m\nTous les tests sont valides.\033[0m"
else
    echo -e "\033[1;31m\nCertains tests ont échoué. Consultez debug.txt pour les détails.\033[0m"
fi