////////////////////////////////////////////////////////////////////////////////
// Instructor: R. Bradley Andrews
// Class: PRG/410
// Group: Team-A
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "Seat.h"
#include "Location.h"

#include <array>

using namespace std;

#define NROWS 10
#define NCOLS 9

/// <summary>
/// This class represents the theater.
/// </summary>
class Theater {
private:
	/// <summary>
	/// the theater is a 10x9 matrix of seats.  This structure simply
	/// represents the seats in the theater.  Given a seat, you can
	/// get information about its price or availability.
	/// </summary>
	array<array<Seat_ptr, NCOLS>, NROWS> _seating;	
	/// <summary>
	/// The # of tickets sold.
	/// </summary>
	int _seatsOccupied;

public:
	/// <summary>
	/// Returns the # of tickets available.
	/// </summary>
	inline int getAvailableSeatCount() const {
		return NROWS * NCOLS - _seatsOccupied;
	}
	
	/// <summary>
	/// Returns the # of tickets sold.
	/// </summary>
	inline int getOccupiedSeatCount() const {
		return _seatsOccupied;
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
	/// Attempts to take the seat at location.  If the seat is occupied,
	/// then the method returns false.  If the seat is available, the
	/// method returns true and marks the seat as sold.
	/// </summary>
	/// <param name="location">The location.</param>
	/// <returns></returns>
	bool tryTakeSeat(const Location& location) {
		return tryTakeSeat(location.getRow() - 1, location.getColumn() - 1);
	}

	/// <summary>
	/// Returns the seat at the specified location.
	/// </summary>
	/// <param name="row">The row.</param>
	/// <param name="col">The col.</param>
	inline Seat_ptr& getSeat(int row, int col) {
		return _seating[row][col];
	}

	/// <summary>
	/// Returns the seat at the specified location.
	/// </summary>
	/// <param name="row">The row.</param>
	/// <param name="col">The col.</param>
	inline Seat_ptr& getSeat(const Location& location) {
		return getSeat(location.getRow() - 1, location.getColumn() - 1);
	}

	/// <summary>
	/// Returns all of the seats in a specified row.
	/// </summary>
	/// <param name="row">The row.</param>
	/// <returns></returns>
	inline const array<Seat_ptr, NCOLS>& getRow(int row) {
		return _seating[row];
	}

	/// <summary>
	/// Initializes a new instance of the <see cref="CTheater"/> class.
	/// </summary>
	Theater();
};
