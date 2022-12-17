#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Room
{
public:
	// Constructor By Default
	Room()
	{
		Name_ = nullptr;
		Width_ = 0;
		Lenght_ = 0;
		Height_ = 0;
		Ceiling_ = false;
	}
	// Copy Constructor
	Room(const Room& UserRoom)
	{
		Name_ = UserRoom.Name_;
		Width_ = UserRoom.Width_;
		Lenght_ = UserRoom.Lenght_;
		Height_ = UserRoom.Height_;
		Ceiling_ = UserRoom.Ceiling_;
	}
	// Add Room 
	void AddRoom()
	{
		cout << "Enter Name: " << endl;
		char Name[20];
		cin >> Name;
		Name_ = new char[strlen(Name) + 1];
		strcpy_s(Name_, strlen(Name) + 1, Name);

		cout << "Enter Width: " << endl;
		float Width;
		cin >> Width;
		Width_ = Width;

		cout << "Enter Lenght: " << endl;
		float Lenght;
		cin >> Lenght;
		Lenght_ = Lenght;

		cout << "Enter Height: " << endl;
		float Height;
		cin >> Height;
		Height_ = Height;

		cout << "Enter Ceiling: " << endl;
		int Ceiling;
		cin >> Ceiling;
		Ceiling_ = Ceiling;
	}
	// Show Rooms
	void Show() const
	{
		if (Name_ == nullptr)
		{
			return;
		}
		cout << "Name: " << Name_ << endl;
		cout << "Width: " << Width_ << endl;
		cout << "Lenght: " << Lenght_ << endl;
		cout << "Height: " << Height_ << endl;
		cout << "Ceiling: " << Ceiling_ << endl;
		cout << endl;
	}

	//Methods whose return value is used in the CalculateRoomCosts() method
	float getRoomWidth()
	{
		return Width_;
	}
	float getRoomLenght()
	{
		return Lenght_;
	}
	float getRoomHeight()
	{
		return Height_;
	}
	// Destructor
	~Room()
	{
		delete[] Name_;
	}

private:
	char* Name_;
	float Width_;
	float Lenght_;
	float Height_;
	bool Ceiling_;
};

class WallpaperUnit
{
public:
	// Constructor by Default
	WallpaperUnit()
	{
		Name_ = nullptr;
		Width_ = 0;
		Lenght_ = 0;
		Cost_ = 0;
	}
	// Copy Constructor
	WallpaperUnit(const WallpaperUnit& UserWalp)
	{
		Name_ = new char[strlen(UserWalp.Name_) + 1];
		strcpy_s(Name_, strlen(UserWalp.Name_) + 1, UserWalp.Name_);
		Width_ = UserWalp.Width_;
		Lenght_ = UserWalp.Lenght_;
		Cost_ = UserWalp.Cost_;
	}
	// Constructor with Parametres
	WallpaperUnit(const char* Name, int Width, int Lenght, float Cost)
	{
		Name_ = new char[strlen(Name) + 1];
		strcpy_s(Name_, strlen(Name) + 1, Name);
		Width_ = Width;
		Lenght_ = Lenght;
		Cost_ = Cost;
	}

	// Add Wallpaper Unit By Parametres
	void AddWallpaper(const char* Name, int Width, int Lenght, float Cost)
	{
		Name_ = new char[strlen(Name) + 1];
		strcpy_s(Name_, strlen(Name) + 1, Name);
		Width_ = Width;
		Lenght_ = Lenght;
		Cost_ = Cost;
		WallpaperCount++;
	}

	// Add Wallpaper Unit 
	WallpaperUnit* AddWallpaperUnit()
	{
		char Name[20];
		cout << "Enter Name: " << endl;
		cin >> Name;
		Name_ = new char[strlen(Name) + 1];
		strcpy_s(Name_, strlen(Name) + 1, Name);
		int Width;
		cout << "Enter Width: " << endl;
		cin >> Width;
		Width_ = Width;
		int Lenght;
		cout << "Enter Lenght: " << endl;
		cin >> Lenght;
		Lenght_ = Lenght;
		float Cost;
		cout << "Enter Cost: " << endl;
		cin >> Cost;
		Cost_ = Cost;
		return this;
	}

