#pragma once

#include "Seat.h"

#include <array>

using namespace std;

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
	array<array<Seat, 10>, 10> _seating;

public:
	/// <summary>
	/// Initializes a new instance of the <see cref="CTheater"/> class.
	/// </summary>
	Theater() {}
};
