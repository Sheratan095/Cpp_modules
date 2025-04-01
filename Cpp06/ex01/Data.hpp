#include <string>
#include <iostream>

class Data
{
	private:
		std::string	strValue;
		int			changes;

	public:
		Data();
		Data(const Data &data);
		virtual	~Data();

		Data	&operator=(const Data &data);

		void		setStrValue(std::string str);
		std::string	getStrValue() const;
		int			getChanges() const;
};

std::ostream &operator<<(std::ostream &os, const Data &data);
