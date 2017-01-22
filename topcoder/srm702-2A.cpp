#include <iostream>

class TestTaking{
	public:
     int findMax(int questions, int guessed, int actual){
     	return questions-(guessed>actual?guessed-actual:actual-guessed);
     }
};
