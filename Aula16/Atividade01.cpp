#include <iostream>
#include <limits.h>
#include <time.h>

using namespace std;

int userAge(int year, int check_age ){
  //This function is used to calculate the ange of the user. 
  
  time_t t = time(NULL);
  struct tm tm = *localtime(&t); //stores the moment date. 

  int age = (tm.tm_year + 1900) - year;
  //creats a number MMDD to be used to check the user's real age.
  int test_age = ((tm.tm_mon * 100) + tm.tm_mday);  

  if( check_age > test_age){
      return age - 1;
  }
  else{
      return age;
  }
}

struct data{
    char name[100];
    int day = 0;
    int month = 0;
    int year = 0;
    int age = 0;
    int check_age = 0;
};

int main()
{
    data people[3];
    data oldest {"Errado", INT_MIN, INT_MIN, INT_MIN, INT_MIN};
    data youngest = {"Errado", INT_MAX, INT_MAX, INT_MAX, INT_MAX};

    for (int i = 0; i < 3; i++){
        
        cout << "Enter the name: ";
        cin >> people[i].name;
        cout << "Day of birth: ";
        cin >> people[i].day;
        cout << "Month of birth: ";
        cin >> people[i].month;
        cout << "year of birth: ";
        cin >> people[i].year;

        people[i].check_age = ((people[i].month -1 )* 100) + people[i].day;
        people[i].age = userAge(people[i].year, people[i].check_age);

        //Tests who is the oldest person.
        if(people[i].age > oldest.age){
            oldest = people[i];
        }
        else if(people[i].age == oldest.age){
            if(people[i].check_age < oldest.check_age){
                oldest = people[i];
            }
        }

        //Testes who is the yougest person. 
        if(people[i].age < youngest.age){
            youngest = people[i];
        }
        else if(people[i].age == youngest.age){
            if(people[i].check_age > youngest.check_age){
                youngest = people[i];
            }
        }
    }
        cout << "Pessoa mais velha: " << oldest.name << " idade: " << oldest.age << endl;
        cout << "Pessoa mais nova: " << youngest.name << " idade: " << youngest.age << endl;
        return 0;
}