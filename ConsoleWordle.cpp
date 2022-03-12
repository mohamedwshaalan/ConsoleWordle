#include <iostream>
#include <stdlib.h>
using namespace std;
int wordCheck(string guessedword, string correctword) {
	int colorcode = 0;
	int greenletters = 0;
	for (int i = 0; i < guessedword.size(); i++) { //LOOPING OVER BOTH WORDS
		bool flag=false;
		for (int j = 0; j < guessedword.size(); j++) {
			if (guessedword[i] == correctword[j]) { //CHECKING EACH LETTER
				flag = true;
				if (i != j) { //yellow
					cout << "\033[1;33m"<<guessedword[i]<<"\033[0m";
				} 
				else { //green
					cout << "\033[1;32m" << guessedword[i] << "\033[0m";
					greenletters++;
				}
				break;
			}		
			}
		if(!flag){

		cout << "\033[1;37m" << guessedword[i] << "\033[0m";
		}
	}
	return greenletters;
}
void gameWordle(int letternumber) {
	
	string correctword = "stern";
	
	for (int i = 0; i < (letternumber+1); i++) {
		string guessedword;
		cout << "Enter guess #" << (i + 1) << ":" << endl;
		cin >> guessedword;
		if (guessedword.size() != letternumber) {
			cout << "You've entered a wrong word size." << endl;
			i--;
			continue;
		}
		int greencount = wordCheck(guessedword, correctword);
		cout << endl;
		if (greencount == letternumber) {
			cout << "You've guessed the correct word in " << (i+1) << " tries!" << endl;
			break;
		}
		cout << endl;
	}
}
int main()
{
	int letternumber;
	cout << "Enter number of letters: " << endl;
	cin >> letternumber;
	gameWordle(letternumber);
	
}