	// Show Wallpaper Unit
	void Show()
	{
		if (Name_ == nullptr)
		{
			return;
		}
		cout << "Name: " << Name_ << endl;
		cout << "Width: " << Width_ << endl;
		cout << "Lenght: " << Lenght_ << endl;
		cout << "Cost: " << Cost_ << endl;
		cout << endl;
	};

	// Destructor
	~WallpaperUnit()
	{
		delete[] Name_;
		WallpaperCount--;
	}

	//Methods whose return value is used in the CalculateRoomCosts() method
	float GetWallpaperLenght()
	{
		return Lenght_;
	}
	float GetWallpaperWidth()
	{
		return Width_;
	}
	float GetWallpaperCost()
	{
		return Cost_;
	}


private:
	char* Name_;
	int Width_;
	int Lenght_;
	float Cost_;
	static int WallpaperCount;
};
int WallpaperUnit::WallpaperCount = 0;
class Wallpaper
{
public:
	// Constructor By Default
	Wallpaper()
	{
		Unit_ = nullptr;
		WallpaperCount = 0;
	}
	// Copy Constructor
	Wallpaper(const Wallpaper& UserWalp)
	{
		Unit_ = new WallpaperUnit[UserWalp.WallpaperCount];
		WallpaperCount = UserWalp.WallpaperCount;
	}
	// Show 
	void Show()
	{
		if (Unit_ == nullptr)
			return;

		for (size_t i = 0; i < WallpaperCount; i++)
		{
			Unit_[i].Show();
		}
	};
	// Add Wallpaper Unit
	void AddWallpaper()
	{
		cout << "Enter count of Wallpapers to Add" << endl;
		int Count = 0;
		cin >> Count;
		Unit_ = new WallpaperUnit[Count];
		for (size_t i = 0; i < Count; i++)
		{
			Unit_[i].AddWallpaperUnit();
		}
		WallpaperCount = Count;
	}

	// Methods to work with Static Variable Count
	static int GetWallpaperCount()
	{
		return WallpaperCount;
	}
	static void SetWallpaperCount(int count)
	{
		WallpaperCount = count;
	}

	//Methods whose return value is used in the CalculateRoomCosts() method
	float SquareWallpaper(int choice)
	{
		return Unit_[choice].GetWallpaperLenght() * Unit_[choice].GetWallpaperWidth();
	}
	float WallpaperCost(int choice)
	{
		return Unit_[choice].GetWallpaperCost();
	}

	// Get Pointer WallpaperUnit
	Wallpaper* GetPtr()
	{
		return this;
	}
	// Set Pointer WallpaperUnit
	void SetPtr(WallpaperUnit* NewPtr)
	{
		Unit_ = NewPtr;
	}

	// Destructor
	~Wallpaper()
	{
		delete[] Unit_;
		WallpaperCount--;
	}
private:
	WallpaperUnit* Unit_;
	static int WallpaperCount;
};
int Wallpaper::WallpaperCount = 0;
class Flat
{
public:
	// Constructor By Default
	Flat()
	{
		Rooms_ = nullptr;
		RoomsNumber_ = 0;
	}
	// Add Room To Flat
	void AddRoomToFlat(Room* Rooms, int NumbersOfRooms)
	{
		Room* temp = new Room[NumbersOfRooms];
		for (int i = 0; i < NumbersOfRooms; i++)
		{
			temp[i] = Rooms[i];
		}
		Rooms_ = Rooms;
		RoomsNumber_ = NumbersOfRooms;
	}
	// Show Rooms in Flat
	void ShowRoomsInFlat()
	{
		if (this == nullptr)
			return;
		for (int i = 0; i < RoomsNumber_; i++)
		{
			cout << "Room Number: " << i + 1 << endl;
			Rooms_[i].Show();
			cout << endl;
		}
	}
	// Calculate Room Cost
	void CalculateRoomCosts(Wallpaper* Walp)
	{
		// (Width + Lenght) * 2 = result;   result * Height = SquareRoom;
		// WallpaperWidth * WallpaperLenght = SquareWallpaper
		// SquareRoom % SquareWallpaper = WallpaperCount;
		// WallpaperCount * WallpaperCost = ResultCost;
		if (this == 0)
			return;


		for (int i = 0; i < RoomsNumber_; i++)
		{
			cout << "Enter Wallpaper Number: " << endl;
			int Choice;
			cin >> Choice;

			if (Choice > Walp->GetWallpaperCount())
			{
				cout << "Error Number of Wallpaper" << endl;
				return;
			}

			cout << "Room Number: " << i + 1 << endl;
			int result = (Rooms_[i].getRoomWidth() + Rooms_[i].getRoomLenght()) * 2;
			int SquareRoom = result * Rooms_[i].getRoomHeight();
			int WallpaperCount = SquareRoom / Walp->SquareWallpaper(Choice - 1);
			int ResultCost = WallpaperCount * Walp->WallpaperCost(Choice - 1);
			cout << "Result Cost: " << ResultCost << endl;
			cout << "Wallpaper Count: " << WallpaperCount << endl;
			cout << endl;
		}
	}
	// Get Rooms Method
	int GetRoomsNum()
	{
		return RoomsNumber_;
	}
	// Destructor
	~Flat()
	{
		delete[] Rooms_;
		RoomsNumber_ = 0;
	}

private:
	Room* Rooms_;
	int RoomsNumber_;
};

