#include <iostream>
#include <cctype>

using namespace std;
//������
bool isDigital(char* str){
	if(str == NULL || *str=='\0')
		return false;
	bool passE = false;
	int cntD = 0;
	for(int i = 0;str[i] != '\0';++i){
		if(i==0){
			if(!isdigit(str[i]) && str[i] != '+'&& str[i] != '-')
			   return false;
		}
		else if(!isdigit(str[i])){
			if(str[i] != '+' && str[i] != '-' && str[i] != '.' && str[i] != 'e' && str[i] != 'E')
				return false;
			if(str[i] == '.'&& cntD ==0)
				cntD++;
			else if(str[i] == '.' && cntD > 0)
				return false;
			if((str[i] == 'e' || str[i] == 'E') && !passE && str[i+1] != '\0'){
				passE = true;
				continue;
			}
			else if((str[i] == 'e' || str[i] == 'E') && !passE && str[i+1] == '\0')
				return false;
			else if((str[i] == 'e' || str[i] == 'E') && passE)
				return false;
			else if(!isdigit(str[i - 1])){
				if((str[i-1]=='e'||str[i-1]=='E') && (str[i] =='+'||str[i] == '-'))
					continue;
				else
					return false;
			}

		}
		else if(passE){
			while(str[i] != '\0'){
				if(!isdigit(str[i]))
					return false;
				++i;
			}
		}
	}
	return true;
}
void scanDigits(char** str){
	while(**str != '\0' && isdigit(**str))
		(*str)++;
}
bool isExponential(char** str){
	if(**str != 'e' || **str != 'E')
		return false;
	++(*str);
	if(**str == '+' || **str == '-')
		++(*str);
	if(**str == '\0')
		return false;
	scanDigits(str);
	return (**str == '\0')? true:false;
}
bool isNumberic(char* string){
	if(string == NULL)
		return false;
	if(*string == '+' || *string == '-')
		++string;
	if(*string == '\0')
		return false;
	bool numberic = true;
	scanDigits(&string);
	if(*string != '\0'){
		if(*string == '.')
		{
			++ string;
			scanDigits(&string);
			if(*string == 'e' || *string == 'E')
				numberic = isExponential(&string);
		}
		else if(*string == 'e' ||*string == 'E')
			numberic = isExponential(&string);
		else
			numberic = false;
	}
	return numberic && *string == '\0';
}
void Test(){
	char* str = "12e+5.4";
	//bool c = isDigital(str);
	bool c = isNumberic(str);
	cout<<c<<endl;
}

