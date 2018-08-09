#pragma once

#include "Seat.h"

#include <array>

using namespace std;

#define NROWS 10
#define NCOLS 10

/// <summary>
/// This class represents the theater.
/// </summary>
class Theater {
private:
	/// <summary>
	/// the theater is a 10x10 matrix of seats.  This structure simply
	/// represents the seats in the theater.  Given a seat, you can
	/// get information about its price or availability.
	/// </summary>
	array<array<Seat, NROWS>, NCOLS> _seating;	
	/// <summary>
	/// The # of tickets sold.
	/// </summary>
	int _ticketsSold;

public:
	/// <summary>
	/// Returns the # of tickets available.
	/// </summary>
	inline int getTicketsAvailable() const {
		return 100 - _ticketsSold;
	}
	
	/// <summary>
	/// Returns the # of tickets sold.
	/// </summary>
	inline int getTicketsSold() const {
		return _ticketsSold;
	}
	
	/// <summary>
	/// Attempts to take the seat at row, col.  If the seat is occupied,
	/// then the method returns false.  If the seat is available, the
	/// method returns true and marks the seat as sold.
	/// </summary>
	/// <param name="row">The row.</param>
	/// <param name="col">The col.</param>
	/// <returns></returns>
	bool tryTakeSeat(int row, int col);

	/// <summary>
	/// Returns the seat at the specified location.
	/// </summary>
	/// <param name="row">The row.</param>
	/// <param name="col">The col.</param>
	inline Seat& getSeat(int row, int col) {
		return _seating[row][col];
	}
	
	/// <summary>
	/// Returns all of the seats in a specified row.
	/// </summary>
	/// <param name="row">The row.</param>
	/// <returns></returns>
	inline const array<Seat, NCOLS>& getRow(int row) {
		return _seating[row];
	}

	/// <summary>
	/// Initializes a new instance of the <see cref="CTheater"/> class.
	/// </summary>
	Theater();
};
