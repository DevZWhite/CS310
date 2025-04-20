/*
 * Name: Zachary White
 * Course: CS310
 * Instructor: Dr. Robert Flowers
 * Assignment: Remove Vowels from a String
 */

/*
 * This program prompts the user for a string,
 * then removes all vowels.
 * It handles input validation like empty inputs or, 
 * strings without vowels.
 * Expected Result: Inputted Sentence will not contain vowels
 */

#include <iostream>
#include <string>

using namespace std;
 
// prototyping
 bool VowelDetector(char c);
 string DeleteVowels(const string & input);
 
int main() {
    string input;
 
/* 
 * Prompting the user to enter a string
 * Allows capturing spaces and full line
 */
    cout << "Write out your sentence here:";
        getline(cin, input); 
 
// Error handling: This will check if input is empty
     if (input.empty()) {
         cerr << "Error: The string is empty." << endl;
         return 1;  // This exits with an error code
     }
 
     // Removing some of the vowels using the 'DeleteVowels' function
     string RemovedVowels = DeleteVowels(input);
 
// Error handling: This will check if original string had any vowels
     if (RemovedVowels.length() == input.length()) {
         cout << "Note: The string contains no vowels" << endl;
     }
 
// shows the results
     cout << "This is your string without vowels: " 
     << RemovedVowels << endl;
     return 0;
 }
 
/*
 * Function to determine if a character is a vowel
 * Wanted to convert to lowercase for a more uniform comparison
 */
    bool VowelDetector(char c) {
        c = tolower(c);
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
 }
 
// remove vowels from the sentence the user input.
 string DeleteVowels(const string & input) {
     string result = "";
 

/*
 * This will be used to iterate the function over each character of the input string.
 * If the character is not a vowel, we add it to the results string.
 */ 
for (int i = 0; i < input.length(); ++i) {
    if (!VowelDetector(input[i])) {
        result += input[i];
    }
}
// terminates the application.
    return result;
}
 
