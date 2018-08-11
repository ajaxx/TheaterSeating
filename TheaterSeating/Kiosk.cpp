#include "stdafx.h"
#include "Kiosk.h"
#include "Location.h"

#include <iomanip>
#include <iostream>
#include <list>
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
	cout << "  p - Display the prices of all seats." << endl;
	cout << "  x - End the session." << endl;
	cout << "  ? - Display this message." << endl;
	cout << endl;
}

/// <summary>
/// Displays the summary information.
/// </summary>
void Kiosk::displaySummary() {
	// We really dont need to keep track of tickets, we just need to know which seats have
	// been sold and how much revenue we have generated.  Lets display some summary information.

	cout << "Thank you for using the theater Kiosk.  Here is a summary of your session." << endl;
	cout << endl;
	//cout << _theater.getAvailableSeatCount() << " seats are still available." << endl;
	//cout << _theater.getOccupiedSeatCount() << " seats are currently occupied." << endl;

}

/// <summary>
/// Shows the seating by row.
/// </summary>
void Kiosk::showSeatingByRow() {
	// ask the user what row they would like to see
	while (true) {
		cout << endl;
		cout << "Enter the row # that you would like to see (e.g. 9 or -1 to return to the menu): ";
		cout.flush();

		string line;
		getline(cin, line);

		int row = ::stoi(line);
		if (row == -1) {
			return;
		}
		else if ((row < 1) || (row > NROWS)) {
			cout << "You have entered an invalid row." << endl;
			continue;
		}

		cout << endl;

		for (int col = 0; col < NCOLS; col++) {
			const Seat_ptr& seat = _theater.getSeat(row - 1, col);
			cout << " " << row << "," << (col + 1) << " - ";
			cout << (seat->isAvailable() ? "available" : "occupied");
			if (seat->isAvailable()) {
				cout << " - $" << seat->getPrice();
			}
			cout << endl;
		}

		cout << endl;
		return;
	}
}

/// <summary>
/// Shows the seating (all).
/// </summary>
void Kiosk::showSeating() {
	// tell the user what you are doing
	cout << endl;
	cout << "Here is the seating chart for the theater.  Seats that are taken are represented" << endl;
	cout << "by an * symbol, and seats that are available are represented by a # symbol." << endl;
	cout << endl;

	// table header
	cout << "      |";

	for (int col = 0; col < NCOLS; col++) {
		cout << "  " << (col + 1);
	}

	cout << endl;
	cout << "------+" << string(31, '-') << endl;

	// table body
	for (int row = 0; row < NROWS; row++) {
		cout << " R " << (row + 1);
		if (row < 9) {
			cout << ' ';
		}

		cout << " | ";

		for (int col = 0; col < NCOLS; col++) {
			const Seat_ptr& seat = _theater.getSeat(row, col);
			cout << " ";
			cout << (seat->isAvailable() ? '#' : '*');
			cout << " ";
		}

		cout << endl;
	}

	cout << endl;
}

/// <summary>
/// Shows the # of tickets available.
/// </summary>
void Kiosk::showTicketsAvailable() {
	cout << endl;
	cout << _theater.getAvailableSeatCount() << " seats are currently available." << endl;
	cout << endl;
}

/// <summary>
/// Shows the # of tickets sold.
/// </summary>
void Kiosk::showTicketsSold() {
	cout << endl;
	cout <<  _theater.getOccupiedSeatCount() << " seats are currently occupied." << endl;
	cout << endl;
}

/// <summary>
/// Shows the prices of all seats.
/// </summary>
void Kiosk::showPrices() {
	cout << std::fixed;
	cout << std::setprecision(0);

	// tell the user what you are doing
	cout << endl;
	cout << "Here are the prices for seats throughout the theater." << endl;
	cout << endl;

	// table header
	cout << "      |";

	for (int col = 0; col < NCOLS; col++) {
		cout << string(col < 9 ? 6 : 5, ' ');
		cout << (col + 1);
	}

	cout << endl;
	cout << "------+" << string(70, '-') << endl;

	// table body
	for (int row = 0; row < NROWS; row++) {
		cout << " R " << (row + 1);
		if (row < 9) {
			cout << ' ';
		}

		cout << " |";

		for (int col = 0; col < NCOLS; col++) {
			const Seat_ptr& seat = _theater.getSeat(row, col);
			cout << "   $" << seat->getPrice();
		}

		cout << endl;
	}

	cout << endl;
}

/// <summary>
/// Help the user purchase tickets.
/// </summary>
void Kiosk::purchaseTickets() {
	string exitLine("xx");

	list<Seat_ptr> seatsPurchased;

	while (true) {
		cout << endl;
		cout << "Please enter the seat (e.g. 1,3) you would like to purchase." << endl;
		cout << "    (enter xx to complete this purchase): ";
		cout.flush();

		string line;
		getline(cin, line);

		if (line == exitLine) {
			break;
		}

		try {
			Location location = Location::parse(line);
			if ((location.getRow() < 1) ||
				(location.getRow() > NROWS) ||
				(location.getColumn() < 1) ||
				(location.getColumn() > NCOLS)) {
				cout << endl;
				cout << "You have entered an invalid seat." << endl;
				continue;
			}

			cout << endl;

			// At this point we have a valid location.  Get the seat.
			if (!_theater.tryTakeSeat(location)) {
				cout << "Sorry, but the seat you have asked for is unavailable." << endl;
				continue;
			}

			// We have taken the seat.  Add the seat to the list of seats for this group
			// purchase.
			seatsPurchased.push_back(_theater.getSeat(location));

			// Let the user know that you have reserved that seat for them.
			cout << "We have reserved seat " << location << " for you." << endl;
		}
		catch (const ParseException& ex) {
			// TBD
		}
	}

	// We need to show summary information about the tickets that have been
	// purchased in this "purchasing" session.
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
		case 'p':
			showPrices();
			return true;
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