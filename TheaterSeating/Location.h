#pragma once

/// <summary>
/// Represents a single location in the theater.  These are identified
/// by their row and their column (aisle may be more appropriate).
/// </summary>
class Location {
private:
	int _row;
	int _column;

public:
	/// <summary>
	/// Returns the row #.
	/// </summary>
	inline int getRow() const { return _row; }
	/// <summary>
	/// Returns the column #.
	/// </summary>
	/// <returns></returns>
	inline int getColumn() const { return _column; }

	/// <summary>
	/// Initializes a new instance of the <see cref="Coordinate"/> class.
	/// </summary>
	Location() : _row(0), _column(0) {}
	/// <summary>
	/// Initializes a new instance of the <see cref="Coordinate"/> class.
	/// </summary>
	/// <param name="row">The row.</param>
	/// <param name="column">The column.</param>
	Location(const int row, const int column) : _row(row), _column(column) {}
};