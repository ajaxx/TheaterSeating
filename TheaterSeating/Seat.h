////////////////////////////////////////////////////////////////////////////////
// Instructor: R. Bradley Andrews
// Class: PRG/410
// Group: Team-A
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "Location.h"

#include <memory>

/// <summary>
/// Represents a single seat in the theater.  Are all seats the same price?
/// </summary>
class Seat {
private:
	double _price;
	bool _available;
	Location _location;

public:	
	/// <summary>
	/// Gets the location of the seat.
	/// </summary>
	Location & getLocation() { return _location; }

	/// <summary>
	/// Sets the location of the seat.
	/// </summary>
	/// <param name="location">The location.</param>
	void setLocation(const Location& location) {
		_location = location;
	}

	/// <summary>
	/// Gets the price of the seat.
	/// </summary>
	/// <returns></returns>
	double getPrice() const { return _price; }

	/// <summary>
	/// Sets the price of the seat.
	/// </summary>
	/// <param name="price">The price.</param>
	void setPrice(const double price) { _price = price; }

	/// <summary>
	/// Determines whether this instance is available.
	/// </summary>
	/// <returns>
	///   <c>true</c> if this instance is available; otherwise, <c>false</c>.
	/// </returns>
	bool isAvailable() const { return _available; }

	/// <summary>
	/// Attempts to take the seat.  If the seat is occupied then the method returns 
	/// false.  If the seat is available, the method returns true and marks the seat 
	/// as unavailable.
	/// </summary>
	/// <param name="row">The row.</param>
	/// <param name="col">The column.</param>
	/// <returns></returns>
	bool tryTake();

	/// <summary>
	/// Initializes a new instance of the <see cref="Seat"/> class.
	/// </summary>
	Seat() : _price(0.0), _available(true), _location() {}
	
	/// <summary>
	/// Initializes a new instance of the <see cref="Seat"/> class.
	/// </summary>
	/// <param name="price">The price.</param>
	Seat(double price, const Location& location)
		: _price(price)
		, _available(true)
		, _location(location)
	{
	}
};

typedef std::shared_ptr<Seat> Seat_ptr;