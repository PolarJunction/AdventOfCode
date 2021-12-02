/* Day Two - 2020 */
#include <fstream>
#include <vector>

struct password_entry
{
    int i_lower;
    int i_upper;
	char c_key;
    std::string s_password;
};

// Check if a given password entry is valid - part one
bool is_valid_part_one(password_entry t_entry)
{
	// The occurances of the key char should be within lower -> upper bounds
	int i_count = 0;
	for (int i=0; i< t_entry.s_password.size(); i++)
	{
		if (t_entry.s_password[i] == t_entry.c_key)
		{
			i_count++;
		}
	}

	if ((i_count >= t_entry.i_lower) && (i_count <= t_entry.i_upper)) return true;
	else return false;
}

// Check if a given password entry is valid - part two
bool is_valid_part_two(password_entry t_entry)
{
	// The Key Char should match only one position, index starts at 1
	if ((t_entry.s_password[t_entry.i_lower - 1] == t_entry.c_key) && (t_entry.s_password[t_entry.i_upper - 1] == t_entry.c_key))
	{
		return false;
	}
	else if ((t_entry.s_password[t_entry.i_lower - 1] == t_entry.c_key) || (t_entry.s_password[t_entry.i_upper - 1] == t_entry.c_key))
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main ()
{
	int i_part_one_valid = 0;
	int i_part_two_valid = 0;
	char c_delim;

	std::vector<password_entry> v_passwords;

	// Process the input file
	std::ifstream in("input.txt");

	while( !in.eof() )
	{
		// Split the contents into a password entry struct
		password_entry tmp_pass;
		in >> tmp_pass.i_lower >> c_delim >> tmp_pass.i_upper >> tmp_pass.c_key >> c_delim >> tmp_pass.s_password;

		v_passwords.push_back(tmp_pass);
	}

	// Check every password entry for validity
	for (int i=0; i<v_passwords.size(); i++)
	{
		// Check for pprt one valid passwords
		if(is_valid_part_one(v_passwords[i]))
		{
			i_part_one_valid++;
		}

		// Check for part two valid passwords
		if(is_valid_part_two(v_passwords[i]))
		{
			i_part_two_valid++;
		}
	}

	printf("P1 Valid: %u, P2 Valid: %u\n", i_part_one_valid, i_part_two_valid);

}
