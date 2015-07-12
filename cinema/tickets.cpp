#include <iostream>

using namespace std;

#define MAX_CAPACITY 200
#define TOTAL_ROOMS 8
#define LIMIT1 70
#define LIMIT2 85
#define HOUSEFULL 100

class Theater {
private:
	int room_number;
	int spectators;
	float capacity_filled;

public:
	static int last_stage_booked;

	Theater() {
		room_number = 0;
		spectators = 0;
		capacity_filled = 0;
	}

	int getSpectators() {
		return spectators;
	}

	float getCapacity() {
		return capacity_filled;
	}

	void addSpectator() {
		capacity_filled = float(++spectators * 100) / MAX_CAPACITY;
	}

	void setRoomNumber(int room_no) {
		if (room_no >= 0 && room_no < TOTAL_ROOMS)
			room_number = room_no + 1;
	}

	int getRoomNumber() {
		return room_number;
	}

	void printDetails() {
		cout << "A ticket was sold for Theater " << room_number << " which now has " 
			<< spectators << " spectators & " << capacity_filled << "% capacity." << endl;
	}

	/* Not requred, but ticket cancellation is a common scenario */
	void cancelTicket() {
		capacity_filled = float(--spectators * 100) / MAX_CAPACITY;
	}

	~Theater() {
	}
};

int Theater::last_stage_booked = 0;

/* Tempted to use TOTAL_ROOMS here but that would 
   mean I have to use -std=c++11 as g++ option */
Theater* rooms =  new Theater[8];

bool sell_ticket()
{
	int i = Theater::last_stage_booked;
	float filled;
	Theater* current;

	while (i < TOTAL_ROOMS) {
		current = &rooms[i];
		filled = current->getCapacity();

		/* This works because current limits are integers.
		   Need to take floor() of LIMIT1 & LIMIT2 for real type limits. */
		if (filled == float(LIMIT1) || filled == float(LIMIT2)) {
			i = ++i % 8;
			current = &rooms[i];
		} else if (filled == float(HOUSEFULL)) {
			if (++i == 8)
				break;

			current = &rooms[i];
		}

		current->addSpectator();
		Theater::last_stage_booked = i;

		return true;
	}

	return false;
}

int main()
{
	int sell = 1601; // 1601 is a good boundary case to test

	cout << "Enter the number of tickets to sell: " << endl;
	cin >> sell;
	if (sell <= 0 ) {
		cout << "Please enter a valid positive number. Exiting..." << endl;
		return -1;
	}

	for (int i =0; i < 8; i++) {
		rooms[i].setRoomNumber(i);
	}	

	cout.precision(4);

	while (sell-- > 0) {
		if (sell_ticket())
			rooms[Theater::last_stage_booked].printDetails();
		else
			cout << "Error: HOUSEFULL!!!" << endl; 
	}


	for (int i = 0; i < TOTAL_ROOMS; i++)
		cout << "Theater " << rooms[i].getRoomNumber() <<  " contains " << rooms[i].getSpectators() 
			<< " customers. It is " << rooms[i].getCapacity() << "% full." << endl;

	delete[] rooms;

	return 0;
}