// Fill Wallpaper from Text File
void GetWallpaperFromFile(Wallpaper* Walp)
{
	FILE* pfile;
	if ((pfile = fopen("1.txt", "r")) == NULL)
	{
		cout << "File isnt open" << endl;
		exit(EXIT_FAILURE);
	}

	int i = 0;
	char WallpaperNames[20];
	while (!feof(pfile))
	{
		fscanf(pfile, "%s ", WallpaperNames);
		i++;
	}
	fclose(pfile);
	if ((pfile = fopen("1.txt", "r")) == NULL)
	{
		cout << "File isnt open" << endl;
		exit(EXIT_FAILURE);
	}

	int UserChoice = i / 4;

	WallpaperUnit* temp = new WallpaperUnit[UserChoice];
	Walp->SetWallpaperCount(UserChoice);

	for (int j = 0; j < UserChoice; j++)
	{
		// Name
		char UserName[20];
		fscanf(pfile, "%s", UserName);
		// Size
		int Width = 0;
		fscanf_s(pfile, "%d", &Width);

		int Lenght = 0;
		fscanf_s(pfile, "%d", &Lenght);

		float Cost = 0;
		fscanf(pfile, "%f", &Cost);
		temp[j].AddWallpaper(UserName,Width,Lenght,Cost);

	}
	Walp->SetPtr(temp);

	cout << "Count of Wallpaper in text File: " << i / 4 << endl;
	cout << "Wallpaper in Text File: " << endl;
	for (int i = 0; i < UserChoice; i++)
	{
		cout << "Number " << i + 1 << endl;
		temp[i].Show();
		cout << endl;
	}
	fclose(pfile);
}
int main()
{
	Wallpaper Walp;
	Flat* flat = 0;
	Room* Rooms = 0;
	while (1)
	{
		int UserChoice;
		cout << "1. Create a Flat" << endl;
		cout << "2. Add Wallpaper From Text File" << endl;
		cout << "3. Show Rooms" << endl;
		cout << "4. Create New Wallpaper" << endl;
		cout << "5. Show Wallpapers" << endl;
		cout << "6. Calculate Cost" << endl;
		cout << "7. Exit" << endl;
		cin >> UserChoice;
		system("cls");
		switch (UserChoice)
		{
		case 1:
		{
			cout << "Enter Counts of Rooms: " << endl;
			int CountRooms;
			cin >> CountRooms;
			Rooms = new Room[CountRooms];

			for (int i = 0; i < CountRooms; i++)
			{
				Rooms[i].AddRoom();
			}

			flat = new Flat[CountRooms];
			flat->AddRoomToFlat(Rooms, CountRooms);
			break;
		}
		case 2:
		{
			GetWallpaperFromFile(Walp.GetPtr());
			break;
		}
		case 3:
		{
			flat->ShowRoomsInFlat();
			break;
		}
		case 4:
		{
			Walp.AddWallpaper();
			break;
		}
		case 5:
		{
			if (Walp.GetWallpaperCount() == 0)
			{
				cout << "Wallpapers is Empty" << endl;
				break;
			}

			Walp.Show();
			break;
		}
		case 6:
		{
			if (Walp.GetWallpaperCount() == 0)
			{
				cout << "To Calculate Rooms Cost You Need To Add Wallpaper: " << endl;
				break;
			}

			flat->CalculateRoomCosts(Walp.GetPtr());

			break;
		}
		case 7: return 0;
		default: cout << "Error" << endl; break;
		}
	}
}
