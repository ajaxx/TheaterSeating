#include "stdafx.h"
#include "Kiosk.h"

#include <iostream>
#include <string>

using namespace std;

/// <summary>
/// Displays the welcome message.
/// </summary>
void Kiosk::displayWelcomeMessage() {
	cout << "Welcome to the Team A - Theater Seating Kiosk" << endl;
	cout << "--------------------------------------------------" << endl;
	cout << endl;
}

/// <summary>
/// Displays the help message.
/// </summary>
void Kiosk::displayHelp() {
	cout << "Please select an option from the list below:" << endl;
	cout << "  b - Purchase tickets." << endl;
	cout << "  r - Display available seating by row." << endl;
	cout << "  a - Display available seating (theater-wide)." << endl;
	cout << "  s - Display # of tickets sold." << endl;
	cout << "  q - Display # of tickets available." << endl;
	cout << "  x - End the session." << endl;
	cout << "  ? - Display this message." << endl;
	cout << endl;
}

/// <summary>
/// Displays the summary information.
/// </summary>
void Kiosk::displaySummary() {
}

/// <summary>
/// Shows the seating by row.
/// </summary>
void Kiosk::showSeatingByRow() {
}

/// <summary>
/// Shows the seating (all).
/// </summary>
void Kiosk::showSeating() {
}

/// <summary>
/// Shows the # of tickets available.
/// </summary>
void Kiosk::showTicketsAvailable() {
}

/// <summary>
/// Shows the # of tickets sold.
/// </summary>
void Kiosk::showTicketsSold() {
}

/// <summary>
/// Help the user purchase tickets.
/// </summary>
void Kiosk::purchaseTickets() {
}

/// <summary>
/// Displays a messge when an invalid option is chosen.
/// </summary>
/// <param name="option">The option.</param>
void Kiosk::displayInvalidOption(string option) {
	cout << endl;
	cout << "The option you have selected (" << option << ") is invalid.  Please try a different option." << endl;
	cout << endl;
}

/// <summary>
/// Gets a command from the user.  Processes that command and
/// returns true if we should continue processing.
/// </summary>
bool Kiosk::doUserCommand() {
	// display a command prompt to the user
	displayHelp();

	cout << "Enter choice: ";
	cout.flush();

	// Get a command from the user
	string command;
	getline(cin, command);

	// Check the command.
	// We know that if the enter zero characters it's an error.
	// We also know that if the enter more than 1 character that it's an error.
	if (command.length() == 1) {
		// The first character in the command is all that we need.  We can use
		// a switch statement to determine which path to take.
		switch (command[0]) {
		case 'b':
			purchaseTickets();
			return true;
		case 'r':
			showSeatingByRow();
			return true;
		case 'a':
			showSeating();
			return true;
		case 's':
			showTicketsSold();
			return true;
		case 'q':
			showTicketsAvailable();
			return true;
		case 'x':
			displaySummary();
			return false;
		case '?':
			// Do nothing.  The application will cycle back around and display the
			// help menu to the user.
			return false;
		default:
			// We intentionally do nothing with the default case.  It will fall
			// through and be handled as an invalid input.
			break;
		}
	}

	displayInvalidOption(command);
	return true;  // returning true will repeat the cycle
}

/// <summary>
/// Starts the user session.  This method only returns
/// when the user has completed their interactive session.
/// </summary>
void Kiosk::startUserSession() {
	displayWelcomeMessage();
	while (doUserCommand()) {
		// Continue processing until the user has told us to stop
	}
}