#pragma once

#include "Theater.h"

/// <summary>
/// Represents a kiosk that provides a user with the ability to purchase tickets
/// or get information about available tickets.
/// </summary>
class Kiosk {
private:
	Theater _theater;

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
	void showTicketsAvailable();
	/// <summary>
	/// Shows the # of tickets sold.
	/// </summary>
	void showTicketsSold();
	/// <summary>
	/// Help the user purchase tickets.
	/// </summary>
	void purchaseTickets();
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
