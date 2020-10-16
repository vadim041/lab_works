
struct name
{
	char name[30];
	char surname[50];
	char patronymic[50];
};
struct adress {
	char street[15];
	int house_number;
	int flat_number;
};
class Abiturient {
	name n;
	adress adr;
	int marks[5];
public:
	Abiturient();
	void show();
	bool BadMarksCheck();
	int sum();
};