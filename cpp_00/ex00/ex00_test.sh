#!/bin/bash

all_tests_passed=true
echo -e "\033[1;33mRunning tests for ex00...\033[0m" > debug.txt
echo -e "\033[1;33mRunning tests for ex00...\033[0m"

# Test 1
echo -e "\033[1;36mTest 1:\033[0m" >> debug.txt
echo -e "\033[1;36mTest 1:\033[0m"
./megaphone "shhhhh... I think the students are asleep..." > output.txt
echo -n "SHHHHH... I THINK THE STUDENTS ARE ASLEEP...
" > expected.txt
if diff -q output.txt expected.txt >> /dev/null 2>&1; then
    echo -e "\033[1;32mValide\033[0m"
    echo -e "\033[1;32mValide\033[0m" >> debug.txt
else
    all_tests_passed=false
    echo -e "\033[1;31mInvalide\033[0m"
    echo -e "\033[1;33mOutput megaphone:\033[0m" >> debug.txt
    cat output.txt >> debug.txt
    echo -e "\033[1;33mOutput expected:\033[0m" >> debug.txt
    cat expected.txt >> debug.txt
    echo -e "" >> debug.txt
fi

# Test 2
echo -e "\033[1;36mTest 2:\033[0m" >> debug.txt
echo -e "\033[1;36mTest 2:\033[0m"
./megaphone Damnit " ! " "Sorry students, I thought this thing was off." > output.txt
echo -n "DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.
" > expected.txt
if diff -q output.txt expected.txt >> /dev/null 2>&1; then
    echo -e "\033[1;32mValide\033[0m"
    echo -e "\033[1;32mValide\033[0m" >> debug.txt
else
    all_tests_passed=false
    echo -e "\033[1;31mInvalide\033[0m"
    echo -e "\033[1;33mOutput megaphone:\033[0m" >> debug.txt
    cat output.txt >> debug.txt
    echo -e "\033[1;33mOutput expected:\033[0m" >> debug.txt
    cat expected.txt >> debug.txt
    echo -e "" >> debug.txt
fi

# Test 3
echo -e "\033[1;36mTest 3:\033[0m" >> debug.txt
echo -e "\033[1;36mTest 3:\033[0m"
./megaphone "" > output.txt
echo -n "* LOUD AND UNBEARABLE FEEDBACK NOISE *
" > expected.txt
if diff -q output.txt expected.txt >> /dev/null 2>&1; then
    echo -e "\033[1;32mValide\033[0m"
    echo -e "\033[1;32mValide\033[0m" >> debug.txt
else
    all_tests_passed=false
    echo -e "\033[1;31mInvalide\033[0m"
    echo -e "\033[1;33mOutput megaphone:\033[0m" >> debug.txt
    cat output.txt >> debug.txt
    echo -e "\033[1;33mOutput expected:\033[0m" >> debug.txt
    cat expected.txt >> debug.txt
    echo -e "" >> debug.txt
fi

# Test 4
echo -e "\033[1;36mTest 4:\033[0m" >> debug.txt
echo -e "\033[1;36mTest 4:\033[0m"
./megaphone "" "" "" > output.txt
echo -n "* LOUD AND UNBEARABLE FEEDBACK NOISE *
" > expected.txt
if diff -q output.txt expected.txt >> /dev/null 2>&1; then
    echo -e "\033[1;32mValide\033[0m"
    echo -e "\033[1;32mValide\033[0m" >> debug.txt
else
    all_tests_passed=false
    echo -e "\033[1;31mInvalide\033[0m"
    echo -e "\033[1;33mOutput megaphone:\033[0m" >> debug.txt
    cat output.txt >> debug.txt
    echo -e "\033[1;33mOutput expected:\033[0m" >> debug.txt
    cat expected.txt >> debug.txt
    echo -e "" >> debug.txt
fi

# Test 5
echo -e "\033[1;36mTest 5:\033[0m" >> debug.txt
echo -e "\033[1;36mTest 5:\033[0m"
./megaphone > output.txt
echo -n "* LOUD AND UNBEARABLE FEEDBACK NOISE *
" > expected.txt
if diff -q output.txt expected.txt >> /dev/null 2>&1; then
    echo -e "\033[1;32mValide\033[0m"
    echo -e "\033[1;32mValide\033[0m" >> debug.txt
else
    all_tests_passed=false
    echo -e "\033[1;31mInvalide\033[0m"
    echo -e "\033[1;33mOutput megaphone:\033[0m" >> debug.txt
    cat output.txt >> debug.txt
    echo -e "\033[1;33mOutput expected:\033[0m" >> debug.txt
    cat expected.txt >> debug.txt
    echo -e "" >> debug.txt
