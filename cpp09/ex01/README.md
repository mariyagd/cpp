### Why use `stack` ?


Consider you have:
```c++
4  2  5  *  + 
```

you firstly need to multiply `5 * 2` and then add 4 `4 + (5 * 2)`.
So you need to have access on the last number you added in your container.
And this is the main purpose of `std::stack`.

### TESTS

subject tests:
```c++
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"       // 42
./RPN "7 7 * 7 -"                       // 42
./RPN "1 2 * 2 / 2 * 2 4 - +"           // 0
./RPN "(1 + 1)"                         //invalid
```

valid inputs:
```c++
./RPN "1"
./RPN " 4"
./RPN "4      " 
./RPN "4  2  5  *  + "                                                          // returns 14 attention to the last space !
./RPN "1 2 + 3 4 + *"                                                           // returns 21 -> (1 + 2) * (3 + 4) = 3 * 7 = 21
./RPN "1 2 3 * + 4 +"                                                           // returns 11 -> 1 + (2 * 3) + 4 = 1 + 6 + 4 = 11 
./RPN "1 2 + 3 * 4 +"                                                           // returns 13 -> ( (1 + 2) * 3 ) + 4 = (3 * 3) + 4 = 9 + 4 = 13
./RPN "4  2  5  *  +  1  3  2  *  +  /"                                         // returns 2  -> (4 + 2 * 5) / (1 + 3 * 2) = (4 + 10) / ( 1 + 6) = 14 / 7 = 2;
./RPN "4  8  +  1  3  +  /"                                                     // returns 3  -> (4 + 8) / (1 + 3) = 12 / 4 = 3
./RPN "-8 -2 /"                                                                 // returns 4
./RPN "8 -2 /"                                                                  // returns -4
./RPN "1 5 -9 3 4 -7 6 5 2 -4 0 4 5 + - * / + - * / - - + -"                    // returns 8
./RPN "6 5 1 3 4 7 6 5 2 4 9 5 4 1 0 4 5 + - * / + - * / - - + + - /  + -"      // returns 1
```

returns error:
```c++
./RPN "8 0 /"                           // division by 0
./RPN "1 +"
./RPN "1 + +"
./RPN "1 1"
./RPN "1 1 5"
./RPN " 28  6  2  4  *  +  /"
./RPN "8 -2 / /"
./RPN "- 8 2 +"
```

