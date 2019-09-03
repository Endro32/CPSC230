/*
 * Main.cpp
 *
 *  Created on: Sep 3, 2019
 *      Author: stefan
 */

#include <iostream>
#include <string>

using namespace std;

int main() {
	//variables
	string adj1, pNoun1, pNoun2;
	string noun1, noun2;
	string verb1, verb2, verb3;

	//input
	cout << "Madlibs!\n\n" <<
			"You'll need to enter several words" <<
			"to compose the story.\n\n" <<
			"Enter an adjective: ";
	cin >> adj1;
	cout << "Enter a plural noun: ";
	cin >> pNoun1;
	cout << "Enter another plural noun: ";
	cin >> pNoun2;
	cout << "Now enter a singular noun: ";
	cin >> noun1;
	cout << "Enter another singular noun: ";
	cin >> noun2;
	cout << "Enter a past-tense verb: ";
	cin >> verb1;
	cout << "And another past-tense verb: ";
	cin >> verb2;
	cout << "And another past-tense verb: ";
	cin >> verb3;

	//output
	cout << "\nAlright, here is your story:\n" <<
			"Can We Go Home Now?\n\n" <<
			"The music roaring out of the speakers was loud and " <<
			adj1 << ". " << "Why did I agree to come with " <<
			"them here? My two sisters were dancing and singing " <<
			"along with the musicians on stage. At least they " <<
			"were having fun, right?" << endl <<
			"Me being the only boy in our small family, I was " <<
			"expected to do these kinds of things with my " <<
			pNoun1 << ", even though I absolutely HATED these " <<
			"kinds of things!";
	cout << "The music roaring out of the speakers was loud and " << adj1 << ".\n" <<
			"Why did I agree to come with them here? My two sisters were dancing\n" <<
			"and singing along with the musicians on stage. At least they were\n" <<
			"having fun, right?\nMe being the only boy in our small family, I was\n" <<
			"expected to do these kinds of things with my" << pNoun1 << ", even though\n" <<
			"I absolutely HATED these kinds of things! I was practically dragged\n" <<
			"to this concert against my will. I looked over to my older" << noun1 <<
			", Katie, and whispered into her ear, \"When can we leave? I'm getting bored.\”\n" <<
			"She looked my way and shrugged, as if she didn't know.\n" <<
			"\“Ask Zoe, after all it was her idea in the first place,” Katie said shortly after";

	return 0;
}
