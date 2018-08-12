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

#include "stdafx.h"
#include "Theater.h"

/// <summary>
/// Initializes a new instance of the <see cref="CTheater"/> class.
/// </summary>

Theater::Theater() 
	: _seatsOccupied(0)
{
	
	// Each seat in the theater needs to have its own price.  Generally speaking, a theater
	// has prices that are the most expensive near the front (and center) and least expensive
	// at the back (and towards the edges).  Here we're going to initialize the prices for
	// the seats in the theater based on a front-to-back algorithm.

	double price = 200.0;
	double maxdist = sqrt(130.25); // sqrt(5.5*5.5 + 10*10)

	for (int row = 0; row < NROWS; row++) {
		for (int col = 0; col < NCOLS; col++) {
			double xdist = abs((double) col - 4.5);
			double ydist = NROWS - row;
			double rdist = sqrt(xdist * xdist + ydist * ydist);
			double discount = 1.0 - 0.5 * (rdist / maxdist); // maximum 50% discount based on distance
			double seatPrice = round(price * discount);
			Location location(row + 1, col + 1);
			_seating[row][col] = std::make_shared<Seat>(seatPrice, Location(row + 1, col + 1));
		}
	}
}

/// <summary>
/// Attempts to take the seat at row, col.  If the seat is occupied,
/// then the method returns false.  If the seat is available, the
/// method returns true and marks the seat as sold.
/// </summary>
/// <param name="row">The row.</param>
/// <param name="col">The col.</param>
/// <returns></returns>
bool Theater::tryTakeSeat(int row, int col) {
	Seat_ptr& seat = getSeat(row, col);
	if (seat->tryTake()) {
		_seatsOccupied++;
		return true;
	}

	return false;
}
