#include <iostream>
#include <string>
#include <time.h>


#define province_num 81

//std::string * get_il(int boundary){
//	std::string * arr = new std::string[20];

//	return arr;
//}

class mm_op
{
	public:
		std::string min_char = "";
		std::string max_char = "";
		int max_lengt = 0;
		int min_length = 0;

		//methods
		void initilaze_parameters(std::string * provinces);

};
void mm_op::initilaze_parameters(std::string * province)
{
	max_lengt = province[0].length();
	min_length = province[1].length();

	for (int i = 0;i < province_num;i++){

		if(province[i].length() > max_lengt)
		{
			max_lengt = province[i].length();
			max_char = province[i];
		}
		if(province[i].length() < min_length)
		{
			min_length = province[i].length();
			min_char = province[i];
		}
	}
}

std::string * get_random_provinces(std::string * random_list,std::string * provinces,int rand_num)
{
	//seed time module
	srand(time(0));

	for(int i = 0;i < rand_num;i++)
	{
		random_list[i] = provinces[rand()%province_num];
		std::cout << random_list[i] << std::endl;
	}
	
}



int main()
{
	std::string *  province{new std::string[province_num]{"Adana", "Adiyaman", "Afyon", "Agrý", "Amasya", "Ankara", "Antalya", "Artvin", "Aydin", "Balikesir", "Bilecik", "Bingol", "Bitlis", "Bolu", "Burdur", "Bursa", "Canakkale", "Cankiri", "Corum", "Denizli", "Diyarbakir", "Edirne", "Elazig", "Erzincan", "Erzurum", "Eskisehir", "Gaziantep", "Giresun", "Gumushane", "Hakkari", "Hatay", "Isparta", "Mersin", "Ýstanbul", "Ýzmir", "Kars", "Kastamonu", "Kayseri", "Kirklareli", "Kirsehir", "Kocaeli", "Konya", "Kutahya", "Malatya", "Manisa", "Kahramanmaras", "Mardin", "Mugla", "Mus", "Nevsehir", "Nigde", "Ordu", "Rize", "Sakarya", "Samsun", "Siirt", "Sinop", "Sivas", "Tekirdag", "Tokat", "Trabzon", "Tunceli", "Sanlýurfa", "Usak", "Van", "Yozgat", "Zonguldak", "Aksaray", "Bayburt", "Karaman", "Kirikkale", "Batman", "Sýrnak", "Bartin", "Ardahan", "Igdir", "Yalova", "Karabuk", "Kilis", "Osmaniye", "Düzce"}};
	std::string * random_list = new std::string[20];

	//step 1
	mm_op mm_op_obj;
	mm_op_obj.initilaze_parameters(province);

	get_random_provinces(random_list,province,mm_op_obj.min_length);
	

	//step 2

	
	
	

	


	////3 rastgele sayi belirle
	//for(int i = 0;i < min_length;i++){
		
	//	random_list[i] = rand() % il_sayisi;
	//	std::cout << random_list[i] << std::endl;
	//std::cout << "max : " << max_char << " min : " << min_char;



	return 0;

}