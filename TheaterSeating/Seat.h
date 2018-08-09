#pragma once

/// <summary>
/// Represents a single seat in the theater.  Are all seats the same price?
/// </summary>
class Seat {
private:
	double _price;
	bool _available;

public:
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
	/// Initializes a new instance of the <see cref="Seat"/> class.
	/// </summary>
	Seat() : _price(0.0), _available(false) {}
};
