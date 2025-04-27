/*
 * Name: Zachary White
 * Course: CS310
 * Professor: Robert Flowers
 * Assignment: Voting Calculator
 */

/*
 * This program prompts the user for names and votes.
 * The program will then print and calculate the total of percentage of votes for each candidate.
 * The program does not account for input validation on names, nor does it account for duplication.
 * Meaning multiple cnadidates may have the same last name and varrying totals of votes.
 */

/*
 * Tested: Windows 11
 * IDE: Visual Studio Code
 */ 

#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <vector>

using namespace std;

// --- Global constants ---
constexpr int N_CANDIDATES = 5;       // Number of candidates
constexpr int MAX_NAME_LENGTH = 20;   // Maximum allowed length for a candidate's last name

// Prototype Functions
void Candidates(string names[], int votes[]);
int Totalvotes(const int votes[]);
void PercentageValidation(const int votes[], double percentages[], int totalVotes);
vector<int> Winners(const int votes[]);
void ResultPrinted(const string names[], const int votes[], const double percentages[], int totalVotes, const vector<int>& winners);

int main() {
    // Arrays that store candidate data and information
    string candidateNames[N_CANDIDATES];
    int candidateVotes[N_CANDIDATES];
    double candidatePercentages[N_CANDIDATES];

    // Step 1: Get candidates' names and votes
    Candidates(candidateNames, candidateVotes);

    // Step 2: Calculate total number of votes
    int totalVotes = Totalvotes(candidateVotes);

    // Step 3: Calculate the vote percentage for each candidate
    PercentageValidation(candidateVotes, candidatePercentages, totalVotes);

    // Step 4: We determine the winner 
    vector<int> winners = Winners(candidateVotes);

    // Step 5: We print the final election results
    ResultPrinted(candidateNames, candidateVotes, candidatePercentages, totalVotes, winners);

    return 0;
}

// Candidates: Input candidates' names and votes with validation
void Candidates(string names[], int votes[]) {
    cout << "Enter the last names and number of votes for " << N_CANDIDATES << " candidates.\n" << endl;

    for (int i = 0; i < N_CANDIDATES; ++i) {
        // Input candidate's last name
        cout << "Candidate " << (i + 1) << " last name: ";
        getline(cin, names[i]);
        while (names[i].empty() || names[i].length() > MAX_NAME_LENGTH) {
            cout << "Invalid input. Name must not be empty or longer than " << MAX_NAME_LENGTH << " characters.\n";
            cout << "Candidate " << (i + 1) << " last name: ";
            getline(cin, names[i]);
        }

        // Input candidate's votes
        cout << "Number of votes for " << names[i] << ": ";
        while (!(cin >> votes[i]) || votes[i] < 0) {
            cin.clear(); // Clear input error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid input. Enter a non-negative whole number: ";
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear leftover input for getline()

        cout << endl;
    }
}

//  Totalvotes: Sums up all votes for each candidate
int Totalvotes(const int votes[]) {
    int total = 0;
    for (int i = 0; i < N_CANDIDATES; ++i) {
        total += votes[i];
    }
    return total;
}

// PercentageValidation: Calculate each candidate's percentage of the total votes
void PercentageValidation(const int votes[], double percentages[], int totalVotes) {
    if (totalVotes == 0) {
        // If no votes were casted, set all percentages to 0
        for (int i = 0; i < N_CANDIDATES; ++i) {
            percentages[i] = 0.0;
        }
    } else {
        // Calculate percentage for each candidate
        for (int i = 0; i < N_CANDIDATES; ++i) {
            percentages[i] = (static_cast<double>(votes[i]) / totalVotes) * 100.0;
        }
    }
}

// Winners: Identify the candidate(s) with the most votes
vector<int> Winners(const int votes[]) {
    vector<int> winners;
    int highest = votes[0];

    // Find highest vote count
    for (int i = 1; i < N_CANDIDATES; ++i) {
        if (votes[i] > highest) {
            highest = votes[i];
        }
    }

    // Collect all candidates with the highest number of votes
    for (int i = 0; i < N_CANDIDATES; ++i) {
        if (votes[i] == highest) {
            winners.push_back(i);
        }
    }

    return winners;
}

// 'ResultPrinted' Display final election results with proper format
void ResultPrinted(const string names[], const int votes[], const double percentages[], int totalVotes, const vector<int>& winners) {
    cout << fixed << setprecision(2);
    
    // Print header
    cout << left << setw(20) << "Candidate"
         << setw(15) << "Votes Received"
         << setw(15) << "% of Total Votes" << endl;
    cout << string(50, '-') << endl;

    // Print each candidate's results
    for (int i = 0; i < N_CANDIDATES; ++i) {
        cout << left << setw(20) << names[i]
             << setw(15) << votes[i]
             << setw(15) << percentages[i] << endl;
    }

    // Print total number of votes
    cout << string(50, '-') << endl;
    cout << left << setw(20) << "Total"
         << setw(15) << totalVotes << endl;

    // Print the winner or represent a tie situation
    if (totalVotes == 0) {
        cout << "\nNo votes were cast. There is no winner.\n";
    } else if (winners.size() == 1) {
        cout << "\nWinner of the election: " << names[winners[0]] << "!" << endl;
    } else {
        cout << "\nThere is a tie between:\n";
        for (int index : winners) {
            cout << "- " << names[index] << endl;
        }
    }
}
