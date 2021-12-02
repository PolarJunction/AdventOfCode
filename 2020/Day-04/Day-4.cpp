/* Day Four - 2020 */
#include <fstream>
#include <vector>
#include <sstream>

// Check if a given password entry is valid - part one
bool b_all_passport_fields(std::string s_entry)
{
    return ( s_entry.find("byr:") != std::string::npos &&
             s_entry.find("iyr:") != std::string::npos &&
             s_entry.find("eyr:") != std::string::npos &&
             s_entry.find("hgt:") != std::string::npos &&
             s_entry.find("hcl:") != std::string::npos &&
             s_entry.find("ecl:") != std::string::npos &&
             s_entry.find("pid:") != std::string::npos );
}

bool b_check_single_pair(std::string s_field, std::string s_value)
{
    // Check the validity of the key-value pairs
    if (s_field == "byr")
    {
        if (atoi(s_value.c_str()) < 1920 || atoi(s_value.c_str())> 2002) return false;
    }
    else if (s_field == "iyr")
    {
        // Check the Issue Year is >= 2010 && <= 2020
        if(atoi(s_value.c_str()) < 2010 || atoi(s_value.c_str()) > 2020) return false; 
    }
    else if (s_field == "eyr")
    {
        // Check the Expiration year is >= 2020 && <= 2030
        if(atoi(s_value.c_str()) < 2020 || atoi(s_value.c_str()) > 2030) return false;
    }
    else if (s_field == "hgt")
    {
        std::istringstream tmp_iss(s_field);
        int height = 0;
        tmp_iss >> height;

        if(s_value.find("cm") != std::string::npos)
        {
            // Check the range in CM
            height = atoi(s_value.substr(0, s_value.find("cm")).c_str());
            if (height < 150 || height > 193) return false;
        }
        else if(s_value.find("in") != std::string::npos)
        {
            // Check the range in IN
            height = atoi(s_value.substr(0, s_value.find("in")).c_str());
            if (height < 59 || height > 76) return false;
        }
        else return false;
    }
    else if (s_field == "hcl")
    {
        if (s_value.length() != 7 || s_value[0] != '#') return false;
    }
    else if (s_field == "ecl")
    {
        // amb blu brn gry grn hzl oth
        if (s_value != "amb" && s_value != "blu" && s_value != "brn" && s_value != "gry" && s_value != "grn" && s_value != "hzl" && s_value != "oth") return false;
    }
    else if (s_field == "pid")
    {
        if (s_value.length() != 9) return false;
    }
    return true;
}

// Check if the rules have been met - part two
bool b_check_field_rules(std::string s_entry)
{
    std::string s_field;
    std::string s_value;
    std::istringstream iss(s_entry);

    while(std::getline(iss, s_field, ':'))
    {
        std::getline(iss, s_value, ' ');

        if (b_check_single_pair(s_field, s_value) == false)
        {
            printf("ERR - Field: %s, Value: %s.\n", s_field.c_str(), s_value.c_str());
            return false;
        }
    }

    // All fields passed. Return true
    return true;
}

int main ()
{
    // Process the input file
    std::ifstream in("input.txt");
    std::string s_entry;
    std::string s_line;

    int i_all_fields = 0;
    int i_all_valid = 0;

    while( getline(in, s_line) )
    {
        // This means we have to add an extra empty line at the end of the input to "finish" the last entry
        if (s_line.empty())
        {
            if (b_all_passport_fields(s_entry))
            {
                i_all_fields++;
                if (b_check_field_rules(s_entry))
                {
                    i_all_valid++;
                }
            }
            s_entry.clear();
        }
        else
        {
            s_entry.append(s_line);
            s_entry.append(" "); // Add a space betweeen consequtive lines
        }
    }

    printf("P1 - Valid Passports: %u\n", i_all_fields);
    printf("P2 - Valid Passports: %u\n", i_all_valid);
}
