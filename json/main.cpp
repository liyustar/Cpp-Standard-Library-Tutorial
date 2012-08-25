#include <string>
#include <iostream>
#include <json.h>
using namespace std;

int ParseJsonFromString()  
{  
	const char* str = "{\"uploadid\": \"UP000000\",\"code\": 100,\"msg\": \"\",\"files\": \"\"}";  

	Json::Reader reader;  
	Json::Value root;  
	if (reader.parse(str, root))  // reader��Json�ַ���������root��root������Json��������Ԫ��  
	{  
		std::string upload_id = root["uploadid"].asString();  // ���ʽڵ㣬upload_id = "UP000000"  
		int code = root["code"].asInt();    // ���ʽڵ㣬code = 100  
		cout << "code: " << code << endl;
	}  
	return 0;  
}

int main() {
	ParseJsonFromString();
	return 0;
}
