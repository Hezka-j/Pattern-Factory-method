#include <iostream>
using namespace std;
class PictureCat{
public:
	PictureCat() {
		cout << "PictureCat\n";
	}
	virtual void MakeHappy() = 0;
};
class PictureFranceCat : public PictureCat{
public:
	PictureFranceCat() {
		cout << "PictureFranceCat\n";
	}
	virtual void MakeHappy() {
		cout << "happy sounds\n";
	}
};

class ArtistCat{
	//int age = 0;
public:
	ArtistCat() {
		cout << "ArtistCat\n";
	}
	virtual PictureCat* CreateMasterpiece() = 0;
};

class ArtistFranceCat : public ArtistCat{
public:
	ArtistFranceCat() {
		cout << "ArtistFranceCat\n";
	}
	virtual PictureCat* CreateMasterpiece() override {
		return new PictureFranceCat;
	}
};
int main()
{
	ArtistCat* man = new ArtistFranceCat;
	PictureCat* masterpiece = man->CreateMasterpiece();
	masterpiece->MakeHappy();
}
