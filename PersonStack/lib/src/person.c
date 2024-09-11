/*
 * person.c
 *
 *  Created on: Sep 9, 2024
 *      Author: taham
 */
#include "date.h"
#include "person.h"
#include "string.h"
#include "stdlib.h"
#include "stdio.h"

#define PUBLIC
#define PRIVATE static

#define ASIZE(a) (sizeof((a)) / sizeof((a)[0]));

PRIVATE const char* const names[] = {
    "Ahmet Cengiz Yilmaz", "Ayse Demir", "Mehmet Ali Yilmaz", "Fatma Kaya",
    "Ali Mert Can", "Elif Ozturk", "Hasan Yalcin", "Merve Aslan",
    "MustafaKucuk", "Zeynep Karaca", "Ahmet Toprak", "Seda Yilmaz",
    "Emre Kurt", "Nazan Koc", "Burak Celik", "Hulya Aydin",
    "Omer Akin", "Gulsen Arslan", "Murat Tekin", "Cansu Kaya",
    "Ahmet Tekin", "Elif Guler", "Deniz Ozer", "Meryem Tuncer",
    "Yusuf Ozdemir", "Emine Keskin", "Osman Polat", "Sibel Yilmaz",
    "Huseyin Cakmak", "Ayla Duman", "Ege Can", "Ilknur Yilmaz",
    "Serkan Kucuk", "Derya Ekinci", "Cemil Akin", "Seda Yurt",
    "Yavuz Karahan", "Asli Erdem", "Hikmet Sari", "Sibel Demir",
    "Selim Cinar", "Seda Su Yilmaz", "Huseyin Mert Kaya", "Burcu Atalay",
    "Oktay Yalcin", "Fadime Ozturk", "Mehmet Cakir", "Nilufer Yavuz",
    "Ercan Atasoy", "Aysel Karaca", "Melek Soylu", "Serdar Aydin",
    "Ayten Yilmaz", "Emre Bal", "Selda Ertugrul", "Ali Ergin",
    "Fatma Demir", "Gokhan Yurt", "Huriye Sadi", "Ali Koc",
    "Sibel Nur Kizir", "Hikmet Can Ekinci", "Oya Arslan", "Mert Ali Yildirim",
    "Buket Akin", "Gunay Ozturk", "Fikri Yalcin", "Aysel Keskin",
    "Huseyin Kurt", "Merve Koc", "Mehmet Ali Basaran", "Neslihan Deniz Toprak",
    "Emre Yilmaz", "Nazan Guler", "Yasemin Yilmaz", "Cemil Cem Yurt",
    "Serap Yalcin", "Ali Can", "Gulseren Erdem", "Oktay Ali Celik"
};

PRIVATE const char* const cities[] = {
    "Adana", "Adiyaman", "Afyonkarahisar", "Agri", "Aksaray", "Amasya", "Ankara", "Antalya",
    "Ardahan", "Artvin", "Aydin", "Balikesir", "Bartin", "Batman", "Bayburt", "Bilecik",
    "Bingol", "Bitlis", "Bolu", "Burdur", "Bursa", "Canakkale", "Cankiri", "Corum",
    "Denizli", "Diyarbakir", "Duzce", "Edirne", "Elazig", "Erzincan", "Erzurum", "Eskisehir",
    "Gaziantep", "Giresun", "Gumushane", "Hakkari", "Hatay", "Igdir", "Isparta", "Istanbul",
    "Izmir", "Kahramanmaras", "Karabuk", "Karaman", "Kars", "Kastamonu", "Kayseri", "Kirikkale",
    "Kirklareli", "Kirsehir", "Kilis", "Kocaeli", "Konya", "Kutahya", "Malatya", "Manisa",
    "Mardin", "Mersin", "Mugla", "Mus", "Nevsehir", "Nigde", "Ordu", "Osmaniye",
    "Rize", "Sakarya", "Samsun", "Sanliurfa", "Sirnak", "Sinop", "Sivas", "Sile",
    "Tekirdag", "Tokat", "Trabzon", "Tunceli", "Usak", "Van", "Yalova", "Yozgat",
    "Zonguldak"
};

PRIVATE size_t name_count = 50;
PRIVATE size_t city_count = 80;

PRIVATE void get_person_name_surname(const char * const* fullname_in, char** name_out, char** surname_out);
PRIVATE int get_random_int(int min, int max);
PRIVATE char* make_strncpy(const char* source, int size);

PUBLIC void create_random_person(Person *out)
{
	int iname = get_random_int(0, name_count);
	int icity = get_random_int(0, city_count);

	Date* birthday = (Date*)malloc(sizeof(Date));
	set_random_date_range(birthday, 1995, 1999);

	get_person_name_surname(&names[iname], &(out->name), &(out->surname));
	out->city = cities[icity];
	out->birthday = birthday;
}

PUBLIC void print_person(const Person* in)
{
	char date[13];
	snprintf(date, sizeof(date), "%02d.%02d.%04d", in->birthday->m_mday, in->birthday->m_month, in->birthday->m_year);
	printf("%-10s %-15s %-15s %-10s\n", 
		in->surname, in->name, date, in->city);
}

PUBLIC void free_person(const Person* in)
{
	free(in->name);
	free(in->surname);
	free(in->birthday);
}

PRIVATE void get_person_name_surname(const char * const* fullname_in,  char** name_out,  char** surname_out)
{
	const char* fullname = *fullname_in;
	const char* last_space = NULL;
	int length = (int)strlen(fullname);

	for(int i = 0; fullname[i] != '\0' && i < length; i++)
	{
		if(fullname[i] == ' ')
		{
			last_space = (fullname + i);
		}
	}

	if(last_space == NULL)
	{
		*name_out = (char*)malloc((length + 1) * (int)sizeof(char));
		strcpy(*name_out, fullname);

		*surname_out = (char*)malloc(2 * sizeof(char));
		strcpy(*surname_out, "-\0");
		return;
	}

	int name_size = (last_space - fullname);
	char* name = make_strncpy(fullname, name_size);

	int surname_size = length - name_size;
	char* surname = make_strncpy(fullname + name_size + 1, surname_size);

	*name_out = name;
	*surname_out = surname;
 }

PRIVATE int get_random_int(int min, int max)
{
	return min + rand() % (max - min + 1);
}

PRIVATE char* make_strncpy(const char* source, int size)
{
	char* ret = (char*)malloc((size + 1)* (int)sizeof(char));
	if(ret == NULL)
	{
		fprintf(stderr, "Could not allocate memory\n");
		getchar();
		exit(EXIT_FAILURE);
	}
	strncpy(ret, source, size);
	ret[size] = '\0';
	return ret;
}