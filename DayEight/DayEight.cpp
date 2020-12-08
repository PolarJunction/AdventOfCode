/* Day Eight - 2020 */
#include <fstream>
#include <vector>

struct instruction
{
    std::string action;
    int value;
    int count; // Times this instruction has been executed
};

// Return true if we didn't hit an infinite loop
bool b_execute(std::vector<instruction> &v_tmp, int &acc)
{
    for (int i = 0; i < v_tmp.size();)
    {
        v_tmp[i].count++;

        if (v_tmp[i].count > 1)
        {
            return false;
        }

        // Perform action
        if (v_tmp[i].action == "acc")
        {
            acc += v_tmp[i].value;
            i++;
        }
        else if (v_tmp[i].action == "jmp")
        {
            i += v_tmp[i].value;
        }
        else 
        {
            // Nop does nothing
            i++;
        }
    }

    return true;
}

int main ()
{
    std::vector<instruction> v_instructions;
    std::vector<instruction> v_tmp;
    int i_acc = 0;

    // Process the input file
    std::ifstream in("input.txt");

    // Decode the input file into a vector of instructions
    while( !in.eof() )
    {
        instruction tmp_code;

        in >> tmp_code.action >> tmp_code.value;
        tmp_code.count = 0;

        v_instructions.push_back(tmp_code);
    }

    // Copy the instructions so we can modify them
    v_tmp = v_instructions;

    b_execute(v_tmp, i_acc);
    printf("P1 - Acc Val: %u\n", i_acc);


    int i_failed = 1;
    int i_idx = 0;

    while (i_failed == 1)
    {
        // Take a fresh copy of the instructions
        v_tmp = v_instructions;
        i_acc = 0;

        // Search through for Nops/Jmps that we can change
        do
        {
            i_idx++;
        }
        while (v_tmp[i_idx].action != "jmp" && v_tmp[i_idx].action != "nop" && i_idx < v_tmp.size());

        // Assume we found a nop/jump, switch it
        if(v_tmp[i_idx].action == "jmp") v_tmp[i_idx].action = "nop";
        else v_tmp[i_idx].action = "jmp";

        // Run the program again
        i_failed = !b_execute(v_tmp, i_acc);
    }

    printf("P2 - Acc Val: %u\n", i_acc);
}