#include <string>
#include <iostream>
#include <json.h>
using namespace std;

int ParseJsonFromString()  
{  
	const char* str = "{\"uploadid\": \"UP000000\",\"code\": 100,\"msg\": \"\",\"files\": \"\"}";  

	Json::Reader reader;  
	Json::Value root;  
	if (reader.parse(str, root))  // reader将Json字符串解析到root，root将包含Json里所有子元素  
	{  
		std::string upload_id = root["uploadid"].asString();  // 访问节点，upload_id = "UP000000"  
		int code = root["code"].asInt();    // 访问节点，code = 100  
		cout << "code: " << code << endl;
	}  
	return 0;  
}

int main() {
	ParseJsonFromString();
	return 0;
}
