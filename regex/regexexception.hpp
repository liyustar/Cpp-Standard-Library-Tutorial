#include <boost/regex.hpp>
#include <string>

template <typename T>
std::string regexCode (T code)
{
	switch (code) {
		case boost::regex_constants::error_collate:
			return "error_coolate: "
				   "regex has invalid collating element name";
		case boost::regex_constants::error_ctype:
			return "error_ctype: "
				   "regex has invalid character class name";
		case boost::regex_constants::error_escape:
			return "error_escape: "
				   "regex has invalid escaped char. or trailing escape";
		case boost::regex_constants::error_backref:
			return "error_backref: "
				   "regex has mismatched '[' and ']'";
		case boost::regex_constants::error_paren:
			return "error_paren: "
				   "regex has mismatched '(' and ')'";
		case boost::regex_constants::error_brace:
			return "error_brace: "
				   "regex has mismatched '{' and '}'";
		case boost::regex_constants::error_badbrace:
			return "error_badbrace: "
				   "regex has invalid range in {} expression";
		case boost::regex_constants::error_range:
			return "error_range: "
				   "regex has invalid character range, such as '[b-a]'";
		case boost::regex_constants::error_space:
			return "error_space: "
				   "insufficient memory to convert regex into finite state";
		case boost::regex_constants::error_badrepeat:
			return "error_badrepeat: "
				   "one of *?+{ not preceded by valid regex";
		case boost::regex_constants::error_complexity:
			return "error_complexity: "
				   "complexity of match against regex over pre-set level";
		case boost::regex_constants::error_stack:
			return "error_stack: "
				   "insufficient memory to determine regex match";
	}
	return "unknown/non-standard/non-boost regex error code";
}

