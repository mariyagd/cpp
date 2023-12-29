#include <iostream>

int	main()
{
	int	numberOfBalls = 42;

	int* ballsPtr = &numberOfBalls; // ballsPtr is a pointer to an int
									// initialized to the adress of numberOfBalls

	int& ballsRef = numberOfBalls; // ballsRef is a reference to an int
									// initialized to the value of numberOfBalls
	
	// int& ballsRef2; est faux, on ne peux pas avoir une reference qui pointe vers rien
	
	// *ballsPtr is dereferencing the pointer ballsPtr
	std::cout << numberOfBalls << " " << *ballsPtr << " " << ballsRef << std::endl;

	*ballsPtr = 21; // numberOfBalls is now equal to 21
	std::cout << numberOfBalls << std::endl;
	std::cout << numberOfBalls << " " << *ballsPtr << " " << ballsRef << std::endl;
	ballsRef = 84; // numberOfBalls is now equal to 84
	std::cout << numberOfBalls << std::endl;
	std::cout << numberOfBalls << " " << *ballsPtr << " " << ballsRef << std::endl;
	return (0);
}
