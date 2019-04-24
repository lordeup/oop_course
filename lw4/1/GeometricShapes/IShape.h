#pragma once

class IShape
{
public:
	IShape() = default;
	virtual ~IShape() = default;

	virtual double GetArea() const = 0;
	virtual double GetPerimeter() const = 0;
	virtual void PrintInfo(std::ostream& iss) const = 0;
	virtual std::string GetOutlineColor() const = 0;
};
