////////////////////////////////////////////////////////////////////////////////
// Instructor: R. Bradley Andrews
// Class: PRG/410
// Group: Team-A
////////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Seat.h"

/// <summary>
/// Attempts to take the seat.  If the seat is occupied then the method returns 
/// false.  If the seat is available, the method returns true and marks the seat 
/// as unavailable.
/// </summary>
/// <param name="row">The row.</param>
/// <param name="col">The column.</param>
/// <returns></returns>
bool Seat::tryTake() {
	if (_available) {
		_available = false;
		return true;
	}
	
	return false;
}