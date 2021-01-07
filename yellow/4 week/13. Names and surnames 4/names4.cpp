// В приватных полях класса Person сохраним два словаря:

// first_names, для каждого года с изменением имени хранящий соответствующее имя.
// last_names, для каждого года с изменением фамилии хранящий соответствующую фамилию.
// Методы ChangeFirstName и ChangeLastName будут лишь добавлять очередную запись в соответствующий словарь.

// В методе GetFulName найдём имя и фамилию, соответствующие данному году, и затем аккуратно их выведем, 
// соблюдая все требования условия. Здесь нам пригодится функция FindNameByYear, 
// принимающая на вход год и словарь «год → имя/фамилия» и возвращающая имя/фамилию, соответствующую данному году.
#include <bits/stdc++.h>

// если имя неизвестно, возвращает пустую строку
string FindNameByYear(const map<int, string>& names, int year) {
	string name;  // изначально имя неизвестно

	auto it = names.upper_bound(year);
	if(it != names.begin()) {
		name = (--it)->second;
	}

	return name;
}

class Person {
	private:
	  	map<int, string> first_names;
	  	map<int, string> last_names;
	  	
	public:
	  	void ChangeFirstName(int year, const string& first_name) {
	    	first_names[year] = first_name;
	  	}
	  	
	  	void ChangeLastName(int year, const string& last_name) {
	    	last_names[year] = last_name;
	  	}
	  	
	  	string GetFullName(int year) {
	    	// получаем имя и фамилию по состоянию на год year
	    	const string first_name = FindNameByYear(first_names, year);
	    	const string last_name = FindNameByYear(last_names, year);
	    
	    	// если и имя, и фамилия неизвестны
	    	if (first_name.empty() && last_name.empty()) {
		      	return "Incognito";
		    	
	    	// если неизвестно только имя
	    	} else if (first_name.empty()) {
	      		return last_name + " with unknown first name";
	      
	    	// если неизвестна только фамилия
	    	} else if (last_name.empty()) {
	      		return first_name + " with unknown last name";
	      
	    	// если известны и имя, и фамилия
	    	} else {
	      		return first_name + " " + last_name;
	   	 	}
	  	}
};