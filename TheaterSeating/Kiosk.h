////////////////////////////////////////////////////////////////////////////////
// Instructor: R. Bradley Andrews
// Class: PRG/410
// Group: Team-A
//
// Contributing Members:
//    Aaron Jackson
//    Rudy Pena
//    Troy Shannon
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "Seat.h"
#include "Theater.h"

#include <vector>

/// <summary>
/// Represents a kiosk that provides a user with the ability to purchase tickets
/// or get information about available tickets.
/// </summary>
class Kiosk {
private:
	Theater _theater;
	vector<Seat_ptr> _seatsPurchased;

public:
	/// <summary>
	/// Displays the welcome message.
	/// </summary>
	void displayWelcomeMessage();
	/// <summary>
	/// Displays the help message.
	/// </summary>
	void displayHelp();
	/// <summary>
	/// Displays the summary information.
	/// </summary>
	void displaySummary();
	/// <summary>
	/// Displays the summary information for a set of seats.
	/// </summary>
	void displaySummary(vector<Seat_ptr>& seatsToReview);	
	/// <summary>
	/// Shows the seating by row.
	/// </summary>
	/// <param name="row">The row.</param>
	bool showSeatingByRow(int row);
	/// <summary>
	/// Shows the seating by row.
	/// </summary>
	void showSeatingByRow();
	/// <summary>
	/// Shows the seating (all).
	/// </summary>
	void showSeating();
	/// <summary>
	/// Shows the # of tickets available.
	/// </summary>
	void showSeatsAvailable();
	/// <summary>
	/// Shows the # of tickets sold.
	/// </summary>
	void showSeatsSold();	
	/// <summary>
	/// Shows the prices of all seats.
	/// </summary>
	void showPrices();
	/// <summary>
	/// Help the user purchase tickets.
	/// </summary>
	void purchaseSeats();
	/// <summary>
	/// Displays a messge when an invalid option is chosen.
	/// </summary>
	/// <param name="option">The option.</param>
	void displayInvalidOption(string option);

	/// <summary>
	/// Gets a command from the user.  Processes that command and
	/// returns true if we should continue processing.
	/// </summary>
	bool doUserCommand();

	/// <summary>
	/// Starts the user session.  This method only returns
	/// when the user has completed their interactive session.
	/// </summary>
	void startUserSession();
};
