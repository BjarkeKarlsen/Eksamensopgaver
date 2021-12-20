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

//+= operator - medlemsfunktion - se Januar 2019
	Header
			Stack& operator+=(int element);
	Source
			Stack& Stack::operator+=(int element)
			{
				if (stacktop_ < stacksize_) {
					dataPtr_[stacktop_] = element;
					stacktop_++;
				}
				return *this;
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


DISSE TING IMPLEMENTERES OG TESTES NORMALT 11

//Overload || and && if the resistor -- Januar 2021
			friend Resistor operator&&(const Resistor& right, const Resistor& left);
			friend Resistor operator||(const Resistor& right, const Resistor& left);
			Resistor operator&&(const Resistor& right, const Resistor& left);
			Resistor operator||(const Resistor& right, const Resistor& left);

			Resistor operator&&(const Resistor& right, const Resistor& left)
			{
				Resistor local(0);
				local = right.resistance_ + left.resistance_;
				return local;
			}

			Resistor operator||(const Resistor& right, const Resistor& left)
			{
				Resistor local(0);
				local.setConductance(right.getConductance() + left.getConductance());
				//local.resistance_ = (right.getResitance() * left.getResitance())/ (right.getResitance() + left.getResitance());
				//local.resistance_ = (right.resistance_ * left.resistance_) / (right.resistance_ + left.resistance_);
				return local;
			}

// ++ Pre operator  - medlems funktion
		Header
			const Person& operator++();

		Source
			const Person& Person::operator++()
			{
				if (vaccineStatus_ < 2) {
					vaccineStatus_++;
				}

				return *this;
			}

// ++ Post operator - medlems funktion
		Header
			Person operator++(int dummy);

		Source
			Person Person::operator++(int dummy)
			{
				Person local = *this;

				if (vaccineStatus_ < 2) {
					++((*this).vaccineStatus_);
					//vaccineStatus_++;
				}

				return local;
			}