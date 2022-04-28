#include "Menu.h"

Menu::Menu() {
	menu = "A|a add an offer\nS|s show all offers\nP|p filter offers by price\nT|t filter offers by type\nB|b filter offers by type and price\nQ|q quit\n";
	validInputs = { 'a', 's', 'p', 't', 'b', 'q', 'A', 'S', 'P', 'T', 'B', 'Q' };
}

void Menu::display_menu() const {
	std::cout << menu << " ";
}

void Menu::display_offers(DynamicArray& offers) const {
	if (offers.getLength())
		std::cout << offers << "\n";
	else std::cout << "No offers to show\n";
}

int Menu::get_task() const {
	string user_input;
	std::cout << "Your choice:";
	std::cin >> user_input;

	auto it = find(validInputs.begin(), validInputs.end(), user_input[0]);
	if (user_input.size() != 1 || it == validInputs.end()) {
		std::cout << "No valid command\n\n";
		return -1;
	}

	if (user_input[0] >= 'A' && user_input[0] <= 'Z') user_input[0] += 32;
	return user_input[0];
}

Offer Menu::get_offer() const {
	string id, departure, destination;
	unsigned int price;
	Date start, end;
	offer_type type;
	string _type;

	std::cout << "ID:";
	std::cin >> id;

	std::cout << "Departure:";
	std::cin >> departure;

	std::cout << "Destination:";
	std::cin >> destination;

	std::cout << "Price:";
	std::cin >> price;
	if (price < 0)
	{ 
		std::cout << "\033[1;31mPrice not valid!\033[0m\n";

		exit(-1); 
	}

	std::cout << "Starting date\n";
	unsigned int day, month, year;
	std::cout << "Day:";
	std::cin >> day;
	std::cout << "Month:";
	std::cin >> month;
	std::cout << "Year:";
	std::cin >> year;

	start = create_date(day, month, year);

	std::cout << "Ending date\n";
	std::cout << "Day:";
	std::cin >> day;
	std::cout << "Month:";
	std::cin >> month;
	std::cout << "Year:";
	std::cin >> year;
	end = create_date(day, month, year);

	if (start.year > end.year || (start.year == end.year && start.month > end.month) || (start.year == end.year && start.month == end.month && start.day > end.day))
	{
		std::cout << "\033[1;31mDate not valid!\033[0m\n";
		exit(-1);
	}
	std::cout << "Type:";
	std::cin >> _type;
	if (_type == "circuit") type = circuit;
	else if (_type == "cruise") type = cruise;
	else if (_type == "all_inlcusive") type = all_inclusive;
	else if (_type == "city_break") type = city_break;
	else
	{
		std::cout << "\033[1;31mInvalid type! (type must be one from ['circuit','cruise','all_inclusiv','city_brak'])\033[0m\n";
		exit(-1);
	}
	return Offer(id, departure, destination, price, start, end, type);

}

unsigned int Menu::get_price() const {
	std::cout << "Price:";
	unsigned int price; std::cin >> price;
	return price;
}

offer_type Menu::get_type() const {
	string input;
	std::cout << "Type:";
	std::cin >> input;
	offer_type type;

	if (input == "circuit")
		return type = circuit;
	else if (input == "cruise")
		return type = cruise;
	else if (input == "all_inlcusive")
		return type = all_inclusive;
	else if (input == "city_break")
		return type = city_break;
}


void Menu::start() const {

	DynamicArray offers;
	Offer offer;

	FilteringPrice f;
	FilteringType t;


	unsigned int price;
	offer_type type;

	while (true) {
		display_menu();
		char task = get_task();
		if (task == -1) continue;



		switch (task) {
		case 'a':
			offer = get_offer();
			offers.append(offer);
			break;

		case 's':
			display_offers(offers);
			break;

		case 'p': {
			price = get_price();
			f.set_price(price);
			offers = f.filter(offers);
		}
				break;

		case 't':
			type = get_type();
			t.set_type(type);
			offers = t.filter(offers);
			break;

		case 'b': {
			price = get_price();
			type = get_type();
			FilteringCriteriaTypeAndPrice ft(price, type);
			offers = ft.filter(offers);
		}
				break;

		case 'q':
			exit(0);
		}
	}
}