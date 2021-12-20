//== operator - medlemsfunktion
	Header
			bool operator==(const StraightLine&) const;

	Source
			bool StraightLine::operator==(const StraightLine& correctLine) const
			{
				return (slope_ == correctLine.slope_ && yCross_ == correctLine.yCross_);
			}


//+= operator - medlemsfunktion
	Header
			void Point::operator+=(const Point & rightRef);


	Source
			void Point::operator+=(const Point& rightRef)
			{
				setX(x_ + rightRef.x_);
				setY(y_ + rightRef.y_);
			}


// / operator - medlemsfunktion
	Header
			const Point Point::operator/(double divisor) const:


	Source
			const Point Point::operator/(double divisor) const
			{
				return Point(x_ / divisor, y_ / divisor);
			}


// + operator - fri funktion
	Header
		const Point operator+(const Point & leftRef, const Point & rightRef);

	Source
		const Point operator+(const Point& leftRef, const Point& rightRef)
		{
			return Point(leftRef.getX() + rightRef.getX(), leftRef.getY() + rightRef.getY());
		}


// - operator - fri funktion
	Header
		const Point operator-(const Point & leftRef, const Point & rightRef);


	Source
		const Point operator+(const Point& leftRef, const Point& rightRef)
		{
			return Point(leftRef.getX() - rightRef.getX(), leftRef.getY() - rightRef.getY());
		}



// << ostream operator - fri funktion(altid)
	Header	
			ostream & operator<<(ostream & output, const Point & rightRef);
	Altid const ved referencen

	Source
			ostream& operator<<(ostream& output, const Point& rightRef)
			{
				output << "(" << rightRef.getX() << " , " << rightRef.getY() << ")";

				return output;
			}


// >> istream operator - fri funktion(altid)
	Header
			istream& operator>> (istream& input, Point& rightRef);

	Source
			istream& operator>> (istream& input, Point& rightRef)
			{
				double a, b;

				input >> a >> b;

				rightRef.setX(a);
				rightRef.setY(b);

				return input;
			}

// [] index operator - fri funktion(altid)
	Header
			int& operator[](int);

	Source
			int& Array::operator[](int index)
			{
				if (index >= size) {
					cout << "Array index out of bound, exiting";
					exit(0);
				}
				return ptr[index];
			}

// < operator

	Header //fri funktion
	bool operator<(const Kasse& kasse1, const Kasse& kassek2);

	Source
	bool operator<(const Kasse& kasse1, const Kasse& kasse2)
	{
		if (kasse1.beregnVolumen() < kasse2.beregnVolumen()) 
		{
			return true;
		}

		return false;
	}

// > operator
	Header
	bool operator>(const Kasse& kasse1, const Kasse& kassek2);

	Source
	bool operator>(const Kasse& kasse1, const Kasse& kasse2)
	{
		return (kasse1.beregnVolumen() > kasse2.beregnVolumen() ? true : false);
	}
DISSE TING IMPLEMENTERES OG TESTES NORMALT