fi

# Valgrind Tests
echo -e ""
echo -e "\033[1;33mRunning valgrind for ex00...\033[0m"

# Valgrind Test 1
echo -e "\033[1;36mValgrind Test 1:\033[0m" >> debug.txt
echo -e "\033[1;36mValgrind Test 1:\033[0m"
valgrind --leak-check=full ./megaphone "shhhhh... I think the students are asleep..." > valgrind_tmp.txt 2>&1
if grep -q "ERROR SUMMARY: 0 errors" valgrind_tmp.txt; then
    echo -e "\033[1;32mValide\033[0m" >> debug.txt
    echo -e "\033[1;32mValide\033[0m"
else
    all_tests_passed=false
    echo -e "\033[1;31mInvalide\033[0m"
    echo -e "\033[1;31mInvalide\033[0m" >> debug.txt
    cat valgrind_tmp.txt >> debug.txt
    echo -e "" >> debug.txt
fi

# Valgrind Test 2
echo -e "\033[1;36mValgrind Test 2:\033[0m" >> debug.txt
echo -e "\033[1;36mValgrind Test 2:\033[0m"
valgrind --leak-check=full ./megaphone Damnit " ! " "Sorry students, I thought this thing was off." > valgrind_tmp.txt 2>&1
if grep -q "ERROR SUMMARY: 0 errors" valgrind_tmp.txt; then
    echo -e "\033[1;32mValide\033[0m" >> debug.txt
    echo -e "\033[1;32mValide\033[0m"
else
    all_tests_passed=false
    echo -e "\033[1;31mInvalide\033[0m"
    echo -e "\033[1;31mInvalide\033[0m" >> debug.txt
    cat valgrind_tmp.txt >> debug.txt
    echo -e "" >> debug.txt
fi

# Valgrind Test 3
echo -e "\033[1;36mValgrind Test 3:\033[0m" >> debug.txt
echo -e "\033[1;36mValgrind Test 3:\033[0m"
valgrind --leak-check=full ./megaphone "" > valgrind_tmp.txt 2>&1
if grep -q "ERROR SUMMARY: 0 errors" valgrind_tmp.txt; then
    echo -e "\033[1;32mValide\033[0m" >> debug.txt
    echo -e "\033[1;32mValide\033[0m"
else
    all_tests_passed=false
    echo -e "\033[1;31mInvalide\033[0m"
    echo -e "\033[1;31mInvalide\033[0m" >> debug.txt
    cat valgrind_tmp.txt >> debug.txt
    echo -e "" >> debug.txt
fi

# Valgrind Test 4
echo -e "\033[1;36mValgrind Test 4:\033[0m" >> debug.txt
echo -e "\033[1;36mValgrind Test 4:\033[0m"
valgrind --leak-check=full ./megaphone "" "" "" > valgrind_tmp.txt 2>&1
if grep -q "ERROR SUMMARY: 0 errors" valgrind_tmp.txt; then
    echo -e "\033[1;32mValide\033[0m" >> debug.txt
    echo -e "\033[1;32mValide\033[0m"
else
    all_tests_passed=false
    echo -e "\033[1;31mInvalide\033[0m"
    echo -e "\033[1;31mInvalide\033[0m" >> debug.txt
    cat valgrind_tmp.txt >> debug.txt
    echo -e "" >> debug.txt
fi

# Valgrind Test 5
echo -e "\033[1;36mValgrind Test 5:\033[0m" >> debug.txt
echo -e "\033[1;36mValgrind Test 5:\033[0m"
valgrind --leak-check=full ./megaphone > valgrind_tmp.txt 2>&1
if grep -q "ERROR SUMMARY: 0 errors" valgrind_tmp.txt; then
    echo -e "\033[1;32mValide\033[0m" >> debug.txt
    echo -e "\033[1;32mValide\033[0m"
else
    all_tests_passed=false
    echo -e "\033[1;31mInvalide\033[0m"
    echo -e "\033[1;31mInvalide\033[0m" >> debug.txt
    cat valgrind_tmp.txt >> debug.txt
    echo -e "" >> debug.txt
fi

# Nettoyer le fichier temporaire
rm -f valgrind_tmp.txt output.txt expected.txt

if $all_tests_passed; then
    rm -f debug.txt
    echo -e ""
    echo -e "\033[1;32mTous les tests sont valides.\033[0m"
else
    echo -e ""
    echo -e "\033[1;31mCertains tests ont échoué. Consultez debug.txt pour les détails.\033[0m"
fi