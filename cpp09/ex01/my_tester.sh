#!/bin/bash

BLUE='\033[0;34m'
GREEN='\033[0;32m'
RED='\033[0;31m'
END='\033[0m'

echo "Subject tests:"
echo "-------------------------------------------"

echo "./RPN \"8 9 * 9 - 9 - 9 - 4 - 1 +\""
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
echo -e "${BLUE}[42]\n${END}"


echo "./RPN \"7 7 * 7 -\""
./RPN "7 7 * 7 -"
echo -e "${BLUE}[42]\n${END}"

echo "./RPN \"1 2 * 2 / 2 * 2 4 - +\""
./RPN "1 2 * 2 / 2 * 2 4 - +"
echo -e "${BLUE}[0]\n${END}"

echo "./RPN \"(1 + 1)\""
./RPN "(1 + 1)"
echo -e "${BLUE}[Invalid input]\n${END}"

echo -e "${GREEN}Should return valid value:"
echo -e "-------------------------------------------${END}"

echo "./RPN \"1\""
./RPN "1"
echo -e "${BLUE}[1]\n${END}"

echo "./RPN \"1  \""
./RPN "1  "
echo -e "${BLUE}[1]\n${END}"

echo "./RPN \"   1  \""
./RPN "   1  "
echo -e "${BLUE}[1]\n${END}"

echo "./RPN \"4  +2  5  *  +   \""
./RPN "4  +2  5  *  +   "
echo -e "${BLUE}[14]\n${END}"

echo "./RPN \" 1 +2 + 3 4 + *\""
./RPN " 1 +2 + 3 4 + *"
echo -e "${BLUE}[21]\n${END}"

echo "./RPN \"1 2 3 * + +4 +\""
./RPN "1 2 3 * + +4 +"
echo -e "${BLUE}[11]\n${END}"

echo "./RPN \"1 2 + 3 * 4 + \""
./RPN "1 2 + 3 * 4 + "
echo -e "${BLUE}[13]\n${END}"

echo "./RPN \" 4    2  5  *    +  1  +3  2  *  +    /\""
./RPN " 4    2  5  *    +  1  +3  2  *  +      /"
echo -e "${BLUE}[2]\n${END}"

echo "./RPN \"4  8  +  +1  3  +  /\""
./RPN "4  8  +  +1  3  +  /"
echo -e "${BLUE}[3]\n${END}"

echo "./RPN \"-8 -2 /\""
./RPN "-8 -2 /"
echo -e "${BLUE}[4]\n${END}"

echo "./RPN \"8 -2 /\""
./RPN "8 -2 /"
echo -e "${BLUE}[-4]\n${END}"

echo "./RPN \"1 5 -9 3 4 -7 6 5 2 -4 0 4 5 + - * / + - * / - - + -\""
./RPN "1 5 -9 3 4 -7 6 5 2 -4 0 4 5 + - * / + - * / - - + -"
echo -e "${BLUE}[3]\n${END}"

echo "./RPN \"6 5 1 3 4 7 6 5 2 4 9 5 4 1 0 4 5 + - * / + - * / - - + + - /  + -\""
./RPN "6 5 1 3 4 7 6 5 2 4 9 5 4 1 0 4 5 + - * / + - * / - - + + - /  + -"
echo -e "${BLUE}[1]\n${END}"

echo -e "${RED}Should return error message:"
echo -e "------------------------------------------- ${END}"

echo "./RPN \"8 0 /\""
./RPN "8 0 /"
echo -e "${BLUE}[Invalid input]\n${END}"

echo "./RPN \"1 +\""
./RPN "1 +"
echo -e "${BLUE}[Invalid input]\n${END}"

echo "./RPN \"1 + +\""
./RPN "1 + +"
echo -e "${BLUE}[Invalid input]\n${END}"

echo "./RPN \"1 1\""
./RPN "1 1"
echo -e "${BLUE}[Invalid input]\n${END}"

echo "./RPN \"1 1 5\""
./RPN "1 1 5"
echo -e "${BLUE}[Invalid input]\n${END}"

echo "./RPN \"28  6  2  4  *  +  /\""
./RPN " 28  6  2  4  *  +  /"
echo -e "${BLUE}[Invalid input]\n${END}"

echo "./RPN \"8 -2 / /\""
./RPN "8 -2 / /"
echo -e "${BLUE}[Invalid input]\n${END}"

echo "./RPN \"- 8 2 +\""
./RPN "- 8 2 +"
echo -e "${BLUE}[Invalid input]\n${END}"

echo "./RPN \"6 5 1 3 4 7 6 5 2 4 9 4 5 + - * / + - * / - - +\""
./RPN "6 5 1 3 4 7 6 5 2 4 9 4 5 + - * / + - * / - - +"
echo -e "${BLUE}[Invalid input]\n${END}"

echo "./RPN \"6 5 1 3 4 7 6 5 2 4 9 5 4 1 0 4 5 + - * / + - * / - - + + - /  + - + \""
./RPN "6 5 1 3 4 7 6 5 2 4 9 5 4 1 0 4 5 + - * / + - * / - - + + - /  + - + "
echo -e "${BLUE}[Invalid input]\n${END}"
